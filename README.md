# syn68k

syn68k is a Motorola 68LC040 CPU emulator built as a static library. It either JIT-compiles blocks of 68k instructions to native x86 machine code or falls back to a portable interpreter on non-x86 hosts. It is the CPU engine for [Executor](../README.md), a clean-room Macintosh emulator.

## Architecture

```
┌─ syn68k ──────────────────────────────────────────────────────────┐
│                                                                    │
│  ┌─ syngen (build-time tool) ──────────────────────────────────┐  │
│  │  68k.scm + 68k.defines.scm  →  syn68k.c, mapinfo.c,        │  │
│  │  (Scheme-like DSL)              mapindex.c                  │  │
│  └─────────────────────────────────────────────────────────────┘  │
│                          │                                         │
│                          ▼                                         │
│  ┌─ runtime ───────────────────────────────────────────────────┐  │
│  │                                                             │  │
│  │  translate.c  ──→  block cache  ──→  ┌─ native/i386  ─┐   │  │
│  │  (68k → synops)   (hash + range)     │  JIT to x86    │   │  │
│  │                                      └────────────────┘   │  │
│  │                                      ┌─ native/null  ─┐   │  │
│  │                                      │  interpreter   │   │  │
│  │                                      └────────────────┘   │  │
│  │                                                             │  │
│  │  callback.c / trap.c  ←── A-trap dispatch from Executor    │  │
│  └─────────────────────────────────────────────────────────────┘  │
│                                                                    │
│  Public API: syn68k_public.h                                       │
└────────────────────────────────────────────────────────────────────┘
```

### Code generation pipeline (build time)

`syngen/` is a standalone tool that reads a Scheme-like DSL (`runtime/68k.scm` + `runtime/68k.defines.scm`) describing the semantics and bit patterns of every 68k instruction. It emits three C files that are compiled into the runtime:

| Output | Contents |
|---|---|
| `syn68k.c` | Per-opcode C handlers (the "synthetic opcodes") |
| `mapinfo.c` | Operand mode tables — how to fetch/store each addressing mode |
| `mapindex.c` | Opcode → mapinfo index table for fast dispatch |

`syngen` itself is a small compiler: tokenizer (`token.c`), parser (`parse.c`), macro expander (`macro.c`), expression reducer (`reduce.c`), and C code emitter (`generatecode.c`).

### Runtime modules

| File | Role |
|---|---|
| `translate.c` | Core translator: decodes a 68k instruction stream, calls syngen-generated handlers, emits synthetic opcodes or triggers native-code generation |
| `block.c` / `blockinfo.c` | Compiled block allocation and metadata |
| `hash.c` | Hash table mapping 68k PC → compiled block (the translation cache) |
| `rangetree.c` | Range tree for fast "does this address overlap a compiled block?" lookups used during invalidation |
| `backpatch.c` | Resolves forward branch targets after a block is fully compiled |
| `recompile.c` | Invalidates and recompiles blocks when written-to memory overlaps them (self-modifying code support) |
| `checksum.c` | Stores a CRC over the 68k bytes backing each block; used to detect stale cache entries without scanning |
| `destroyblock.c` / `deathqueue.c` | Block GC - queues and reclaims invalidated blocks |
| `alloc.c` | Pool allocator for compiled-block storage |
| `callback.c` | Installs a host C function at a "magic" 68k address so that when 68k code jumps there it calls back into the host |
| `trap.c` | Mac A-trap handler table: maps trap numbers to callbacks |
| `interrupt.c` | Synchronous interrupt polling and delivery |
| `init.c` | `initialize_68k_emulator()` - sets up all runtime state |
| `profile.c` | Optional execution profiling |
| `diagnostics.c` | Debug printing |
| `native.c` | Dispatch between interpreter and JIT backends |

### Backends

**`native/i386/`** - JIT compiler (x86 only)

Translates the intermediate synthetic opcodes into x86 machine code and writes them to an executable code buffer. Key files: `xlate.c` (opcode → x86 emission), `process.c` (post-processing / peephole), `analyze.c` (liveness analysis for condition-code optimization), `template.c` (x86 code templates), `i386-aux.c` (address-mode helpers). Perl scripts (`fold.pl`, `sched.pl`, `i486-optimize.pl`, `i486-cleanup.pl`, `x86_recog.pl`) perform additional peephole passes at build time.

**`native/null/`** - Portable interpreter fallback

Used on all non-x86 hosts (arm64, PowerPC, Alpha, etc.). Executes synthetic opcodes directly in C without emitting native machine code. No JIT overhead, but slower.

### Address space model

The 68k has a 32-bit address space. The host maps a contiguous block of memory as the "68k RAM" and records the base address in `ROMlib_offset`. Two macros translate between the two spaces:

```c
SYN68K_TO_US(addr)   // 68k addr  → native pointer
US_TO_SYN68K(addr)   // native ptr → 68k addr
```

On 32-bit hosts this is a simple add/subtract. On 64-bit hosts (where pointers are wider than 32 bits) it uses a `uint64` offset and truncates back to 32 bits.

Memory access macros (`READUB`, `READUW`, `READUL`, `WRITEUB`, etc.) call `SYN68K_TO_US` and handle big/little-endian byte swapping transparently.

### CPU state

The global `cpu_state` struct (`CPUState`) holds:

