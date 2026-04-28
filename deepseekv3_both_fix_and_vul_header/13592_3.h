#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <inttypes.h>

typedef struct tiff TIFF;
typedef int32_t tmsize_t;
#define TIFF_TMSIZE_T_MAX INT32_MAX

struct image_data {
    uint16_t bps;
    uint16_t spp;
    uint16_t planar;
    uint32_t width;
    uint32_t length;
    float xres;
    float yres;
    uint16_t res_unit;
    uint16_t compression;
    uint16_t photometric;
    uint16_t orientation;
    int adjustments;
};

struct dump_opts {
    FILE *infile;
    const char *format;
    int level;
};

#define NUM_BUFF_OVERSIZE_BYTES 3
#define TILE 1
#define STRIP 2
#define MIRROR_HORIZ 1
#define MIRROR_VERT 2
#define ROTATECW_90 4
#define ROTATECW_180 8
#define ROTATECW_270 16
#define JPEGCOLORMODE_RGB 1
#define PLANARCONFIG_CONTIG 1
#define RESUNIT_INCH 2
#define COMPRESSION_NONE 1
#define COMPRESSION_JPEG 7
#define PHOTOMETRIC_YCBCR 6
#define ORIENTATION_TOPLEFT 1
#define ORIENTATION_TOPRIGHT 2
#define ORIENTATION_BOTRIGHT 3
#define ORIENTATION_BOTLEFT 4
#define ORIENTATION_LEFTTOP 5
#define ORIENTATION_RIGHTTOP 6
#define ORIENTATION_RIGHTBOT 7
#define ORIENTATION_LEFTBOT 8

#define TIFFTAG_BITSPERSAMPLE 258
#define TIFFTAG_SAMPLESPERPIXEL 277
#define TIFFTAG_PLANARCONFIG 284
#define TIFFTAG_ORIENTATION 274
#define TIFFTAG_PHOTOMETRIC 262
#define TIFFTAG_IMAGEWIDTH 256
#define TIFFTAG_IMAGELENGTH 257
#define TIFFTAG_XRESOLUTION 282
#define TIFFTAG_YRESOLUTION 283
#define TIFFTAG_RESOLUTIONUNIT 296
#define TIFFTAG_COMPRESSION 259
#define TIFFTAG_TILEWIDTH 322
#define TIFFTAG_TILELENGTH 323
#define TIFFTAG_ROWSPERSTRIP 278
#define TIFFTAG_JPEGCOLORMODE 32768
#define TIFFTAG_YCBCRSUBSAMPLING 530

#define TIFF_SSIZE_FORMAT "d"

uint32_t rowsperstrip;
uint16_t jpegcolormode;

int TIFFGetFieldDefaulted(TIFF*, int, ...);
void TIFFError(const char*, const char*, ...);
int TIFFGetField(TIFF*, int, ...);
tmsize_t TIFFScanlineSize(TIFF*);
int TIFFIsTiled(TIFF*);
tmsize_t TIFFTileSize(TIFF*);
uint32_t TIFFNumberOfTiles(TIFF*);
tmsize_t TIFFTileRowSize(TIFF*);
void dump_info(FILE*, const char*, const char*, const char*, ...);
tmsize_t TIFFStripSize(TIFF*);
uint32_t TIFFNumberOfStrips(TIFF*);
int TIFFSetField(TIFF*, int, ...);
void* limitMalloc(size_t);
void* _TIFFrealloc(void*, size_t);
int readContigStripsIntoBuffer(TIFF*, unsigned char*);
int readSeparateStripsIntoBuffer(TIFF*, unsigned char*, uint32_t, uint32_t, uint16_t, struct dump_opts*);
int readContigTilesIntoBuffer(TIFF*, unsigned char*, uint32_t, uint32_t, uint32_t, uint32_t, uint16_t, uint16_t);
int readSeparateTilesIntoBuffer(TIFF*, unsigned char*, uint32_t, uint32_t, uint32_t, uint32_t, uint16_t, uint16_t);
void dump_buffer(FILE*, const char*, int, uint32_t, uint32_t, unsigned char*);