#include <stdint.h>
#include <string.h>

#define OK 0
#define ERROR_MB_ADDRESS_T -1
#define ERROR_MB_TYPE -2
#define P_SLICE 0
#define B_SLICE 1
#define CAB_P_SKIP 0
#define CAB_B_SKIP 1
#define P_MB 0
#define B_MB 1
#define D_INTER_MB 0
#define D_B_SLICE 1
#define D_INTRA_MB 2
#define MB_SKIP 0
#define I_PCM_MB 1
#define I_4x4_MB 2
#define I_16x16_MB 3
#define PART_DIRECT_16x16 0
#define CABAC 0

typedef int32_t WORD32;
typedef uint32_t UWORD32;
typedef uint16_t UWORD16;
typedef uint8_t UWORD8;
typedef int16_t WORD16;
typedef int8_t WORD8;

typedef struct dec_bit_stream_t {
    UWORD32 u4_ofst;
} dec_bit_stream_t;

typedef struct ctxt_inc_mb_info_t {
    UWORD8 u1_mb_type;
} ctxt_inc_mb_info_t;

typedef struct parse_part_params_t {
    UWORD8 u1_is_direct;
    UWORD8 u1_sub_mb_num;
} parse_part_params_t;

typedef struct parse_pmbarams_t {
    UWORD8 u1_num_part;
    UWORD8 u1_isI_mb;
} parse_pmbarams_t;

typedef struct deblk_mb_t {
    UWORD8 u1_mb_type;
    UWORD8 u1_mb_qp;
} deblk_mb_t;

typedef struct {
    UWORD8 u1_mb_type;
    UWORD8 u1_cbp;
    UWORD8 u1_tran_form8x8;
    UWORD8 u1_end_of_slice;
    UWORD8 u1_Mux;
    UWORD8 u1_topmb;
    struct {
        UWORD8 u1_mb_type;
        UWORD8 u1_tran_form8x8;
    } *ps_curmb;
} dec_mb_info_t;

typedef struct dec_slice_params_t {
    UWORD8 u1_slice_type;
    UWORD8 u1_slice_qp;
    UWORD8 u1_mbaff_frame_flag;
} dec_slice_params_t;

typedef struct dec_struct_t {
    UWORD16 u2_frm_wd_in_mbs;
    UWORD8 u1_qp;
    UWORD8 u1_mb_idx;
    UWORD32 u4_app_disable_deblk_frm;
    UWORD8 u1_mb_ngbr_availablity;
    UWORD8 u1_cur_mb_fld_dec_flag;
    UWORD32 u2_total_mbs_coded;
    UWORD16 u2_mbx;
    UWORD8 u1_recon_mb_grp;
    UWORD8 u1_separate_parse;
    UWORD32 u4_num_mbs_cur_nmb;
    UWORD32 u4_num_pmbair;
    
    dec_bit_stream_t *ps_bitstrm;
    parse_pmbarams_t *ps_parse_mb_data;
    dec_mb_info_t *ps_nmb_info;
    deblk_mb_t *ps_deblk_mbn;
    ctxt_inc_mb_info_t *ps_curr_ctxt_mb_info;
    parse_part_params_t *ps_part;
    parse_part_params_t *ps_parse_part_params;
    void *pv_prev_mb_parse_tu_coeff_data;
    void *pv_parse_tu_coeff_data;
    UWORD8 *pu1_left_mv_ctxt_inc[16][4];
    UWORD8 *pi1_left_ref_idx_ctxt_inc;
    UWORD8 *pu1_left_yuv_dc_csbp;
    WORD8 i1_prev_mb_qp_delta;
    
    struct {
        UWORD16 u2_max_mb_addr;
    } *ps_cur_sps;
    
    struct {
        UWORD32 u4_mbs_in_slice;
    } *ps_cur_slice;
    
    struct {
        // cabac env
    } s_cab_dec_env;
    
    WORD32 (*pf_get_mb_info)(struct dec_struct_t *, WORD32, dec_mb_info_t *, UWORD32);
    WORD32 (*pf_parse_inter_mb)(struct dec_struct_t *, dec_mb_info_t *, UWORD32, UWORD32);
    void (*pf_mvpred_ref_tfr_nby2mb)(struct dec_struct_t *, UWORD32, UWORD32);
} dec_struct_t;

void ih264d_update_qp(dec_struct_t *ps_dec, WORD32 i_qp);
WORD32 ih264d_init_cabac_dec_envirnoment(void *env, dec_bit_stream_t *ps_bitstrm);
void ih264d_set_deblocking_parameters(deblk_mb_t *ps_deblk_mb, dec_slice_params_t *ps_slice, UWORD32 u1_avail, UWORD32 u1_fld_flag);
UWORD8 ih264d_parse_mb_type_cabac(dec_struct_t *ps_dec);
WORD32 ih264d_parse_ipcm_mb(dec_struct_t *ps_dec, dec_mb_info_t *ps_mb_info, UWORD32 u1_mb);
WORD32 ih264d_parse_imb_cabac(dec_struct_t *ps_dec, dec_mb_info_t *ps_mb_info, UWORD8 u1_mb_type);
void ih264d_update_mbaff_left_nnz(dec_struct_t *ps_dec, dec_mb_info_t *ps_mb_info);
UWORD8 ih264d_decode_terminate(void *env, dec_bit_stream_t *ps_bitstrm);
void ih264d_update_nnz_for_skipmb(dec_struct_t *ps_dec, dec_mb_info_t *ps_mb_info, UWORD32 u1_cabac);
void ih264d_parse_tfr_nmb(dec_struct_t *ps_dec, UWORD32 u1_mb_idx, UWORD32 u1_num_mbs, UWORD32 u1_next, UWORD32 u1_tfr, UWORD32 u1_end);
void ih264d_decode_recon_tfr_nmb(dec_struct_t *ps_dec, UWORD32 u1_mb_idx, UWORD32 u1_num_mbs, UWORD32 u1_next, UWORD32 u1_tfr, UWORD32 u1_end);

#define MEMSET_16BYTES(p, val) memset((p), (val), 16)
#define COPYTHECONTEXT(str, val)