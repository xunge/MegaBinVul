#include <stdint.h>

#define WORD32 int32_t
#define UWORD32 uint32_t
#define UWORD8 uint8_t
#define OK 0
#define ERROR_INCOMPLETE_FRAME -1
#define ERROR_INV_SPS_PPS_T -2
#define REJECT_CUR_PIC 0x1

#define NAL_FORBIDDEN_BIT(x) ((x) & 0x80)
#define NAL_UNIT_TYPE(x) ((x) & 0x1F)
#define NAL_REF_IDC(x) (((x) >> 5) & 0x3)

#define IDR_SLICE_NAL 5
#define SLICE_NAL 1
#define SLICE_DATA_PARTITION_A_NAL 2
#define SLICE_DATA_PARTITION_B_NAL 3
#define SLICE_DATA_PARTITION_C_NAL 4
#define SEI_NAL 6
#define SEQ_PARAM_NAL 7
#define PIC_PARAM_NAL 8
#define ACCESS_UNIT_DELIMITER_RBSP 9
#define END_OF_STREAM_RBSP 10
#define FILLER_DATA_NAL 12

typedef struct iv_obj_t {
    void *pv_codec_handle;
} iv_obj_t;

typedef struct ivd_video_decode_op_t {
    uint32_t u4_frame_decoded_flag;
} ivd_video_decode_op_t;

typedef struct ivd_video_decode_ip_t {
    // placeholder for decode input params
} ivd_video_decode_ip_t;

typedef struct dec_bit_stream_t {
    // placeholder for bitstream structure
} dec_bit_stream_t;

typedef struct dec_err_status_t {
    uint8_t u1_err_flag;
} dec_err_status_t;

typedef struct dec_slice_params_t {
    // placeholder for slice parameters
} dec_slice_params_t;

typedef struct dec_struct_t {
    void *pv_dec_in;
    dec_slice_params_t *ps_cur_slice;
    dec_bit_stream_t *ps_bitstrm;
    uint16_t u2_total_mbs_coded;
    uint8_t u1_nal_unit_type;
    int32_t i4_decode_header;
    int32_t i4_header_decoded;
    uint32_t u4_slice_start_code_found;
    uint32_t u4_first_slice_in_pic;
    dec_err_status_t *ps_dec_err_status;
} dec_struct_t;

#define H264_DEC_DEBUG_PRINT(...)
#define DEBUG_THREADS_PRINTF(...)
#define SWITCHOFFTRACE

void ih264d_process_nal_unit(dec_bit_stream_t *ps_bitstrm, UWORD8 *pu1_buf, UWORD32 u4_length);
UWORD8 ih264d_get_bits_h264(dec_bit_stream_t *ps_bitstrm, UWORD8 u1_num_bits);
void ih264d_parse_slice_partition(dec_struct_t *ps_dec, dec_bit_stream_t *ps_bitstrm);
void ih264d_rbsp_to_sodb(dec_bit_stream_t *ps_bitstrm);
WORD32 ih264d_parse_decode_slice(UWORD8 u1_is_idr, UWORD8 u1_nal_ref_idc, dec_struct_t *ps_dec);
WORD32 ih264d_parse_sei_message(dec_struct_t *ps_dec, dec_bit_stream_t *ps_bitstrm);
void ih264d_parse_sei(dec_struct_t *ps_dec, dec_bit_stream_t *ps_bitstrm);
WORD32 ih264d_parse_sps(dec_struct_t *ps_dec, dec_bit_stream_t *ps_bitstrm);
WORD32 ih264d_parse_pps(dec_struct_t *ps_dec, dec_bit_stream_t *ps_bitstrm);
void ih264d_access_unit_delimiter_rbsp(dec_struct_t *ps_dec);
void ih264d_parse_end_of_stream(dec_struct_t *ps_dec);
void ih264d_parse_filler_data(dec_struct_t *ps_dec, dec_bit_stream_t *ps_bitstrm);