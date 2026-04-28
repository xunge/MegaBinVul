#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

typedef unsigned char MagickBooleanType;
typedef size_t MagickSizeType;
typedef long MagickOffsetType;
typedef unsigned char IndexPacket;

typedef struct _PixelPacket {
    unsigned short red;
    unsigned short green;
    unsigned short blue;
    unsigned short alpha;
} PixelPacket;

typedef struct _ColorPacket {
    unsigned short red;
    unsigned short green;
    unsigned short blue;
} ColorPacket;

struct _Image;
typedef struct _Image Image;

struct _Image {
    size_t columns;
    size_t rows;
    unsigned depth;
    size_t colors;
    MagickBooleanType matte;
    ColorPacket *colormap;
    void *exception;
    Image *previous;
    Image *next;
    unsigned scene;
    char *filename;
    unsigned storage_class;
};

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
    unsigned scene;
    unsigned number_scenes;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0xabacadabUL
#define MAGICKCORE_QUANTUM_DEPTH 16
#define ReadBinaryBlobMode 0
#define PseudoClass 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define CoderError 0

enum {
    TraceEvent,
    LoadImageTag,
    LoadImagesTag
};

static unsigned short ScaleCharToQuantum(unsigned char c) { return c * 257; }
static unsigned short ConstrainColormapIndex(Image *image, unsigned char index) { return index; }
static unsigned short GetPixelRed(PixelPacket *q) { return q->red; }
static unsigned short GetPixelGreen(PixelPacket *q) { return q->green; }
static unsigned short GetPixelBlue(PixelPacket *q) { return q->blue; }
static void SetPixelRed(PixelPacket *q, unsigned short red) { q->red = red; }
static void SetPixelGreen(PixelPacket *q, unsigned short green) { q->green = green; }
static void SetPixelBlue(PixelPacket *q, unsigned short blue) { q->blue = blue; }
static void SetPixelAlpha(PixelPacket *q, unsigned short alpha) { q->alpha = alpha; }
static void SetPixelIndex(IndexPacket *indexes, unsigned short idx) { *indexes = idx; }