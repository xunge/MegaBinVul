#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tiff TIFF;

typedef uint32_t uint32;
typedef uint16_t uint16;

struct image_data {
    uint16 bps;
    uint16 spp;
    uint16 planar;
    uint32 width;
    uint32 length;
    float xres;
    float yres;
    uint16 res_unit;
    uint16 compression;
    uint16 photometric;
    uint16 orientation;
    int adjustments;
};

struct dump_opts {
    FILE *infile;
    char *format;
    int level;
};

#define DEBUG2
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
#define ORIENTATION_TOPLEFT 1
#define ORIENTATION_TOPRIGHT 2
#define ORIENTATION_BOTRIGHT 3
#define ORIENTATION_BOTLEFT 4
#define ORIENTATION_LEFTTOP 5
#define ORIENTATION_RIGHTTOP 6
#define ORIENTATION_RIGHTBOT 7
#define ORIENTATION_LEFTBOT 8
#define COMPRESSION_NONE 1
#define COMPRESSION_CCITTRLE 2
#define COMPRESSION_CCITTFAX3 3
#define COMPRESSION_CCITTFAX4 4
#define COMPRESSION_LZW 5
#define COMPRESSION_OJPEG 6
#define COMPRESSION_JPEG 7
#define COMPRESSION_NEXT 32766
#define COMPRESSION_CCITTRLEW 32771
#define COMPRESSION_PACKBITS 32773
#define COMPRESSION_THUNDERSCAN 32809
#define COMPRESSION_IT8CTPAD 32895
#define COMPRESSION_IT8LW 32896
#define COMPRESSION_IT8MP 32897
#define COMPRESSION_IT8BL 32898
#define COMPRESSION_PIXARFILM 32908
#define COMPRESSION_PIXARLOG 32909
#define COMPRESSION_DEFLATE 32946
#define COMPRESSION_ADOBE_DEFLATE 8
#define PHOTOMETRIC_MINISWHITE 0
#define PHOTOMETRIC_MINISBLACK 1
#define PHOTOMETRIC_RGB 2
#define PHOTOMETRIC_PALETTE 3
#define PHOTOMETRIC_MASK 4
#define PHOTOMETRIC_SEPARATED 5
#define PHOTOMETRIC_YCBCR 6
#define PHOTOMETRIC_CIELAB 8
#define PHOTOMETRIC_ICCLAB 9
#define PHOTOMETRIC_ITULAB 10
#define PHOTOMETRIC_LOGL 32844
#define PHOTOMETRIC_LOGLUV 32845

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
#define TIFFTAG_JPEGCOLORMODE 65538
#define TIFFTAG_YCBCRSUBSAMPLING 530

extern int TIFFGetFieldDefaulted(TIFF*, int, ...);
extern int TIFFGetField(TIFF*, int, ...);
extern void TIFFError(const char*, const char*, ...);
extern uint32 TIFFScanlineSize(TIFF*);
extern int TIFFIsTiled(TIFF*);
extern uint32 TIFFTileSize(TIFF*);
extern uint32 TIFFNumberOfTiles(TIFF*);
extern uint32 TIFFTileRowSize(TIFF*);
extern uint32 TIFFStripSize(TIFF*);
extern uint32 TIFFNumberOfStrips(TIFF*);
extern int TIFFSetField(TIFF*, int, ...);
extern void* _TIFFmalloc(uint32);
extern void* _TIFFrealloc(void*, uint32);

extern int readContigStripsIntoBuffer(TIFF*, unsigned char*);
extern int readSeparateStripsIntoBuffer(TIFF*, unsigned char*, uint32, uint32, uint16, struct dump_opts*);
extern int readContigTilesIntoBuffer(TIFF*, unsigned char*, uint32, uint32, uint32, uint32, uint16, uint16);
extern int readSeparateTilesIntoBuffer(TIFF*, unsigned char*, uint32, uint32, uint32, uint32, uint16, uint16);
extern void dump_info(FILE*, char*, const char*, const char*, ...);
extern void dump_buffer(FILE*, char*, int, uint32, uint32, unsigned char*);

uint16 rowsperstrip;
uint16 jpegcolormode;