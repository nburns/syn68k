#include "syn68k_public.h"
#include "testbattery.h"

extern void unpk_reg (uint16 *);
extern void unpk_mem (uint16 *);
extern void unlk (uint16 *);
extern void movewl_ind_ind (uint16 *);
extern void divsl_ll_reg (uint16 *);
extern void divsl_ll_ind (uint16 *);
extern void divsl_ll_absl (uint16 *);
extern void lea_pc_ind_preix (uint16 *);
extern void lea_pc_ind_postix (uint16 *);
extern void moveb_pc_ind_preix_dreg (uint16 *);
extern void moveb_pc_ind_postix_dreg (uint16 *);
extern void moveb_pcd16_dreg (uint16 *);
extern void movewl_pcd16_dreg (uint16 *);
extern void moveb_pcd8_dreg (uint16 *);
extern void movewl_pcd8_dreg (uint16 *);
extern void moveb_pc_ind_ix_dreg (uint16 *);
extern void movewl_pc_ind_ix_dreg (uint16 *);
extern void lea_ind_preix (uint16 *);
extern void lea_ind_postix (uint16 *);
extern void add_absl_dreg (uint16 *);
extern void abcd_reg (uint16 *);
extern void abcd_mem (uint16 *);
extern void addb_dreg_dreg (uint16 *);
extern void addw_reg_dreg (uint16 *);
extern void addl_reg_dreg (uint16 *);
extern void add_d16_dreg (uint16 *);
extern void addb_const_dreg (uint16 *);
extern void addw_const_dreg (uint16 *);
extern void add_dreg_ind (uint16 *);
extern void add_ind_dreg (uint16 *);
extern void addl_const_dreg (uint16 *);
extern void add_dreg_d16 (uint16 *);
extern void add_dreg_absl (uint16 *);
extern void addaw_reg_areg (uint16 *);
extern void addal_reg_areg (uint16 *);
extern void adda_ind_areg (uint16 *);
extern void adda_d16_areg (uint16 *);
extern void adda_absl_areg (uint16 *);
extern void addaw_const_areg (uint16 *);
extern void addal_const_areg (uint16 *);
extern void addibw_dreg (uint16 *);
extern void addil_dreg (uint16 *);
extern void addibw_ind (uint16 *);
extern void addil_ind (uint16 *);
extern void addibw_d16 (uint16 *);
extern void addil_d16 (uint16 *);
extern void addibw_absl (uint16 *);
extern void addil_absl (uint16 *);
extern void addq_dreg (uint16 *);
extern void addq_areg (uint16 *);
extern void addq_ind (uint16 *);
extern void addq_d16 (uint16 *);
extern void addq_absl (uint16 *);
extern void addx_reg (uint16 *);
extern void addx_mem (uint16 *);
extern void and_dreg_dreg (uint16 *);
extern void and_ind_dreg (uint16 *);
extern void and_d16_dreg (uint16 *);
extern void and_absl_dreg (uint16 *);
extern void andbw_const_dreg (uint16 *);
extern void andl_const_dreg (uint16 *);
extern void and_dreg_ind (uint16 *);
extern void and_dreg_d16 (uint16 *);
extern void and_dreg_absl (uint16 *);
extern void andibw_dreg (uint16 *);
extern void andil_dreg (uint16 *);
extern void andibw_ind (uint16 *);
extern void andil_ind (uint16 *);
extern void andibw_d16 (uint16 *);
extern void andil_d16 (uint16 *);
extern void andibw_absl (uint16 *);
extern void andil_absl (uint16 *);
extern void andi_to_ccr (uint16 *);
extern void asl_dx_dy (uint16 *);
extern void asl_const_dy (uint16 *);
extern void asl_ind (uint16 *);
extern void asl_d16 (uint16 *);
extern void asl_absl (uint16 *);
extern void asr_dx_dy (uint16 *);
extern void asr_const_dy (uint16 *);
extern void asr_ind (uint16 *);
extern void asr_d16 (uint16 *);
extern void asr_absl (uint16 *);
extern void lsl_dx_dy (uint16 *);
extern void lsl_const_dy (uint16 *);
extern void lsl_ind (uint16 *);
extern void lsl_d16 (uint16 *);
extern void lsl_absl (uint16 *);
extern void lsr_dx_dy (uint16 *);
extern void lsr_const_dy (uint16 *);
extern void lsr_ind (uint16 *);
extern void lsr_d16 (uint16 *);
extern void lsr_absl (uint16 *);
extern void bra_b (uint16 *);
extern void bhi_b (uint16 *);
extern void bls_b (uint16 *);
extern void bcc_b (uint16 *);
extern void bcs_b (uint16 *);
extern void bne_b (uint16 *);
extern void beq_b (uint16 *);
extern void bvc_b (uint16 *);
extern void bvs_b (uint16 *);
extern void bpl_b (uint16 *);
extern void bmi_b (uint16 *);
extern void bge_b (uint16 *);
extern void blt_b (uint16 *);
extern void bgt_b (uint16 *);
extern void ble_b (uint16 *);
extern void bra_w (uint16 *);
extern void bhi_w (uint16 *);
extern void bls_w (uint16 *);
extern void bcc_w (uint16 *);
extern void bcs_w (uint16 *);
extern void bne_w (uint16 *);
extern void beq_w (uint16 *);
extern void bvc_w (uint16 *);
extern void bvs_w (uint16 *);
extern void bpl_w (uint16 *);
extern void bmi_w (uint16 *);
extern void bge_w (uint16 *);
extern void blt_w (uint16 *);
extern void bgt_w (uint16 *);
extern void ble_w (uint16 *);
extern void bra_l (uint16 *);
extern void bhi_l (uint16 *);
extern void bls_l (uint16 *);
extern void bcc_l (uint16 *);
extern void bcs_l (uint16 *);
extern void bne_l (uint16 *);
extern void beq_l (uint16 *);
extern void bvc_l (uint16 *);
extern void bvs_l (uint16 *);
extern void bpl_l (uint16 *);
extern void bmi_l (uint16 *);
extern void bge_l (uint16 *);
extern void blt_l (uint16 *);
extern void bgt_l (uint16 *);
extern void ble_l (uint16 *);
extern void bchg_reg_reg (uint16 *);
extern void bchg_const_reg (uint16 *);
extern void bchg_reg_ind (uint16 *);
extern void bchg_const_ind (uint16 *);
extern void bchg_reg_d16 (uint16 *);
extern void bchg_const_d16 (uint16 *);
extern void bchg_reg_absl (uint16 *);
extern void bchg_const_absl (uint16 *);
extern void bclr_reg_reg (uint16 *);
extern void bclr_const_reg (uint16 *);
extern void bclr_reg_ind (uint16 *);
extern void bclr_const_ind (uint16 *);
extern void bclr_reg_d16 (uint16 *);
extern void bclr_const_d16 (uint16 *);
extern void bclr_reg_absl (uint16 *);
extern void bclr_const_absl (uint16 *);
extern void bset_reg_reg (uint16 *);
extern void bset_const_reg (uint16 *);
extern void bset_reg_ind (uint16 *);
extern void bset_const_ind (uint16 *);
extern void bset_reg_d16 (uint16 *);
extern void bset_const_d16 (uint16 *);
extern void bset_reg_absl (uint16 *);
extern void bset_const_absl (uint16 *);
extern void btst_reg_reg (uint16 *);
extern void btst_const_reg (uint16 *);
extern void btst_reg_ind (uint16 *);
extern void btst_const_ind (uint16 *);
extern void btst_reg_d16 (uint16 *);
extern void btst_const_d16 (uint16 *);
extern void btst_reg_absl (uint16 *);
extern void btst_const_absl (uint16 *);
extern void bfchg_reg (uint16 *);
extern void bfchg_ind (uint16 *);
extern void bfchg_d16 (uint16 *);
extern void bfchg_absl (uint16 *);
extern void bfclr_reg (uint16 *);
extern void bfclr_ind (uint16 *);
extern void bfclr_d16 (uint16 *);
extern void bfclr_absl (uint16 *);
extern void bfset_reg (uint16 *);
extern void bfset_ind (uint16 *);
extern void bfset_d16 (uint16 *);
extern void bfset_absl (uint16 *);
extern void bftst_reg (uint16 *);
extern void bftst_ind (uint16 *);
extern void bftst_d16 (uint16 *);
extern void bftst_absl (uint16 *);
extern void bfexts_reg (uint16 *);
extern void bfexts_ind (uint16 *);
extern void bfexts_d16 (uint16 *);
extern void bfexts_absl (uint16 *);
extern void bfextu_reg (uint16 *);
extern void bfextu_ind (uint16 *);
extern void bfextu_d16 (uint16 *);
extern void bfextu_absl (uint16 *);
extern void bfffo_reg (uint16 *);
extern void bfffo_ind (uint16 *);
extern void bfffo_d16 (uint16 *);
extern void bfffo_absl (uint16 *);
extern void bfins_reg (uint16 *);
extern void bfins_ind (uint16 *);
extern void bfins_d16 (uint16 *);
extern void bfins_absl (uint16 *);
extern void bsr_b (uint16 *);
extern void bsr_w (uint16 *);
extern void bsr_l (uint16 *);
extern void cas_ind (uint16 *);
extern void cas2_areg (uint16 *);
extern void cas2_anyreg (uint16 *);
extern void clr_reg (uint16 *);
extern void clrb_ind (uint16 *);
extern void clrwl_ind (uint16 *);
extern void clrb_absl (uint16 *);
extern void clrwl_absl (uint16 *);
extern void cmp_dreg (uint16 *);
extern void cmp_areg (uint16 *);
extern void cmpb_ind (uint16 *);
extern void cmpwl_ind (uint16 *);
extern void cmpb_d16 (uint16 *);
extern void cmpwl_d16 (uint16 *);
extern void cmpa_reg (uint16 *);
extern void cmpa_ind (uint16 *);
extern void cmpa_ind2 (uint16 *);
extern void cmpa_d16 (uint16 *);
extern void cmpa_d16_2 (uint16 *);
extern void cmpa_absl (uint16 *);
extern void cmpibw_reg (uint16 *);
extern void cmpil_reg (uint16 *);
extern void cmpib_ind (uint16 *);
extern void cmpiw_ind (uint16 *);
extern void cmpil_ind (uint16 *);
extern void cmpmb (uint16 *);
extern void cmpmwl (uint16 *);
extern void cmp2b_ind (uint16 *);
extern void cmp2wl_ind (uint16 *);
extern void dbcc (uint16 *);
extern void divs_reg (uint16 *);
extern void divs_same_reg (uint16 *);
extern void divs_ind (uint16 *);
extern void divs_absl (uint16 *);
extern void divu_reg (uint16 *);
extern void divu_same_reg (uint16 *);
extern void divu_ind (uint16 *);
extern void divu_absl (uint16 *);
extern void divul_ll_reg (uint16 *);
extern void divul_ll_ind (uint16 *);
extern void divul_ll_absl (uint16 *);
extern void eor_reg (uint16 *);
extern void eor_ind (uint16 *);
extern void eor_d16 (uint16 *);
extern void eor_absl (uint16 *);
extern void eoribw_dreg (uint16 *);
extern void eoril_dreg (uint16 *);
extern void eoribw_ind (uint16 *);
extern void eoril_ind (uint16 *);
extern void eoribw_d16 (uint16 *);
extern void eoril_d16 (uint16 *);
extern void eoribw_absl (uint16 *);
extern void eoril_absl (uint16 *);
extern void eori_to_ccr (uint16 *);
extern void exg (uint16 *);
extern void ext (uint16 *);
extern void jmp_absl (uint16 *);
extern void jmp_ind (uint16 *);
extern void jmp_d16 (uint16 *);
extern void jsr_absl (uint16 *);
extern void jsr_ind (uint16 *);
extern void jsr_d16 (uint16 *);
extern void lea_ind (uint16 *);
extern void lea_d16 (uint16 *);
extern void lea_absw (uint16 *);
extern void lea_absl (uint16 *);
extern void linkw (uint16 *);
extern void linkl (uint16 *);
extern void move16_postinc_postinc (uint16 *);
extern void move16_absl_ind (uint16 *);
extern void move16_absl_postinc (uint16 *);
extern void move16_ind_absl (uint16 *);
extern void move16_postinc_absl (uint16 *);
extern void moveb_dreg_dreg (uint16 *);
extern void movewl_reg_dreg (uint16 *);
extern void moveb_ind_dreg (uint16 *);
extern void movewl_ind_dreg (uint16 *);
extern void moveb_d16_dreg (uint16 *);
extern void movewl_d16_dreg (uint16 *);
extern void moveb_absl_dreg (uint16 *);
extern void movewl_absl_dreg (uint16 *);
extern void movebw_const_dreg (uint16 *);
extern void movel_const_dreg (uint16 *);
extern void moveb_dreg_ind (uint16 *);
extern void movewl_reg_ind (uint16 *);
extern void moveb_dreg_d16 (uint16 *);
extern void movewl_reg_d16 (uint16 *);
extern void moveb_dreg_absl (uint16 *);
extern void movewl_reg_absl (uint16 *);
extern void moveb_ind_ind (uint16 *);
extern void moveb_ind_d16 (uint16 *);
extern void moveb_d16_ind (uint16 *);
extern void movewl_ind_d16 (uint16 *);
extern void movewl_d16_ind (uint16 *);
extern void moveb_d16_d16 (uint16 *);
extern void movewl_d16_d16 (uint16 *);
extern void moveb_ind_absl (uint16 *);
extern void movewl_ind_absl (uint16 *);
extern void moveb_absl_ind (uint16 *);
extern void movewl_absl_ind (uint16 *);
extern void moveb_absl_absl (uint16 *);
extern void movewl_absl_absl (uint16 *);
extern void moveb_d16_absl (uint16 *);
extern void movewl_d16_absl (uint16 *);
extern void moveb_absl_d16 (uint16 *);
extern void movewl_absl_d16 (uint16 *);
extern void moveb_const_ind (uint16 *);
extern void moveb_const_d16 (uint16 *);
extern void moveb_const_absl (uint16 *);
extern void movew_const_ind (uint16 *);
extern void movew_const_d16 (uint16 *);
extern void movew_const_absl (uint16 *);
extern void movel_const_ind (uint16 *);
extern void movel_const_d16 (uint16 *);
extern void movel_const_absl (uint16 *);
extern void movea_reg (uint16 *);
extern void movea_ind (uint16 *);
extern void movea_d16 (uint16 *);
extern void movea_absl (uint16 *);
extern void moveaw_const (uint16 *);
extern void moveal_const (uint16 *);
extern void move_from_ccr_dreg (uint16 *);
extern void move_from_ccr_ind (uint16 *);
extern void move_from_ccr_d16 (uint16 *);
extern void move_to_ccr_reg (uint16 *);
extern void move_to_ccr_ind (uint16 *);
extern void movem_to_ind (uint16 *);
extern void movem_to_predec (uint16 *);
extern void movem_to_d16 (uint16 *);
extern void movem_to_absl (uint16 *);
extern void movem_from_d16 (uint16 *);
extern void movem_from_ind (uint16 *);
extern void movem_from_absl (uint16 *);
extern void movep_to_mem (uint16 *);
extern void movep_from_mem (uint16 *);
extern void moveq (uint16 *);
extern void mulsw_dreg (uint16 *);
extern void mulsw_ind (uint16 *);
extern void mulsw_d16 (uint16 *);
extern void mulsw_absl (uint16 *);
extern void muluw_dreg (uint16 *);
extern void muluw_ind (uint16 *);
extern void muluw_d16 (uint16 *);
extern void muluw_absl (uint16 *);
extern void mulsl_dreg (uint16 *);
extern void mulsl_ind (uint16 *);
extern void mulsl_d16 (uint16 *);
extern void mulsl_absl (uint16 *);
extern void mulul_dreg (uint16 *);
extern void mulul_ind (uint16 *);
extern void mulul_d16 (uint16 *);
extern void mulul_absl (uint16 *);
extern void nbcd_reg (uint16 *);
extern void nbcd_ind (uint16 *);
extern void nbcd_d16 (uint16 *);
extern void nbcd_absl (uint16 *);
extern void neg_reg (uint16 *);
extern void negb_ind (uint16 *);
extern void negwl_ind (uint16 *);
extern void negb_d16 (uint16 *);
extern void negwl_d16 (uint16 *);
extern void neg_absl (uint16 *);
extern void negx_reg (uint16 *);
extern void negxb_ind (uint16 *);
extern void negxwl_ind (uint16 *);
extern void negxb_d16 (uint16 *);
extern void negxwl_d16 (uint16 *);
extern void negx_absl (uint16 *);
extern void nop (uint16 *);
extern void not_reg (uint16 *);
extern void notb_ind (uint16 *);
extern void notwl_ind (uint16 *);
extern void notb_d16 (uint16 *);
extern void notwl_d16 (uint16 *);
extern void not_absl (uint16 *);
extern void or_dreg_dreg (uint16 *);
extern void or_ind_dreg (uint16 *);
extern void or_d16_dreg (uint16 *);
extern void or_absl_dreg (uint16 *);
extern void orbw_const_dreg (uint16 *);
extern void orl_const_dreg (uint16 *);
extern void or_dreg_ind (uint16 *);
extern void or_dreg_d16 (uint16 *);
extern void or_dreg_absl (uint16 *);
extern void oribw_dreg (uint16 *);
extern void oril_dreg (uint16 *);
extern void oribw_ind (uint16 *);
extern void oril_ind (uint16 *);
extern void oribw_d16 (uint16 *);
extern void oril_d16 (uint16 *);
extern void oribw_absl (uint16 *);
extern void oril_absl (uint16 *);
extern void ori_to_ccr (uint16 *);
extern void pack_reg (uint16 *);
extern void pack_mem (uint16 *);
extern void pea_ind (uint16 *);
extern void pea_d16 (uint16 *);
extern void pea_absw (uint16 *);
extern void pea_absl (uint16 *);
extern void rol_dx_dy (uint16 *);
extern void rol_const_dy (uint16 *);
extern void rol_ind (uint16 *);
extern void rol_d16 (uint16 *);
extern void rol_absl (uint16 *);
extern void ror_dx_dy (uint16 *);
extern void ror_const_dy (uint16 *);
extern void ror_ind (uint16 *);
extern void ror_d16 (uint16 *);
extern void ror_absl (uint16 *);
extern void roxl_dx_dy (uint16 *);
extern void roxl_const_dy (uint16 *);
extern void roxl_ind (uint16 *);
extern void roxl_d16 (uint16 *);
extern void roxl_absl (uint16 *);
extern void roxr_dx_dy (uint16 *);
extern void roxr_const_dy (uint16 *);
extern void roxr_ind (uint16 *);
extern void roxr_d16 (uint16 *);
extern void roxr_absl (uint16 *);
extern void rtd (uint16 *);
extern void rtr (uint16 *);
extern void rts (uint16 *);
extern void sbcd_reg (uint16 *);
extern void sbcd_mem (uint16 *);
extern void Scc_reg (uint16 *);
extern void Scc_ind (uint16 *);
extern void Scc_d16 (uint16 *);
extern void Scc_absl (uint16 *);
extern void subb_dreg_dreg (uint16 *);
extern void subw_reg_dreg (uint16 *);
extern void subl_reg_dreg (uint16 *);
extern void sub_ind_dreg (uint16 *);
extern void sub_d16_dreg (uint16 *);
extern void sub_absl_dreg (uint16 *);
extern void subb_const_dreg (uint16 *);
extern void subw_const_dreg (uint16 *);
extern void subl_const_dreg (uint16 *);
extern void sub_dreg_ind (uint16 *);
extern void sub_dreg_d16 (uint16 *);
extern void sub_dreg_absl (uint16 *);
extern void subaw_reg_areg (uint16 *);
extern void subal_reg_areg (uint16 *);
extern void suba_ind_areg (uint16 *);
extern void suba_d16_areg (uint16 *);
extern void suba_absl_areg (uint16 *);
extern void subaw_const_areg (uint16 *);
extern void subal_const_areg (uint16 *);
extern void subibw_dreg (uint16 *);
extern void subil_dreg (uint16 *);
extern void subibw_ind (uint16 *);
extern void subil_ind (uint16 *);
extern void subibw_d16 (uint16 *);
extern void subil_d16 (uint16 *);
extern void subibw_absl (uint16 *);
extern void subil_absl (uint16 *);
extern void subq_dreg (uint16 *);
extern void subq_areg (uint16 *);
extern void subq_ind (uint16 *);
extern void subq_d16 (uint16 *);
extern void subq_absl (uint16 *);
extern void subx_reg (uint16 *);
extern void subx_mem (uint16 *);
extern void swap (uint16 *);
extern void tas_dreg (uint16 *);
extern void tas_ind (uint16 *);
extern void tas_d16 (uint16 *);
extern void tas_absl (uint16 *);
extern void tstb_dreg (uint16 *);
extern void tstwl_reg (uint16 *);
extern void tstb_ind (uint16 *);
extern void tstwl_ind (uint16 *);
extern void tstb_d16 (uint16 *);
extern void tstwl_d16 (uint16 *);
extern void tst_absl (uint16 *);

