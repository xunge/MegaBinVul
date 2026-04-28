#include <stdint.h>

typedef uint32_t UWORD32;

typedef struct {
    UWORD32 u4_offset;
    UWORD32 u4_max_offset;
} stream_t;

typedef struct {
    stream_t s_bit_stream;
} dec_state_t;

#define START_CODE_LEN 32

UWORD32 impeg2d_bit_stream_nxt(stream_t *ps_stream, UWORD32 u4_num_bits);
void impeg2d_bit_stream_flush_to_byte_boundary(stream_t *ps_stream);
UWORD32 impeg2d_bit_stream_get(stream_t *ps_stream, UWORD32 u4_num_bits);