#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef uint8_t l_uint8;
typedef uint16_t l_uint16;
typedef uint32_t l_uint32;
typedef int32_t l_int32;

#define L_ALPHA_CHANNEL 0x0
#define COLOR_RED 0x0
#define COLOR_GREEN 0x1
#define COLOR_BLUE 0x2

#define SAMPLEFORMAT_UINT 1
#define ORIENTATION_TOPLEFT 1
#define PHOTOMETRIC_MINISWHITE 0
#define PHOTOMETRIC_MINISBLACK 1
#define COMPRESSION_OJPEG 6
#define COMPRESSION_CCITTFAX3 3
#define COMPRESSION_CCITTFAX4 4
#define COMPRESSION_CCITTRLE 2
#define COMPRESSION_CCITTRLEW 32771
#define IFF_TIFF 1
#define REMOVE_CMAP_BASED_ON_SRC 1

#define TIFFTAG_SAMPLEFORMAT 339
#define TIFFTAG_COMPRESSION 259
#define TIFFTAG_BITSPERSAMPLE 258
#define TIFFTAG_SAMPLESPERPIXEL 277
#define TIFFTAG_IMAGEWIDTH 256
#define TIFFTAG_IMAGELENGTH 257
#define TIFFTAG_COLORMAP 320
#define TIFFTAG_PHOTOMETRIC 262
#define TIFFTAG_ORIENTATION 274
#define TIFFTAG_IMAGEDESCRIPTION 270

#define MaxTiffWidth 1000000
#define MaxTiffHeight 1000000

#define LEPT_CALLOC(n, size) calloc(n, size)
#define LEPT_FREE(p) free(p)
#define L_ABS(x) abs(x)

#define ERROR_PTR(msg, proc, ret) NULL
#define L_ERROR(...)
#define L_WARNING(...)
#define L_INFO(...)

#define PROCNAME(name) static const char *procName = name

#define SET_DATA_BYTE(pixel, channel, value) 

typedef struct PIX PIX;
typedef struct PIXCMAP PIXCMAP;
typedef struct TIFF TIFF;

struct tiff_transform {
    int vflip;
    int hflip;
    int rotate;
};

static struct tiff_transform tiff_orientation_transforms[8];
static struct tiff_transform tiff_partial_orientation_transforms[8];

static void pixDestroy(PIX **pix);
static PIX *pixCreate(l_uint32 width, l_uint32 height, l_int32 depth);
static void pixSetInputFormat(PIX *pix, l_int32 format);
static l_uint8 *pixGetData(PIX *pix);
static l_int32 pixGetWpl(PIX *pix);
static void pixEndianByteSwap(PIX *pix);
static void pixEndianTwoByteSwap(PIX *pix);
static void pixSetSpp(PIX *pix, l_int32 spp);
static void composeRGBPixel(l_int32 rval, l_int32 gval, l_int32 bval, l_uint32 *ppixel);
static void composeRGBAPixel(l_int32 rval, l_int32 gval, l_int32 bval, l_int32 aval, l_uint32 *ppixel);
static l_int32 getTiffStreamResolution(TIFF *tif, l_int32 *xres, l_int32 *yres);
static l_int32 getTiffCompressedFormat(l_uint16 tiffcomp);
static PIXCMAP *pixcmapCreate(l_int32 depth);
static l_int32 pixcmapAddColor(PIXCMAP *cmap, l_int32 rval, l_int32 gval, l_int32 bval);
static l_int32 pixSetColormap(PIX *pix, PIXCMAP *cmap);
static PIX *pixRemoveColormap(PIX *pix, l_int32 type);
static void pixInvert(PIX *pixd, PIX *pixs);
static void pixFlipTB(PIX *pixd, PIX *pixs);
static void pixFlipLR(PIX *pixd, PIX *pixs);
static PIX *pixRotate90(PIX *pixs, l_int32 direction);
static void pixSetText(PIX *pix, const char *text);
static void pixSetXRes(PIX *pix, l_int32 res);
static void pixSetYRes(PIX *pix, l_int32 res);

/* TIFF function prototypes */
int TIFFGetFieldDefaulted(TIFF*, int, ...);
int TIFFIsTiled(TIFF*);
int TIFFReadScanline(TIFF*, void*, l_uint32, l_uint16);
int TIFFReadRGBAImageOriented(TIFF*, l_uint32, l_uint32, l_uint32*, int, int);
l_uint32 TIFFScanlineSize(TIFF*);
int TIFFGetField(TIFF*, int, ...);
#define TIFFGetR(t) ((t) & 0xff)
#define TIFFGetG(t) (((t) >> 8) & 0xff)
#define TIFFGetB(t) (((t) >> 16) & 0xff)
#define TIFFGetA(t) (((t) >> 24) & 0xff)