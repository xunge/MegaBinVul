#include <stdint.h>
#include <string.h>
#include <stddef.h>

typedef int32_t WORD32;
typedef uint32_t UWORD32;
typedef uint8_t UWORD8;

#define OK 0
#define IV_SUCCESS 0
#define IV_FAIL -1
#define IDR_SLICE_NAL 5
#define NUM_FRAMES_LIMIT 1000
#define MAX_DISP_BUFS_NEW 16
#define FMT_CONV_NUM_ROWS 16
#define ERROR_FRAME_LIMIT_OVER 1
#define ERROR_START_CODE_NOT_FOUND 2
#define ERROR_INCOMPLETE_FRAME 3
#define ERROR_DANGLING_FIELD_IN_PIC 4
#define ERROR_IN_LAST_SLICE_OF_PIC 5
#define ERROR_UNAVAIL_PICBUF_T 6
#define ERROR_UNAVAIL_MVBUF_T 7
#define IVD_RES_CHANGED 8
#define IVD_MEM_ALLOC_FAILED 9
#define IVD_DEC_FRM_BS_BUF_NULL 10
#define IVD_DEC_NUMBYTES_INV 11
#define IVD_DISP_FRM_ZERO_OP_BUFS 12
#define IVD_DISP_FRM_OP_BUF_NULL 13
#define IVD_DISP_FRM_ZERO_OP_BUF_SIZE 14
#define IVD_DEC_REF_BUF_NULL 15
#define IVD_DEC_FRM_SKIPPED 16
#define IVD_INSUFFICIENTDATA 17
#define IVD_UNSUPPORTEDPARAM 18
#define ERROR_DYNAMIC_RESOLUTION_NOT_SUPPORTED 19
#define IV_NA_FRAME 0
#define IV_IDR_FRAME 1
#define IV_I_FRAME 2
#define IV_P_FRAME 3
#define IV_B_FRAME 4
#define B_SLICE 0
#define P_SLICE 1
#define I_SLICE 2
#define TOP_FIELD_ONLY 1
#define BOT_FIELD_ONLY 2
#define REJECT_CUR_PIC 1
#define BUF_MGR_IO 1
#define IVD_SKIP_B 1
#define IVD_DECODE_FRAME_OUT 1

typedef struct ivd_video_decode_op_t {
    uint32_t u4_error_code;
    uint32_t u4_num_bytes_consumed;
    int32_t e_pic_type;
    uint32_t u4_output_present;
    uint32_t u4_frame_decoded_flag;
    uint32_t u4_pic_wd;
    uint32_t u4_pic_ht;
    uint32_t u4_new_seq;
    uint32_t u4_progressive_frame_flag;
    uint32_t e_output_format;
    uint32_t s_disp_frm_buf;
    uint32_t e4_fld_type;
    uint32_t u4_ts;
    uint32_t u4_disp_buf_id;
    uint32_t u4_is_ref_flag;
    uint32_t u4_size;
    uint32_t u4_num_bufs;
    uint8_t **pu1_bufs;
    uint32_t *u4_min_out_buf_size;
} ivd_video_decode_op_t;

typedef struct ivd_video_decode_ip_t {
    void *pv_stream_buffer;
    uint32_t u4_num_Bytes;
    uint32_t u4_ts;
    uint32_t u4_size;
    struct {
        uint32_t u4_num_bufs;
        uint8_t **pu1_bufs;
        uint32_t *u4_min_out_buf_size;
    } s_out_buffer;
} ivd_video_decode_ip_t;

typedef struct sps_t {
    uint32_t u1_is_valid;
    uint32_t u1_frame_mbs_only_flag;
    uint32_t u1_mb_aff_flag;
    uint32_t u2_max_mb_addr;
} sps_t;

typedef struct slice_t {
    uint8_t u1_field_pic_flag;
    uint8_t u1_bottom_field_flag;
    uint32_t u2_frame_num;
    uint32_t u1_nal_unit_type;
} slice_t;

typedef struct dec_err_status_t {
    uint32_t u1_err_flag;
} dec_err_status_t;

typedef struct disp_frame_info_t {
    uint32_t u4_y_ht;
} disp_frame_info_t;

typedef struct disp_op_t {
    uint32_t u4_error_code;
    uint32_t u4_progressive_frame_flag;
    uint32_t e_output_format;
    uint32_t s_disp_frm_buf;
    uint32_t e4_fld_type;
    uint32_t u4_ts;
    uint32_t u4_disp_buf_id;
} disp_op_t;

