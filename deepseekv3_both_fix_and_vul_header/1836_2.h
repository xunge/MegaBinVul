#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_REGIONS 10
#define MAX_IMAGES 1000
#define MAX_SECTIONS 100
#define MAX_PAPERNAMES 32
#define PATH_MAX 4096

#define TRUE 1
#define FALSE 0

#define FILLORDER_LSB2MSB 1
#define FILLORDER_MSB2LSB 2
#define PLANARCONFIG_SEPARATE 1
#define PLANARCONFIG_CONTIG 2

#define ONE_FILE_COMPOSITE 1
#define ONE_FILE_SEPARATED 2
#define FILE_PER_IMAGE_COMPOSITE 3
#define FILE_PER_IMAGE_SEPARATED 4
#define FILE_PER_SELECTION 5

#define COMPOSITE_IMAGES 1
#define SEPARATED_IMAGES 2

#define CROP_REGIONS 0x01
#define CROP_MARGINS 0x02
#define CROP_WIDTH 0x04
#define CROP_LENGTH 0x08
#define CROP_ZONES 0x10
#define CROP_MIRROR 0x20
#define CROP_ROTATE 0x40
#define CROP_INVERT 0x80

#define EDGE_TOP 1
#define EDGE_BOTTOM 2
#define EDGE_LEFT 3
#define EDGE_RIGHT 4

#define MIRROR_HORIZ 1
#define MIRROR_VERT 2
#define MIRROR_BOTH 3

#define PHOTOMETRIC_MINISBLACK 1
#define PHOTOMETRIC_MINISWHITE 2
#define INVERT_DATA_ONLY 3
#define INVERT_DATA_AND_TAG 4

#define RESUNIT_INCH 2
#define RESUNIT_CENTIMETER 3
#define RESUNIT_NONE 1

#define ORIENTATION_AUTO 0
#define ORIENTATION_PORTRAIT 1
#define ORIENTATION_LANDSCAPE 2

#define PAGE_MODE_NONE 0
#define PAGE_MODE_PAPERSIZE 1
#define PAGE_MODE_RESOLUTION 2
#define PAGE_MODE_MARGINS 4
#define PAGE_MODE_ROWSCOLS 8

#define DUMP_NONE 0
#define DUMP_TEXT 1
#define DUMP_RAW 2

typedef uint32_t tmsize_t;

struct point {
    double X1;
    double Y1;
    double X2;
    double Y2;
};

struct zone {
    int position;
    int total;
};

struct crop_mask {
    uint32_t crop_mode;
    uint32_t regions;
    uint32_t zones;
    uint16_t exp_mode;
    uint16_t img_mode;
    uint16_t edge_ref;
    uint16_t mirror;
    uint16_t rotation;
    uint16_t photometric;
    uint16_t res_unit;
    double margins[4];
    double width;
    double length;
    struct point corners[MAX_REGIONS];
    struct zone zonelist[MAX_REGIONS];
};

struct pagedef {
    uint32_t mode;
    uint16_t orient;
    uint16_t res_unit;
    double width;
    double length;
    double hres;
    double vres;
    double hmargin;
    double vmargin;
    uint32_t cols;
    uint32_t rows;
    char name[16];
};

struct dump_opts {
    uint16_t format;
    uint16_t level;
    uint16_t debug;
    char infilename[PATH_MAX];
    char outfilename[PATH_MAX];
    char mode[3];
};

struct paperdef {
    const char *name;
    double width;
    double length;
};

extern struct paperdef PaperTable[MAX_PAPERNAMES];
extern int ignore;
extern tmsize_t maxMalloc;
extern int outtiled;
extern const char *tiffcrop_version_id;
extern const char *tiffcrop_rev_date;

extern int get_page_geometry(const char *name, struct pagedef *page);
extern int processCompressOptions(const char *opt);
extern void usage(int code);
extern int streq(const char *a, const char *b);
extern void TIFFError(const char *module, const char *fmt, ...);
extern const char *TIFFGetVersion(void);