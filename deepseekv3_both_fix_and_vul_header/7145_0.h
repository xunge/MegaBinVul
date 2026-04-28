#include <stdint.h>
#include <stdio.h>

struct image_data {
    uint32_t width;
    uint32_t length;
    uint16_t bps;
    uint16_t spp;
};

struct crop_mask {
    uint32_t selections;
    uint32_t combined_width;
    uint32_t combined_length;
    int edge_ref;
    struct {
        uint32_t x1;
        uint32_t y1;
        uint32_t x2;
        uint32_t y2;
        uint32_t width;
        uint32_t length;
        unsigned char *buffptr;
    } *regionlist;
};

typedef int tsample_t;

#define EDGE_TOP 0
#define EDGE_BOTTOM 1
#define EDGE_LEFT 2
#define EDGE_RIGHT 3

#define PRIu32 "u"
#define PRIu16 "hu"

extern int extractContigSamplesBytes(unsigned char *src, unsigned char *dst, uint32_t img_width, tsample_t sample, uint16_t spp, uint16_t bps, tsample_t count, uint32_t first_col, uint32_t last_col);
extern int extractContigSamplesShifted8bits(unsigned char *src, unsigned char *dst, uint32_t img_width, tsample_t sample, uint16_t spp, uint16_t bps, tsample_t count, uint32_t first_col, uint32_t last_col, uint32_t prev_trailing_bits);
extern int extractContigSamplesShifted16bits(unsigned char *src, unsigned char *dst, uint32_t img_width, tsample_t sample, uint16_t spp, uint16_t bps, tsample_t count, uint32_t first_col, uint32_t last_col, uint32_t prev_trailing_bits);
extern int extractContigSamplesShifted24bits(unsigned char *src, unsigned char *dst, uint32_t img_width, tsample_t sample, uint16_t spp, uint16_t bps, tsample_t count, uint32_t first_col, uint32_t last_col, uint32_t prev_trailing_bits);
extern int extractContigSamplesShifted32bits(unsigned char *src, unsigned char *dst, uint32_t img_width, tsample_t sample, uint16_t spp, uint16_t bps, tsample_t count, uint32_t first_col, uint32_t last_col, uint32_t prev_trailing_bits);

void TIFFError(const char *module, const char *fmt, ...);