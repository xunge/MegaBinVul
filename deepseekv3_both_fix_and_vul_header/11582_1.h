#include <stdint.h>
#include <string.h>

#define MAX_BITSTREAM_BUFFER_SIZE 1024

typedef uint32_t UWORD32;
typedef uint16_t UWORD16;
typedef uint8_t UWORD8;

typedef enum {
    IVD_ERROR_NONE,
    IV_SUCCESS,
    IMPEG2D_UNSUPPORTED_DIMENSIONS
} IMPEG2D_ERROR_CODES_T;

typedef enum {
    SEQUENCE_HEADER_CODE,
    IV_NA_FRAME
} IMPEG2D_CODES_T;

typedef struct {
    UWORD32 u4_num_Bytes;
    void *pv_stream_buffer;
} ivd_video_decode_ip_t;

typedef struct {
    UWORD32 u4_error_code;
    UWORD32 u4_num_bytes_consumed;
    UWORD32 u4_pic_ht;
    UWORD32 u4_pic_wd;
    IMPEG2D_ERROR_CODES_T e_pic_type;
    UWORD32 u4_frame_decoded_flag;
} ivd_video_decode_op_t;

typedef struct {
    ivd_video_decode_ip_t s_ivd_video_decode_ip_t;
} impeg2d_video_decode_ip_t;

typedef struct {
    ivd_video_decode_op_t s_ivd_video_decode_op_t;
} impeg2d_video_decode_op_t;

typedef struct {
    UWORD8 *pu1_input_buffer;
    UWORD32 u4_frm_buf_stride;
    UWORD16 u2_vertical_size;
    UWORD16 u2_horizontal_size;
    UWORD16 u2_reinit_max_height;
    UWORD16 u2_reinit_max_width;
    UWORD16 u2_header_done;
    struct {
        UWORD8 *pu1_input_buffer;
        UWORD32 u4_size;
    } s_bit_stream;
} dec_state_t;

void impeg2d_bit_stream_init(void *stream, UWORD8 *buffer, UWORD32 size);
UWORD32 impeg2d_bit_stream_num_bits_read(void *stream);
IMPEG2D_ERROR_CODES_T impeg2d_process_video_header(dec_state_t *ps_dec);
void impeg2d_next_code(dec_state_t *ps_dec, IMPEG2D_CODES_T code);