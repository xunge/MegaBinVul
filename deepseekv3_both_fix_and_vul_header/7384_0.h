#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct image_data {
    uint32_t width;
    uint32_t length;
    uint16_t bps;
    uint16_t spp;
};

struct pageseg {
    uint32_t x1;
    uint32_t x2;
    uint32_t y1;
    uint32_t y2;
};

#define DEVELMODE
#define _TIFFmemcpy memcpy
#define TIFFError printf
#define PRIu32 "u"
#define PRIu16 "u"