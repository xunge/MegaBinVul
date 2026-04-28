#include <assert.h>
#include <string.h>
#include <stddef.h>

typedef unsigned int MagickBooleanType;
typedef unsigned int Quantum;
typedef long ssize_t;
typedef unsigned long size_t;
typedef long MagickOffsetType;

typedef struct _PixelInfo {
    int colorspace;
    int depth;
    double alpha;
} PixelInfo;

typedef struct _ImageInfo {
    unsigned long signature;
    int type;
    char filename[4096];
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char filename[4096];
    size_t rows;
    size_t columns;
    size_t colors;
    PixelInfo *colormap;
    int storage_class;
    int alpha_trait;
} Image;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _QuantizeInfo {
} QuantizeInfo;

typedef struct _RectangleInfo {
    ssize_t x;
    ssize_t y;
    size_t width;
    size_t height;
} RectangleInfo;

#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define MagickPathExtent 4096
#define UndefinedPixelTrait 0
#define PseudoClass 1
#define PaletteType 1
#define TrueColorType 2
#define TriangleFilter 1
#define WriteBinaryBlobMode 1
#define sRGBColorspace 1
#define XPMCompliance 1
#define OpaqueAlpha 255
#define TransparentAlpha 0
#define ResourceLimitError 1
#define SaveImageTag 1
#define TraceEvent 1
#define BasePath 1