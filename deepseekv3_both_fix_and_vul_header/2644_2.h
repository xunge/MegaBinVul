#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

typedef int MagickBooleanType;
typedef unsigned char IndexPacket;

typedef struct _PixelPacket {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} PixelPacket;

typedef struct _ExceptionInfo {
    int dummy;
} ExceptionInfo;

typedef struct _Colormap {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char opacity;
} Colormap;

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    ExceptionInfo exception;
    unsigned long colors;
    Colormap *colormap;
    MagickBooleanType matte;
    int storage_class;
    int colorspace;
    unsigned long columns;
    unsigned long rows;
    PixelPacket transparent_color;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
} ImageInfo;

typedef void sixel_output_t;

#define MagickSignature 0
#define MagickFalse 0
#define WriteBinaryBlobMode 0
#define OpaqueOpacity 0
#define ResourceLimitError 0
#define TraceEvent 0
#define sRGBColorspace 0
#define DirectClass 0
#define PaletteType 0
#define PaletteBilevelMatteType 0

typedef double MagickRealType;

static void *AcquireQuantumMemory(size_t, size_t);
static void *RelinquishMagickMemory(void *);
static MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
static MagickBooleanType CloseBlob(Image *);
static MagickBooleanType LogMagickEvent(int, const char *, const char *, ...);
static const char *GetMagickModule(void);
static MagickBooleanType IssRGBCompatibleColorspace(int);
static MagickBooleanType TransformImageColorspace(Image *, int);
static MagickBooleanType SetImageType(Image *, int);
static const PixelPacket *GetVirtualPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
static const IndexPacket *GetVirtualIndexQueue(Image *);
static unsigned char GetPixelIndex(const IndexPacket *);
static void ThrowWriterException(int, const char *);
static unsigned char ScaleQuantumToChar(unsigned char);
static sixel_output_t *sixel_output_create(Image *);
static MagickBooleanType sixel_encode_impl(unsigned char *, size_t, size_t, unsigned char *, size_t, int, sixel_output_t *);