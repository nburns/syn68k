# AGENTS.md — syn68k

Quick orientation for agents. Read this before touching any code. Companion to `README.md` (architecture) and `../README.md` (Executor context).

## What this is

A static library (`libsyn68k.a`) that emulates the Motorola 68LC040 CPU. Its sole consumer is Executor (`../src/`) — a clean-room Mac emulator. syn68k either JIT-compiles 68k instruction blocks to x86 machine code (`GENERATE_NATIVE_CODE` path) or interprets a portable intermediate representation (`native/null` fallback, used on arm64 and all non-x86 hosts).

## Critical orientation before editing

### Generated files — do not read or edit

The following C files are **outputs of the `syngen` build tool**, not source files. They are in `.gitignore` and regenerated at every build. **Do not read them** — `syn68k.c` alone is 57,000 lines and will saturate your context.

- `runtime/syn68k.c` (57k lines) — per-opcode handlers
- `runtime/mapinfo.c` — operand/addressing-mode tables
- `runtime/mapindex.c` — opcode→mapinfo dispatch table

To understand or change opcode behavior, read `runtime/68k.scm` instead (**6500 lines** — always use `offset`/`limit`; search for opcodes with `rg 'defopcode MOVE'`). To change the code generator, edit `syngen/*.c`.

### 32-bit vs 64-bit split

The entire library was designed for 32-bit hosts. The 64-bit path (`SIZEOF_CHAR_P == 8`) exists but is incomplete. Key differences:

- `ROMlib_offset` is `uint64` on 64-bit, `uint32` on 32-bit.
- `SYN68K_TO_US(addr)` truncates to 32 bits on 64-bit hosts to keep addresses within the Mac RAM window.
- `DEREF(typ, addr)` uses packed-struct unions on 64-bit to avoid alignment faults.
- The JIT (`GENERATE_NATIVE_CODE`) is only enabled on 32-bit i386; it is `#ifdef`'d out everywhere else.
- `init.c:initialize_68k_emulator()` has a special 64-bit code path for the `MAGIC_RTE_ADDRESS` setup (lines ~112–128).

### Endianness

The 68k is big-endian. The host may be little-endian (x86, arm64). All 68k memory reads/writes go through the `READUB/UW/UL` / `WRITEUB/UW/UL` macros (defined in `syn68k_public.h`) which call `SWAPUW_IFLE` / `SWAPUL_IFLE` as needed. Never access 68k memory with a bare pointer dereference.

`SWAPUW_IFLE` / `SWAPUL_IFLE` are no-ops on big-endian hosts. On little-endian hosts they call the architecture-specific swap inline (x86 inline asm `rorw`/`bswap`, or C fallback).

### Condition codes

The 68k CCR is **not** stored packed. Instead `cpu_state` has five separate fields:

```c
CCRElement ccnz, ccn, ccc, ccv, ccx;  // 0 = cleared, non-0 = set (NOT 0 or 1)
```

`ccnz` is inverted: `ccnz == 0` means the Z flag is set (result was zero). This matches the hardware sense of "not zero". Reconstruct the full SR byte with `COMPUTE_SR_FROM_CPU_STATE()`.

`CCRElement` is `uint8` on i386 (so `setb`/`sete` can write it directly), `int32` elsewhere.

## File map

### Must-read for any work

| File | Why |
|---|---|
| `include/syn68k_public.h` | Complete public API, CPUState struct, all memory/swap macros, address translation |
| `include/syn68k_private.h.in` | Internal types: `OpcodeMappingInfo`, `BitfieldInfo`, `BOOL`, CC bit constants, `USE_DIRECT_DISPATCH` / `GENERATE_NATIVE_CODE` guards |
| `runtime/translate.c` | Core translator — the entry point for understanding how a 68k instruction stream becomes compiled blocks |

### For interpreter/opcode work

| File | Contents |
|---|---|
| `runtime/68k.scm` | DSL source for all 68k instruction semantics (~3000 lines) |
| `runtime/68k.defines.scm` | Macros used by 68k.scm |
| `syngen/generatecode.c` | Emits C from the parsed DSL |
| `syngen/parse.c` | DSL parser |
| `syngen/reduce.c` | Expression simplifier/reducer |

### For JIT work (x86 only)

