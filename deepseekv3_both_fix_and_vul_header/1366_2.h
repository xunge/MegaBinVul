#include <assert.h>
#include <string.h>
#include <stddef.h>

typedef unsigned char MagickBooleanType;
typedef unsigned int Quantum;
typedef long ssize_t;
typedef long MagickOffsetType;

typedef struct _PixelInfo {
    double red;
    double green;
    double blue;
    double alpha;
    int colorspace;
    int depth;
} PixelInfo;

typedef struct _ImageInfo {
    unsigned long signature;
    char *magick;
    char *filename;
    int type;
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    int colorspace;
    int storage_class;
    int alpha_trait;
    size_t rows;
    size_t columns;
    size_t colors;
    PixelInfo *colormap;
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

#define MagickCoreSignature 0x12345678
#define MagickFalse 0
#define MagickTrue 1
#define MagickPathExtent 4096
#define UndefinedPixelTrait 0
#define PseudoClass 0
#define PaletteType 0
#define TrueColorType 0
#define TransparentAlpha 0
#define OpaqueAlpha 1
#define sRGBColorspace 0
#define XPMCompliance 0
#define SaveImageTag 0
#define WriteBinaryBlobMode 0
#define TriangleFilter 0
#define TraceEvent 0
#define ResourceLimitError 0
#define BasePath 0