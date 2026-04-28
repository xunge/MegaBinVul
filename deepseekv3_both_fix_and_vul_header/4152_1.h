#include <stdint.h>

#define OK 0
#define ERROR_MB_ADDRESS_T -1
#define ERROR_MB_TYPE -2
#define I_SLICE 0
#define D_INTRA_MB 0x01
#define I_PCM_MB 0x25

typedef int32_t WORD32;
typedef uint32_t UWORD32;
typedef uint16_t UWORD16;
typedef int16_t WORD16;
typedef uint8_t UWORD8;
typedef int8_t WORD8;

typedef struct dec_bit_stream_t {
    UWORD32 u4_ofst;
} dec_bit_stream_t;

typedef struct mv_pred_t {
    WORD16 s_mv[4];
    WORD16 s_mvpred[2];
    UWORD8 u1_mv_bits;
    UWORD8 u1_mv_bits_available;
} mv_pred_t;

typedef struct dec_mb_info_t {
    UWORD8 u1_end_of_slice;
    UWORD8 u1_tran_form8x8;
    UWORD8 u1_mb_type;
    UWORD8 u1_topmb;
    struct {
        UWORD8 u1_tran_form8x8;
        UWORD8 u1_mb_type;
    } *ps_curmb;
} dec_mb_info_t;

typedef struct deblk_mb_t {
    UWORD8 u1_mb_type;
    UWORD8 u1_mb_qp;
} deblk_mb_t;

typedef struct dec_slice_params_t {
    UWORD8 u1_slice_qp;
    UWORD8 u1_mbaff_frame_flag;
} dec_slice_params_t;

typedef struct dec_struct_t {
    dec_bit_stream_t *ps_bitstrm;
    UWORD16 u2_frm_wd_in_mbs;
    UWORD8 u1_qp;
    UWORD8 u1_mb_idx;
    UWORD8 u1_mb_ngbr_availablity;
    UWORD8 u1_cur_mb_fld_dec_flag;
    UWORD8 u4_app_disable_deblk_frm;
    UWORD8 u4_num_cores;
    UWORD8 u1_recon_mb_grp;
    UWORD8 u1_separate_parse;
    UWORD16 u2_mbx;
    UWORD16 u2_total_mbs_coded;
    WORD8 i1_prev_mb_qp_delta;
    UWORD32 u4_num_mbs_cur_nmb;
    UWORD32 u4_num_pmbair;
    void *pv_prev_mb_parse_tu_coeff_data;
    void *pv_parse_tu_coeff_data;
    dec_mb_info_t *ps_nmb_info;
    deblk_mb_t *ps_deblk_mbn;
    mv_pred_t *ps_mv_cur;
    struct {
        UWORD16 u2_max_mb_addr;
    } *ps_cur_sps;
    struct {
        UWORD32 u4_mbs_in_slice;
    } *ps_cur_slice;
    struct {
        /* cabac decoding environment */
    } s_cab_dec_env;
    void (*pf_get_mb_info)(struct dec_struct_t *, WORD16, dec_mb_info_t *, UWORD8);
    void (*pf_compute_bs)(struct dec_struct_t *, dec_mb_info_t *, UWORD16);
} dec_struct_t;

#define COPYTHECONTEXT(str, val) (void)0