#include <stdint.h>

typedef uint16_t u16;

typedef struct {
    void *bs;
} SWFReader;

u16 gf_bs_read_u16_le(void *bs);
u16 swf_read_int(SWFReader *read, int bits);