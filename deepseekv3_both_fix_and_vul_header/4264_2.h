#include <stdint.h>
#include <string.h>

#define WORD32 int32_t
#define UWORD32 uint32_t
#define WORD16 int16_t
#define UWORD16 uint16_t
#define WORD8 int8_t
#define UWORD8 uint8_t

#define OK 0
#define ERROR_NUM_REF -1
#define ERROR_REFIDX_ORDER_T -2
#define ERROR_DBP_MANAGER_T -3
#define ERROR_INV_SLICE_HDR_T -4
#define ERROR_INV_RANGE_QP_T -5

#define MAX_FRAMES 16
#define OUT_OF_RANGE_REF -1
#define FRM_LIST_L0 0
#define FRM_LIST_L1 1
#define TOP_LIST_FLD_L0 2
#define BOT_LIST_FLD_L0 3
#define TOP_LIST_FLD_L1 4
#define BOT_LIST_FLD_L1 5
#define MAX_CABAC_INIT_IDC 2
#define SLICE_BOUNDARY_DBLK_DISABLED 2
#define MIN_DBLK_FIL_OFF -6
#define MAX_DBLK_FIL_OFF 6
#define PAD_MAP_IDX_POC 4
#define CABAC 1
#define B_SLICE 1

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct dec_bit_stream_t {
    UWORD32 *pu4_buffer;
    UWORD32 u4_ofst;
} dec_bit_stream_t;

typedef struct dec_pic_params_t {
    UWORD8 u1_num_ref_idx_lx_active[2];
    UWORD8 u1_pic_init_qp;
    UWORD8 u1_entropy_coding_mode;
    UWORD8 u1_deblocking_filter_parameters_present_flag;
    UWORD8 u1_wted_bipred_idc;
} dec_pic_params_t;

typedef struct dec_slice_params_t {
    UWORD8 u1_num_ref_idx_active_override_flag;
    UWORD8 u1_num_ref_idx_lx_active[2];
    UWORD8 u1_field_pic_flag;
    UWORD8 u1_mbaff_frame_flag;
    UWORD8 u1_nal_ref_idc;
    UWORD8 u1_cabac_init_idc;
    UWORD8 u1_slice_qp;
    UWORD8 u1_disable_dblk_filter_idc;
    WORD8 i1_slice_alpha_c0_offset;
    WORD8 i1_slice_beta_offset;
    UWORD16 u2_log2Y_crwd;
    UWORD8 u1_slice_type;
} dec_slice_params_t;

typedef struct pic_buffer_t {
    UWORD8 *pu1_buf1;
} pic_buffer_t;

typedef struct dpb_manager_t {
    pic_buffer_t *ps_init_dpb[2];
    pic_buffer_t *ps_mod_dpb[2];
    UWORD8 u1_dpb_commands_read;
} dpb_manager_t;

typedef struct dpb_commands_t {
    UWORD8 u1_dpb_commands_read;
} dpb_commands_t;

typedef struct dec_struct_t {
    dec_pic_params_t *ps_cur_pps;
    dec_slice_params_t *ps_cur_slice;
    dec_bit_stream_t *ps_bitstrm;
    struct {
        WORD16 i2_mv[2];
        WORD8 i1_ref_frame[2];
        UWORD8 u1_col_ref_pic_idx;
        UWORD8 u1_pic_type;
    } s_default_mv_pred;
    UWORD8 u1_pr_sl_type;
    UWORD8 u1_sl_typ_5_9;
    UWORD8 u1_first_pb_nal_in_pic;
    UWORD8 u1_num_ref_idx_lx_active_prev;
    pic_buffer_t (*ps_ref_pic_buf_lx[2])[MAX_FRAMES];
    dpb_manager_t *ps_dpb_mgr;
    dpb_commands_t *ps_dpb_cmds;
    void *ppv_map_ref_idx_to_poc[6 * MAX_FRAMES];
    UWORD32 u4_num_cores;
    UWORD32 u4_num_ref_frames_at_init;
    struct {
        void *ppv_map_ref_idx_to_poc[6 * MAX_FRAMES];
        UWORD16 u2_log2Y_crwd;
    } *ps_parse_cur_slice;
    UWORD32 u4_bitoffset;
    UWORD8 u1_slice_header_done;
    UWORD8 u1_B;
    UWORD16 *pu4_wts_ofsts_mat;
    UWORD16 *pu4_wt_ofsts;
    WORD32 (*pf_parse_inter_slice)(struct dec_struct_t *, dec_slice_params_t *, UWORD16);
    WORD32 (*pf_parse_inter_mb)(struct dec_struct_t *);
    WORD32 (*pf_get_mb_info)(struct dec_struct_t *);
    void (*pf_mvpred_ref_tfr_nby2mb)(struct dec_struct_t *);
} dec_struct_t;

WORD32 ih264d_get_bit_h264(dec_bit_stream_t *ps_bitstrm);
WORD32 ih264d_uev(UWORD32 *pu4_bitstrm_ofst, UWORD32 *pu4_bitstrm_buf);
WORD32 ih264d_sev(UWORD32 *pu4_bitstrm_ofst, UWORD32 *pu4_bitstrm_buf);
void ih264d_init_ref_idx_lx_b(dec_struct_t *ps_dec);
WORD32 ih264d_ref_idx_reordering(dec_struct_t *ps_dec, WORD32 list_no);
void ih264d_convert_frm_mbaff_list(dec_struct_t *ps_dec);
WORD32 ih264d_parse_pred_weight_table(dec_slice_params_t *ps_slice, dec_bit_stream_t *ps_bitstrm);
void ih264d_form_pred_weight_matrix(dec_struct_t *ps_dec);
void ih264d_get_implicit_weights(dec_struct_t *ps_dec);
WORD32 ih264d_read_mmco_commands(dec_struct_t *ps_dec);
void ih264d_init_cabac_contexts(UWORD8 slice_type, dec_struct_t *ps_dec);
WORD32 ih264d_parse_inter_slice_data_cabac(dec_struct_t *ps_dec, dec_slice_params_t *ps_slice, UWORD16 u2_first_mb_in_slice);
WORD32 ih264d_parse_bmb_cabac(dec_struct_t *ps_dec);
WORD32 ih264d_get_mb_info_cabac_mbaff(dec_struct_t *ps_dec);
WORD32 ih264d_get_mb_info_cabac_nonmbaff(dec_struct_t *ps_dec);
WORD32 ih264d_parse_inter_slice_data_cavlc(dec_struct_t *ps_dec, dec_slice_params_t *ps_slice, UWORD16 u2_first_mb_in_slice);
WORD32 ih264d_parse_bmb_cavlc(dec_struct_t *ps_dec);
WORD32 ih264d_get_mb_info_cavlc_mbaff(dec_struct_t *ps_dec);
WORD32 ih264d_get_mb_info_cavlc_nonmbaff(dec_struct_t *ps_dec);
WORD32 ih264d_cal_col_pic(dec_struct_t *ps_dec);
void ih264d_mv_pred_ref_tfr_nby2_bmb(dec_struct_t *ps_dec);

#define COPYTHECONTEXT(s, v)
#define SWITCHOFFTRACE
#define SWITCHONTRACE
#define SWITCHOFFTRACECABAC
#define SWITCHONTRACECABAC