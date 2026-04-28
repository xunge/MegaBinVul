#include <stdint.h>
#include <stddef.h>

#define UNUSED(x) (void)(x)
#define TRUE 1
#define FALSE 0
#define OK 0
#define ERROR_INV_SLICE_HDR_T -1
#define REJECT_CUR_PIC 1
#define P_SLICE 0
#define B_SLICE 1
#define MAX_NUM_PIC_PARAMS 32
#define MAX_FRAMES 16
#define PAD_MAP_IDX_POC 4
#define SUB_BLK_SIZE 16
#define PRED_16x16 0
#define PART_DIRECT_16x16 0
#define MB_SKIP 0
#define P_MB 0
#define D_INTER_MB 0
#define CAVLC 0

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MOD(a,b) ((a) % (b))
#define DIV(a,b) ((a) / (b))

typedef uint32_t UWORD32;
typedef uint16_t UWORD16;
typedef uint8_t UWORD8;
typedef int32_t WORD32;
typedef int16_t WORD16;
typedef int8_t WORD8;

typedef struct dec_bit_stream_t {
    UWORD32* pu4_buffer;
    UWORD32 u4_ofst;
} dec_bit_stream_t;

typedef struct dec_slice_params_t {
    UWORD32 u1_mbaff_frame_flag;
    UWORD16 u2_frame_num;
    UWORD32 u2_first_mb_in_slice;
    UWORD8 u1_slice_type;
    UWORD8 u1_nal_ref_idc;
    UWORD8 u1_nal_unit_type;
    UWORD8 u1_slice_qp;
    UWORD16 u2_log2Y_crwd;
    UWORD8 u1_field_pic_flag;
    WORD8 i1_slice_alpha_c0_offset;
    WORD8 i1_slice_beta_offset;
    UWORD32 u4_mbs_in_slice;
} dec_slice_params_t;

typedef struct deblk_mb_t {
    UWORD32 u1_mb_type;
    UWORD8 u1_mb_qp;
} deblk_mb_t;

typedef struct dec_mb_info_t {
    UWORD16 u2_mby;
    UWORD16 u2_mbx;
    UWORD8 u1_mb_ngbr_availablity;
    UWORD8 u1_mb_type;
    UWORD8 u1_mb_mc_mode;
    UWORD8 u1_cbp;
    UWORD8 u1_end_of_slice;
    UWORD8 u1_Mux;
    struct dec_mb_info_t* ps_curmb;
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
    volatile void** ppv_map_ref_idx_to_poc;
    void* pv_tu_coeff_data_start;
} dec_slice_struct_t;

typedef struct pocstruct_t {
    // Placeholder for POC structure
} pocstruct_t;

typedef struct dec_struct_t dec_struct_t;

typedef void (*PF_MVPRED_REF_TFR_NBY2MB)(dec_struct_t*, UWORD32, UWORD32);

