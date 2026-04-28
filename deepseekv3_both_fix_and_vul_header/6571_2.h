#include <assert.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MagickCoreSignature 0xabacadabUL
#define MagickPathExtent 4096
#define MaxColormapSize 65535
#define MagickFalse 0
#define MagickTrue 1

typedef ptrdiff_t ssize_t;
typedef unsigned char Quantum;
typedef unsigned long MagickSizeType;
typedef int MagickBooleanType;

typedef enum {
    PseudoClass,
    DirectClass
} ClassType;

typedef enum {
    BlendPixelTrait
} AlphaTraitType;

typedef enum {
    TraceEvent,
    ResourceLimitError,
    CorruptImageError
} LogEventType;

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

typedef enum {
    XPMCompliance
} ComplianceType;

typedef struct _PixelInfo {
    size_t depth;
} PixelInfo;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    size_t colors;
    size_t depth;
    ClassType storage_class;
    AlphaTraitType alpha_trait;
    PixelInfo *colormap;
} Image;

typedef struct _SplayTreeInfo SplayTreeInfo;

typedef void *(*AcquireMemoryHandler)(size_t);
typedef void (*DestroyMemoryHandler)(void *);
typedef int (*CompareHandler)(const void *, const void *);

static size_t MagickMin(size_t a, size_t b) {
    return a < b ? a : b;
}

static int CompareXPMColor(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

static void RelinquishMagickMemory(void *memory) {
    free(memory);
}

static const char *GetMagickModule(void) {
    return "XPM";
}