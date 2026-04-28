#include <stdint.h>
#include <string.h>

#define START_CODE_LEN 32
#define SEQUENCE_HEADER_CODE 0x000001B3
#define MIN_WIDTH 16
#define MIN_HEIGHT 16
#define NUM_PELS_IN_BLOCK 64
#define MPEG2_MAX_FRAME_RATE_CODE 8

typedef uint16_t UWORD16;
typedef uint32_t UWORD32;
typedef uint8_t UWORD8;

typedef enum {
    IVD_ERROR_NONE = 0,
    IVD_RES_CHANGED = 1,
    IMPEG2D_FRM_HDR_START_CODE_NOT_FOUND = 2,
    IMPEG2D_FRM_HDR_DECODE_ERR = 3,
    IMPEG2D_UNSUPPORTED_DIMENSIONS = 4
} IMPEG2D_ERROR_CODES_T;

typedef struct stream_t {
    int dummy;
} stream_t;

typedef struct {
    UWORD16 u2_horizontal_size;
    UWORD16 u2_vertical_size;
    UWORD16 u2_create_max_width;
    UWORD16 u2_create_max_height;
    UWORD16 u2_reinit_max_width;
    UWORD16 u2_reinit_max_height;
    UWORD16 u2_aspect_ratio_info;
    UWORD16 u2_frame_rate_code;
    UWORD32 u4_frm_buf_stride;
    int i4_pic_count;
    UWORD8 au1_intra_quant_matrix[NUM_PELS_IN_BLOCK];
    UWORD8 au1_inter_quant_matrix[NUM_PELS_IN_BLOCK];
    UWORD8 u2_header_done;
    stream_t s_bit_stream;
} dec_state_t;

extern const UWORD8 gau1_impeg2_inv_scan_zig_zag[NUM_PELS_IN_BLOCK];
extern const UWORD8 gau1_impeg2_intra_quant_matrix_default[NUM_PELS_IN_BLOCK];
extern const UWORD8 gau1_impeg2_inter_quant_matrix_default[NUM_PELS_IN_BLOCK];

int impeg2d_bit_stream_nxt(stream_t *ps_stream, int len);
void impeg2d_bit_stream_flush(stream_t *ps_stream, int len);
UWORD16 impeg2d_bit_stream_get(stream_t *ps_stream, int bits);
int impeg2d_bit_stream_get_bit(stream_t *ps_stream);
void impeg2d_next_start_code(dec_state_t *ps_dec);
#define GET_MARKER_BIT(dec, stream) impeg2d_bit_stream_get_bit(stream)