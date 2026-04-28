#include <stdint.h>

#define MB_ESCAPE_CODE_LEN 11
#define MB_ESCAPE_CODE 0x8
#define MB_ADDR_INCR_LEN 11
#define MB_ADDR_INCR_OFFSET 1

typedef uint16_t UWORD16;

typedef struct {
    uint32_t u4_offset;
    uint32_t u4_max_offset;
} stream_t;

extern int impeg2d_bit_stream_nxt(stream_t *ps_stream, int len);
extern void impeg2d_bit_stream_flush(stream_t *ps_stream, int len);
extern int impeg2d_dec_vld_symbol(stream_t *ps_stream, const int *table, int len);
extern const int gai2_impeg2d_mb_addr_incr[];