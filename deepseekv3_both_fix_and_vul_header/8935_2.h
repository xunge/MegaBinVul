#include <stdlib.h>
#include <errno.h>

#define FFMAX(a, b) ((a) > (b) ? (a) : (b))
#define FFMIN(a, b) ((a) < (b) ? (a) : (b))
#define AVERROR(e) (-(e))

typedef struct Jpeg2000DecoderContext {
    int numXtiles;
    int tile_width;
    int tile_height;
    int tile_offset_x;
    int tile_offset_y;
    int image_offset_x;
    int image_offset_y;
    int width;
    int height;
    int ncomponents;
    int *cdx;
    int *cdy;
    int *cbps;
    int reduction_factor;
    void *avctx;
    struct Jpeg2000Tile *tile;
} Jpeg2000DecoderContext;

typedef struct Jpeg2000Tile {
    struct Jpeg2000Component *comp;
    int coord[2][2];
    struct Jpeg2000CodingStyle *codsty;
    struct Jpeg2000QuantStyle *qntsty;
} Jpeg2000Tile;

typedef struct Jpeg2000Component {
    int coord_o[2][2];
    int coord[2][2];
} Jpeg2000Component;

typedef struct Jpeg2000CodingStyle {
    int dummy;
} Jpeg2000CodingStyle;

typedef struct Jpeg2000QuantStyle {
    int dummy;
} Jpeg2000QuantStyle;

static int ff_jpeg2000_ceildivpow2(int a, int b);
static int ff_jpeg2000_init_component(Jpeg2000Component *comp, 
                                     Jpeg2000CodingStyle *codsty,
                                     Jpeg2000QuantStyle *qntsty,
                                     int cbps, int cdx, int cdy, void *avctx);