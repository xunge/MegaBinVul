#include <stdint.h>
#include <string.h>

typedef int32_t WORD32;
typedef uint32_t UWORD32;
typedef uint16_t UWORD16;
typedef int16_t WORD16;
typedef uint8_t UWORD8;
#define OK 0

#define MAX_DISP_BUFS_NEW 16
#define MB_SIZE 16
#define BLK8x8SIZE 8
#define YUV420SP_FACTOR 2
#define SUB_BLK_SIZE 4
#define PAD_LEN_Y_H 0
#define PAD_LEN_UV_H 0
#define HIGH_PROFILE_IDC 100
#define I_SLICE 0
#define SI_SLICE 1
#define IDR_SLICE_NAL 5
#define PIC_TYPE_I 0
#define PIC_TYPE_UNKNOWN 0
#define ACCEPT_ALL_PICS 0
#define BOT_FLD 0
#define ERROR_UNAVAIL_PICBUF_T 0
#define ERROR_UNAVAIL_MVBUF_T 0
#define SKIP_NONE 0
#define BUF_MGR_REF 0
#define BUF_MGR_IO 0

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct pocstruct_t {
    WORD32 i4_pic_order_cnt_lsb;
    WORD32 i4_pic_order_cnt_msb;
    WORD32 i4_delta_pic_order_cnt_bottom;
    WORD32 i4_delta_pic_order_cnt[2];
    UWORD8 u1_bot_field;
    WORD32 i4_prev_frame_num_ofst;
    UWORD16 u2_frame_num;
} pocstruct_t;

typedef struct dec_seq_params_t {
    UWORD8 u1_mb_aff_flag;
    UWORD8 u1_profile_idc;
    WORD32 i4_seq_scaling_matrix_present_flag;
    UWORD8 u1_direct_8x8_inference_flag;
    UWORD8 u1_frame_mbs_only_flag;
} dec_seq_params_t;

typedef struct dec_pic_params_t {
    dec_seq_params_t *ps_sps;
    WORD32 i4_top_field_order_cnt;
    WORD32 i4_bottom_field_order_cnt;
    WORD32 i4_avg_poc;
    WORD32 i4_pic_scaling_matrix_present_flag;
    WORD32 i4_transform_8x8_mode_flag;
} dec_pic_params_t;

typedef struct dec_slice_params_t {
    UWORD8 u1_bottom_field_flag;
    UWORD8 u1_field_pic_flag;
    UWORD8 u1_slice_type;
    UWORD8 u1_nal_ref_idc;
    UWORD8 u1_nal_unit_type;
    UWORD8 u1_mbaff_frame_flag;
} dec_slice_params_t;

typedef struct high_profile_tools_t {
    UWORD8 u1_scaling_present;
    UWORD8 u1_transform8x8_present;
    UWORD8 u1_direct_8x8_inference_flag;
    void *s_cavlc_ctxt;
} high_profile_tools_t;

typedef struct dec_err_status_t {
    UWORD8 u1_cur_pic_type;
    UWORD8 u1_pic_aud_i;
    UWORD8 u1_err_flag;
} dec_err_status_t;

typedef struct buf_mgr_t {
    int dummy;
} buf_mgr_t;

typedef struct col_mv_buf_t {
    void *pv_col_zero_flag;
    void *pv_mv;
} col_mv_buf_t;

typedef struct mv_pred_t {
    int dummy;
} mv_pred_t;

typedef struct tfr_ctxt_t {
    UWORD8 *pu1_dest_y;
    UWORD8 *pu1_dest_u;
    UWORD8 *pu1_dest_v;
    UWORD16 u2_frm_wd_y;
    UWORD16 u2_frm_wd_uv;
    UWORD32 u4_inc_y[2];
    UWORD32 u4_inc_uv[2];
    UWORD16 u2_mv_top_left_inc;
    UWORD16 u2_mv_left_inc;
} tfr_ctxt_t;

