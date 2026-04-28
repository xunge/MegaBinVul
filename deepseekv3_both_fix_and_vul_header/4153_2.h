#include <stdint.h>

#define WORD32 int32_t
#define UWORD32 uint32_t
#define WORD16 int16_t
#define UWORD16 uint16_t
#define UWORD8 uint8_t
#define OK 0
#define ERROR_MB_ADDRESS_T -1
#define ERROR_MB_TYPE -2
#define I_PCM_MB 26
#define D_INTRA_MB 0x01

typedef struct dec_bit_stream_t {
    UWORD32 u4_ofst;
    UWORD32 u4_max_ofst;
    UWORD32* pu4_buffer;
} dec_bit_stream_t;

typedef struct cur_mb_t {
    UWORD8 u1_mb_type;
} cur_mb_t;

typedef struct dec_mb_info_t {
    UWORD8 u1_end_of_slice;
    UWORD8 u1_mb_type;
    cur_mb_t* ps_curmb;
} dec_mb_info_t;

typedef struct deblk_mb_t {
    UWORD8 u1_mb_type;
    UWORD8 u1_mb_qp;
} deblk_mb_t;

typedef struct mv_pred_t {
    WORD16 s_mv[4];
    WORD16 s_mvpos[2];
    UWORD8 u1_ref_idx;
    UWORD8 u1_part_pred;
} mv_pred_t;

typedef struct dec_slice_params_t {
    UWORD8 u1_slice_qp;
    UWORD8 u1_mbaff_frame_flag;
} dec_slice_params_t;

typedef struct dec_struct_t {
    dec_bit_stream_t* ps_bitstrm;
    UWORD16 u2_frm_wd_in_mbs;
    UWORD8 u1_qp;
    UWORD8 u1_mb_idx;
    void* pv_prev_mb_parse_tu_coeff_data;
    void* pv_parse_tu_coeff_data;
    struct {
        UWORD16 u2_max_mb_addr;
    } *ps_cur_sps;
    dec_mb_info_t* ps_nmb_info;
    UWORD32 u4_num_mbs_cur_nmb;
    UWORD32 u4_num_pmbair;
    void (*pf_get_mb_info)(struct dec_struct_t*, WORD16, dec_mb_info_t*, UWORD8);
    deblk_mb_t* ps_deblk_mbn;
    UWORD32 u4_app_disable_deblk_frm;
    UWORD8 u1_mb_ngbr_availablity;
    UWORD8 u1_cur_mb_fld_dec_flag;
    UWORD32 u4_num_cores;
    UWORD16 u2_total_mbs_coded;
    UWORD16 u2_mbx;
    UWORD8 u1_recon_mb_grp;
    UWORD8 u1_separate_parse;
    mv_pred_t* ps_mv_cur;
    void (*pf_compute_bs)(struct dec_struct_t*, dec_mb_info_t*, UWORD16);
    struct {
        UWORD32 u4_mbs_in_slice;
    } *ps_cur_slice;
} dec_struct_t;

#define CLZ(x) __builtin_clz(x)
#define NEXTBITS_32(val, offset, buf) val = *(buf + (offset >> 5)) >> (offset & 0x1F)
#define GETBITS(val, offset, buf, num_bits) val = (*(buf + (offset >> 5)) >> (offset & 0x1F)) & ((1 << num_bits) - 1)
#define MORE_RBSP_DATA(bitstrm) ((bitstrm)->u4_ofst < ((bitstrm)->u4_max_ofst - 1))
#define COPYTHECONTEXT(str, val) (void)0

static WORD32 ih264d_update_qp(dec_struct_t *ps_dec, WORD32 i_qp);
static WORD32 ih264d_set_deblocking_parameters(deblk_mb_t *ps_deblk_mb, 
                                             dec_slice_params_t *ps_slice,
                                             UWORD8 u1_mb_ngbr_availablity,
                                             UWORD8 u1_cur_mb_fld_dec_flag);
static WORD32 ih264d_parse_ipcm_mb(dec_struct_t *ps_dec, 
                                  dec_mb_info_t *ps_cur_mb_info,
                                  UWORD8 u1_num_mbs);
static WORD32 ih264d_parse_imb_cavlc(dec_struct_t *ps_dec,
                                    dec_mb_info_t *ps_cur_mb_info,
                                    UWORD8 u1_num_mbs,
                                    UWORD8 u1_mb_type);
static void ih264d_update_mbaff_left_nnz(dec_struct_t *ps_dec,
                                       dec_mb_info_t *ps_cur_mb_info);
static void ih264d_rep_mv_colz(dec_struct_t *ps_dec,
                              mv_pred_t *ps_mv_pred,
                              mv_pred_t *ps_col_mv_pred,
                              WORD32 i_ref_idx,
                              UWORD8 u1_is_top_submb,
                              UWORD8 u1_mbpart_width,
                              UWORD8 u1_mbpart_height);
static void ih264d_parse_tfr_nmb(dec_struct_t *ps_dec,
                                UWORD8 u1_mb_idx,
                                UWORD8 u1_num_mbs,
                                UWORD8 u1_num_mbs_next,
                                UWORD8 u1_tfr_n_mb,
                                UWORD8 u1_end_of_row);
static void ih264d_decode_recon_tfr_nmb(dec_struct_t *ps_dec,
                                      UWORD8 u1_mb_idx,
                                      UWORD8 u1_num_mbs,
                                      UWORD8 u1_num_mbs_next,
                                      UWORD8 u1_tfr_n_mb,
                                      UWORD8 u1_end_of_row);