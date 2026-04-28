#include <stdint.h>

typedef uint32_t UWORD32;

typedef struct {
    void *pv_stream_buffer;
    uint32_t u4_num_Bytes;
} ivd_video_decode_ip_t;

typedef enum {
    IV_NA_FRAME,
    IV_I_FRAME,
    IV_P_FRAME,
    IV_B_FRAME
} IV_PIC_TYPE_T;

typedef struct {
    uint32_t u4_error_code;
    uint32_t u4_num_bytes_consumed;
    uint32_t u4_pic_ht;
    uint32_t u4_pic_wd;
    IV_PIC_TYPE_T e_pic_type;
    uint32_t u4_frame_decoded_flag;
} ivd_video_decode_op_t;

typedef struct {
    ivd_video_decode_ip_t s_ivd_video_decode_ip_t;
} impeg2d_video_decode_ip_t;

typedef struct {
    ivd_video_decode_op_t s_ivd_video_decode_op_t;
} impeg2d_video_decode_op_t;

typedef enum {
    IVD_ERROR_NONE,
    IV_SUCCESS,
    IMPEG2D_UNSUPPORTED_DIMENSIONS
} IMPEG2D_ERROR_CODES_T;

typedef struct {
    uint16_t u2_header_done;
    uint16_t u2_reinit_max_height;
    uint16_t u2_reinit_max_width;
    uint16_t u2_vertical_size;
    uint16_t u2_horizontal_size;
    void *s_bit_stream;
} dec_state_t;

#define SEQUENCE_HEADER_CODE 0

void impeg2d_bit_stream_init(void *s_bit_stream, void *pv_stream_buffer, uint32_t u4_num_Bytes);
uint32_t impeg2d_bit_stream_num_bits_read(void *s_bit_stream);
IMPEG2D_ERROR_CODES_T impeg2d_process_video_header(dec_state_t *ps_dec);
void impeg2d_next_code(dec_state_t *ps_dec, int code);