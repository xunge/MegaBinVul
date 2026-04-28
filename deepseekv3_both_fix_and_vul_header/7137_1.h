#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

typedef unsigned short tsample_t;

struct image_data {
    uint32_t width;
    uint32_t length;
    uint16_t bps;
    uint16_t spp;
};

struct crop_mask {
    uint32_t combined_width;
    uint32_t combined_length;
    uint32_t selections;
    int edge_ref;
    struct {
        uint32_t x1;
        uint32_t x2;
        uint32_t y1;
        uint32_t y2;
        uint32_t width;
        uint32_t length;
        unsigned char *buffptr;
    } *regionlist;
};

enum {
    EDGE_TOP,
    EDGE_BOTTOM,
    EDGE_LEFT,
    EDGE_RIGHT
};

extern int extractContigSamplesBytes(unsigned char *src, unsigned char *dst, 
                                   uint32_t img_width, tsample_t sample, 
                                   uint16_t spp, uint16_t bps, tsample_t count, 
                                   uint32_t start_col, uint32_t end_col);
extern int extractContigSamplesShifted8bits(unsigned char *src, unsigned char *dst, 
                                          uint32_t img_width, tsample_t sample, 
                                          uint16_t spp, uint16_t bps, tsample_t count, 
                                          uint32_t start_col, uint32_t end_col, 
                                          uint32_t trailing_bits);
extern int extractContigSamplesShifted16bits(unsigned char *src, unsigned char *dst, 
                                           uint32_t img_width, tsample_t sample, 
                                           uint16_t spp, uint16_t bps, tsample_t count, 
                                           uint32_t start_col, uint32_t end_col, 
                                           uint32_t trailing_bits);
extern int extractContigSamplesShifted24bits(unsigned char *src, unsigned char *dst, 
                                           uint32_t img_width, tsample_t sample, 
                                           uint16_t spp, uint16_t bps, tsample_t count, 
                                           uint32_t start_col, uint32_t end_col, 
                                           uint32_t trailing_bits);
extern int extractContigSamplesShifted32bits(unsigned char *src, unsigned char *dst, 
                                           uint32_t img_width, tsample_t sample, 
                                           uint16_t spp, uint16_t bps, tsample_t count, 
                                           uint32_t start_col, uint32_t end_col, 
                                           uint32_t trailing_bits);
extern void TIFFError(const char *module, const char *fmt, ...);