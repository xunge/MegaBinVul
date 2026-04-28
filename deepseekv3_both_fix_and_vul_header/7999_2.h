#include <string.h>
#include <stddef.h>

typedef int WORD32;
typedef unsigned int UWORD32;
typedef unsigned char UWORD8;
typedef unsigned short UWORD16;
typedef char WORD8;
typedef short WORD16;

#define DEFAULT_SEPARATE_PARSE 0
#define IVD_SKIP_NONE 0
#define MAX_NUM_PIC_PARAMS 32
#define MAX_NUM_SEQ_PARAMS 32
#define ACCEPT_ALL_PICS 0
#define PIC_TYPE_UNKNOWN 0
#define SYNC_FRM_DEFAULT 0
#define INIT_FRAME 0
#define SKIP_NONE 0
#define MAX_DISP_BUFS_NEW 16

#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef struct pred_info_t {
    UWORD8 dummy[64];  // Placeholder for actual structure
} pred_info_t;

typedef struct disp_mgr_t {
    UWORD8 dummy[128]; // Placeholder for actual structure
} disp_mgr_t;

typedef struct buf_mgr_t {
    UWORD8 dummy[256]; // Placeholder for actual structure
} buf_mgr_t;

typedef struct dec_err_status_t {
    UWORD8 u1_err_flag;
    UWORD8 u1_cur_pic_type;
    UWORD32 u4_frm_sei_sync;
    UWORD32 u4_cur_frm;
    UWORD8 u1_pic_aud_i;
} dec_err_status_t;

typedef struct sei {
    UWORD8 u1_is_valid;
    UWORD8 dummy[127]; // Placeholder for other fields
} sei;

typedef struct dpb_commands_t {
    UWORD8 dummy[64];  // Placeholder for actual structure
} dpb_commands_t;

typedef struct dec_bit_stream_t {
    void *pv_codec_handle;
    UWORD8 dummy[128]; // Placeholder for other fields
} dec_bit_stream_t;

typedef struct dec_slice_params_t {
    void *pv_codec_handle;
    UWORD8 u1_mbaff_frame_flag;
    UWORD8 u1_mmco_equalto5;
    UWORD16 u2_frame_num;
    UWORD8 dummy[124]; // Placeholder for other fields
} dec_slice_params_t;

typedef struct dec_seq_params_t {
    UWORD8 dummy[256]; // Placeholder for actual structure
} dec_seq_params_t;

typedef struct dec_pic_params_t {
    UWORD8 dummy[256]; // Placeholder for actual structure
} dec_pic_params_t;

typedef struct ctxt_inc_mb_info_t {
    UWORD8 dummy[64];  // Placeholder for actual structure
} ctxt_inc_mb_info_t;

typedef struct neighbouradd_t {
    UWORD8 dummy[16];  // Placeholder for actual structure
} neighbouradd_t;

typedef struct disp_buf_t {
    UWORD8 dummy[64];  // Placeholder for actual structure
} disp_buf_t;

typedef struct dpb_mgr_t {
    void *pv_codec_handle;
    UWORD8 dummy[128]; // Placeholder for other fields
} dpb_mgr_t;

typedef struct pocstruct_t {
    WORD32 i4_pic_order_cnt_lsb;
    WORD32 i4_pic_order_cnt_msb;
    WORD32 i4_delta_pic_order_cnt_bottom;
    WORD32 i4_delta_pic_order_cnt[2];
    UWORD8 u1_mmco_equalto5;
    WORD32 i4_top_field_order_count;
    WORD32 i4_bottom_field_order_count;
    UWORD8 u1_bot_field;
    WORD32 i4_prev_frame_num_ofst;
} pocstruct_t;

typedef struct cabac_env_t {
    void *pv_codec_handle;
    const UWORD32 *cabac_table;
} cabac_env_t;