typedef struct pic_buffer_t {
    UWORD32 u4_ts;
    UWORD8 u1_mv_buf_id;
    UWORD8 *pu1_col_zero_flag;
    mv_pred_t *ps_mv;
    UWORD8 u1_picturetype;
    UWORD32 u4_pack_slc_typ;
    WORD32 i4_poc;
    WORD32 i4_frame_num;
    WORD32 i4_pic_num;
    WORD32 i4_top_field_order_cnt;
    WORD32 i4_bottom_field_order_cnt;
    WORD32 i4_avg_poc;
    UWORD32 u4_time_stamp;
    UWORD8 *pu1_buf1;
    UWORD8 *pu1_buf2;
    UWORD8 *pu1_buf3;
    UWORD16 u2_frm_wd_y;
    UWORD16 u2_frm_wd_uv;
} pic_buffer_t;

typedef struct dpb_mgr_t {
    pic_buffer_t ***ps_init_dpb;
} dpb_mgr_t;

typedef struct dec_struct_t {
    pocstruct_t s_cur_pic_poc;
    void *pv_dec_out;
    dec_slice_params_t *ps_cur_slice;
    dec_slice_params_t *ps_parse_cur_slice;
    dec_slice_params_t *ps_decode_cur_slice;
    dec_slice_params_t *ps_computebs_cur_slice;
    dec_slice_params_t *ps_dec_slice_buf[1];
    WORD32 i1_prev_mb_qp_delta;
    WORD32 i1_next_ctxt_idx;
    UWORD32 u4_nmb_deblk;
    UWORD32 u4_num_cores;
    UWORD32 u4_use_intrapred_line_copy;
    UWORD32 u4_app_disable_deblk_frm;
    WORD32 i4_degrade_type;
    WORD32 i4_degrade_pics;
    WORD32 i4_degrade_pic_cnt;
    WORD32 i4_nondegrade_interval;
    WORD32 i4_mv_frac_mask;
    UWORD8 u1_sl_typ_5_9;
    dec_err_status_t *ps_dec_err_status;
    dpb_mgr_t *ps_dpb_mgr;
    pic_buffer_t **ps_ref_pic_buf_lx;
    UWORD8 u1_init_dec_flag;
    struct {
        UWORD8 u1_eoseq_pending;
    } s_prev_seq_params;
    UWORD8 u1_second_field;
    WORD32 i4_cur_display_seq;
    WORD32 i4_prev_max_display_seq;
    WORD32 i4_max_poc;
    WORD32 i4_error_code;
    void *pv_parse_tu_coeff_data;
    void *pv_proc_tu_coeff_data;
    void *pv_pic_tu_coeff_data;
    void *ps_nmb_info;
    void *ps_frm_mb_info;
    UWORD8 u1_separate_parse;
    UWORD16 u2_pic_wd;
    UWORD16 u2_pic_ht;
    UWORD8 *pu1_dec_mb_map;
    UWORD8 *pu1_recon_mb_map;
    UWORD16 *pu2_slice_num_map;
    high_profile_tools_t s_high_profile;
    UWORD32 u4_share_disp_buf;
    UWORD32 u4_disp_buf_to_be_freed[MAX_DISP_BUFS_NEW];
    UWORD32 u4_disp_buf_mapping[MAX_DISP_BUFS_NEW];
    UWORD8 u1_top_bottom_decoded;
    pic_buffer_t *ps_cur_pic;
    UWORD8 u1_pic_buf_id;
    UWORD32 u4_ts;
    UWORD32 u4_pts;
    UWORD8 au1_pic_buf_id_mv_buf_id_map[MAX_DISP_BUFS_NEW];
    UWORD8 au1_pic_buf_ref_flag[MAX_DISP_BUFS_NEW];
    UWORD8 u1_first_slice_in_stream;
    void *apv_buf_id_pic_buf_map[MAX_DISP_BUFS_NEW];
    pic_buffer_t s_cur_pic;
    UWORD16 u2_frm_wd_in_mbs;
    UWORD16 u2_frm_wd_y;
    UWORD16 u2_frm_wd_uv;
    UWORD8 u1_recon_mb_grp;
    void *ps_nbr_mb_row;
    void *ps_cur_mb_row;
    void *ps_top_mb_row;
    dec_seq_params_t *ps_cur_sps;
    void *ps_mv_top_p[1];
    UWORD8 u1_mv_top_p;
    UWORD8 u1_mb_idx;
    UWORD16 u2_total_mbs_coded;
    WORD32 i4_submb_ofst;
    UWORD32 u4_pred_info_idx;
    UWORD32 u4_pred_info_pkd_idx;
    UWORD32 u4_dma_buf_idx;
    mv_pred_t *ps_mv;
    mv_pred_t *ps_mv_cur;
    mv_pred_t *ps_mv_top;
    mv_pred_t *ps_mv_left;
    mv_pred_t *ps_mv_bank_cur;
    UWORD8 *pu1_col_zero_flag;
    void *ps_parse_part_params;
    void *ps_part;
    WORD16 i2_prev_slice_mbx;
    WORD16 i2_prev_slice_mby;
    UWORD16 u2_mv_2mb[2];
    UWORD8 u1_last_pic_not_decoded;
    UWORD16 u2_cur_slice_num;
    UWORD16 u2_cur_slice_num_dec_thread;
    UWORD16 u2_cur_slice_num_bs;
    UWORD32 u4_intra_pred_line_ofst;
    UWORD8 *pu1_y_intra_pred_line;
    UWORD8 *pu1_u_intra_pred_line;
    UWORD8 *pu1_v_intra_pred_line;
    UWORD8 *pu1_cur_y_intra_pred_line;
    UWORD8 *pu1_cur_u_intra_pred_line;
    UWORD8 *pu1_cur_v_intra_pred_line;
    UWORD8 *pu1_cur_y_intra_pred_line_base;
    UWORD8 *pu1_cur_u_intra_pred_line_base;
    UWORD8 *pu1_cur_v_intra_pred_line_base;
    UWORD8 *pu1_prev_y_intra_pred_line;
    UWORD8 *pu1_prev_u_intra_pred_line;
    UWORD8 *pu1_prev_v_intra_pred_line;
    void *ps_deblk_pic;
    void *ps_deblk_mbn;
    void *pf_compute_bs;
    void *pf_mvpred;
    UWORD8 u1_cur_mb_fld_dec_flag;
    UWORD8 i1_recon_in_thread3_flag;
    tfr_ctxt_t s_tran_addrecon;
    tfr_ctxt_t s_tran_addrecon_parse;
    tfr_ctxt_t s_tran_iprecon;
    void *ps_frame_buf_ip_recon;
    void *pv_pic_buf_mgr;
    void *pv_mv_buf_mgr;
    void *s_pad_mgr;
    void *ps_cur_deblk_mb;
    UWORD32 u4_cur_deblk_mb_num;
    UWORD32 u4_deblk_mb_x;
    UWORD32 u4_deblk_mb_y;
    UWORD32 *pu4_wt_ofsts;
    UWORD32 *pu4_wts_ofsts_mat;
    void *process_disp_mutex;
    void *s_cavlc_ctxt;
    UWORD32 u4_pic_buf_got;
} dec_struct_t;

