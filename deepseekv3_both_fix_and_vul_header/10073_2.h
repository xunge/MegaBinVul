#include <stddef.h>
#include <assert.h>
#include <unistd.h>

typedef long ssize_t;
typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef long long MagickOffsetType;
typedef unsigned char Quantum;

typedef struct _ImageInfo {
    unsigned long signature;
    int compression;
    int debug;
    char magick[4096];
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    int debug;
    char *filename;
    unsigned long columns;
    unsigned long rows;
    struct {
        double x;
        double y;
    } resolution;
    int storage_class;
    int alpha_trait;
    unsigned long colors;
    struct _Image *previous;
    struct {
        Quantum red;
        Quantum green;
        Quantum blue;
    } *colormap;
} Image;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _StringInfo {
    size_t length;
    unsigned char *datum;
} StringInfo;

typedef struct {
    short top;
    short left;
    short bottom;
    short right;
} PICTRectangle;

typedef struct {
    short version;
    short pack_type;
    unsigned int pack_size;
    short pixel_type;
    short bits_per_pixel;
    short component_count;
    short component_size;
    unsigned int plane_bytes;
    unsigned int table;
    unsigned int reserved;
} PICTPixmap;

typedef enum {
    UndefinedPixelTrait,
    DirectClass,
    PseudoClass
} StorageClass;

typedef enum {
    JPEGCompression
} CompressionType;

typedef enum {
    sRGBColorspace
} ColorspaceType;

typedef enum {
    TraceEvent
} LogEventType;

typedef enum {
    ImageError,
    ResourceLimitError
} ExceptionType;

typedef enum {
    WriteBinaryBlobMode
} BlobMode;

typedef enum {
    SaveImageTag
} ProgressTag;

#define MagickSignature 0xabacadabUL
#define DefaultResolution 72.0
#define MagickPathExtent 4096
#define SEEK_SET 0