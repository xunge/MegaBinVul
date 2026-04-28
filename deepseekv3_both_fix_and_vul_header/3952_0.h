#include <stdint.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define UINT32_MAX 4294967295U
#define NUM_BUFF_OVERSIZE_BYTES 3
#define TIFF_TMSIZE_T_MAX ((tmsize_t)(~(tmsize_t)0))
#define PRIu16 "hu"
#define TIFF_SSIZE_FORMAT "zd"

typedef int32_t tmsize_t;

struct image_data {
    uint32_t width;
    uint32_t length;
    uint16_t spp;
    uint16_t bps;
    float xres;
    float yres;
};

void TIFFError(const char* module, const char* fmt, ...);
void* limitMalloc(size_t size);
void _TIFFfree(void* ptr);
void _TIFFmemset(void* ptr, int val, size_t size);
int reverseSamples8bits(uint16_t spp, uint16_t bps, uint32_t width, unsigned char* src, unsigned char* dst);
int reverseSamples16bits(uint16_t spp, uint16_t bps, uint32_t width, unsigned char* src, unsigned char* dst);
int reverseSamples24bits(uint16_t spp, uint16_t bps, uint32_t width, unsigned char* src, unsigned char* dst);
int reverseSamples32bits(uint16_t spp, uint16_t bps, uint32_t width, unsigned char* src, unsigned char* dst);
int rotateContigSamples8bits(uint16_t rotation, uint16_t spp, uint16_t bps, uint32_t width, uint32_t length, uint32_t col, unsigned char* src, unsigned char* dst);
int rotateContigSamples16bits(uint16_t rotation, uint16_t spp, uint16_t bps, uint32_t width, uint32_t length, uint32_t col, unsigned char* src, unsigned char* dst);
int rotateContigSamples24bits(uint16_t rotation, uint16_t spp, uint16_t bps, uint32_t width, uint32_t length, uint32_t col, unsigned char* src, unsigned char* dst);
int rotateContigSamples32bits(uint16_t rotation, uint16_t spp, uint16_t bps, uint32_t width, uint32_t length, uint32_t col, unsigned char* src, unsigned char* dst);