struct dec_struct_t {
    UWORD32 u1_mb_idx;
    UWORD16 u2_frm_wd_in_mbs;
    dec_bit_stream_t* ps_bitstrm;
    dec_slice_params_t* ps_cur_slice;
    struct {
        UWORD32 u1_err_flag;
    }* ps_dec_err_status;
    struct {
        UWORD8 u1_long_term_reference_flag;
    }* ps_dpb_cmds;
    struct {
        UWORD32 i4_poc;
    }* ps_cur_pic;
    struct {
        UWORD8 u1_is_valid;
        struct {
            UWORD8 u1_is_valid;
        }* ps_sps;
    } ps_pps[MAX_NUM_PIC_PARAMS];
    UWORD32 u4_pic_buf_got;
    void* pv_map_ref_idx_to_poc_buf;
    UWORD16 u2_cur_slice_num;
    UWORD32 u4_num_mbs_cur_nmb;
    UWORD16 u2_cur_mb_addr;
    UWORD32 u4_num_mbs_prev_nmb;
    UWORD16 u2_mby;
    UWORD16 u2_mbx;
    UWORD8 u1_mb_ngbr_availablity;
    void* pv_parse_tu_coeff_data;
    void* pv_prev_mb_parse_tu_coeff_data;
    UWORD8 u1_pr_sl_type;
    UWORD32 u2_total_mbs_coded;
    UWORD16 u2_frm_ht_in_mbs;
    UWORD8 u1_pic_decode_done;
    UWORD8 u1_slice_header_done;
    UWORD8 u1_qp;
    UWORD8 u1_separate_parse;
    UWORD32 u4_dec_thread_created;
    void* pv_dec_thread_handle;
    UWORD32 u4_num_cores;
    UWORD32 u4_app_disable_deblk_frm;
    UWORD8 i1_recon_in_thread3_flag;
    UWORD32 u4_bs_deblk_thread_created;
    void* pv_bs_deblk_thread_handle;
    UWORD32 u4_start_recon_deblk;
    UWORD32 u4_first_slice_in_pic;
    dec_slice_struct_t* ps_dec_slice_buf;
    dec_slice_struct_t* ps_parse_cur_slice;
    UWORD16 u2_prv_frame_num;
    void* pv_proc_tu_coeff_data;
    UWORD32 u4_num_ref_frames_at_init;
    UWORD32 u1_recon_mb_grp;
    UWORD32 u4_num_pmbair;
    dec_mb_info_t* ps_nmb_info;
    deblk_mb_t* ps_deblk_mbn;
    parse_pmbarams_t* ps_parse_mb_data;
    parse_part_params_t* ps_part;
    parse_part_params_t* ps_parse_part_params;
    struct {
        UWORD16 u2_max_mb_addr;
    }* ps_cur_sps;
    struct {
        UWORD32 u4_error_code;
    } s_disp_op;
    struct {
        UWORD32 u4_y_ht;
    } s_disp_frame_info;
    UWORD32 u4_fmt_conv_cur_row;
    UWORD32 u4_output_present;
    void* ps_out_buffer;
    WORD32 i2_prev_slice_mbx;
    WORD32 i2_prev_slice_mby;
    WORD32 i4_submb_ofst;
    void* (*pf_mvpred)(void);
    void* (*p_form_mb_part_info)(void);
    void* (*p_motion_compensate)(void);
    PF_MVPRED_REF_TFR_NBY2MB pf_mvpred_ref_tfr_nby2mb;
    struct {
        UWORD8 u1_pic_buf_id;
    }* ps_ref_pic_buf_lx[2][2];
    WORD8 i1_prev_mb_qp_delta;
    UWORD8 u1_sub_mb_num;
    UWORD8 u1_cur_mb_fld_dec_flag;
};

// Function prototypes
void ih264d_err_pic_dispbuf_mgr(dec_struct_t* ps_dec);
void* ih264d_mvpred_nonmbaff(void);
void* ih264d_form_mb_part_info_bp(void);
void* ih264d_motion_compensate_bp(void);
WORD32 ih264d_start_of_pic(dec_struct_t* ps_dec, WORD32 poc, pocstruct_t* ps_cur_poc, UWORD16 u2_frame_num, void* pps);
void ih264d_get_next_display_field(dec_struct_t* ps_dec, void* ps_out_buffer, void* ps_disp_op);
int ithread_create(void* handle, void* attr, void* (*start_routine)(void*), void* arg);
void* ih264d_decode_picture_thread(void* arg);
void* ih264d_recon_deblk_thread(void* arg);
void ih264d_parse_tfr_nmb(dec_struct_t* ps_dec, UWORD32 u1_mb_idx, UWORD32 u1_num_mbs, UWORD32 u1_num_mbs_next, UWORD32 u1_tfr_n_mb, UWORD32 u1_end_of_row);
void ih264d_decode_recon_tfr_nmb(dec_struct_t* ps_dec, UWORD32 u1_mb_idx, UWORD32 u1_num_mbs, UWORD32 u1_num_mbs_next, UWORD32 u1_tfr_n_mb, UWORD32 u1_end_of_row);
void ih264d_get_mb_info_cavlc_mbaff(dec_struct_t* ps_dec, WORD32 i2_cur_mb_addr, dec_mb_info_t* ps_cur_mb_info, WORD32 i2_mb_skip_run);
void ih264d_get_mb_info_cavlc_nonmbaff(dec_struct_t* ps_dec, WORD32 i2_cur_mb_addr, dec_mb_info_t* ps_cur_mb_info, WORD32 i2_mb_skip_run);
void ih264d_set_deblocking_parameters(deblk_mb_t* ps_cur_deblk_mb, dec_slice_params_t* ps_slice, UWORD8 u1_mb_ngbr_availablity, UWORD8 u1_cur_mb_fld_dec_flag);
void ih264d_update_nnz_for_skipmb(dec_struct_t* ps_dec, dec_mb_info_t* ps_cur_mb_info, UWORD8 u1_cavlc);
void ih264d_update_mbaff_left_nnz(dec_struct_t* ps_dec, dec_mb_info_t* ps_cur_mb_info);
void ih264d_update_qp(dec_struct_t* ps_dec, WORD32 i1_qp_delta);
void ih264d_mv_pred_ref_tfr_nby2_pmb(dec_struct_t* ps_dec, UWORD32 u1_mb_idx, UWORD32 u1_num_mbs);
void H264_DEC_DEBUG_PRINT(const char* fmt, ...);