#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>

struct image_data {
    uint32_t width;
    uint32_t length;
    uint16_t bps;
    uint16_t spp;
};

struct pageseg {
    uint32_t x1;
    uint32_t y1;
    uint32_t x2;
    uint32_t y2;
};

#define _TIFFmemcpy memcpy
#define TIFFError fprintf