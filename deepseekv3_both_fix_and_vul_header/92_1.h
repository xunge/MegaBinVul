#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

#define MAX_SECTIONS 1000
#define PAGE_MODE_MARGINS 0x01
#define PAGE_MODE_ROWSCOLS 0x02
#define PAGE_MODE_PAPERSIZE 0x04

#define RESUNIT_NONE 1
#define RESUNIT_INCH 2
#define RESUNIT_CENTIMETER 3

#define ORIENTATION_NONE 0
#define ORIENTATION_PORTRAIT 1
#define ORIENTATION_LANDSCAPE 2
#define ORIENTATION_AUTO 3

struct crop_mask {
    uint32_t combined_width;
    uint32_t combined_length;
};

struct image_data {
    uint32_t width;
    uint32_t length;
    uint16_t res_unit;
    float xres;
    float yres;
    uint16_t bps;
    uint16_t spp;
};

struct pagedef {
    char *name;
    uint16_t res_unit;
    double width;
    double length;
    double hres;
    double vres;
    double hmargin;
    double vmargin;
    uint32_t mode;
    uint32_t rows;
    uint32_t cols;
    uint32_t orient;
};

struct pageseg {
    uint32_t x1;
    uint32_t x2;
    uint32_t y1;
    uint32_t y2;
    uint32_t buffsize;
    uint32_t position;
    uint32_t total;
};

struct dump_opts {
    int debug;
};

static uint32_t _TIFFClampDoubleToUInt32(double d) {
    if (d < 0) return 0;
    if (d > UINT32_MAX) return UINT32_MAX;
    return (uint32_t)d;
}

static uint32_t TIFFhowmany(uint32_t a, uint32_t b) {
    return (a + b - 1) / b;
}

static uint32_t TIFFhowmany8(uint32_t a) {
    return (a + 7) / 8;
}

static void TIFFError(const char* module, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "%s: ", module);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    va_end(ap);
}