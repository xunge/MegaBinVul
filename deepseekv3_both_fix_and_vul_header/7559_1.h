#include <stdint.h>
#include <stddef.h>

typedef int SIXELSTATUS;
typedef struct sixel_encoder sixel_encoder_t;
typedef struct sixel_frame sixel_frame_t;
typedef struct sixel_dither sixel_dither_t;

#define SIXEL_FALSE 0
#define SIXEL_OK 1
#define SIXEL_LOGIC_ERROR (-1)
#define SIXEL_FAILED(x) ((x) != SIXEL_OK)

enum {
    SIXEL_COLOR_OPTION_HIGHCOLOR,
    SIXEL_COLOR_OPTION_MONOCHROME,
    SIXEL_COLOR_OPTION_MAPFILE,
    SIXEL_COLOR_OPTION_BUILTIN,
    SIXEL_COLOR_OPTION_DEFAULT
};

enum {
    SIXEL_FORMATTYPE_PALETTE,
    SIXEL_FORMATTYPE_GRAYSCALE
};

enum {
    SIXEL_PIXELFORMAT_G1,
    SIXEL_PIXELFORMAT_G2,
    SIXEL_PIXELFORMAT_G4,
    SIXEL_PIXELFORMAT_G8
};

enum {
    SIXEL_BUILTIN_G1,
    SIXEL_BUILTIN_G2,
    SIXEL_BUILTIN_G4,
    SIXEL_BUILTIN_G8
};

enum {
    SIXEL_DIFFUSE_NONE
};

struct sixel_encoder {
    int color_option;
    sixel_dither_t *dither_cache;
    void *allocator;
    int finvert;
    int builtin_palette;
    int reqcolors;
    int method_for_largest;
    int method_for_rep;
    int quality_mode;
    int method_for_diffuse;
};

struct sixel_frame {
    int pixelformat;
    int ncolors;
    int transparent;
    void *palette;
    void *pixels;
    int width;
    int height;
};

int sixel_frame_get_pixelformat(sixel_frame_t *frame);
void *sixel_frame_get_palette(sixel_frame_t *frame);
int sixel_frame_get_ncolors(sixel_frame_t *frame);
int sixel_frame_get_transparent(sixel_frame_t *frame);
void *sixel_frame_get_pixels(sixel_frame_t *frame);
int sixel_frame_get_width(sixel_frame_t *frame);
int sixel_frame_get_height(sixel_frame_t *frame);

SIXELSTATUS sixel_dither_new(sixel_dither_t **dither, int colors, void *allocator);
SIXELSTATUS sixel_prepare_monochrome_palette(sixel_dither_t **dither, int finvert);
SIXELSTATUS sixel_prepare_specified_palette(sixel_dither_t **dither, sixel_encoder_t *encoder);
SIXELSTATUS sixel_prepare_builtin_palette(sixel_dither_t **dither, int builtin_palette);
sixel_dither_t *sixel_dither_get(int builtin);
void sixel_dither_unref(sixel_dither_t *dither);
void sixel_dither_set_palette(sixel_dither_t *dither, void *palette);
void sixel_dither_set_pixelformat(sixel_dither_t *dither, int pixelformat);
void sixel_dither_set_transparent(sixel_dither_t *dither, int transparent);
int sixel_dither_get_num_of_histogram_colors(sixel_dither_t *dither);
SIXELSTATUS sixel_dither_initialize(sixel_dither_t *dither, void *pixels, int width, int height, int pixelformat, int method_for_largest, int method_for_rep, int quality_mode);