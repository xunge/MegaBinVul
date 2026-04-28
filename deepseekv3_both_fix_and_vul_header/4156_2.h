#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define WORD32 int32_t
#define UWORD32 uint32_t
#define WORD16 int16_t
#define UWORD16 uint16_t
#define UWORD8 uint8_t
#define TRUE 1
#define FALSE 0
#define OK 0
#define MAX_NUM_PIC_PARAMS 256
#define MAX_FRAMES 16
#define PAD_MAP_IDX_POC 2
#define SUB_BLK_SIZE 16
#define P_SLICE 0
#define B_SLICE 1
#define MB_SKIP 0
#define PRED_16x16 0
#define PART_DIRECT_16x16 0
#define P_MB 0
#define D_INTER_MB 0
#define CAVLC 0
#define REJECT_CUR_PIC 1

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define H264_DEC_DEBUG_PRINT(fmt, ...) 

typedef struct dec_struct_t dec_struct_t;
typedef struct pocstruct_t {
    uint16_t u2_frame_num;
} pocstruct_t;
typedef struct dec_bit_stream_t dec_bit_stream_t;
typedef struct dec_slice_params_t dec_slice_params_t;
typedef struct deblk_mb_t deblk_mb_t;
typedef struct dec_mb_info_t dec_mb_info_t;
typedef struct parse_pmbarams_t parse_pmbarams_t;
typedef struct parse_part_params_t parse_part_params_t;
typedef struct dec_slice_struct_t dec_slice_struct_t;
typedef struct pic_param_set_t pic_param_set_t;
typedef struct ref_pic_buf_t ref_pic_buf_t;
typedef struct cur_pic_t cur_pic_t;
typedef struct seq_param_set_t seq_param_set_t;
typedef struct cur_mb_t cur_mb_t;

typedef struct {
    uint32_t u1_err_flag;
} dec_err_status_t;

typedef struct {
    uint32_t u4_error_code;
} disp_op_t;

typedef struct {
    uint32_t u4_y_ht;
} disp_frame_info_t;

struct dec_bit_stream_t {
    uint32_t* pu4_buffer;
    uint32_t u4_ofst;
};

struct pic_param_set_t {
    uint8_t u1_is_valid;
};

struct ref_pic_buf_t {
    uint8_t u1_pic_buf_id;
};

struct cur_pic_t {
    int32_t i4_poc;
};

struct seq_param_set_t {
    uint16_t u2_max_mb_addr;
};

struct cur_mb_t {
    uint8_t u1_mb_type;
};

struct dec_mb_info_t {
    uint8_t u1_mb_type;
    uint8_t u1_mb_mc_mode;
    uint8_t u1_cbp;
    uint8_t u1_end_of_slice;
    uint8_t u1_mb_ngbr_availablity;
    uint16_t u2_mby;
    uint16_t u2_mbx;
    uint8_t u1_Mux;
    cur_mb_t* ps_curmb;
};

struct deblk_mb_t {
    uint8_t u1_mb_type;
    uint8_t u1_mb_qp;
};

struct parse_pmbarams_t {
    uint8_t u1_num_part;
    uint8_t u1_isI_mb;
};

struct parse_part_params_t {
    uint8_t u1_is_direct;
    uint8_t u1_sub_mb_num;
};

struct dec_slice_params_t {
    uint8_t u1_mbaff_frame_flag;
    uint16_t u2_frame_num;
    uint8_t u1_field_pic_flag;
    uint16_t u2_first_mb_in_slice;
    uint8_t u1_slice_qp;
    uint8_t u1_slice_type;
    uint16_t u2_log2Y_crwd;
    uint32_t u4_mbs_in_slice;
    uint32_t u4_first_mb_in_slice;
    volatile void** ppv_map_ref_idx_to_poc;
    void* pv_tu_coeff_data_start;
    uint8_t slice_type;
};

struct dec_slice_struct_t {
    uint32_t u4_first_mb_in_slice;
    uint16_t u2_log2Y_crwd;
    uint8_t slice_type;
    void* pv_tu_coeff_data_start;
    volatile void** ppv_map_ref_idx_to_poc;
};

