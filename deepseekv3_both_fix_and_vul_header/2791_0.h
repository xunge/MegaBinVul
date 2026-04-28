#include <stdint.h>

typedef uint32_t u32;

typedef struct {
    void* bs;
} SWFReader;

u32 gf_bs_read_u32_le(void* bs);
u32 swf_read_int(SWFReader* read, int bits);