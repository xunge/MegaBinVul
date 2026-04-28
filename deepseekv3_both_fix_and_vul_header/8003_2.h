#include <stdint.h>
#include <stddef.h>

typedef int32_t WORD32;
typedef uint32_t UWORD32;
typedef uint16_t UWORD16;
typedef uint8_t UWORD8;
typedef int8_t WORD8;

#define MAX_NUM_PIC_PARAMS 32
#define MAX_FRAMES 16
#define PAD_MAP_IDX_POC 2
#define SUB_BLK_SIZE 16
#define REJECT_CUR_PIC 1
#define OK 0
#define TRUE 1
#define P_SLICE 5
#define B_SLICE 6
#define P_MB 1
#define D_INTER_MB 1
#define MB_SKIP 0
#define PRED_16x16 0
#define PART_DIRECT_16x16 0
#define CAVLC 0
#define BASE_PROFILE_IDC 66

typedef struct dec_struct_t dec_struct_t;
typedef struct pocstruct_t pocstruct_t;
typedef struct dec_bit_stream_t dec_bit_stream_t;
typedef struct dec_slice_params_t dec_slice_params_t;
typedef struct deblk_mb_t deblk_mb_t;
typedef struct dec_mb_info_t dec_mb_info_t;
typedef struct parse_pmbarams_t parse_pmbarams_t;
typedef struct parse_part_params_t parse_part_params_t;
typedef struct dec_slice_struct_t dec_slice_struct_t;
typedef struct dec_sps_t dec_sps_t;
typedef struct dec_pic_buf_t dec_pic_buf_t;
typedef struct disp_op_t disp_op_t;
typedef struct disp_frame_info_t disp_frame_info_t;
typedef struct dec_pps_t dec_pps_t;
typedef struct dec_err_status_t dec_err_status_t;
typedef struct cur_mb_t cur_mb_t;

struct dec_bit_stream_t {
    UWORD32 *pu4_buffer;
    UWORD32 u4_ofst;
};

struct dec_slice_params_t {
    UWORD16 u2_frame_num;
    UWORD8 u1_mbaff_frame_flag;
    UWORD8 u1_bottom_field_flag;
    UWORD8 u1_field_pic_flag;
    UWORD8 u1_slice_type;
    UWORD8 u1_nal_ref_idc;
    UWORD8 u1_nal_unit_type;
    WORD8 i1_slice_alpha_c0_offset;
    WORD8 i1_slice_beta_offset;
    UWORD8 u1_slice_qp;
    UWORD16 u2_log2Y_crwd;
    UWORD32 u4_mbs_in_slice;
    UWORD16 u2_first_mb_in_slice;
};

struct dec_mb_info_t {
    UWORD16 u2_mby;
    UWORD16 u2_mbx;
    UWORD8 u1_mb_ngbr_availablity;
    UWORD8 u1_end_of_slice;
    UWORD8 u1_mb_type;
    UWORD8 u1_mb_mc_mode;
    UWORD8 u1_cbp;
    UWORD8 u1_Mux;
    cur_mb_t *ps_curmb;
};

struct parse_pmbarams_t {
    UWORD8 u1_num_part;
    UWORD8 u1_isI_mb;
};

struct parse_part_params_t {
    UWORD8 u1_is_direct;
    UWORD8 u1_sub_mb_num;
};

struct dec_slice_struct_t {
    UWORD32 u4_first_mb_in_slice;
    UWORD16 u2_log2Y_crwd;
    UWORD8 slice_type;
    volatile void **ppv_map_ref_idx_to_poc;
    void *pv_tu_coeff_data_start;
};

struct disp_op_t {
    UWORD32 u4_error_code;
};

struct disp_frame_info_t {
    UWORD32 u4_y_ht;
};

struct dec_pic_buf_t {
    UWORD8 u1_pic_buf_id;
    WORD32 i4_poc;
};

struct dec_sps_t {
    UWORD8 u1_num_ref_frames;
    UWORD8 u1_profile_idc;
    UWORD16 u2_max_mb_addr;
};

struct dec_pps_t {
    UWORD8 u1_is_valid;
};

struct deblk_mb_t {
    UWORD8 u1_mb_type;
    UWORD8 u1_mb_qp;
};

struct dec_err_status_t {
    UWORD8 u1_err_flag;
};

struct pocstruct_t {
    UWORD16 u2_frame_num;
};

struct cur_mb_t {
    UWORD8 u1_mb_type;
};

