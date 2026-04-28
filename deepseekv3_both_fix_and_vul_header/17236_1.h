#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>

typedef unsigned char Quantum;
typedef unsigned char MagickBooleanType;
typedef size_t MagickSizeType;
typedef off_t MagickOffsetType;
typedef double MagickRealType;

#define MagickCoreSignature 0x12345678
#define MagickFalse 0
#define BlendPixelTrait 1
#define UndefinedPixelTrait 0
#define PseudoClass 1
#define CorruptImageError 1
#define ResourceLimitError 2
#define CoderError 3
#define MAGICKCORE_QUANTUM_DEPTH 8
#define LoadImageTag 1
#define LoadImagesTag 2
#define TraceEvent 1
#define ReadBinaryBlobMode 1

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
    size_t number_scenes;
    size_t scene;
} ImageInfo;

typedef struct _ColormapEntry {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
} ColormapEntry;

typedef struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    size_t depth;
    size_t colors;
    struct _Image *previous;
    struct _Image *next;
    size_t scene;
    const char *filename;
    MagickBooleanType alpha_trait;
    size_t storage_class;
    ColormapEntry *colormap;
} Image;