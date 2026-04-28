#include <stdint.h>

#define RESUNIT_INCH 1
#define RESUNIT_CENTIMETER 2
#define RESUNIT_NONE 0

#define CROP_REGIONS 1
#define CROP_MARGINS 2
#define CROP_LENGTH 4
#define CROP_WIDTH 8

#define COMPOSITE_IMAGES 1

#define EDGE_LEFT 0
#define EDGE_RIGHT 1
#define EDGE_TOP 2
#define EDGE_BOTTOM 3

struct crop_mask {
    int res_unit;
    int crop_mode;
    int regions;
    struct {
        double X1, Y1, X2, Y2;
    } *corners;
    struct {
        uint32_t x1, y1, x2, y2;
        uint32_t buffsize;
    } *regionlist;
    uint32_t bufftotal;
    int img_mode;
    int edge_ref;
    uint32_t combined_length;
    uint32_t combined_width;
    double margins[4];
    double width;
    double length;
};

struct image_data {
    int res_unit;
    float xres, yres;
    uint32_t width;
    uint32_t length;
    uint32_t bps;
    uint32_t spp;
};

struct offset {
    uint32_t tmargin;
    uint32_t bmargin;
    uint32_t lmargin;
    uint32_t rmargin;
    uint32_t startx;
    uint32_t starty;
    uint32_t endx;
    uint32_t endy;
    uint32_t crop_width;
    uint32_t crop_length;
};

uint32_t _TIFFClampDoubleToUInt32(double);
void TIFFError(const char*, const char*);