struct dec_struct_t {
    UWORD8 u1_mb_idx;
    UWORD8 u1_recon_mb_grp;
    UWORD16 u2_frm_wd_in_mbs;
    UWORD16 u2_frm_ht_in_mbs;
    UWORD32 u4_num_mbs_cur_nmb;
    UWORD32 u4_num_mbs_prev_nmb;
    UWORD16 u2_mby;
    UWORD16 u2_mbx;
    UWORD16 u2_prv_frame_num;
    UWORD8 u1_mb_ngbr_availablity;
    void *pv_parse_tu_coeff_data;
    void *pv_prev_mb_parse_tu_coeff_data;
    UWORD32 u2_cur_mb_addr;
    WORD32 i4_submb_ofst;
    UWORD8 u1_pr_sl_type;
    UWORD8 u1_first_slice_in_stream;
    UWORD8 u1_pic_decode_done;
    UWORD8 u1_slice_header_done;
    UWORD8 u1_qp;
    UWORD8 u1_separate_parse;
    UWORD8 u1_cur_mb_fld_dec_flag;
    UWORD8 u1_recon_in_thread3_flag;
    UWORD8 u1_app_disable_deblk_frm;
    UWORD32 u4_app_disable_deblk_frm;
    UWORD32 u4_dec_thread_created;
    UWORD32 u4_bs_deblk_thread_created;
    UWORD32 u4_start_recon_deblk;
    UWORD32 u4_num_cores;
    UWORD32 u4_output_present;
    UWORD32 u4_fmt_conv_cur_row;
    UWORD32 u4_first_slice_in_pic;
    UWORD16 u2_cur_slice_num;
    UWORD16 u2_total_mbs_coded;
    WORD32 i2_prev_slice_mbx;
    WORD32 i2_prev_slice_mby;
    WORD32 i1_prev_mb_qp_delta;
    WORD32 i1_recon_in_thread3_flag;
    WORD32 i4_display_delay;
    WORD32 u1_sub_mb_num;
    WORD32 u4_num_pmbair;
    dec_bit_stream_t *ps_bitstrm;
    dec_slice_params_t *ps_cur_slice;
    dec_mb_info_t *ps_nmb_info;
    parse_pmbarams_t *ps_parse_mb_data;
    parse_part_params_t *ps_parse_part_params;
    parse_part_params_t *ps_part;
    deblk_mb_t *ps_deblk_mbn;
    dec_slice_struct_t *ps_dec_slice_buf;
    dec_slice_struct_t *ps_parse_cur_slice;
    dec_sps_t *ps_cur_sps;
    dec_pic_buf_t *ps_ref_pic_buf_lx[2][2];
    dec_pic_buf_t *ps_cur_pic;
    disp_op_t s_disp_op;
    disp_frame_info_t s_disp_frame_info;
    pocstruct_t s_cur_pic_poc;
    dec_pps_t ps_pps[MAX_NUM_PIC_PARAMS];
    void *pv_dec_thread_handle;
    void *pv_bs_deblk_thread_handle;
    dec_err_status_t *ps_dec_err_status;
    void *ps_out_buffer;
    void *pv_proc_tu_coeff_data;
    void *pv_map_ref_idx_to_poc_buf;
    void (*pf_mvpred)(dec_struct_t *);
    void (*pf_mvpred_ref_tfr_nby2mb)(dec_struct_t *, UWORD32, UWORD32);
    void (*p_form_mb_part_info)(dec_struct_t *);
    void (*p_motion_compensate)(dec_struct_t *);
};

#define H264_DEC_DEBUG_PRINT(fmt, ...) 

void ih264d_err_pic_dispbuf_mgr(dec_struct_t *);
void ih264d_end_of_pic(dec_struct_t *, UWORD8, UWORD16);
void ih264d_mvpred_nonmbaff(dec_struct_t *);
void ih264d_form_mb_part_info_bp(dec_struct_t *);
void ih264d_motion_compensate_bp(dec_struct_t *);
WORD32 ih264d_start_of_pic(dec_struct_t *, WORD32, pocstruct_t *, UWORD16, dec_pps_t *);
void ih264d_get_next_display_field(dec_struct_t *, void *, disp_op_t *);
void ih264d_update_qp(dec_struct_t *, WORD32);
void ih264d_get_mb_info_cavlc_mbaff(dec_struct_t *, WORD32, dec_mb_info_t *, WORD32);
void ih264d_get_mb_info_cavlc_nonmbaff(dec_struct_t *, WORD32, dec_mb_info_t *, WORD32);
void ih264d_set_deblocking_parameters(deblk_mb_t *, dec_slice_params_t *, UWORD8, UWORD8);
void ih264d_update_nnz_for_skipmb(dec_struct_t *, dec_mb_info_t *, WORD32);
void ih264d_update_mbaff_left_nnz(dec_struct_t *, dec_mb_info_t *);
void ih264d_parse_tfr_nmb(dec_struct_t *, UWORD32, UWORD32, UWORD32, UWORD32, UWORD32);
void ih264d_decode_recon_tfr_nmb(dec_struct_t *, UWORD32, UWORD32, UWORD32, UWORD32, UWORD32);
void ih264d_mv_pred_ref_tfr_nby2_pmb(dec_struct_t *, UWORD32, UWORD32);
void *ithread_create(void *, void *, void *, void *);
void ih264d_decode_picture_thread(void *);
void ih264d_recon_deblk_thread(void *);