- `regs[16]` - data registers d0–d7 and address registers a0–a7, each a `M68kReg` union exposing `.ul.n` (uint32), `.uw.n` (uint16), `.ub.n` (uint8) sub-fields with correct endian layout
- `ccnz`, `ccn`, `ccc`, `ccv`, `ccx` - condition-code elements stored separately for speed (not packed into a flags byte)
- `sr` - status register (interrupt mask bits; cc bits are always zero here)
- `vbr`, `cacr`, `caar`, `usp`, `msp`, `isp` - supervisor registers
- `interrupt_pending[8]` / `interrupt_status_changed` - synchronous interrupt state
- `trap_handler_info[64]` - A-trap callback table
- `jsr_stack` - small stack for tracking JSR/RTS pairs (used by the JIT)

Macros `EM_D0`–`EM_D7` and `EM_A0`–`EM_A7` (alias `EM_SP`/`EM_FP`) provide convenient access to individual registers.

## Public API

Everything a host application needs is in `include/syn68k_public.h`.

```c
// Initialize - call once before running any 68k code.
void initialize_68k_emulator(void (*while_busy)(int), int native_p,
                             uint32 trap_vector_storage[64],
                             uint32 dos_int_flag_addr);

// Execute 68k code starting at `addr`.
#define CALL_EMULATOR(addr)  ...  // pushes magic exit addr, calls interpret_code

// JIT lookup - finds or creates a compiled block for the given 68k PC.
const uint16 *hash_lookup_code_and_create_if_needed(syn68k_addr_t adr);

// Execute a (possibly already-compiled) block.
void interpret_code(const uint16 *code);

// Invalidate compiled blocks covering the given 68k address range.
// Call whenever the host writes to 68k memory that might contain code.
unsigned long destroy_blocks(syn68k_addr_t low_m68k_address, uint32 num_bytes);

// Install a host C function as a callback reachable from 68k code.
// Returns a 68k address; when 68k code jumps/calls there, func(pc, arg) fires.
syn68k_addr_t callback_install(callback_handler_t func, void *arbitrary_argument);
void          callback_remove(syn68k_addr_t m68k_address);

// Install/remove a Mac A-trap handler (trap number 0..63).
void trap_install_handler(unsigned trap_number, callback_handler_t func, void *arg);
void trap_remove_handler(unsigned trap_number);

// Interrupt delivery (synchronous mode).
void interrupt_generate(unsigned priority);
```

## How Executor uses syn68k

Executor (`../src/`) is the only consumer of this library. The integration pattern:

1. **Startup** - Executor calls `initialize_68k_emulator()` with `native_p=1` on x86 (enables JIT) or `0` on other architectures (interpreter only).

2. **Trap installation** - For each Mac A-trap Executor implements (QuickDraw, Memory Manager, etc.), it calls `trap_install_handler()` mapping the trap number to the ROMlib C function.

3. **Running code** - To launch a Mac application, Executor sets up `cpu_state.regs` (stack pointer, etc.) and calls `CALL_EMULATOR(entry_point)`.

4. **Trap dispatch** - When the JIT or interpreter hits an A-line instruction, it calls the registered handler via the `trap_handler_info` table. The handler is an Executor ROMlib function that reads/writes arguments through `cpu_state.regs` and `READ*/WRITE*` macros.

5. **Memory invalidation** - When Executor loads a new CODE segment into the Mac heap, it calls `destroy_blocks()` on that address range so the JIT does not execute stale compiled code.

6. **Address translation** - Executor sets `ROMlib_offset` to the base of its Mac RAM allocation. All 68k pointer values are 32-bit offsets into that buffer; `SYN68K_TO_US` / `US_TO_SYN68K` and the byteswap macros are used throughout ROMlib to dereference Mac pointers.

## Building

syn68k uses autoconf/automake.

```bash
./autogen.sh
./configure
make
make install        # installs to /usr/local by default
```

To install into a local prefix for use by Executor:

```bash
./autogen.sh
mkdir build && cd build
../configure --prefix="$(pwd)/../../syn68k-prefix"
make && make install
```

To build a 32-bit library on an x86_64 host:

```bash
CC='gcc -m32' ./configure --build=i686-pc-linux-gnu --host=i686-pc-linux-gnu
make
```

On arm64 / Apple Silicon the JIT backend is not available; the library builds with the `native/null` interpreter automatically.

## Testing

```bash
cd test
./syngentest          # run against the golden output files in test/output/
```

The test suite (`test/tests.c`, `test/testrt.c`, `test/testqsort.c`) runs a battery of 68k instructions through both the interpreter and (on x86) the JIT, comparing against known-good results. `test/maketestbattery.pl` generates additional test vectors.

## Platform support

| Architecture | JIT | Interpreter | Notes |
|---|---|---|---|
| i386 / x86 (32-bit) | Yes | Yes | Primary target |
| x86_64 | No | Yes | 64-bit JIT not implemented |
| arm64 / aarch64 | No | Yes | Current porting target in Executor |
| PowerPC (32-bit) | No | Yes | Tested circa 2009 |
| Alpha | No | Yes | Historic; had a modified-gcc 32-bit-pointer port |

## History

syn68k was written at ARDI (Abacus Research and Development, Inc.) in the early 1990s to allow Executor to run on Sun-3 and NeXT workstations that lacked a physical 680x0 CPU. Active development ended around 1995. The code was converted to the GNU autotools build system in 2003 and published on GitHub in 2008 by the original author, Cliff Matthews (ctm).
