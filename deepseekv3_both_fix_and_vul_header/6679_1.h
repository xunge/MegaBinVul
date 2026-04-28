#include <stdint.h>
#include <stddef.h>

#define WORD32 int32_t
#define UWORD32 uint32_t
#define UWORD16 uint16_t
#define UWORD8 uint8_t
#define WORD16 int16_t
#define WORD8 int8_t

#define MAIN_PROFILE_IDC 77
#define BASE_PROFILE_IDC 66
#define HIGH_PROFILE_IDC 100
#define EXTENDED_PROFILE_IDC 88

#define ERROR_FEATURE_UNAVAIL -1
#define ERROR_INV_SPS_PPS_T -2
#define ERROR_INV_POC_TYPE_T -3
#define ERROR_NUM_REF -4
#define IVD_RES_CHANGED -5
#define IVD_STREAM_WIDTH_HEIGHT_NOT_SUPPORTED -6
#define OK 0

#define MAX_BITS_IN_FRAME_NUM 16
#define MAX_PIC_ORDER_CNT_TYPE 2
#define MAX_BITS_IN_POC_LSB 16
#define H264_MAX_REF_PICS 16
#define H264_MAX_FRAME_WIDTH 4096
#define H264_MAX_FRAME_HEIGHT 2304
#define H264_MIN_FRAME_WIDTH 16
#define H264_MIN_FRAME_HEIGHT 16
#define H264_MAX_FRAME_SIZE (H264_MAX_FRAME_WIDTH * H264_MAX_FRAME_HEIGHT)
#define MB_SIZE 16
#define PAD_LEN_Y_H 0
#define PAD_LEN_Y_V 0
#define PAD_LEN_UV_H 0
#define PAD_LEN_UV_V 0
#define YUV420SP_FACTOR 1
#define MASK_ERR_SEQ_SET_ID 0x80000000
#define TRUE 1

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    UWORD32 u4_ofst;
    UWORD32* pu4_buffer;
    UWORD32 u4_max_ofst;
} dec_bit_stream_t;

typedef struct {
    UWORD8 u1_profile_idc;
    UWORD8 u1_level_idc;
    UWORD8 u1_seq_parameter_set_id;
    UWORD8 u1_bits_in_frm_num;
    UWORD16 u2_u4_max_pic_num_minus1;
    UWORD8 u1_pic_order_cnt_type;
    UWORD8 u1_log2_max_pic_order_cnt_lsb_minus;
    UWORD32 i4_max_pic_order_cntLsb;
    UWORD8 u1_delta_pic_order_always_zero_flag;
    WORD32 i4_ofst_for_non_ref_pic;
    WORD32 i4_ofst_for_top_to_bottom_field;
    UWORD8 u1_num_ref_frames_in_pic_order_cnt_cycle;
    WORD32 i4_ofst_for_ref_frame[256];
    UWORD8 u1_num_ref_frames;
    UWORD8 u1_gaps_in_frame_num_value_allowed_flag;
    UWORD16 u2_frm_wd_in_mbs;
    UWORD16 u2_frm_ht_in_mbs;
    UWORD32 u2_max_mb_addr;
    UWORD32 u2_total_num_of_mbs;
    UWORD8 u1_frame_mbs_only_flag;
    UWORD8 u1_mb_aff_flag;
    UWORD8 u1_direct_8x8_inference_flag;
    UWORD8 u1_vui_parameters_present_flag;
    UWORD8 u1_is_valid;
    WORD32 i4_chroma_format_idc;
    WORD32 i4_bit_depth_luma_minus8;
    WORD32 i4_bit_depth_chroma_minus8;
    WORD32 i4_qpprime_y_zero_transform_bypass_flag;
    WORD32 i4_seq_scaling_matrix_present_flag;
    UWORD8 u1_seq_scaling_list_present_flag[8];
    UWORD8 u1_use_default_scaling_matrix_flag[8];
    WORD16 i2_scalinglist4x4[6][16];
    WORD16 i2_scalinglist8x8[2][64];
    struct {
        UWORD8 u1_bitstream_restriction_flag;
        UWORD32 u4_num_reorder_frames;
    } s_vui;
} dec_seq_params_t;

typedef struct {
    UWORD32 i4_header_decoded;
    UWORD8 u1_res_changed;
    UWORD32 u4_app_disp_width;
    UWORD32 u4_share_disp_buf;
    UWORD16 u2_pic_wd;
    UWORD16 u2_pic_ht;
    UWORD16 u2_disp_width;
    UWORD16 u2_disp_height;
    UWORD16 u2_frm_wd_y;
    UWORD16 u2_frm_ht_y;
    UWORD16 u2_frm_wd_uv;
    UWORD16 u2_frm_ht_uv;
    UWORD16 u2_crop_offset_y;
    UWORD16 u2_crop_offset_uv;
    UWORD16 u2_frm_wd_in_mbs;
    UWORD16 u2_frm_ht_in_mbs;
    void* pv_scratch_sps_pps;
    dec_seq_params_t* ps_cur_sps;
    dec_seq_params_t ps_sps[32];
    struct {
        UWORD8 u1_pad_len_y_v;
        UWORD8 u1_pad_len_cr_v;
    } s_pad_mgr;
} dec_struct_t;

#define SWITCHONTRACE
#define COPYTHECONTEXT(a, b)

UWORD8 ih264d_get_bits_h264(dec_bit_stream_t* ps_bitstrm, UWORD8 u1_num_bits);
UWORD8 ih264d_get_bit_h264(dec_bit_stream_t* ps_bitstrm);
UWORD32 ih264d_uev(UWORD32* pu4_bitstrm_ofst, UWORD32* pu4_bitstrm_buf);
WORD32 ih264d_sev(UWORD32* pu4_bitstrm_ofst, UWORD32* pu4_bitstrm_buf);
void ih264d_scaling_list(WORD16* pi2_scaling_list, WORD32 i4_size_of_scaling_list, UWORD8* pu1_use_default_scaling_matrix_flag, dec_bit_stream_t* ps_bitstrm);
WORD32 ih264d_parse_vui_parametres(void* ps_vui, dec_bit_stream_t* ps_bitstrm);
UWORD8 ih264d_correct_level_idc(UWORD8 u1_level_idc, UWORD32 u2_total_num_of_mbs);