typedef struct dec_struct_t {
    pred_info_t *ps_pred;
    void *pv_disp_buf_mgr;
    void *pv_pic_buf_mgr;
    dec_err_status_t *ps_dec_err_status;
    sei *ps_sei;
    dpb_commands_t *ps_dpb_cmds;
    dec_bit_stream_t *ps_bitstrm;
    dec_slice_params_t *ps_cur_slice;
    void *pv_scratch_sps_pps;
    ctxt_inc_mb_info_t *ps_left_mb_ctxt_info;
    neighbouradd_t *ps_left_mvpred_addr;
    void *pv_mv_buf_mgr;
    
    UWORD32 init_done;
    UWORD32 u4_num_cores;
    UWORD16 u2_pic_ht;
    UWORD16 u2_pic_wd;
    UWORD8 u1_separate_parse;
    UWORD32 u4_app_disable_deblk_frm;
    WORD32 i4_degrade_type;
    WORD32 i4_degrade_pics;
    WORD32 i4_app_skip_mode;
    WORD32 i4_dec_skip_mode;
    
    dec_pic_params_t *ps_pps;
    dec_seq_params_t *ps_sps;
    void (*p_DeblockPicture[2])(struct dec_struct_t *);
    cabac_env_t s_cab_dec_env;
    UWORD32 u4_num_fld_in_frm;
    dpb_mgr_t *ps_dpb_mgr;
    
    dec_pic_params_t *ps_cur_pps;
    dec_seq_params_t *ps_cur_sps;
    UWORD8 u1_init_dec_flag;
    UWORD8 u1_first_slice_in_stream;
    UWORD8 u1_first_pb_nal_in_pic;
    UWORD8 u1_last_pic_not_decoded;
    UWORD32 u4_app_disp_width;
    WORD32 i4_header_decoded;
    UWORD32 u4_total_frames_decoded;
    
    WORD32 i4_error_code;
    WORD32 i4_content_type;
    
    UWORD8 u1_pr_sl_type;
    UWORD16 u2_mbx;
    UWORD16 u2_mby;
    UWORD16 u2_total_mbs_coded;
    
    pocstruct_t s_prev_pic_poc;
    pocstruct_t s_cur_pic_poc;
    
    WORD32 i4_max_poc;
    WORD32 i4_prev_max_display_seq;
    UWORD8 u1_recon_mb_grp;
    
    UWORD8 u1_second_field;
    struct {
        UWORD8 u1_eoseq_pending;
    } s_prev_seq_params;
    
    UWORD16 u2_crop_offset_y;
    UWORD16 u2_crop_offset_uv;
    
    WORD32 i4_vui_frame_rate;
    WORD32 i4_pic_type;
    WORD32 i4_frametype;
    
    UWORD8 u1_res_changed;
    UWORD8 u1_frame_decoded_flag;
    UWORD32 u4_skip_frm_mask;
    
    void (*pf_cavlc_4x4res_block[3])(struct dec_struct_t *);
    void (*pf_cavlc_parse4x4coeff[2])(struct dec_struct_t *);
    void (*pf_cavlc_parse_8x8block[4])(struct dec_struct_t *);
    
    void (*pf_fill_bs1[2][2])(struct dec_struct_t *);
    void (*pf_fill_bs_xtra_left_edge[2])(struct dec_struct_t *);
    
    UWORD16 u2_prv_frame_num;
    UWORD8 u1_top_bottom_decoded;
    UWORD8 u1_dangling_field;
    
    UWORD8 u1_left_mv_ctxt_inc_arr[1];
    WORD8 i1_left_ref_idx_ctx_inc_arr[1][1];
    UWORD8 u1_yuv_dc_csbp_topmb;
    UWORD8 *pu1_left_mv_ctxt_inc;
    WORD8 *pi1_left_ref_idx_ctxt_inc;
    UWORD8 *pu1_left_yuv_dc_csbp;
    
    UWORD8 u1_flushfrm;
    
    disp_buf_t disp_bufs[MAX_DISP_BUFS_NEW];
    UWORD32 u4_disp_buf_mapping[MAX_DISP_BUFS_NEW];
    UWORD32 u4_disp_buf_to_be_freed[MAX_DISP_BUFS_NEW];
    
    enum {
        IVD_DISPLAY_FRAME_OUT
    } e_frm_out_mode;
} dec_struct_t;

extern const UWORD32 gau4_ih264d_cabac_table[];
size_t ithread_get_mutex_lock_size(void);
void ih264d_free_dynamic_bufs(dec_struct_t *ps_dec);
void ih264d_deblock_picture_non_mbaff(dec_struct_t *ps_dec);
void ih264d_deblock_picture_mbaff(dec_struct_t *ps_dec);
void ih264d_cavlc_4x4res_block_totalcoeff_1(dec_struct_t *ps_dec);
void ih264d_cavlc_4x4res_block_totalcoeff_2to10(dec_struct_t *ps_dec);
void ih264d_cavlc_4x4res_block_totalcoeff_11to16(dec_struct_t *ps_dec);
void ih264d_cavlc_parse4x4coeff_n0to7(dec_struct_t *ps_dec);
void ih264d_cavlc_parse4x4coeff_n8(dec_struct_t *ps_dec);
void ih264d_cavlc_parse_8x8block_none_available(dec_struct_t *ps_dec);
void ih264d_cavlc_parse_8x8block_left_available(dec_struct_t *ps_dec);
void ih264d_cavlc_parse_8x8block_top_available(dec_struct_t *ps_dec);
void ih264d_cavlc_parse_8x8block_both_available(dec_struct_t *ps_dec);
void ih264d_fill_bs1_16x16mb_pslice(dec_struct_t *ps_dec);
void ih264d_fill_bs1_non16x16mb_pslice(dec_struct_t *ps_dec);
void ih264d_fill_bs1_16x16mb_bslice(dec_struct_t *ps_dec);
void ih264d_fill_bs1_non16x16mb_bslice(dec_struct_t *ps_dec);
void ih264d_fill_bs_xtra_left_edge_cur_frm(dec_struct_t *ps_dec);
void ih264d_fill_bs_xtra_left_edge_cur_fld(dec_struct_t *ps_dec);
void ih264d_init_ref_bufs(dpb_mgr_t *ps_dpb_mgr);
void ih264d_init_arch(dec_struct_t *ps_dec);
void ih264d_init_function_ptr(dec_struct_t *ps_dec);