#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int MagickBooleanType;
typedef int MagickStatusType;
typedef long ssize_t;
typedef unsigned long size_t;

struct _ExceptionInfo {
    unsigned long signature;
};

struct _PixelPacket {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char opacity;
};

struct _Image {
    size_t columns;
    size_t rows;
    MagickBooleanType matte;
    unsigned depth;
    unsigned storage_class;
    size_t colors;
    struct _PixelPacket *colormap;
    struct _Image *previous;
    struct _ExceptionInfo exception;
    char *filename;
    unsigned units;
    double x_resolution;
    double y_resolution;
};

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    char *size;
};

struct _DIBInfo {
    unsigned long size;
    long width;
    long height;
    unsigned short planes;
    unsigned short bits_per_pixel;
    unsigned long compression;
    unsigned long image_size;
    unsigned long x_pixels;
    unsigned long y_pixels;
    unsigned long number_colors;
    unsigned long colors_important;
    unsigned long red_mask;
    unsigned long green_mask;
    unsigned long blue_mask;
};

struct _MemoryInfo {
    void *blob;
};

struct _RectangleInfo {
    size_t width;
    size_t height;
};

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _DIBInfo DIBInfo;
typedef struct _MemoryInfo MemoryInfo;
typedef struct _RectangleInfo RectangleInfo;
typedef unsigned char IndexPacket;
typedef struct _PixelPacket PixelPacket;

enum {
    BI_RGB,
    BI_RLE8,
    BI_RLE4,
    BI_BITFIELDS,
    BI_JPEG,
    BI_PNG
};

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0xabacadabUL
#define TraceEvent 0
#define ReadBinaryBlobMode 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define CoderError 0
#define PseudoClass 0
#define DirectClass 1
#define PixelsPerCentimeterResolution 0
#define LoadImageTag 0
#define WidthValue 1
#define HeightValue 2

static inline long MagickAbsoluteValue(long x) { return labs(x); }
static inline size_t MagickMax(size_t a, size_t b) { return a > b ? a : b; }
static inline unsigned char ScaleCharToQuantum(unsigned char x) { return x; }
static inline unsigned char ScaleColor5to8(unsigned char x) { return (x << 3) | (x >> 2); }
static inline unsigned char ScaleColor6to8(unsigned char x) { return (x << 2) | (x >> 4); }