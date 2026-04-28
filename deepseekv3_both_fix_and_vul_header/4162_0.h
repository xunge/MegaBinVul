#include <stdint.h>

typedef struct {
    uint32_t u4_offset;
    uint32_t u4_max_offset;
} stream_t;

typedef struct {
    stream_t s_bit_stream;
} dec_state_t;

#define START_CODE_PREFIX 0x000001
#define START_CODE_PREFIX_LEN 24

void impeg2d_bit_stream_flush_to_byte_boundary(stream_t *);
uint32_t impeg2d_bit_stream_nxt(stream_t *, int);
uint32_t impeg2d_bit_stream_get(stream_t *, int);