const TestInfo test_info[] = {
  { "unpk_reg", unpk_reg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "unpk_mem", unpk_mem, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "unlk", unlk, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_ind_ind", movewl_ind_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "divsl_ll_reg", divsl_ll_reg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "divsl_ll_ind", divsl_ll_ind, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "divsl_ll_absl", divsl_ll_absl, ALL_CCS, 4, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "lea_pc_ind_preix", lea_pc_ind_preix, ALL_CCS, 50, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "lea_pc_ind_postix", lea_pc_ind_postix, ALL_CCS, 50, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_pc_ind_preix_dreg", moveb_pc_ind_preix_dreg, ALL_CCS, 50, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_pc_ind_postix_dreg", moveb_pc_ind_postix_dreg, ALL_CCS, 50, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_pcd16_dreg", moveb_pcd16_dreg, ALL_CCS, 6, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_pcd16_dreg", movewl_pcd16_dreg, ALL_CCS, 6, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_pcd8_dreg", moveb_pcd8_dreg, ALL_CCS, 40, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_pcd8_dreg", movewl_pcd8_dreg, ALL_CCS, 40, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_pc_ind_ix_dreg", moveb_pc_ind_ix_dreg, ALL_CCS, 40, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_pc_ind_ix_dreg", movewl_pc_ind_ix_dreg, ALL_CCS, 40, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "lea_ind_preix", lea_ind_preix, ALL_CCS, 50, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "lea_ind_postix", lea_ind_postix, ALL_CCS, 50, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "add_absl_dreg", add_absl_dreg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "abcd_reg", abcd_reg, C_BIT | Z_BIT | X_BIT, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "abcd_mem", abcd_mem, C_BIT | Z_BIT | X_BIT, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "addb_dreg_dreg", addb_dreg_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "addw_reg_dreg", addw_reg_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "addl_reg_dreg", addl_reg_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "add_d16_dreg", add_d16_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "addb_const_dreg", addb_const_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "addw_const_dreg", addw_const_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "add_dreg_ind", add_dreg_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "add_ind_dreg", add_ind_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "addl_const_dreg", addl_const_dreg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "add_dreg_d16", add_dreg_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "add_dreg_absl", add_dreg_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "addaw_reg_areg", addaw_reg_areg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "addal_reg_areg", addal_reg_areg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "adda_ind_areg", adda_ind_areg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "adda_d16_areg", adda_d16_areg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "adda_absl_areg", adda_absl_areg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "addaw_const_areg", addaw_const_areg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "addal_const_areg", addal_const_areg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "addibw_dreg", addibw_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "addil_dreg", addil_dreg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "addibw_ind", addibw_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "addil_ind", addil_ind, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "addibw_d16", addibw_d16, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "addil_d16", addil_d16, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "addibw_absl", addibw_absl, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "addil_absl", addil_absl, ALL_CCS, 5, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "addq_dreg", addq_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "addq_areg", addq_areg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "addq_ind", addq_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "addq_d16", addq_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "addq_absl", addq_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "addx_reg", addx_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "addx_mem", addx_mem, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "and_dreg_dreg", and_dreg_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "and_ind_dreg", and_ind_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "and_d16_dreg", and_d16_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "and_absl_dreg", and_absl_dreg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "andbw_const_dreg", andbw_const_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "andl_const_dreg", andl_const_dreg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "and_dreg_ind", and_dreg_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "and_dreg_d16", and_dreg_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "and_dreg_absl", and_dreg_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "andibw_dreg", andibw_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "andil_dreg", andil_dreg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "andibw_ind", andibw_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "andil_ind", andil_ind, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "andibw_d16", andibw_d16, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "andil_d16", andil_d16, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "andibw_absl", andibw_absl, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "andil_absl", andil_absl, ALL_CCS, 5, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "andi_to_ccr", andi_to_ccr, ALL_CCS, 2, WONT_CHANGE_MEMORY, 32 },
  { "asl_dx_dy", asl_dx_dy, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "asl_const_dy", asl_const_dy, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "asl_ind", asl_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "asl_d16", asl_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "asl_absl", asl_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "asr_dx_dy", asr_dx_dy, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "asr_const_dy", asr_const_dy, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "asr_ind", asr_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "asr_d16", asr_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "asr_absl", asr_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "lsl_dx_dy", lsl_dx_dy, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "lsl_const_dy", lsl_const_dy, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "lsl_ind", lsl_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "lsl_d16", lsl_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "lsl_absl", lsl_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "lsr_dx_dy", lsr_dx_dy, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "lsr_const_dy", lsr_const_dy, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "lsr_ind", lsr_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "lsr_d16", lsr_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "lsr_absl", lsr_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bra_b", bra_b, ALL_CCS, 5, WONT_CHANGE_MEMORY, 2 },
  { "bhi_b", bhi_b, ALL_CCS, 5, WONT_CHANGE_MEMORY, 2 },
  { "bls_b", bls_b, ALL_CCS, 5, WONT_CHANGE_MEMORY, 2 },
  { "bcc_b", bcc_b, ALL_CCS, 5, WONT_CHANGE_MEMORY, 2 },
  { "bcs_b", bcs_b, ALL_CCS, 5, WONT_CHANGE_MEMORY, 2 },
  { "bne_b", bne_b, ALL_CCS, 5, WONT_CHANGE_MEMORY, 2 },
  { "beq_b", beq_b, ALL_CCS, 5, WONT_CHANGE_MEMORY, 2 },
  { "bvc_b", bvc_b, ALL_CCS, 5, WONT_CHANGE_MEMORY, 2 },
  { "bvs_b", bvs_b, ALL_CCS, 5, WONT_CHANGE_MEMORY, 2 },
  { "bpl_b", bpl_b, ALL_CCS, 5, WONT_CHANGE_MEMORY, 2 },
  { "bmi_b", bmi_b, ALL_CCS, 5, WONT_CHANGE_MEMORY, 2 },
  { "bge_b", bge_b, ALL_CCS, 5, WONT_CHANGE_MEMORY, 2 },
  { "blt_b", blt_b, ALL_CCS, 5, WONT_CHANGE_MEMORY, 2 },
  { "bgt_b", bgt_b, ALL_CCS, 5, WONT_CHANGE_MEMORY, 2 },
  { "ble_b", ble_b, ALL_CCS, 5, WONT_CHANGE_MEMORY, 2 },
  { "bra_w", bra_w, ALL_CCS, 6, WONT_CHANGE_MEMORY, 2 },
  { "bhi_w", bhi_w, ALL_CCS, 6, WONT_CHANGE_MEMORY, 2 },
  { "bls_w", bls_w, ALL_CCS, 6, WONT_CHANGE_MEMORY, 2 },
  { "bcc_w", bcc_w, ALL_CCS, 6, WONT_CHANGE_MEMORY, 2 },
  { "bcs_w", bcs_w, ALL_CCS, 6, WONT_CHANGE_MEMORY, 2 },
  { "bne_w", bne_w, ALL_CCS, 6, WONT_CHANGE_MEMORY, 2 },
  { "beq_w", beq_w, ALL_CCS, 6, WONT_CHANGE_MEMORY, 2 },
  { "bvc_w", bvc_w, ALL_CCS, 6, WONT_CHANGE_MEMORY, 2 },
  { "bvs_w", bvs_w, ALL_CCS, 6, WONT_CHANGE_MEMORY, 2 },
  { "bpl_w", bpl_w, ALL_CCS, 6, WONT_CHANGE_MEMORY, 2 },
  { "bmi_w", bmi_w, ALL_CCS, 6, WONT_CHANGE_MEMORY, 2 },
  { "bge_w", bge_w, ALL_CCS, 6, WONT_CHANGE_MEMORY, 2 },
  { "blt_w", blt_w, ALL_CCS, 6, WONT_CHANGE_MEMORY, 2 },
  { "bgt_w", bgt_w, ALL_CCS, 6, WONT_CHANGE_MEMORY, 2 },
  { "ble_w", ble_w, ALL_CCS, 6, WONT_CHANGE_MEMORY, 2 },
  { "bra_l", bra_l, ALL_CCS, 7, WONT_CHANGE_MEMORY, 2 },
  { "bhi_l", bhi_l, ALL_CCS, 7, WONT_CHANGE_MEMORY, 2 },
  { "bls_l", bls_l, ALL_CCS, 7, WONT_CHANGE_MEMORY, 2 },
  { "bcc_l", bcc_l, ALL_CCS, 7, WONT_CHANGE_MEMORY, 2 },
  { "bcs_l", bcs_l, ALL_CCS, 7, WONT_CHANGE_MEMORY, 2 },
  { "bne_l", bne_l, ALL_CCS, 7, WONT_CHANGE_MEMORY, 2 },
  { "beq_l", beq_l, ALL_CCS, 7, WONT_CHANGE_MEMORY, 2 },
  { "bvc_l", bvc_l, ALL_CCS, 7, WONT_CHANGE_MEMORY, 2 },
  { "bvs_l", bvs_l, ALL_CCS, 7, WONT_CHANGE_MEMORY, 2 },
  { "bpl_l", bpl_l, ALL_CCS, 7, WONT_CHANGE_MEMORY, 2 },
  { "bmi_l", bmi_l, ALL_CCS, 7, WONT_CHANGE_MEMORY, 2 },
  { "bge_l", bge_l, ALL_CCS, 7, WONT_CHANGE_MEMORY, 2 },
  { "blt_l", blt_l, ALL_CCS, 7, WONT_CHANGE_MEMORY, 2 },
  { "bgt_l", bgt_l, ALL_CCS, 7, WONT_CHANGE_MEMORY, 2 },
  { "ble_l", ble_l, ALL_CCS, 7, WONT_CHANGE_MEMORY, 2 },
  { "bchg_reg_reg", bchg_reg_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bchg_const_reg", bchg_const_reg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bchg_reg_ind", bchg_reg_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bchg_const_ind", bchg_const_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bchg_reg_d16", bchg_reg_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bchg_const_d16", bchg_const_d16, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bchg_reg_absl", bchg_reg_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bchg_const_absl", bchg_const_absl, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bclr_reg_reg", bclr_reg_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bclr_const_reg", bclr_const_reg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bclr_reg_ind", bclr_reg_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bclr_const_ind", bclr_const_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bclr_reg_d16", bclr_reg_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bclr_const_d16", bclr_const_d16, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bclr_reg_absl", bclr_reg_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bclr_const_absl", bclr_const_absl, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bset_reg_reg", bset_reg_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bset_const_reg", bset_const_reg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bset_reg_ind", bset_reg_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bset_const_ind", bset_const_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bset_reg_d16", bset_reg_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bset_const_d16", bset_const_d16, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bset_reg_absl", bset_reg_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bset_const_absl", bset_const_absl, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "btst_reg_reg", btst_reg_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "btst_const_reg", btst_const_reg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "btst_reg_ind", btst_reg_ind, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "btst_const_ind", btst_const_ind, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "btst_reg_d16", btst_reg_d16, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "btst_const_d16", btst_const_d16, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "btst_reg_absl", btst_reg_absl, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "btst_const_absl", btst_const_absl, ALL_CCS, 4, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfchg_reg", bfchg_reg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfchg_ind", bfchg_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bfchg_d16", bfchg_d16, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bfchg_absl", bfchg_absl, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bfclr_reg", bfclr_reg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfclr_ind", bfclr_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bfclr_d16", bfclr_d16, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bfclr_absl", bfclr_absl, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bfset_reg", bfset_reg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfset_ind", bfset_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bfset_d16", bfset_d16, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bfset_absl", bfset_absl, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bftst_reg", bftst_reg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bftst_ind", bftst_ind, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bftst_d16", bftst_d16, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bftst_absl", bftst_absl, ALL_CCS, 4, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfexts_reg", bfexts_reg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfexts_ind", bfexts_ind, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfexts_d16", bfexts_d16, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfexts_absl", bfexts_absl, ALL_CCS, 4, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfextu_reg", bfextu_reg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfextu_ind", bfextu_ind, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfextu_d16", bfextu_d16, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfextu_absl", bfextu_absl, ALL_CCS, 4, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfffo_reg", bfffo_reg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfffo_ind", bfffo_ind, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfffo_d16", bfffo_d16, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfffo_absl", bfffo_absl, ALL_CCS, 4, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfins_reg", bfins_reg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "bfins_ind", bfins_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bfins_d16", bfins_d16, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bfins_absl", bfins_absl, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bsr_b", bsr_b, ALL_CCS, 6, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bsr_w", bsr_w, ALL_CCS, 7, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "bsr_l", bsr_l, ALL_CCS, 8, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "cas_ind", cas_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "cas2_areg", cas2_areg, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "cas2_anyreg", cas2_anyreg, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "clr_reg", clr_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "clrb_ind", clrb_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "clrwl_ind", clrwl_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "clrb_absl", clrb_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "clrwl_absl", clrwl_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "cmp_dreg", cmp_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmp_areg", cmp_areg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmpb_ind", cmpb_ind, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmpwl_ind", cmpwl_ind, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmpb_d16", cmpb_d16, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmpwl_d16", cmpwl_d16, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmpa_reg", cmpa_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmpa_ind", cmpa_ind, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmpa_ind2", cmpa_ind2, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmpa_d16", cmpa_d16, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmpa_d16_2", cmpa_d16_2, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmpa_absl", cmpa_absl, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmpibw_reg", cmpibw_reg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmpil_reg", cmpil_reg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmpib_ind", cmpib_ind, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmpiw_ind", cmpiw_ind, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmpil_ind", cmpil_ind, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmpmb", cmpmb, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmpmwl", cmpmwl, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmp2b_ind", cmp2b_ind, X_BIT | Z_BIT | C_BIT, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "cmp2wl_ind", cmp2wl_ind, X_BIT | Z_BIT | C_BIT, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "dbcc", dbcc, ALL_CCS, 3, WONT_CHANGE_MEMORY, 16 },
  { "divs_reg", divs_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "divs_same_reg", divs_same_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "divs_ind", divs_ind, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "divs_absl", divs_absl, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "divu_reg", divu_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "divu_same_reg", divu_same_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "divu_ind", divu_ind, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "divu_absl", divu_absl, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "divul_ll_reg", divul_ll_reg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "divul_ll_ind", divul_ll_ind, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "divul_ll_absl", divul_ll_absl, ALL_CCS, 4, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "eor_reg", eor_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "eor_ind", eor_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "eor_d16", eor_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "eor_absl", eor_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "eoribw_dreg", eoribw_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "eoril_dreg", eoril_dreg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "eoribw_ind", eoribw_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "eoril_ind", eoril_ind, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "eoribw_d16", eoribw_d16, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "eoril_d16", eoril_d16, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "eoribw_absl", eoribw_absl, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "eoril_absl", eoril_absl, ALL_CCS, 5, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "eori_to_ccr", eori_to_ccr, ALL_CCS, 2, WONT_CHANGE_MEMORY, 32 },
  { "exg", exg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "ext", ext, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "jmp_absl", jmp_absl, ALL_CCS, 5, WONT_CHANGE_MEMORY, 2 },
  { "jmp_ind", jmp_ind, ALL_CCS, 3, WONT_CHANGE_MEMORY, 8 },
  { "jmp_d16", jmp_d16, ALL_CCS, 4, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "jsr_absl", jsr_absl, ALL_CCS, 7, MIGHT_CHANGE_MEMORY, 2 },
  { "jsr_ind", jsr_ind, ALL_CCS, 5, MIGHT_CHANGE_MEMORY, 8 },
  { "jsr_d16", jsr_d16, ALL_CCS, 6, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "lea_ind", lea_ind, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "lea_d16", lea_d16, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "lea_absw", lea_absw, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "lea_absl", lea_absl, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "linkw", linkw, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "linkl", linkl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "move16_postinc_postinc", move16_postinc_postinc, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "move16_absl_ind", move16_absl_ind, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "move16_absl_postinc", move16_absl_postinc, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "move16_ind_absl", move16_ind_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "move16_postinc_absl", move16_postinc_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_dreg_dreg", moveb_dreg_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_reg_dreg", movewl_reg_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_ind_dreg", moveb_ind_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_ind_dreg", movewl_ind_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_d16_dreg", moveb_d16_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_d16_dreg", movewl_d16_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_absl_dreg", moveb_absl_dreg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_absl_dreg", movewl_absl_dreg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "movebw_const_dreg", movebw_const_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "movel_const_dreg", movel_const_dreg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_dreg_ind", moveb_dreg_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_reg_ind", movewl_reg_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_dreg_d16", moveb_dreg_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_reg_d16", movewl_reg_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_dreg_absl", moveb_dreg_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_reg_absl", movewl_reg_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_ind_ind", moveb_ind_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_ind_d16", moveb_ind_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_d16_ind", moveb_d16_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_ind_d16", movewl_ind_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_d16_ind", movewl_d16_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_d16_d16", moveb_d16_d16, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_d16_d16", movewl_d16_d16, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_ind_absl", moveb_ind_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_ind_absl", movewl_ind_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_absl_ind", moveb_absl_ind, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_absl_ind", movewl_absl_ind, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_absl_absl", moveb_absl_absl, ALL_CCS, 5, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_absl_absl", movewl_absl_absl, ALL_CCS, 5, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_d16_absl", moveb_d16_absl, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_d16_absl", movewl_d16_absl, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_absl_d16", moveb_absl_d16, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movewl_absl_d16", movewl_absl_d16, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_const_ind", moveb_const_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_const_d16", moveb_const_d16, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "moveb_const_absl", moveb_const_absl, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movew_const_ind", movew_const_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movew_const_d16", movew_const_d16, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movew_const_absl", movew_const_absl, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movel_const_ind", movel_const_ind, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movel_const_d16", movel_const_d16, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movel_const_absl", movel_const_absl, ALL_CCS, 5, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movea_reg", movea_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "movea_ind", movea_ind, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "movea_d16", movea_d16, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "movea_absl", movea_absl, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "moveaw_const", moveaw_const, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "moveal_const", moveal_const, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "move_from_ccr_dreg", move_from_ccr_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "move_from_ccr_ind", move_from_ccr_ind, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "move_from_ccr_d16", move_from_ccr_d16, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "move_to_ccr_reg", move_to_ccr_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "move_to_ccr_ind", move_to_ccr_ind, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "movem_to_ind", movem_to_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movem_to_predec", movem_to_predec, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movem_to_d16", movem_to_d16, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movem_to_absl", movem_to_absl, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movem_from_d16", movem_from_d16, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "movem_from_ind", movem_from_ind, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "movem_from_absl", movem_from_absl, ALL_CCS, 4, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "movep_to_mem", movep_to_mem, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "movep_from_mem", movep_from_mem, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "moveq", moveq, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "mulsw_dreg", mulsw_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "mulsw_ind", mulsw_ind, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "mulsw_d16", mulsw_d16, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "mulsw_absl", mulsw_absl, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "muluw_dreg", muluw_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "muluw_ind", muluw_ind, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "muluw_d16", muluw_d16, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "muluw_absl", muluw_absl, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "mulsl_dreg", mulsl_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "mulsl_ind", mulsl_ind, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "mulsl_d16", mulsl_d16, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "mulsl_absl", mulsl_absl, ALL_CCS, 4, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "mulul_dreg", mulul_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "mulul_ind", mulul_ind, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "mulul_d16", mulul_d16, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "mulul_absl", mulul_absl, ALL_CCS, 4, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "nbcd_reg", nbcd_reg, X_BIT | Z_BIT | C_BIT, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "nbcd_ind", nbcd_ind, X_BIT | Z_BIT | C_BIT, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "nbcd_d16", nbcd_d16, X_BIT | Z_BIT | C_BIT, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "nbcd_absl", nbcd_absl, X_BIT | Z_BIT | C_BIT, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "neg_reg", neg_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "negb_ind", negb_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "negwl_ind", negwl_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "negb_d16", negb_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "negwl_d16", negwl_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "neg_absl", neg_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "negx_reg", negx_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "negxb_ind", negxb_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "negxwl_ind", negxwl_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "negxb_d16", negxb_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "negxwl_d16", negxwl_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "negx_absl", negx_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "nop", nop, ALL_CCS, 1, WONT_CHANGE_MEMORY, 1 },
  { "not_reg", not_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "notb_ind", notb_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "notwl_ind", notwl_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "notb_d16", notb_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "notwl_d16", notwl_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "not_absl", not_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "or_dreg_dreg", or_dreg_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "or_ind_dreg", or_ind_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "or_d16_dreg", or_d16_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "or_absl_dreg", or_absl_dreg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "orbw_const_dreg", orbw_const_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "orl_const_dreg", orl_const_dreg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "or_dreg_ind", or_dreg_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "or_dreg_d16", or_dreg_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "or_dreg_absl", or_dreg_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "oribw_dreg", oribw_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "oril_dreg", oril_dreg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "oribw_ind", oribw_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "oril_ind", oril_ind, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "oribw_d16", oribw_d16, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "oril_d16", oril_d16, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "oribw_absl", oribw_absl, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "oril_absl", oril_absl, ALL_CCS, 5, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "ori_to_ccr", ori_to_ccr, ALL_CCS, 2, WONT_CHANGE_MEMORY, 32 },
  { "pack_reg", pack_reg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "pack_mem", pack_mem, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "pea_ind", pea_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "pea_d16", pea_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "pea_absw", pea_absw, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "pea_absl", pea_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "rol_dx_dy", rol_dx_dy, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "rol_const_dy", rol_const_dy, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "rol_ind", rol_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "rol_d16", rol_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "rol_absl", rol_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "ror_dx_dy", ror_dx_dy, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "ror_const_dy", ror_const_dy, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "ror_ind", ror_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "ror_d16", ror_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "ror_absl", ror_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "roxl_dx_dy", roxl_dx_dy, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "roxl_const_dy", roxl_const_dy, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "roxl_ind", roxl_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "roxl_d16", roxl_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "roxl_absl", roxl_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "roxr_dx_dy", roxr_dx_dy, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "roxr_const_dy", roxr_const_dy, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "roxr_ind", roxr_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "roxr_d16", roxr_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "roxr_absl", roxr_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "rtd", rtd, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "rtr", rtr, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "rts", rts, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "sbcd_reg", sbcd_reg, X_BIT | Z_BIT | C_BIT, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "sbcd_mem", sbcd_mem, X_BIT | Z_BIT | C_BIT, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "Scc_reg", Scc_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "Scc_ind", Scc_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "Scc_d16", Scc_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "Scc_absl", Scc_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "subb_dreg_dreg", subb_dreg_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "subw_reg_dreg", subw_reg_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "subl_reg_dreg", subl_reg_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "sub_ind_dreg", sub_ind_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "sub_d16_dreg", sub_d16_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "sub_absl_dreg", sub_absl_dreg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "subb_const_dreg", subb_const_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "subw_const_dreg", subw_const_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "subl_const_dreg", subl_const_dreg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "sub_dreg_ind", sub_dreg_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "sub_dreg_d16", sub_dreg_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "sub_dreg_absl", sub_dreg_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "subaw_reg_areg", subaw_reg_areg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "subal_reg_areg", subal_reg_areg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "suba_ind_areg", suba_ind_areg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "suba_d16_areg", suba_d16_areg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "suba_absl_areg", suba_absl_areg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "subaw_const_areg", subaw_const_areg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "subal_const_areg", subal_const_areg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "subibw_dreg", subibw_dreg, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "subil_dreg", subil_dreg, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "subibw_ind", subibw_ind, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "subil_ind", subil_ind, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "subibw_d16", subibw_d16, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "subil_d16", subil_d16, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "subibw_absl", subibw_absl, ALL_CCS, 4, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "subil_absl", subil_absl, ALL_CCS, 5, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "subq_dreg", subq_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "subq_areg", subq_areg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "subq_ind", subq_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "subq_d16", subq_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "subq_absl", subq_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "subx_reg", subx_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "subx_mem", subx_mem, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "swap", swap, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "tas_dreg", tas_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "tas_ind", tas_ind, ALL_CCS, 1, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "tas_d16", tas_d16, ALL_CCS, 2, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "tas_absl", tas_absl, ALL_CCS, 3, MIGHT_CHANGE_MEMORY, NO_LIMIT },
  { "tstb_dreg", tstb_dreg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "tstwl_reg", tstwl_reg, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "tstb_ind", tstb_ind, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "tstwl_ind", tstwl_ind, ALL_CCS, 1, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "tstb_d16", tstb_d16, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "tstwl_d16", tstwl_d16, ALL_CCS, 2, WONT_CHANGE_MEMORY, NO_LIMIT },
  { "tst_absl", tst_absl, ALL_CCS, 3, WONT_CHANGE_MEMORY, NO_LIMIT },
  { 0, 0, 0, 0, 0, 0 }
};
