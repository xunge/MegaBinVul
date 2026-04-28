#include <stdint.h>

#define START_CODE_PREFIX_LEN 24
#define Y_LUMA 0
#define U_CHROMA 1
#define V_CHROMA 2

typedef uint32_t UWORD32;
typedef uint16_t UWORD16;

typedef enum {
    IMPEG2D_INVALID_VERT_SIZE,
    IVD_ERROR_NONE
} IMPEG2D_ERROR_CODES_T;

typedef struct stream_t {
    uint32_t u4_offset;
    uint32_t u4_max_offset;
} stream_t;

typedef struct dec_state_t {
    stream_t s_bit_stream;
    uint16_t u2_num_vert_mb;
    uint16_t u2_mb_y;
    uint16_t u2_mb_x;
    uint16_t u2_first_mb;
    uint8_t u1_quant_scale;
    uint16_t u2_q_scale_type;
    uint16_t u2_intra_dc_precision;
    uint16_t u2_def_dc_pred[3];
    IMPEG2D_ERROR_CODES_T (*pf_decode_slice)(struct dec_state_t *);
} dec_state_t;

extern const uint8_t gau1_impeg2_non_linear_quant_scale[];

IMPEG2D_ERROR_CODES_T impeg2d_bit_stream_flush(stream_t *ps_stream, int len);
uint32_t impeg2d_bit_stream_get(stream_t *ps_stream, int bits);
uint32_t impeg2d_bit_stream_nxt(stream_t *ps_stream, int bits);
uint32_t impeg2d_bit_stream_get_bit(stream_t *ps_stream);
IMPEG2D_ERROR_CODES_T impeg2d_next_start_code(dec_state_t *ps_dec);