#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define DefaultResolution 72.0
#define QuantumRange 65535
#define UndefinedResolution 0
#define PixelsPerInchResolution 1
#define UndefinedPixelTrait 0
#define BlendPixelTrait 1
#define PseudoClass 1
#define DirectClass 2
#define CopyCompositeOp 40
#define LoadImageTag 1
#define TraceEvent 1
#define CoderEvent 2
#define CorruptImageError 1
#define ResourceLimitError 2
#define FileOpenError 3
#define ReadBinaryBlobMode 0
#define EOF (-1)

typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef struct _StringInfo StringInfo;
typedef unsigned long Quantum;
typedef int MagickBooleanType;
typedef long ssize_t;
typedef unsigned long size_t;

typedef struct {
    ssize_t left;
    ssize_t top;
    ssize_t right;
    ssize_t bottom;
} PICTRectangle;

typedef struct {
    ssize_t bits_per_pixel;
    ssize_t component_size;
    ssize_t component_count;
    ssize_t horizontal_resolution;
    ssize_t vertical_resolution;
} PICTPixmap;

struct _Image {
    size_t columns;
    size_t rows;
    size_t depth;
    size_t colors;
    size_t scene;
    struct {
        double x;
        double y;
    } resolution;
    int units;
    int alpha_trait;
    int storage_class;
    int compression;
    int debug;
    int colorspace;
    char filename[MagickPathExtent];
    struct {
        Quantum red;
        Quantum green;
        Quantum blue;
    } background_color;
    struct {
        Quantum red;
        Quantum green;
        Quantum blue;
    } *colormap;
    unsigned long signature;
};

struct _ImageInfo {
    unsigned long signature;
    int debug;
    int ping;
    size_t number_scenes;
    size_t scene;
    char filename[MagickPathExtent];
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _StringInfo {
    unsigned char *datum;
    size_t length;
};

static struct {
    const char *name;
    const char *description;
    ssize_t length;
} codes[] = {
    [0x01] = {"PICTVersion", "PICT version", -1},
    [0x12] = {"PICTDirectBitsRect", "Direct bits rectangle", -1},
    [0x13] = {"PICTDirectBitsRgn", "Direct bits region", -1},
    [0x14] = {"PICTCompressedQuickTime", "Compressed QuickTime", -1},
    [0x1b] = {"PICTRGBColor", "RGB color", -1},
    [0x70] = {"PICTComment", "Comment", -1},
    [0x90] = {"PICTCompressedBits", "Compressed bits", -1},
    [0x91] = {"PICTUncompressedBits", "Uncompressed bits", -1},
    [0x98] = {"PICTCompressedBits", "Compressed bits", -1},
    [0x99] = {"PICTUncompressedBits", "Uncompressed bits", -1},
    [0x9a] = {"PICTCompressedBits", "Compressed bits", -1},
    [0x9b] = {"PICTUncompressedBits", "Uncompressed bits", -1},
    [0xa1] = {"PICTLongComment", "Long comment", -1},
    [0xc00] = {"PICTHeaderOp", "Header op", -1},
    [0x8200] = {"PICTJPEG", "JPEG", -1}
};

static int ReadBlobByte(Image *image);
static int ReadBlobMSBShort(Image *image);
static int ReadBlobMSBSignedShort(Image *image);
static long ReadBlobMSBLong(Image *image);
static MagickBooleanType ReadRectangle(Image *image, PICTRectangle *rectangle);
static void ReadPixmap(PICTPixmap pixmap);
static unsigned char *DecodeImage(Image *image, Image *tile_image, ssize_t bytes_per_line, size_t bits_per_pixel, size_t *extent, ExceptionInfo *exception);
static Quantum *QueueAuthenticPixels(Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception);
static MagickBooleanType SyncAuthenticPixels(Image *image, ExceptionInfo *exception);
static Quantum ConstrainColormapIndex(Image *image, Quantum index, ExceptionInfo *exception);
static void SetPixelIndex(Image *image, Quantum index, Quantum *q);
static void SetPixelRed(Image *image, Quantum red, Quantum *q);
static void SetPixelGreen(Image *image, Quantum green, Quantum *q);
static void SetPixelBlue(Image *image, Quantum blue, Quantum *q);
static void SetPixelAlpha(Image *image, Quantum alpha, Quantum *q);
static size_t GetPixelChannels(Image *image);
static Image *AcquireImage(const ImageInfo *image_info, ExceptionInfo *exception);
static MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image, int mode, ExceptionInfo *exception);
static Image *DestroyImageList(Image *image);
static Image *DestroyImage(Image *image);
static Image *GetFirstImageInList(Image *image);
static MagickBooleanType CloseBlob(Image *image);
static MagickBooleanType SetImageExtent(Image *image, size_t columns, size_t rows, ExceptionInfo *exception);
static MagickBooleanType SetImageBackgroundColor(Image *image, ExceptionInfo *exception);
static MagickBooleanType AcquireImageColormap(Image *image, size_t colors, ExceptionInfo *exception);
static MagickBooleanType CompositeImage(Image *image, Image *tile_image, int compose, MagickBooleanType clip, ssize_t x, ssize_t y, ExceptionInfo *exception);
static MagickBooleanType SetImageProgress(Image *image, int tag, ssize_t offset, ssize_t span);
static void *RelinquishMagickMemory(void *memory);
static void *AcquireQuantumMemory(size_t count, size_t quantum);
static StringInfo *BlobToStringInfo(const void *blob, size_t length);
static void SetStringInfoDatum(StringInfo *info, const unsigned char *datum);
static MagickBooleanType SetImageProfile(Image *image, const char *name, StringInfo *profile, ExceptionInfo *exception);
static StringInfo *DestroyStringInfo(StringInfo *info);
static void ThrowReaderException(int severity, const char *reason);
static void ThrowFileException(ExceptionInfo *exception, int severity, const char *reason, const char *description);
static int LogMagickEvent(int event, const char *module, const char *format, ...);
static const char *GetMagickModule(void);
static Image *CloneImage(const Image *image, size_t columns, size_t rows, MagickBooleanType detach, ExceptionInfo *exception);
static ImageInfo *CloneImageInfo(const ImageInfo *image_info);
static void SetImageInfoBlob(ImageInfo *image_info, void *blob, size_t length);
static int AcquireUniqueFileResource(char *filename);
static void RelinquishUniqueFileResource(const char *filename);
static void CopyMagickString(char *destination, const char *source, size_t length);
static int FormatLocaleString(char *string, size_t length, const char *format, ...);
static Image *ReadImage(const ImageInfo *image_info, ExceptionInfo *exception);
static ImageInfo *DestroyImageInfo(ImageInfo *image_info);
static MagickBooleanType TransformImageColorspace(Image *image, int colorspace, ExceptionInfo *exception);
static int TellBlob(Image *image);
static int EOFBlob(Image *image);
static int ReadBlob(Image *image, size_t length, unsigned char *data);
static Quantum ScaleShortToQuantum(unsigned short value);
static Quantum ScaleCharToQuantum(unsigned char value);