#include <stdint.h>
#include <string.h>

typedef enum {
    IMPEG2D_FRM_HDR_START_CODE_NOT_FOUND,
    IMPEG2D_UNSUPPORTED_DIMENSIONS,
    IMPEG2D_FRM_HDR_DECODE_ERR,
    IVD_RES_CHANGED,
    IVD_ERROR_NONE
} IMPEG2D_ERROR_CODES_T;

typedef uint16_t UWORD16;
typedef uint32_t UWORD32;
typedef uint8_t UWORD8;

typedef struct stream_t {
    // Add necessary stream_t members here
} stream_t;

typedef struct {
    uint16_t u2_horizontal_size;
    uint16_t u2_vertical_size;
    uint16_t u2_header_done;
    uint32_t u4_frm_buf_stride;
    uint16_t u2_create_max_width;
    uint16_t u2_create_max_height;
    uint16_t u2_reinit_max_width;
    uint16_t u2_reinit_max_height;
    uint16_t u2_aspect_ratio_info;
    uint16_t u2_frame_rate_code;
    uint8_t au1_intra_quant_matrix[64];
    uint8_t au1_inter_quant_matrix[64];
    stream_t s_bit_stream;
} dec_state_t;

#define START_CODE_LEN 32
#define SEQUENCE_HEADER_CODE 0x000001B3
#define MPEG2_MAX_FRAME_RATE_CODE 8
#define NUM_PELS_IN_BLOCK 64

extern uint8_t gau1_impeg2_inv_scan_zig_zag[64];
extern uint8_t gau1_impeg2_intra_quant_matrix_default[64];
extern uint8_t gau1_impeg2_inter_quant_matrix_default[64];

uint32_t impeg2d_bit_stream_nxt(stream_t *ps_stream, uint32_t bits);
void impeg2d_bit_stream_flush(stream_t *ps_stream, uint32_t bits);
uint16_t impeg2d_bit_stream_get(stream_t *ps_stream, uint32_t bits);
uint32_t impeg2d_bit_stream_get_bit(stream_t *ps_stream);
void impeg2d_next_start_code(dec_state_t *ps_dec);
#define GET_MARKER_BIT(dec, stream) impeg2d_bit_stream_get_bit(stream)
#define SET_IVD_FATAL_ERROR(err) err