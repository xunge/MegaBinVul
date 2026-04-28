#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>

typedef unsigned char Quantum;
typedef int MagickStatusType;
typedef size_t MagickSizeType;
typedef off_t MagickOffsetType;
typedef double MagickRealType;

typedef struct _PixelInfo {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
} PixelInfo;

typedef struct _ImageInfo {
    unsigned long signature;
    int debug;
    char *filename;
    int ping;
    unsigned long number_scenes;
    unsigned long scene;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
    unsigned long signature;
    struct _Image *previous;
    struct _Image *next;
    struct {
        int x;
        int y;
    } page;
    unsigned long columns;
    unsigned long rows;
    int alpha_trait;
    unsigned long scene;
    unsigned long colors;
    int storage_class;
    PixelInfo *colormap;
    char *filename;
} Image;

typedef struct _MemoryInfo {
    void *blob;
} MemoryInfo;

enum {
    MagickFalse,
    MagickTrue
};

enum {
    UndefinedPixelTrait,
    BlendPixelTrait
};

enum {
    DirectClass
};

enum {
    LoadImageTag,
    LoadImagesTag
};

enum {
    TraceEvent,
    CorruptImageError,
    ResourceLimitError,
    UnexpectedEndOfFile,
    UnableToReadImageData
};

enum {
    ReadBinaryBlobMode
};

#define MagickCoreSignature 0x12345678
#define MagickMax(a,b) ((a) > (b) ? (a) : (b))