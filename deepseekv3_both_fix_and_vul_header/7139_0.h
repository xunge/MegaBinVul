#include <stdint.h>
#include <inttypes.h>

struct image_data {
    uint32_t width;
    uint32_t length;
    uint16_t bps;
    uint16_t spp;
};

struct region {
    uint32_t x1;
    uint32_t y1;
    uint32_t x2;
    uint32_t y2;
    uint32_t width;
    uint32_t length;
    unsigned char *buffptr;
};

struct crop_mask {
    struct region *regionlist;
};

typedef uint16_t tsample_t;

extern int extractContigSamplesBytes(unsigned char *src, unsigned char *dst, uint32_t img_width, tsample_t sample, uint16_t spp, uint16_t bps, tsample_t count, uint32_t first_col, uint32_t last_col);
extern int extractContigSamplesShifted8bits(unsigned char *src, unsigned char *dst, uint32_t img_width, tsample_t sample, uint16_t spp, uint16_t bps, tsample_t count, uint32_t first_col, uint32_t last_col, int prev_trailing_bits);
extern int extractContigSamplesShifted16bits(unsigned char *src, unsigned char *dst, uint32_t img_width, tsample_t sample, uint16_t spp, uint16_t bps, tsample_t count, uint32_t first_col, uint32_t last_col, int prev_trailing_bits);
extern int extractContigSamplesShifted24bits(unsigned char *src, unsigned char *dst, uint32_t img_width, tsample_t sample, uint16_t spp, uint16_t bps, tsample_t count, uint32_t first_col, uint32_t last_col, int prev_trailing_bits);
extern int extractContigSamplesShifted32bits(unsigned char *src, unsigned char *dst, uint32_t img_width, tsample_t sample, uint16_t spp, uint16_t bps, tsample_t count, uint32_t first_col, uint32_t last_col, int prev_trailing_bits);
extern void TIFFError(const char *module, const char *fmt, ...);