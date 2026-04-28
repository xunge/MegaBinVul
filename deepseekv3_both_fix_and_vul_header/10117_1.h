#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

typedef int MagickBooleanType;
typedef int ExceptionInfo;
typedef int MagickRealType;
typedef int sixel_output_t;

typedef struct _ImageInfo {
    unsigned long signature;
} ImageInfo;

typedef struct _PixelPacket {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char opacity;
} PixelPacket;

typedef struct _TransparentColor {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} TransparentColor;

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    ExceptionInfo exception;
    int colorspace;
    MagickBooleanType matte;
    int storage_class;
    size_t colors;
    PixelPacket *colormap;
    TransparentColor transparent_color;
    size_t columns;
    size_t rows;
} Image;

typedef unsigned char IndexPacket;

#define MagickSignature 0
#define MagickFalse 0
#define TraceEvent 0
#define WriteBinaryBlobMode 0
#define sRGBColorspace 0
#define DirectClass 0
#define PaletteType 0
#define PaletteBilevelMatteType 0
#define OpaqueOpacity 0

static int LogMagickEvent(int, const char*, const char*, ...);
static const char* GetMagickModule(void);
static MagickBooleanType OpenBlob(const ImageInfo*, Image*, int, ExceptionInfo*);
static int IssRGBCompatibleColorspace(int);
static void TransformImageColorspace(Image*, int);
static void SetImageType(Image*, int);
static int GetVirtualPixels(Image*, int, int, int, int, ExceptionInfo*);
static const IndexPacket* GetVirtualIndexQueue(Image*);
static unsigned char GetPixelIndex(const IndexPacket*);
static void* AcquireQuantumMemory(size_t, size_t);
static void* RelinquishMagickMemory(void*);
static void CloseBlob(Image*);
static sixel_output_t* sixel_output_create(Image*);
static int sixel_encode_impl(unsigned char*, int, int, unsigned char*, int, int, sixel_output_t*);
static unsigned char ScaleQuantumToChar(int);