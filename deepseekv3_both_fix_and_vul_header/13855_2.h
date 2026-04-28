#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct _PixelPacket {
    unsigned long red;
    unsigned long green;
    unsigned long blue;
    unsigned long opacity;
} PixelPacket;

typedef struct _PointInfo {
    float x, y;
} PointInfo;

typedef struct _ChromaticityInfo {
    PointInfo red_primary;
    PointInfo green_primary;
    PointInfo blue_primary;
    PointInfo white_point;
} ChromaticityInfo;

typedef struct _RectangleInfo {
    ssize_t x;
    ssize_t y;
    size_t width;
    size_t height;
} RectangleInfo;

typedef struct _Image {
    ChromaticityInfo chromaticity;
    float gamma;
    double x_resolution;
    double y_resolution;
    int units;
    int rendering_intent;
    int matte;
    int interlace;
    RectangleInfo page;
    size_t columns;
    size_t rows;
    PixelPacket background_color;
    char filename[4096];
    void *exception;
} Image;

typedef struct _ImageInfo {
    int ping;
    char filename[4096];
} ImageInfo;

typedef struct _MngInfo {
    Image *image;
    size_t mng_width;
    size_t mng_height;
    int mng_type;
    ssize_t *x_off;
    ssize_t *y_off;
    int object_id;
    int image_found;
} MngInfo;

typedef struct _ExceptionInfo {
    char *description;
} ExceptionInfo;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef unsigned char png_byte;
typedef unsigned long png_uint_32;
typedef unsigned int uInt;
typedef long ssize_t;

enum ErrorType {
    UndefinedError = 0,
    CorruptImageError = 1,
    ResourceLimitError = 2,
    NegativeOrZeroImageSize = 3
};

#define MaxTextExtent 4096
#define PNG_UINT_31_MAX 0x7fffffffL
#define PNG_RESOLUTION_METER 1
#define QuantumRange 65535
#define OpaqueOpacity QuantumRange
#define SEEK_SET 0

enum {
    CoderEvent,
    LoadImagesTag,
    WriteBinaryBlobMode,
    NoInterlace,
    PNGInterlace,
    PixelsPerCentimeterResolution
};

static const char mng_JHDR[] = "JHDR";
static const char mng_JDAT[] = "JDAT";
static const char mng_JdAA[] = "JdAA";
static const char mng_IDAT[] = "IDAT";
static const char mng_JDAA[] = "JDAA";
static const char mng_JSEP[] = "JSEP";
static const char mng_bKGD[] = "bKGD";
static const char mng_gAMA[] = "gAMA";
static const char mng_cHRM[] = "cHRM";
static const char mng_sRGB[] = "sRGB";
static const char mng_oFFs[] = "oFFs";
static const char mng_pHYs[] = "pHYs";
static const char mng_IEND[] = "IEND";
static const char mng_IHDR[] = "IHDR";

unsigned long crc32(unsigned long, const unsigned char *, unsigned int);
void *AcquireQuantumMemory(size_t, size_t);
void *AcquireMagickMemory(size_t);
void *RelinquishMagickMemory(void *);
void GetImageInfo(ImageInfo *);
Image *AcquireImage(ImageInfo *);
Image *DestroyImageList(Image *);
Image *DestroyImage(Image *);
ImageInfo *DestroyImageInfo(ImageInfo *);
Image *ReadImage(ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(ImageInfo *, Image *, int, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, ssize_t, ssize_t);
MagickBooleanType LogMagickEvent(int, const char *, const char *, ...);
MagickBooleanType SetImageExtent(Image *, size_t, size_t);
const char *GetMagickModule(void);
ssize_t TellBlob(Image *);
ssize_t GetBlobSize(Image *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
ssize_t ReadBlobMSBLong(Image *);
unsigned char ReadBlobByte(Image *);
void ThrowReaderException(int, const char *);
void AcquireNextImage(const ImageInfo *, Image *);
PixelPacket *GetAuthenticPixelQueue(Image *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
void *ConcatenateMagickString(char *, const char *, size_t);
void *CopyMagickMemory(void *, const void *, size_t);
void *SeekBlob(Image *, ssize_t, int);
void *WriteBlob(Image *, size_t, const unsigned char *);
void *WriteBlobMSBULong(Image *, size_t);
void *WriteBlobMSBLong(Image *, long);
void *FormatLocaleString(char *, size_t, const char *, ...);
void *AcquireUniqueFilename(char *);
void *RelinquishUniqueFileResource(char *);
void InheritException(ExceptionInfo *, void *);
PixelPacket *GetVirtualPixels(Image *, ssize_t, ssize_t, size_t, size_t, void *);
PixelPacket *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
void PNGType(unsigned char *, const char *);
void LogPNGChunk(MagickBooleanType, const char *, size_t);
void PNGLong(unsigned char *, size_t);
unsigned long mng_get_long(const unsigned char *);
unsigned char ScaleCharToQuantum(unsigned char);
int Magick_RenderingIntent_from_PNG_RenderingIntent(int);
void SetPixelOpacity(PixelPacket *, unsigned long);
void SetPixelAlpha(PixelPacket *, unsigned long);
unsigned long GetPixelRed(const PixelPacket *);
unsigned long GetPixelOpacity(const PixelPacket *);