#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char Quantum;
typedef unsigned long size_t;
typedef long ssize_t;
typedef int MagickBooleanType;

#define MagickFalse 0
#define MagickTrue 1
#define MagickCoreSignature 0x1234
#define MagickPathExtent 4096
#define QuantumRange 255
#define MagickEpsilon 1.0E-12
#define UpdatePixelTrait 0x01
#define AllCompliance 0
#define DirectClass 1
#define TraceEvent 0
#define ResourceLimitError 0
#define SaveImageTag "SaveImage"

typedef struct _PixelInfo {
    double red;
    double green;
    double blue;
} PixelInfo;

typedef struct _RectangleInfo {
    size_t width;
    size_t height;
} RectangleInfo;

typedef struct _BlobInfo {
    void *data;
    size_t length;
} BlobInfo;

typedef struct _ExceptionInfo {
    int severity;
    char *reason;
} ExceptionInfo;

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    size_t columns;
    size_t rows;
    PixelInfo background_color;
    char filename[MagickPathExtent];
    BlobInfo *blob;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    char *filename;
    char *density;
    char *magick;
} ImageInfo;

static size_t MagickMax(size_t a, size_t b) { return a > b ? a : b; }
static unsigned char ScaleQuantumToChar(Quantum quantum) { return quantum; }
static const char *GetMagickModule(void) { return "HISTOGRAM"; }