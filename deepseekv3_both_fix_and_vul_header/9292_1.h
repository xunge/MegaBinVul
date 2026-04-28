#include <stdint.h>

typedef struct Jpeg2000Codsty {
    int mct;
} Jpeg2000Codsty;

typedef struct Jpeg2000Tile {
    Jpeg2000Codsty *codsty;
} Jpeg2000Tile;

typedef struct Jpeg2000DecoderContext {
    int *cdef;
    int ncomponents;
    int precision;
} Jpeg2000DecoderContext;

typedef struct AVFrame {
    int format;
} AVFrame;

enum AV_PIX_FMT {
    AV_PIX_FMT_XYZ12,
    AV_PIX_FMT_RGB48,
    AV_PIX_FMT_RGBA64,
    AV_PIX_FMT_GRAY16
};

void tile_codeblocks(Jpeg2000DecoderContext *s, Jpeg2000Tile *tile);
void mct_decode(Jpeg2000DecoderContext *s, Jpeg2000Tile *tile);
void write_frame_8(Jpeg2000DecoderContext *s, Jpeg2000Tile *tile, AVFrame *picture, int bits);
void write_frame_16(Jpeg2000DecoderContext *s, Jpeg2000Tile *tile, AVFrame *picture, int bits);