#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Quantum;
typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;
typedef unsigned int MagickBooleanType;
typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _QuantizeInfo QuantizeInfo;
typedef struct _PixelPacket PixelPacket;
typedef unsigned char IndexPacket;

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0xabacadabUL
#define PALM_HAS_COLORMAP_FLAG 0x8000
#define PALM_IS_DIRECT_COLOR 0x4000
#define PALM_IS_COMPRESSED_FLAG 0x2000
#define PALM_HAS_TRANSPARENCY_FLAG 0x1000
#define PALM_COMPRESSION_RLE 1
#define PALM_COMPRESSION_SCANLINE 2
#define PALM_COMPRESSION_NONE 0
#define RLECompression 1
#define FaxCompression 2
#define sRGBColorspace 1
#define GRAYColorspace 2
#define PaletteType 1
#define PseudoClass 1
#define DirectClass 2
#define TransparentOpacity 0
#define QuantumRange 255UL
#define TraceEvent 1
#define WriteBinaryBlobMode 1
#define CharPixel 1
#define ResourceLimitError 1
#define SaveImagesTag 1
#define SEEK_SET 0

static const unsigned char PalmPalette[256*3] = {0};

struct _PixelPacket {
    Quantum red;
    Quantum green;
    Quantum blue;
    Quantum opacity;
};

struct _ExceptionInfo {
    int signature;
    int severity;
    char *reason;
    char *description;
};

struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    size_t columns;
    size_t rows;
    unsigned long colors;
    unsigned long storage_class;
    PixelPacket *colormap;
    ExceptionInfo exception;
    void *blob;
    int colorspace;
};

struct _ImageInfo {
    unsigned long signature;
    unsigned long depth;
    unsigned long compression;
    MagickBooleanType adjoin;
};

struct _QuantizeInfo {
    MagickBooleanType dither;
    unsigned long number_colors;
};

static inline size_t MagickMax(size_t a, size_t b) { return a > b ? a : b; }
static inline size_t MagickMin(size_t a, size_t b) { return a < b ? a : b; }

static Quantum GetPixelRed(const PixelPacket *p) { return p->red; }
static Quantum GetPixelGreen(const PixelPacket *p) { return p->green; }
static Quantum GetPixelBlue(const PixelPacket *p) { return p->blue; }
static Quantum GetPixelOpacity(const PixelPacket *p) { return p->opacity; }
static unsigned char ScaleQuantumToChar(Quantum q) { return (unsigned char)q; }
static IndexPacket GetPixelIndex(const IndexPacket *p) { return *p; }
static void SetPixelIndex(IndexPacket *p, IndexPacket index) { *p = index; }
static IndexPacket FindColor(const PixelPacket *p) { return 0; }

static void LogMagickEvent(int event, const char *module, const char *format, ...) {}
static const char *GetMagickModule(void) { return "PALM"; }

static ExceptionInfo *AcquireExceptionInfo(void) { 
    static ExceptionInfo exception;
    return &exception; 
}
static void DestroyExceptionInfo(ExceptionInfo *exception) {}

static QuantizeInfo *AcquireQuantizeInfo(const ImageInfo *image_info) {
    static QuantizeInfo quantize_info;
    return &quantize_info;
}
static QuantizeInfo *DestroyQuantizeInfo(QuantizeInfo *quantize_info) {
    return NULL;
}

static Image *ConstituteImage(size_t width, size_t height, const char *map, 
                             int storage, const void *pixels, ExceptionInfo *exception) {
    static Image image;
    return &image;
}
static Image *DestroyImage(Image *image) { return NULL; }

static void *AcquireQuantumMemory(size_t size, size_t quanta) {
    return calloc(size, quanta);
}
static void *RelinquishMagickMemory(void *memory) {
    free(memory);
    return NULL;
}

static MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image,
                                int mode, ExceptionInfo *exception) {
    return MagickTrue;
}
static MagickBooleanType CloseBlob(Image *image) {
    return MagickTrue;
}

static void WriteBlobMSBShort(Image *image, unsigned short value) {}
static void WriteBlobByte(Image *image, unsigned char value) {}
static void WriteBlobMSBLong(Image *image, unsigned long value) {}
static void WriteBlob(Image *image, size_t length, const unsigned char *data) {}

static MagickOffsetType SeekBlob(Image *image, MagickOffsetType offset, int whence) {
    return 0;
}
static size_t GetBlobSize(Image *image) { return 0; }

static PixelPacket *GetAuthenticPixels(Image *image, ssize_t x, ssize_t y,
                                     size_t columns, size_t rows, ExceptionInfo *exception) {
    static PixelPacket pixels[1];
    return pixels;
}
static IndexPacket *GetAuthenticIndexQueue(Image *image) {
    static IndexPacket indexes[1];
    return indexes;
}

static Image *GetNextImageInList(const Image *image) { return NULL; }
static Image *SyncNextImageInList(Image *image) { return NULL; }
static size_t GetImageListLength(const Image *image) { return 0; }

static MagickBooleanType SetImageProgress(Image *image, int tag,
                                        MagickOffsetType offset, size_t span) {
    return MagickTrue;
}

static MagickBooleanType TransformImageColorspace(Image *image, int colorspace) {
    return MagickTrue;
}
static size_t GetNumberColors(Image *image, void *unused, ExceptionInfo *exception) {
    return 256;
}
static MagickBooleanType SetImageType(Image *image, int type) {
    return MagickTrue;
}
static void SortColormapByIntensity(Image *image) {}
static MagickBooleanType SetImageStorageClass(Image *image, int storage_class) {
    return MagickTrue;
}
static MagickBooleanType IsPaletteImage(Image *image, ExceptionInfo *exception) {
    return MagickTrue;
}
static MagickBooleanType QuantizeImage(QuantizeInfo *quantize_info, Image *image) {
    return MagickTrue;
}
static MagickBooleanType RemapImage(QuantizeInfo *quantize_info, Image *image, Image *affinity_image) {
    return MagickTrue;
}
static void ThrowWriterException(int error, const char *reason) {}
static void ResetMagickMemory(void *ptr, int value, size_t size) {
    memset(ptr, value, size);
}
static void CopyMagickMemory(void *dest, const void *src, size_t size) {
    memcpy(dest, src, size);
}