typedef struct ivd_video_decode_op_t {
    int dummy;
} ivd_video_decode_op_t;

#define H264_MUTEX_LOCK(x) 
#define H264_MUTEX_UNLOCK(x) 
#define H264_DEC_DEBUG_PRINT(x) 

void ih264d_reset_ref_bufs(dpb_mgr_t *ps_dpb_mgr);
WORD32 ih264d_init_pic(dec_struct_t *ps_dec, UWORD16 u2_frame_num, WORD32 i4_poc, dec_pic_params_t *ps_pps);
void ih264d_form_scaling_matrix_picture(dec_seq_params_t *ps_seq, dec_pic_params_t *ps_pps, dec_struct_t *ps_dec);
void ih264d_form_default_scaling_matrix(dec_struct_t *ps_dec);
void ih264d_assign_pic_num(dec_struct_t *ps_dec);
void ih264d_init_deblk_tfr_ctxt(dec_struct_t *ps_dec, void *s_pad_mgr, tfr_ctxt_t *s_tran_addrecon, UWORD16 u2_frm_wd_in_mbs, WORD32 i4_deblk_mb_y);
WORD32 ih264d_compute_bs_mbaff(void);
WORD32 ih264d_compute_bs_non_mbaff(void);
WORD32 ih264d_mvpred_mbaff(void);
void *ih264_buf_mgr_get_next_free(buf_mgr_t *pv_pic_buf_mgr, WORD32 *cur_pic_buf_id);
void ih264_buf_mgr_release(buf_mgr_t *pv_pic_buf_mgr, WORD32 j, WORD32 type);