| File | Contents |
|---|---|
| `runtime/native/i386/xlate.c` | Builds `guest_code_descriptor_t` lookup tables from `xlatetable.c` |
| `runtime/native/i386/process.c` | Post-processes translated x86 blocks (peephole, scheduling) |
| `runtime/native/i386/analyze.c` | Liveness analysis for CC optimization |
| `runtime/native/i386/template.c` | x86 code templates for each operation |
| `runtime/native/i386/host-native.c` | Low-level x86 code emission and interrupt stub |
| `runtime/native/i386/xlatemain.c` | Entry point for native translation pipeline |

### For block-cache / invalidation work

| File | Contents |
|---|---|
| `runtime/hash.c` | `block_hash_table[]` — maps 68k PC → `Block*` |
| `runtime/rangetree.c` | Range tree — `destroy_blocks()` uses this to find all blocks overlapping a write |
| `runtime/block.c` / `runtime/blockinfo.c` | Block allocation and metadata |
| `runtime/deathqueue.c` | GC queue for invalidated blocks |
| `runtime/destroyblock.c` | Actually frees a block |
| `runtime/checksum.c` | CRC over 68k bytes backing a block (stale-cache detection) |
| `runtime/backpatch.c` | Resolves forward branch targets after a block is fully compiled |
| `runtime/recompile.c` | Triggers recompilation when code is overwritten |

### For Executor integration work

| File | Contents |
|---|---|
| `runtime/callback.c` | `callback_install()` / `callback_remove()` — maps a "magic" 68k address to a host C function |
| `runtime/trap.c` | A-trap handler table; `trap_install_handler()` stores func+arg in `cpu_state.trap_handler_info[]` |
| `runtime/interrupt.c` | Synchronous interrupt polling (`SYNCHRONOUS_INTERRUPTS` path) |
| `runtime/init.c` | `initialize_68k_emulator()` — canonical startup; also defines `cpu_state` and `ROMlib_offset` |

## Key data structures

### `Block` (`runtime/include/block.h`)

A compiled basic block. Key fields:
- `m68k_start_address` / `m68k_code_length` — the 68k address range this block covers
- `checksum` — CRC of the backing 68k bytes
- `immortal` — if true, never added to death queue (used for magic blocks)
- `child[]` — linked-list pointer (reused as freelist next when block is free)
- The synthetic opcodes or native x86 bytes follow immediately after the struct in memory

### `OpcodeMappingInfo` (`include/syn68k_private.h.in`)

A packed 32-bit struct describing one 68k opcode variant:
- CC bits it may read/write (`cc_needed`, `cc_may_set`, `cc_may_not_set`) — used for CC liveness optimization
- `ends_block` / `next_block_dynamic` — control flow flags
- `instruction_words` — how many 16-bit words the 68k instruction occupies
- `bitfield[]` — describes how to extract and byte-swap operand fields from the instruction word
- `opcode_shift_count` / `opcode_and_bits` / `opcode_add_bits` — maps the 68k opcode bits to the synthetic opcode index

### `CPUState` (`include/syn68k_public.h`)

Global `cpu_state`. All register access goes through `EM_D0`–`EM_D7` / `EM_A0`–`EM_A7` macros or `cpu_state.regs[n].ul.n` directly. Never read `.uw.n` on `a0`–`a7` unless you specifically want the low 16 bits.

### `TrapHandlerInfo` (`include/syn68k_public.h`)

One per trap (64 total in `cpu_state.trap_handler_info[]`):
```c
syn68k_addr_t callback_address;  // magic 68k addr where the callback "lives"
callback_handler_t func;         // NULL = no handler (unimplemented trap → RTE)
void *arg;                       // passed to func
```

`trap_init()` populates `trap_vector_array` (the 68k exception vector table) with one callback address per trap. When 68k code executes an A-trap, the callback fires `trap_forwarded()`, which dispatches to `func` if non-NULL.

## Naming and coding conventions

- `uint8/16/32/64`, `int8/16/32/64` — use these, not `short`/`int`/`long` (defined in `syn68k_public.h` as aliases for `stdint.h` types)
- `BOOL` with `TRUE`/`FALSE`/`YES`/`NO` — the internal boolean type (pre-C99 era)
- Functions are lowercase with underscores. Module-internal helpers are `static`.
- Macros that expand to statements use `do { ... } while (0)` or GNU statement-expressions `({ ... })`. The latter are guarded by `#if defined(__GNUC__)`.
- Interrupt-safe code uses `BLOCK_INTERRUPTS(save)` / `RESTORE_INTERRUPTS(save)` — never sigblock/sigsetmask directly.
- All 68k address arguments are `syn68k_addr_t` (a `uint32`), never a raw pointer.

## Build system

