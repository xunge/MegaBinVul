#include <stdint.h>
#include <stddef.h>

typedef int32_t WORD32;
typedef uint32_t UWORD32;
typedef uint16_t UWORD16;
typedef uint8_t UWORD8;
typedef int32_t BOOL;

#define TRUE 1
#define FALSE 0
#define OK 0
#define P_SLICE 0
#define B_SLICE 1
#define P_MB 0
#define D_INTER_MB 0
#define MB_SKIP 0
#define PRED_16x16 0
#define PART_DIRECT_16x16 0
#define CAVLC 0
#define REJECT_CUR_PIC 0
#define MAX_NUM_PIC_PARAMS 32
#define MAX_FRAMES 16
#define PAD_MAP_IDX_POC 0
#define BASE_PROFILE_IDC 0
#define SUB_BLK_SIZE 16

typedef struct dec_struct_t dec_struct_t;
typedef struct pocstruct_t pocstruct_t;
typedef struct dec_bit_stream_t dec_bit_stream_t;
typedef struct dec_slice_params_t dec_slice_params_t;
typedef struct deblk_mb_t deblk_mb_t;
typedef struct dec_mb_info_t dec_mb_info_t;
typedef struct parse_pmbarams_t parse_pmbarams_t;
typedef struct parse_part_params_t parse_part_params_t;
typedef struct dec_slice_struct_t dec_slice_struct_t;
typedef struct dec_err_status_t dec_err_status_t;
typedef struct dpb_commands_t dpb_commands_t;
typedef struct sps_t sps_t;
typedef struct pps_t pps_t;
typedef struct dec_pic_buf_t dec_pic_buf_t;
typedef struct disp_op_t disp_op_t;
typedef struct disp_frame_info_t disp_frame_info_t;
typedef struct ithread_t ithread_t;

struct pocstruct_t {
    UWORD16 u2_frame_num;
};

struct dec_bit_stream_t {
    UWORD32 *pu4_buffer;
    UWORD32 u4_ofst;
};

struct dec_slice_params_t {
    UWORD16 u2_frame_num;
    UWORD8 u1_mbaff_frame_flag;
    UWORD8 u1_slice_type;
    UWORD8 u1_nal_ref_idc;
    UWORD8 u1_nal_unit_type;
    UWORD16 u2_first_mb_in_slice;
    int8_t i1_slice_alpha_c0_offset;
    int8_t i1_slice_beta_offset;
    UWORD8 u1_slice_qp;
    UWORD8 u1_field_pic_flag;
    UWORD16 u2_log2Y_crwd;
    UWORD32 u4_mbs_in_slice;
};

struct dec_mb_info_t {
    UWORD8 u1_mb_type;
    UWORD8 u1_mb_mc_mode;
    UWORD8 u1_cbp;
    UWORD16 u2_mby;
    UWORD16 u2_mbx;
    UWORD8 u1_mb_ngbr_availablity;
    UWORD8 u1_end_of_slice;
    UWORD8 u1_Mux;
    struct {
        UWORD8 u1_mb_type;
    } *ps_curmb;
};

struct deblk_mb_t {
    UWORD8 u1_mb_type;
    UWORD8 u1_mb_qp;
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
    void *pv_tu_coeff_data_start;
    volatile void **ppv_map_ref_idx_to_poc;
};

struct dec_err_status_t {
    UWORD8 u1_err_flag;
};

struct dpb_commands_t {
    UWORD8 u1_long_term_reference_flag;
};

struct sps_t {
    UWORD16 u2_max_mb_addr;
    UWORD8 u1_profile_idc;
    UWORD8 u1_num_ref_frames;
};

struct pps_t {
    UWORD8 u1_is_valid;
};

struct dec_pic_buf_t {
    WORD32 i4_poc;
    UWORD8 u1_pic_buf_id;
};

struct disp_op_t {
    UWORD32 u4_error_code;
};

struct disp_frame_info_t {
    UWORD32 u4_y_ht;
};

struct ithread_t {};

