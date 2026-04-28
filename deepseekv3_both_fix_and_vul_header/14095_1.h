#include <assert.h>
#include <string.h>
#include <stddef.h>

typedef int MagickBooleanType;
typedef long long MagickOffsetType;
typedef ptrdiff_t ssize_t;

typedef enum {
    PROP_END,
    PROP_COLORMAP,
    PROP_COMPRESSION,
    PROP_GUIDES,
    PROP_RESOLUTION,
    PROP_TATTOO,
    PROP_PARASITES,
    PROP_UNIT,
    PROP_PATHS,
    PROP_USER_UNIT
} PropType;

typedef enum {
    GIMP_RGB,
    GIMP_GRAY,
    GIMP_INDEXED
} ImageType;

typedef enum {
    COMPRESS_NONE,
    COMPRESS_RLE,
    COMPRESS_ZLIB,
    COMPRESS_FRACTAL
} CompressionType;

typedef struct _XCFDocInfo {
    size_t width;
    size_t height;
    size_t image_type;
    size_t number_layers;
    CompressionType compression;
    MagickOffsetType file_size;
    void *exception;
} XCFDocInfo;

typedef struct _XCFLayerInfo {
    void *image;
    ssize_t offset_x;
    ssize_t offset_y;
    MagickBooleanType visible;
} XCFLayerInfo;

typedef struct _Image {
    size_t columns;
    size_t rows;
    int compression;
    int depth;
    int type;
    int colorspace;
    void *exception;
    char *filename;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
    size_t number_scenes;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0xabacadabUL
#define OpaqueOpacity 1.0
#define GRAYColorspace 1
#define GrayscaleType 1
#define NoCompression 0
#define OverCompositeOp 0
#define TraceEvent 0
#define CorruptImageError 0
#define CoderError 0
#define ResourceLimitError 0
#define NotEnoughPixelData 0
#define ReadBinaryBlobMode 0
#define SEEK_SET 0