struct dec_struct_t {
    uint8_t u1_mb_idx;
    uint16_t u2_frm_wd_in_mbs;
    uint16_t u2_frm_ht_in_mbs;
    uint16_t u2_total_mbs_coded;
    uint16_t u2_cur_mb_addr;
    uint32_t u4_num_mbs_cur_nmb;
    uint32_t u4_num_mbs_prev_nmb;
    uint32_t u4_first_slice_in_pic;
    uint8_t u1_first_slice_in_stream;
    uint8_t u1_pic_decode_done;
    uint8_t u1_slice_header_done;
    uint8_t u1_qp;
    uint16_t u2_cur_slice_num;
    uint16_t u2_prv_frame_num;
    uint32_t u4_num_ref_frames_at_init;
    uint32_t u4_output_present;
    uint32_t u4_fmt_conv_cur_row;
    uint8_t u1_separate_parse;
    uint32_t u4_dec_thread_created;
    uint32_t u4_bs_deblk_thread_created;
    uint32_t u4_app_disable_deblk_frm;
    int32_t i1_recon_in_thread3_flag;
    uint32_t u4_num_cores;
    uint32_t u4_start_recon_deblk;
    uint8_t u1_recon_mb_grp;
    uint8_t u1_cur_mb_fld_dec_flag;
    uint8_t u1_pr_sl_type;
    uint8_t u1_mb_ngbr_availablity;
    uint16_t u2_mby;
    uint16_t u2_mbx;
    int32_t i2_prev_slice_mbx;
    int32_t i2_prev_slice_mby;
    int32_t i4_submb_ofst;
    int32_t i1_prev_mb_qp_delta;
    uint8_t u1_sub_mb_num;
    uint32_t u4_num_pmbair;
    dec_bit_stream_t* ps_bitstrm;
    dec_slice_params_t* ps_cur_slice;
    dec_slice_struct_t* ps_parse_cur_slice;
    dec_slice_struct_t* ps_dec_slice_buf;
    dec_mb_info_t* ps_nmb_info;
    deblk_mb_t* ps_deblk_mbn;
    parse_pmbarams_t* ps_parse_mb_data;
    parse_part_params_t* ps_parse_part_params;
    parse_part_params_t* ps_part;
    void* pv_parse_tu_coeff_data;
    void* pv_prev_mb_parse_tu_coeff_data;
    void* pv_proc_tu_coeff_data;
    void* pv_map_ref_idx_to_poc_buf;
    void* pv_dec_thread_handle;
    void* pv_bs_deblk_thread_handle;
    dec_err_status_t* ps_dec_err_status;
    pocstruct_t s_cur_pic_poc;
    disp_op_t s_disp_op;
    disp_frame_info_t s_disp_frame_info;
    void* ps_out_buffer;
    cur_pic_t* ps_cur_pic;
    pic_param_set_t ps_pps[MAX_NUM_PIC_PARAMS];
    ref_pic_buf_t* ps_ref_pic_buf_lx[2][2];
    seq_param_set_t* ps_cur_sps;
    void (*pf_mvpred)(dec_struct_t*);
    void (*p_form_mb_part_info)(dec_struct_t*);
    void (*p_motion_compensate)(dec_struct_t*);
    void (*pf_mvpred_ref_tfr_nby2mb)(dec_struct_t*, UWORD32, UWORD32);
};

void ih264d_err_pic_dispbuf_mgr(dec_struct_t* ps_dec);
void ih264d_end_of_pic(dec_struct_t* ps_dec, UWORD8 u1_is_idr_slice, UWORD16 u2_frame_num);
int ih264d_start_of_pic(dec_struct_t* ps_dec, WORD32 poc, pocstruct_t* ps_cur_poc, UWORD16 u2_frame_num, pic_param_set_t* pps);
void ih264d_get_next_display_field(dec_struct_t* ps_dec, void* ps_out_buffer, disp_op_t* ps_disp_op);
void ih264d_mvpred_nonmbaff(dec_struct_t* ps_dec);
void ih264d_form_mb_part_info_bp(dec_struct_t* ps_dec);
void ih264d_motion_compensate_bp(dec_struct_t* ps_dec);
void ih264d_mv_pred_ref_tfr_nby2_pmb(dec_struct_t* ps_dec, UWORD32 u1_mb_idx, UWORD32 u1_num_mbs);
void ih264d_parse_tfr_nmb(dec_struct_t* ps_dec, UWORD32 u1_mb_idx, UWORD32 u1_num_mbs, UWORD32 u1_num_mbs_next, UWORD32 u1_tfr_n_mb, UWORD32 u1_end_of_row);
void ih264d_decode_recon_tfr_nmb(dec_struct_t* ps_dec, UWORD32 u1_mb_idx, UWORD32 u1_num_mbs, UWORD32 u1_num_mbs_next, UWORD32 u1_tfr_n_mb, UWORD32 u1_end_of_row);
void ih264d_get_mb_info_cavlc_mbaff(dec_struct_t* ps_dec, WORD32 i2_cur_mb_addr, dec_mb_info_t* ps_cur_mb_info, UWORD32 i2_mb_skip_run);
void ih264d_get_mb_info_cavlc_nonmbaff(dec_struct_t* ps_dec, WORD32 i2_cur_mb_addr, dec_mb_info_t* ps_cur_mb_info, UWORD32 i2_mb_skip_run);
void ih264d_set_deblocking_parameters(deblk_mb_t* ps_cur_deblk_mb, dec_slice_params_t* ps_slice, UWORD8 u1_mb_ngbr_availablity, UWORD8 u1_cur_mb_fld_dec_flag);
void ih264d_update_nnz_for_skipmb(dec_struct_t* ps_dec, dec_mb_info_t* ps_cur_mb_info, UWORD32 u1_cavlc);
void ih264d_update_mbaff_left_nnz(dec_struct_t* ps_dec, dec_mb_info_t* ps_cur_mb_info);
void ih264d_update_qp(dec_struct_t* ps_dec, WORD32 i1_qp_delta);
void* ithread_create(void* pv_dec_thread_handle, void* unused, void* (*ih264d_decode_picture_thread)(void*), void* ps_dec);
void* ih264d_decode_picture_thread(void* ps_dec);
void* ih264d_recon_deblk_thread(void* ps_dec);