struct dec_struct_t {
    UWORD8 u1_mb_idx;
    UWORD16 u2_frm_wd_in_mbs;
    UWORD16 u2_frm_ht_in_mbs;
    dec_bit_stream_t *ps_bitstrm;
    dec_slice_params_t *ps_cur_slice;
    dec_err_status_t *ps_dec_err_status;
    dpb_commands_t *ps_dpb_cmds;
    UWORD8 u1_first_slice_in_stream;
    pocstruct_t s_cur_pic_poc;
    dec_pic_buf_t *ps_cur_pic;
    sps_t *ps_cur_sps;
    pps_t ps_pps[MAX_NUM_PIC_PARAMS];
    dec_pic_buf_t *ps_ref_pic_buf_lx[2][2];
    UWORD32 u4_output_present;
    disp_op_t s_disp_op;
    disp_frame_info_t s_disp_frame_info;
    UWORD32 u4_fmt_conv_cur_row;
    UWORD8 u1_separate_parse;
    UWORD32 u4_dec_thread_created;
    ithread_t *pv_dec_thread_handle;
    UWORD32 u4_num_cores;
    UWORD32 u4_app_disable_deblk_frm;
    UWORD8 i1_recon_in_thread3_flag;
    UWORD32 u4_bs_deblk_thread_created;
    ithread_t *pv_bs_deblk_thread_handle;
    UWORD32 u4_start_recon_deblk;
    UWORD32 u4_num_mbs_cur_nmb;
    dec_mb_info_t *ps_nmb_info;
    UWORD32 u4_num_mbs_prev_nmb;
    UWORD16 u2_mby;
    UWORD16 u2_mbx;
    UWORD8 u1_mb_ngbr_availablity;
    void *pv_parse_tu_coeff_data;
    void *pv_prev_mb_parse_tu_coeff_data;
    UWORD16 u2_cur_mb_addr;
    WORD32 i4_submb_ofst;
    UWORD8 u1_pr_sl_type;
    void (*pf_mvpred_ref_tfr_nby2mb)(dec_struct_t *, UWORD32, UWORD32);
    parse_part_params_t *ps_part;
    parse_part_params_t *ps_parse_part_params;
    UWORD16 u2_total_mbs_coded;
    UWORD8 u1_pic_decode_done;
    UWORD16 u2_cur_slice_num;
    dec_slice_struct_t *ps_dec_slice_buf;
    UWORD8 u1_slice_header_done;
    dec_slice_struct_t *ps_parse_cur_slice;
    WORD32 i2_prev_slice_mbx;
    WORD32 i2_prev_slice_mby;
    UWORD8 u1_qp;
    parse_pmbarams_t *ps_parse_mb_data;
    deblk_mb_t *ps_deblk_mbn;
    UWORD32 u4_num_pmbair;
    WORD32 i1_prev_mb_qp_delta;
    UWORD8 u1_sub_mb_num;
    UWORD8 u1_cur_mb_fld_dec_flag;
    UWORD32 u4_first_slice_in_pic;
    void *pv_map_ref_idx_to_poc_buf;
    UWORD16 u2_prv_frame_num;
    UWORD8 u1_recon_mb_grp;
    void *pv_proc_tu_coeff_data;
    void *ps_out_buffer;
    void (*pf_mvpred)(void);
    void (*p_form_mb_part_info)(void);
    void (*p_motion_compensate)(void);
    WORD32 i4_display_delay;
};

#define H264_DEC_DEBUG_PRINT(fmt, ...) 

WORD32 ih264d_err_pic_dispbuf_mgr(dec_struct_t *ps_dec);
WORD32 ih264d_end_of_pic(dec_struct_t *ps_dec, UWORD8 u1_is_idr_slice, UWORD16 u2_frame_num);
WORD32 ih264d_start_of_pic(dec_struct_t *ps_dec, WORD32 poc, pocstruct_t *ps_cur_poc, UWORD16 u2_frame_num, pps_t *pps);
WORD32 ih264d_get_next_display_field(dec_struct_t *ps_dec, void *ps_out_buffer, disp_op_t *s_disp_op);
WORD32 ithread_create(ithread_t *handle, void *attr, void *(*start_routine)(void *), void *arg);
WORD32 ih264d_parse_tfr_nmb(dec_struct_t *ps_dec, UWORD32 u1_mb_idx, UWORD32 u1_num_mbs, UWORD32 u1_num_mbs_next, UWORD32 u1_tfr_n_mb, UWORD32 u1_end_of_row);
WORD32 ih264d_decode_recon_tfr_nmb(dec_struct_t *ps_dec, UWORD32 u1_mb_idx, UWORD32 u1_num_mbs, UWORD32 u1_num_mbs_next, UWORD32 u1_tfr_n_mb, UWORD32 u1_end_of_row);
WORD32 ih264d_update_qp(dec_struct_t *ps_dec, WORD32 i_qp);
WORD32 ih264d_get_mb_info_cavlc_mbaff(dec_struct_t *ps_dec, WORD32 i2_cur_mb_addr, dec_mb_info_t *ps_cur_mb_info, UWORD32 i2_mb_skip_run);
WORD32 ih264d_get_mb_info_cavlc_nonmbaff(dec_struct_t *ps_dec, WORD32 i2_cur_mb_addr, dec_mb_info_t *ps_cur_mb_info, UWORD32 i2_mb_skip_run);
WORD32 ih264d_set_deblocking_parameters(deblk_mb_t *ps_cur_deblk_mb, dec_slice_params_t *ps_slice, UWORD8 u1_mb_ngbr_availablity, UWORD8 u1_cur_mb_fld_dec_flag);
WORD32 ih264d_update_nnz_for_skipmb(dec_struct_t *ps_dec, dec_mb_info_t *ps_cur_mb_info, UWORD32 u1_cavlc);
WORD32 ih264d_update_mbaff_left_nnz(dec_struct_t *ps_dec, dec_mb_info_t *ps_cur_mb_info);
WORD32 ih264d_mv_pred_ref_tfr_nby2_pmb(dec_struct_t *ps_dec, UWORD32 u1_mb_idx, UWORD32 u1_num_mbs);
WORD32 ih264d_mvpred_nonmbaff(void);
WORD32 ih264d_form_mb_part_info_bp(void);
WORD32 ih264d_motion_compensate_bp(void);
WORD32 ih264d_decode_picture_thread(void *arg);
WORD32 ih264d_recon_deblk_thread(void *arg);