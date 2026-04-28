#include <stdint.h>

#define START_CODE_LEN 32
#define USER_DATA_START_CODE 0x000001B2
#define START_CODE_PREFIX_LEN 24
#define START_CODE_PREFIX 0x000001

typedef uint32_t UWORD32;

typedef struct {
    UWORD32 u4_offset;
    UWORD32 u4_max_offset;
} stream_t;

typedef struct {
    stream_t s_bit_stream;
} dec_state_t;

UWORD32 impeg2d_bit_stream_nxt(stream_t *ps_stream, int len);
void impeg2d_bit_stream_flush(stream_t *ps_stream, int bits);