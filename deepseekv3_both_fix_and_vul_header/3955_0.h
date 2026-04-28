#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BUFF_OVERSIZE_BYTES 3
#define PRIu16 "hu"

struct image_data {
    uint32_t width;
    uint32_t length;
    uint16_t spp;
    uint16_t bps;
    float xres;
    float yres;
};

extern void *_TIFFmalloc(size_t size);
extern void _TIFFfree(void *ptr);
extern void _TIFFmemset(void *ptr, int value, size_t size);
extern void TIFFError(const char *module, const char *fmt, ...);

extern int reverseSamples8bits(uint16_t spp, uint16_t bps, uint32_t width, unsigned char *src, unsigned char *dst);
extern int reverseSamples16bits(uint16_t spp, uint16_t bps, uint32_t width, unsigned char *src, unsigned char *dst);
extern int reverseSamples24bits(uint16_t spp, uint16_t bps, uint32_t width, unsigned char *src, unsigned char *dst);
extern int reverseSamples32bits(uint16_t spp, uint16_t bps, uint32_t width, unsigned char *src, unsigned char *dst);
extern int rotateContigSamples8bits(uint16_t rotation, uint16_t spp, uint16_t bps, uint32_t width, uint32_t length, uint32_t col, unsigned char *src, unsigned char *dst);
extern int rotateContigSamples16bits(uint16_t rotation, uint16_t spp, uint16_t bps, uint32_t width, uint32_t length, uint32_t col, unsigned char *src, unsigned char *dst);
extern int rotateContigSamples24bits(uint16_t rotation, uint16_t spp, uint16_t bps, uint32_t width, uint32_t length, uint32_t col, unsigned char *src, unsigned char *dst);
extern int rotateContigSamples32bits(uint16_t rotation, uint16_t spp, uint16_t bps, uint32_t width, uint32_t length, uint32_t col, unsigned char *src, unsigned char *dst);

static void *limitMalloc(size_t size) {
    return _TIFFmalloc(size);
}