autoconf/automake. Subdirectories: `syngen/` → `runtime/` → `test/` → `profile/`.

`syngen` is built first and run as part of the `runtime/` build to generate `syn68k.c`, `mapinfo.c`, `mapindex.c`. If syngen changes, all three generated files are stale.

```bash
./autogen.sh        # regenerates configure from configure.ac
./configure         # standard options; --prefix= to install elsewhere
make                # builds syngen, runs it, builds runtime, test
make install
```

For the arm64/interpreter-only build (no JIT):
```bash
./configure --build=aarch64-apple-darwin    # GENERATE_NATIVE_CODE not defined
```

The `config/` directory contains legacy per-platform `Makefile.common.*` fragments from before autotools; ignore them.

## Testing

```bash
cd test
./syngentest [options]
diff output/<N> test/output/<N>   # compare against golden output
```

`test/maketestbattery.pl` generates additional test vectors. `test/testall.sh` runs the full suite. Test files:
- `tests.c` — instruction-level tests
- `testrt.c` — runtime/block-cache tests
- `testqsort.c` — sorting benchmark (exercises many instructions in sequence)
- `testtrap.c` — A-trap callback tests
- `callemulator.s` / `run68k.s` — x86 asm shims to enter/exit the emulator in tests

## Common tasks

### Adding or fixing a 68k instruction

1. Find the instruction in `runtime/68k.scm` (search by mnemonic, e.g. `defopcode MOVE`).
2. Edit the DSL. The DSL is Scheme-like: `(assign dst src)`, `(call fn args...)`, `(if cond then else)`.
3. `make` in `runtime/` regenerates `syn68k.c` and recompiles.
4. Run `test/syngentest` and diff against golden output.

### Debugging a crash in translated code

On x86 with JIT: `cpu_state.regs` and the stack (`EM_SP`) hold the 68k context at the crash point. The native PC is inside the JIT buffer — use `m68kaddr(pc)` (declared in `syn68k_public.h`) to map it back to a 68k address.

On non-x86 (interpreter): the interpreter loop is in `runtime/syn68k.c` (generated). The synthetic PC advances one opcode at a time; add `fprintf` tracing to the interpreter loop or use `diagnostics.c` helpers.

### Extending the public API

All public symbols must be declared in `include/syn68k_public.h`. Internal headers live in `runtime/include/`. Do not include `runtime/include/` headers from outside `runtime/`.

### Porting to a new architecture

1. Add endianness and `QUADALIGN` detection for the new CPU to `syn68k_public.h`.
2. Add `SIZEOF_CHAR_P` detection if needed.
3. The interpreter (`native/null`) requires no other changes.
4. For a new JIT backend, add `runtime/native/<arch>/` with `host-native.h` and `host-xlate.h` (see `native/null/` for the stub versions) and a `Makefile.am` entry.

## Claude Code settings (`.claude/settings.json`)

`.claude/settings.json` allowlists common build/search/test commands to reduce permission prompts. If you add new commands to the allowlist, document them here too.

Current allowlist covers:

| Category | Commands |
|---|---|
| Build | `make`, `make install`, `./autogen.sh`, `./configure` |
| Search | `rg`, `fd`, `grep`, `find` |
| Read | `wc`, `ls`, `cat`, `head`, `tail`, `diff` |
| Test | `test/syngentest`, `test/testall.sh` |
| Compiler queries | `gcc --version`, `clang --version`, `uname` |

To add a command: edit `.claude/settings.json` and add an entry to the `allowedTools` bash list, then update the table above.

## What to avoid

- **Editing generated files** (`syn68k.c`, `mapinfo.c`, `mapindex.c`) — changes are silently overwritten.
- **Bare pointer derefs into 68k memory** — always use `READUB/UW/UL` or `SYN68K_TO_US`.
- **Storing native pointers as 68k values** — 68k addresses are always 32-bit `syn68k_addr_t`; `US_TO_SYN68K` truncates to 32 bits.
- **Comparing `ccnz` to 0 to test whether Z is set** — `ccnz == 0` means Z=1 (zero result). If you write `if (cpu_state.ccnz)` you are testing Z=0 (non-zero result).
- **Assuming `GENERATE_NATIVE_CODE` is defined** — all JIT-specific code must be inside `#ifdef GENERATE_NATIVE_CODE`. The interpreter path must work standalone.
- **Calling `destroy_blocks()` while `emulation_depth > 0`** — recompilation while nested causes use-after-free of blocks on the call stack. `recompile.c` defers this via `emulation_depth`.
