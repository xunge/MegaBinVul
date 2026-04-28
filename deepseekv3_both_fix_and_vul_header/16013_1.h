#include <stdlib.h>
#include <stdint.h>

typedef uint32_t u32;

typedef struct {
    unsigned int cfg;
} GF_LASeRCodecInfo;

typedef struct {
    GF_LASeRCodecInfo *info;
    void *bs;
} GF_LASeRCodec;

#define GF_LSR_READ_INT(lsr, val, bits, name)

unsigned int lsr_read_vluimsbf5(GF_LASeRCodec *lsr, const char *name);
void gf_bs_read_long_int(void *bs, unsigned int len);