typedef struct dec_struct_t {
    uint32_t u2_disp_width;
    uint32_t u2_disp_height;
    uint32_t u2_frm_wd_in_mbs;
    uint32_t u2_frm_ht_in_mbs;
    uint32_t u2_pic_wd;
    uint32_t u2_pic_ht;
    uint32_t u4_nmb_deblk;
    uint32_t u4_start_recon_deblk;
    uint32_t u4_cur_bs_mb_num;
    uint32_t u4_cur_deblk_mb_num;
    uint32_t u4_num_cores;
    uint32_t u1_pic_bufs;
    uint32_t *u4_disp_buf_mapping;
    uint32_t *u4_disp_buf_to_be_freed;
    uint32_t u4_total_frames_decoded;
    uint32_t u1_flushfrm;
    uint32_t u1_init_dec_flag;
    uint32_t u4_share_disp_buf;
    uint32_t u1_res_changed;
    uint32_t u1_separate_parse;
    uint32_t u4_prev_nal_skipped;
    uint32_t u4_slice_start_code_found;
    uint32_t u1_pic_decode_done;
    uint32_t u4_output_present;
    uint32_t u1_top_bottom_decoded;
    uint32_t init_done;
    uint32_t i4_header_decoded;
    uint32_t i4_decode_header;
    uint32_t i4_error_code;
    uint32_t u4_pic_buf_got;
    uint32_t u4_return_to_app;
    uint32_t u4_first_slice_in_pic;
    uint32_t u1_slice_header_done;
    uint32_t u1_dangling_field;
    uint32_t u4_dec_thread_created;
    uint32_t u4_bs_deblk_thread_created;
    uint32_t i4_frametype;
    uint32_t i4_content_type;
    uint32_t i4_pic_type;
    uint32_t u1_nal_unit_type;
    uint32_t u4_fmt_conv_cur_row;
    uint32_t u4_fmt_conv_num_rows;
    uint32_t u2_total_mbs_coded;
    uint32_t u2_cur_mb_addr;
    uint32_t u2_cur_slice_num;
    uint32_t cur_dec_mb_num;
    uint32_t cur_recon_mb_num;
    uint32_t u4_ts;
    uint32_t u4_dynamic_bits_buf_size;
    uint32_t u4_static_bits_buf_size;
    void *pv_codec_handle;
    void *pv_mem_ctxt;
    void *pv_pic_buf_mgr;
    void *pv_dec_out;
    uint8_t *pu1_bits_buf_dynamic;
    uint8_t *pu1_bits_buf_static;
    ivd_video_decode_op_t *ps_out_buffer;
    sps_t *ps_cur_sps;
    sps_t *ps_sps;
    slice_t *ps_cur_slice;
    dec_err_status_t *ps_dec_err_status;
    disp_frame_info_t s_disp_frame_info;
    disp_op_t s_disp_op;
    struct {
        uint32_t u1_mb_aff_flag;
    } s_pad_mgr;
    uint32_t i4_app_skip_mode;
    uint32_t e_frm_out_mode;
    void* (*pf_aligned_alloc)(void*, uint32_t, uint32_t);
} dec_struct_t;

typedef struct iv_obj_t {
    void *pv_codec_handle;
} iv_obj_t;

typedef struct out_buf_t {
    uint32_t u4_num_bufs;
    uint8_t **pu1_bufs;
    uint32_t *u4_min_out_buf_size;
} out_buf_t;

typedef struct tfr_ctxt_t {
    uint32_t u4_num_mbs;
} tfr_ctxt_t;

typedef struct pad_mgr_t {
} pad_mgr_t;

typedef struct buf_mgr_t {
} buf_mgr_t;

typedef struct pic_buffer_t {
} pic_buffer_t;

typedef struct pocstruct_t {
} pocstruct_t;

#define NAL_REF_IDC(x) ((x) >> 5)
#define DATA_SYNC() 
#define RETURN_IF(cond, ret) if (cond) return ret
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define H264_DEC_DEBUG_PRINT(fmt, ...)
#define DEBUG_THREADS_PRINTF(fmt)
#define DEBUG_PERF_PRINTF(fmt, ...)

void ih264d_init_decoder(dec_struct_t *ps_dec);
void ih264d_get_next_display_field(dec_struct_t *ps_dec, out_buf_t *ps_out_buffer, disp_op_t *ps_disp_op);
void ih264d_format_convert(dec_struct_t *ps_dec, disp_op_t *ps_disp_op, uint32_t u4_fmt_conv_cur_row, uint32_t u4_fmt_conv_num_rows);
void ih264d_release_display_field(dec_struct_t *ps_dec, disp_op_t *ps_disp_op);
void ih264d_fill_output_struct_from_context(dec_struct_t *ps_dec, ivd_video_decode_op_t *ps_dec_op);
void ih264d_signal_decode_thread(dec_struct_t *ps_dec);
void ih264d_signal_bs_deblk_thread(dec_struct_t *ps_dec);
int32_t ih264d_find_start_code(uint8_t *pu1_buf, uint32_t u4_start_ofst, uint32_t u4_max_ofst, uint32_t *pu4_length_of_start_code, uint32_t *pu4_next_is_aud);
int32_t ih264d_parse_nal_unit(iv_obj_t *dec_hdl, ivd_video_decode_op_t *ps_dec_op, uint8_t *pu1_bitstrm_buf, int32_t buflen);
int32_t ih264d_mark_err_slice_skip(dec_struct_t *ps_dec, int32_t num_mb_skipped, int32_t is_idr_slice, uint32_t u2_frame_num, pocstruct_t *temp_poc, int32_t prev_slice_err);
int32_t ih264d_deblock_display(dec_struct_t *ps_dec);
void ih264d_init_deblk_tfr_ctxt(dec_struct_t *ps_dec, pad_mgr_t *ps_pad_mgr, tfr_ctxt_t *ps_tfr_cxt, uint32_t u2_frm_wd_in_mbs, uint32_t u4_deblk_mode);
void ih264d_check_mb_map_deblk(dec_struct_t *ps_dec, uint32_t u4_num_mbs, tfr_ctxt_t *ps_tfr_cxt, uint32_t u4_deblk_mode);
void* ih264_buf_mgr_get_next_free(buf_mgr_t *pv_pic_buf_mgr, int32_t *pi4_id);
void ih264_buf_mgr_set_status(buf_mgr_t *pv_pic_buf_mgr, int32_t i4_id, uint32_t u4_status);
void ih264_buf_mgr_release(buf_mgr_t *pv_pic_buf_mgr, int32_t i4_id, uint32_t u4_status);
void ithread_set_name(void* name);
uint32_t ih264d_map_error(int32_t error);