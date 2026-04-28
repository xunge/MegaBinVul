#include <stdint.h>
#include <stddef.h>

#define CROP_NONE 0
#define RESUNIT_NONE 0
#define EDGE_TOP 0
#define INVERT_DATA_AND_TAG 0
#define MAX_REGIONS 4
#define ONE_FILE_COMPOSITE 0
#define COMPOSITE_IMAGES 0

struct point {
    double X1;
    double X2;
    double Y1;
    double Y2;
};

struct region {
    int x1;
    int x2;
    int y1;
    int y2;
    int width;
    int length;
    uint32_t buffsize;
    void *buffptr;
};

struct zone {
    int position;
    int total;
};

struct crop_mask {
    int crop_mode;
    int res_unit;
    int edge_ref;
    int width;
    int length;
    double margins[4];
    uint32_t bufftotal;
    uint32_t combined_width;
    uint32_t combined_length;
    uint16_t rotation;
    int photometric;
    uint16_t mirror;
    uint16_t invert;
    uint32_t zones;
    uint32_t regions;
    struct point corners[MAX_REGIONS];
    struct region regionlist[MAX_REGIONS];
    struct zone zonelist[MAX_REGIONS];
    int exp_mode;
    int img_mode;
};