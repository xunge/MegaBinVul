#include <stdint.h>
#include <stdlib.h>

#define OK 0
#define ERROR_MB_ADDRESS_T -1
#define ERROR_MB_TYPE -2
#define ERROR_EOB_FLUSHBITS_T -3
#define D_INTRA_MB 0x04
#define I_PCM_MB 26

typedef uint32_t UWORD32;
typedef uint16_t UWORD16;
typedef uint8_t UWORD8;
typedef int32_t WORD32;
typedef int16_t WORD16;

typedef struct dec_bit_stream_t {
    UWORD32 u4_ofst;
    UWORD32 *pu4_buffer;
} dec_bit_stream_t;

typedef struct dec_mb_info_t {
    UWORD8 u1_mb_type;
    UWORD8 u1_end_of_slice;
    struct {
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

typedef struct mv_pred_t {
    WORD16 s_mv[4];
    WORD16 s_mvpred[2];
    UWORD8 u1_mb_field_decoding_flag;
    UWORD8 u1_mv_bits;
} mv_pred_t;

typedef struct dec_struct_t {
    dec_bit_stream_t *ps_bitstrm;
    UWORD16 u2_frm_wd_in_mbs;
    UWORD8 u1_mb_idx;
    UWORD8 u1_qp;
    UWORD8 u1_mb_ngbr_availablity;
    UWORD8 u1_cur_mb_fld_dec_flag;
    UWORD8 u4_num_cores;
    UWORD8 u4_app_disable_deblk_frm;
    UWORD8 u1_recon_mb_grp;
    UWORD8 u1_separate_parse;
    UWORD16 u2_mbx;
    UWORD16 u2_total_mbs_coded;
    UWORD32 u4_num_mbs_cur_nmb;
    UWORD32 u4_num_pmbair;
    dec_mb_info_t *ps_nmb_info;
    deblk_mb_t *ps_deblk_mbn;
    mv_pred_t *ps_mv_cur;
    void *pv_prev_mb_parse_tu_coeff_data;
    void *pv_parse_tu_coeff_data;
    void (*pf_get_mb_info)(struct dec_struct_t *, WORD16, dec_mb_info_t *, UWORD8);
    void (*pf_compute_bs)(struct dec_struct_t *, dec_mb_info_t *, UWORD16);
    struct {
        UWORD16 u2_max_mb_addr;
    } *ps_cur_sps;
    struct {
        UWORD32 u4_mbs_in_slice;
    } *ps_cur_slice;
} dec_struct_t;

WORD32 ih264d_update_qp(dec_struct_t *ps_dec, WORD32 i_qp);
WORD32 ih264d_set_deblocking_parameters(deblk_mb_t *ps_cur_deblk_mb, dec_slice_params_t *ps_slice, UWORD8 u1_mb_ngbr_availablity, UWORD8 u1_cur_mb_fld_dec_flag);
WORD32 ih264d_parse_ipcm_mb(dec_struct_t *ps_dec, dec_mb_info_t *ps_cur_mb_info, UWORD8 u1_num_mbs);
WORD32 ih264d_parse_imb_cavlc(dec_struct_t *ps_dec, dec_mb_info_t *ps_cur_mb_info, UWORD8 u1_num_mbs, UWORD8 u1_mb_type);
WORD32 ih264d_update_mbaff_left_nnz(dec_struct_t *ps_dec, dec_mb_info_t *ps_cur_mb_info);
WORD32 ih264d_rep_mv_colz(dec_struct_t *ps_dec, mv_pred_t *ps_mvPred, mv_pred_t *ps_mv_nmb_start, WORD32 i_refFrame, UWORD8 u1_mbField, UWORD8 u1_mbPartIdx, UWORD8 u1_subMbPartIdx);
WORD32 ih264d_parse_tfr_nmb(dec_struct_t *ps_dec, UWORD8 u1_mb_idx, UWORD8 u1_num_mbs, UWORD8 u1_num_mbs_next, UWORD8 u1_tfr_n_mb, UWORD8 u1_end_of_row);
WORD32 ih264d_decode_recon_tfr_nmb(dec_struct_t *ps_dec, UWORD8 u1_mb_idx, UWORD8 u1_num_mbs, UWORD8 u1_num_mbs_next, UWORD8 u1_tfr_n_mb, UWORD8 u1_end_of_row);

#define CLZ(x) __builtin_clz(x)
#define NEXTBITS_32(val, offset, buf) do { val = *(buf + (offset >> 5)); } while(0)
#define GETBITS(val, offset, buf, numbits) do { \
    UWORD32 tmp = *(buf + (offset >> 5)); \
    val = (tmp >> (32 - (offset & 31) - (numbits))) & ((1 << (numbits)) - 1); \
} while(0)
#define MORE_RBSP_DATA(bitstrm) ((bitstrm)->u4_ofst < ((*(bitstrm)->pu4_buffer) << 3))
#define COPYTHECONTEXT(str, val)