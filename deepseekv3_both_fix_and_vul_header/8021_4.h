#include <stdint.h>
#include <stddef.h>

#define MAX_NUM_PIC_PARAMS 32
#define MAX_FRAMES 16
#define PAD_MAP_IDX_POC 4
#define SUB_BLK_SIZE 16
#define BASE_PROFILE_IDC 66
#define OK 0
#define TRUE 1
#define FALSE 0
#define REJECT_CUR_PIC 0x1
#define P_SLICE 0
#define B_SLICE 1
#define MB_SKIP 0
#define PRED_16x16 0
#define D_INTER_MB 0
#define P_MB 0
#define PART_DIRECT_16x16 0
#define CAVLC 0

typedef int32_t WORD32;
typedef uint32_t UWORD32;
typedef uint16_t UWORD16;
typedef uint8_t UWORD8;

typedef struct dec_bit_stream_t {
    UWORD32 *pu4_buffer;
    UWORD32 u4_ofst;
} dec_bit_stream_t;

typedef struct dec_slice_params_t {
    UWORD8 u1_mbaff_frame_flag;
    UWORD8 u1_slice_qp;
    UWORD16 u2_frame_num;
    UWORD8 u1_bottom_field_flag;
    UWORD8 u1_field_pic_flag;
    UWORD8 u1_slice_type;
    UWORD8 u1_nal_ref_idc;
    UWORD8 u1_nal_unit_type;
    UWORD32 u4_mbs_in_slice;
    UWORD16 u2_first_mb_in_slice;
    WORD32 i1_slice_alpha_c0_offset;
    WORD32 i1_slice_beta_offset;
    UWORD16 u2_log2Y_crwd;
} dec_slice_params_t;

typedef struct deblk_mb_t {
    UWORD8 u1_mb_type;
    UWORD8 u1_mb_qp;
} deblk_mb_t;

typedef struct dec_mb_info_t {
    UWORD8 u1_mb_type;
    UWORD8 u1_mb_mc_mode;
    UWORD8 u1_cbp;
    UWORD8 u1_end_of_slice;
    UWORD8 u1_mb_ngbr_availablity;
    UWORD16 u2_mby;
    UWORD16 u2_mbx;
    UWORD8 u1_Mux;
    struct dec_mb_info_t *ps_curmb;
} dec_mb_info_t;

typedef struct parse_pmbarams_t {
    UWORD8 u1_num_part;
    UWORD8 u1_isI_mb;
} parse_pmbarams_t;

typedef struct parse_part_params_t {
    UWORD8 u1_is_direct;
    UWORD8 u1_sub_mb_num;
} parse_part_params_t;

typedef struct dec_slice_struct_t {
    UWORD32 u4_first_mb_in_slice;
    UWORD16 u2_log2Y_crwd;
    UWORD8 slice_type;
    void *pv_tu_coeff_data_start;
    volatile void **ppv_map_ref_idx_to_poc;
} dec_slice_struct_t;

typedef struct pocstruct_t {
    UWORD16 u2_frame_num;
} pocstruct_t;

typedef struct dec_err_status_t {
    UWORD32 u1_err_flag;
} dec_err_status_t;

typedef struct pps_t {
    UWORD8 u1_is_valid;
    UWORD8 u1_profile_idc;
} pps_t;

typedef struct sps_t {
    UWORD8 u1_num_ref_frames;
    UWORD16 u2_max_mb_addr;
    UWORD8 u1_profile_idc;
} sps_t;

typedef struct disp_op_t {
    UWORD32 u4_error_code;
} disp_op_t;

typedef struct disp_frame_info_t {
    UWORD32 u4_y_ht;
} disp_frame_info_t;

typedef struct pic_t {
    WORD32 i4_poc;
} pic_t;

typedef struct ref_pic_buf_t {
    UWORD8 u1_pic_buf_id;
} ref_pic_buf_t;

typedef struct dpb_cmds_t {
    UWORD8 u1_long_term_reference_flag;
} dpb_cmds_t;

