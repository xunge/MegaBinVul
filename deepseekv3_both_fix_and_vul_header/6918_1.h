#include <stdint.h>
#include <stdio.h>

typedef uint8_t u8;

typedef struct {
    void *bs;
    uint32_t length;
    double width;
    double height;
    uint16_t frame_rate;
    uint16_t frame_count;
} SWFReader;

typedef struct {
    double w;
    double h;
} SWFRec;

typedef enum {
    GF_OK,
    GF_NON_COMPLIANT_BITSTREAM,
    GF_URL_ERROR
} GF_Err;

enum {
    GF_LOG_INFO,
    GF_LOG_PARSER
};

uint8_t gf_bs_read_u8(void *bs);
uint32_t swf_get_32(SWFReader *read);
void swf_init_decompress(SWFReader *read);
void swf_get_rec(SWFReader *read, SWFRec *rc);
void swf_align(SWFReader *read);
uint16_t swf_get_16(SWFReader *read);
void GF_LOG(int log_level, int log_category, const char *format, ...);