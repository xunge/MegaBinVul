#include <assert.h>
#include <string.h>
#include <sys/types.h>

typedef long ssize_t;
typedef long MagickOffsetType;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    PseudoClass,
    DirectClass
} ClassType;

typedef enum {
    NoInterlace,
    GIFInterlace
} InterlaceType;

typedef enum {
    UndefinedCompression,
    LZWCompression
} CompressionType;

typedef enum {
    UndefinedPixelTrait,
    BlendPixelTrait
} PixelTrait;

typedef enum {
    UndefinedColorspace,
    RGBColorspace,
    GRAYColorspace
} ColorspaceType;

typedef enum {
    UndefinedDispose,
    NoneDispose,
    BackgroundDispose,
    PreviousDispose
} DisposeType;

typedef struct _PixelInfo {
    double red;
    double green;
    double blue;
    double alpha;
} PixelInfo;

typedef struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    size_t depth;
    size_t colors;
    double gamma;
    size_t delay;
    size_t iterations;
    ssize_t scene;
    ssize_t opacity;
    ClassType storage_class;
    CompressionType compression;
    InterlaceType interlace;
    ColorspaceType colorspace;
    DisposeType dispose;
    PixelTrait alpha_trait;
    PixelInfo *colormap;
    PixelInfo background_color;
    PixelInfo transparent_color;
    struct {
        size_t width;
        size_t height;
        ssize_t x;
        ssize_t y;
    } page;
    size_t ticks_per_second;
    size_t duration;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
    size_t number_scenes;
    size_t scene;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _RectangleInfo {
    size_t width;
    size_t height;
    ssize_t x;
    ssize_t y;
} RectangleInfo;

typedef struct _StringInfo {
    unsigned char *datum;
    size_t length;
} StringInfo;

enum {
    TraceEvent,
    CoderEvent
};

enum {
    CorruptImageError,
    ResourceLimitError
};

enum {
    ReadBinaryBlobMode,
    LoadImageTag
};

#define MagickCoreSignature 0xabacadabUL
#define MagickPathExtent 4096
#define TransparentAlpha 0.0

#define MagickMin(x,y) ((x) < (y) ? (x) : (y))
#define MagickMax(x,y) ((x) > (y) ? (x) : (y))