typedef struct dec_struct_t {
    UWORD32 u4_num_mbs_cur_nmb;
    UWORD32 u4_num_mbs_prev_nmb;
    UWORD16 u2_frm_wd_in_mbs;
    UWORD16 u2_frm_ht_in_mbs;
    UWORD16 u2_total_mbs_coded;
    UWORD8 u1_mb_idx;
    UWORD8 u1_first_slice_in_stream;
    UWORD8 u1_pic_decode_done;
    UWORD8 u1_slice_header_done;
    UWORD8 u1_mb_ngbr_availablity;
    UWORD8 u1_qp;
    UWORD8 u1_recon_mb_grp;
    UWORD8 u1_separate_parse;
    UWORD8 u4_dec_thread_created;
    UWORD8 u4_bs_deblk_thread_created;
    UWORD8 u4_app_disable_deblk_frm;
    UWORD8 u1_cur_mb_fld_dec_flag;
    UWORD16 u2_cur_slice_num;
    UWORD16 u2_frame_num;
    UWORD16 u2_prv_frame_num;
    UWORD32 u4_output_present;
    UWORD32 u4_first_slice_in_pic;
    WORD32 i4_display_delay;
    WORD32 i2_prev_slice_mbx;
    WORD32 i2_prev_slice_mby;
    WORD32 i1_prev_mb_qp_delta;
    WORD32 i1_recon_in_thread3_flag;
    WORD32 i4_submb_ofst;
    WORD32 u4_num_cores;
    UWORD16 u2_mbx;
    UWORD16 u2_mby;
    UWORD16 u2_cur_mb_addr;
    UWORD32 u4_num_pmbair;
    UWORD8 u1_sub_mb_num;
    UWORD8 u1_pr_sl_type;
    dec_err_status_t *ps_dec_err_status;
    dec_bit_stream_t *ps_bitstrm;
    dec_slice_params_t *ps_cur_slice;
    dec_mb_info_t *ps_nmb_info;
    parse_pmbarams_t *ps_parse_mb_data;
    parse_part_params_t *ps_parse_part_params;
    parse_part_params_t *ps_part;
    deblk_mb_t *ps_deblk_mbn;
    void *pv_parse_tu_coeff_data;
    void *pv_prev_mb_parse_tu_coeff_data;
    void *pv_proc_tu_coeff_data;
    void *pv_map_ref_idx_to_poc_buf;
    void *pv_dec_thread_handle;
    void *pv_bs_deblk_thread_handle;
    sps_t *ps_cur_sps;
    pps_t ps_pps[MAX_NUM_PIC_PARAMS];
    dec_slice_struct_t *ps_dec_slice_buf;
    dec_slice_struct_t *ps_parse_cur_slice;
    dpb_cmds_t *ps_dpb_cmds;
    pic_t *ps_cur_pic;
    void *ps_out_buffer;
    disp_op_t s_disp_op;
    struct {
        UWORD16 u2_frame_num;
    } s_cur_pic_poc;
    disp_frame_info_t s_disp_frame_info;
    UWORD32 u4_fmt_conv_cur_row;
    UWORD32 u4_start_recon_deblk;
    ref_pic_buf_t *ps_ref_pic_buf_lx[2][2];
    void (*pf_mvpred)(struct dec_struct_t *);
    void (*p_form_mb_part_info)(struct dec_struct_t *);
    void (*p_motion_compensate)(struct dec_struct_t *);
    void (*pf_mvpred_ref_tfr_nby2mb)(struct dec_struct_t *, UWORD32, UWORD32);
} dec_struct_t;

void ih264d_err_pic_dispbuf_mgr(dec_struct_t *ps_dec);
void ih264d_end_of_pic(dec_struct_t *ps_dec, UWORD8 u1_is_idr_slice, UWORD16 u2_frame_num);
void ih264d_mvpred_nonmbaff(dec_struct_t *ps_dec);
void ih264d_form_mb_part_info_bp(dec_struct_t *ps_dec);
void ih264d_motion_compensate_bp(dec_struct_t *ps_dec);
WORD32 ih264d_start_of_pic(dec_struct_t *ps_dec, WORD32 poc, pocstruct_t *ps_cur_poc, UWORD16 u2_frame_num, pps_t *pps);
void ih264d_get_next_display_field(dec_struct_t *ps_dec, void *ps_out_buffer, disp_op_t *s_disp_op);
void *ithread_create(void *handle, void *attr, void *(*start_routine)(void *), void *arg);
void ih264d_decode_picture_thread(void *ps_dec);
void ih264d_recon_deblk_thread(void *ps_dec);
void ih264d_get_mb_info_cavlc_mbaff(dec_struct_t *ps_dec, WORD32 i2_cur_mb_addr, dec_mb_info_t *ps_cur_mb_info, UWORD32 i2_mb_skip_run);
void ih264d_get_mb_info_cavlc_nonmbaff(dec_struct_t *ps_dec, WORD32 i2_cur_mb_addr, dec_mb_info_t *ps_cur_mb_info, UWORD32 i2_mb_skip_run);
void ih264d_set_deblocking_parameters(deblk_mb_t *ps_cur_deblk_mb, dec_slice_params_t *ps_slice, UWORD8 u1_mb_ngbr_availablity, UWORD8 u1_cur_mb_fld_dec_flag);
void ih264d_update_nnz_for_skipmb(dec_struct_t *ps_dec, dec_mb_info_t *ps_cur_mb_info, UWORD32 u4_cavlc);
void ih264d_update_mbaff_left_nnz(dec_struct_t *ps_dec, dec_mb_info_t *ps_cur_mb_info);
void ih264d_parse_tfr_nmb(dec_struct_t *ps_dec, UWORD32 u1_mb_idx, UWORD32 u1_num_mbs, UWORD32 u1_num_mbs_next, UWORD32 u1_tfr_n_mb, UWORD32 u1_end_of_row);
void ih264d_decode_recon_tfr_nmb(dec_struct_t *ps_dec, UWORD32 u1_mb_idx, UWORD32 u1_num_mbs, UWORD32 u1_num_mbs_next, UWORD32 u1_tfr_n_mb, UWORD32 u1_end_of_row);
void ih264d_mv_pred_ref_tfr_nby2_pmb(dec_struct_t *ps_dec, UWORD32 u1_mb_idx, UWORD32 u1_num_mbs);
void ih264d_update_qp(dec_struct_t *ps_dec, WORD32 i1_qp_offset);
void H264_DEC_DEBUG_PRINT(const char *fmt, ...);