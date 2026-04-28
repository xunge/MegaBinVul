#include <stdint.h>
#include <stdio.h>

typedef int32_t GF_Err;
#define GF_OK 0
#define GF_NON_COMPLIANT_BITSTREAM 1

typedef uint8_t u8;

typedef struct {
    void *bs;
    uint32_t length;
    uint32_t width;
    uint32_t height;
    uint32_t frame_rate;
    uint32_t frame_count;
} SWFReader;

typedef struct {
    uint32_t w;
    uint32_t h;
} SWFRec;

uint8_t gf_bs_read_u8(void *bs);
uint32_t swf_get_32(SWFReader *read);
void swf_init_decompress(SWFReader *read);
void swf_get_rec(SWFReader *read, SWFRec *rc);
void swf_align(SWFReader *read);
uint16_t swf_get_16(SWFReader *read);

#define GF_LOG_INFO 0
#define GF_LOG_PARSER 0
void GF_LOG(int level, int category, const char *fmt, ...);