#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MaxTextExtent 1024
#define PNG_UINT_31_MAX 0x7fffffffL
#define OpaqueOpacity 0
#define QuantumRange 255

typedef unsigned char png_byte;
typedef unsigned long png_uint_32;
typedef unsigned int uInt;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    CoderEvent
} LogEventType;

typedef enum {
    LoadImagesTag
} ProgressMonitorTag;

typedef enum {
    NoInterlace,
    PNGInterlace
} InterlaceType;

typedef enum {
    PixelsPerCentimeterResolution
} ResolutionType;

typedef enum {
    PNG_RESOLUTION_METER
} PNGResolutionType;

typedef enum {
    WriteBinaryBlobMode
} BlobMode;

typedef enum {
    CorruptImageError,
    ResourceLimitError
} ExceptionType;

typedef enum {
    SEEK_SET
} WhenceType;

typedef struct _ExceptionInfo ExceptionInfo;

typedef struct {
    float x;
    float y;
} PointInfo;

typedef struct {
    PointInfo red_primary;
    PointInfo green_primary;
    PointInfo blue_primary;
    PointInfo white_point;
} ChromaticityInfo;

typedef struct {
    ssize_t x;
    ssize_t y;
    size_t width;
    size_t height;
} RectangleInfo;

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char opacity;
} PixelPacket;

struct _ExceptionInfo {
    ExceptionType severity;
    char *reason;
    char *description;
};

typedef struct _Image {
    ChromaticityInfo chromaticity;
    float gamma;
    int rendering_intent;
    ResolutionType units;
    double x_resolution;
    double y_resolution;
    RectangleInfo page;
    size_t columns;
    size_t rows;
    InterlaceType interlace;
    MagickBooleanType matte;
    MagickBooleanType ping;
    char filename[MaxTextExtent];
    ExceptionInfo exception;
    PixelPacket *colormap;
    PixelPacket *pixels;
    PixelPacket background_color;
} Image;

typedef struct _ImageInfo {
    MagickBooleanType ping;
    char filename[MaxTextExtent];
} ImageInfo;

typedef struct _MngInfo {
    Image *image;
    size_t mng_width;
    size_t mng_height;
    int mng_type;
    ssize_t x_off[1];
    ssize_t y_off[1];
    int object_id;
    int image_found;
} MngInfo;

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

static unsigned long crc32(unsigned long, const unsigned char *, unsigned int);
static void *AcquireQuantumMemory(size_t, size_t);
static void *RelinquishMagickMemory(void *);
static MagickBooleanType LogMagickEvent(LogEventType, const char *, const char *, ...);
static const char *GetMagickModule(void);
static PixelPacket *GetAuthenticPixelQueue(Image *);
static Image *AcquireNextImage(const ImageInfo *, Image *);
static Image *GetNextImageInList(Image *);
static Image *SyncNextImageInList(Image *);
static Image *DestroyImageList(Image *);
static MagickBooleanType SetImageProgress(Image *, ProgressMonitorTag, ssize_t, ssize_t);
static ssize_t TellBlob(Image *);
static ssize_t GetBlobSize(Image *);
static ssize_t ReadBlob(Image *, size_t, unsigned char *);
static ssize_t ReadBlobMSBLong(Image *);
static int ReadBlobByte(Image *);
static void ThrowReaderException(ExceptionType, const char *);
static void InheritException(ExceptionInfo *, ExceptionInfo *);
static MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
static void GetImageInfo(ImageInfo *);
static Image *AcquireImage(const ImageInfo *);
static int AcquireUniqueFilename(char *);
static void RelinquishUniqueFileResource(char *);
static ssize_t WriteBlob(Image *, size_t, const unsigned char *);
static ssize_t WriteBlobMSBULong(Image *, size_t);
static void PNGType(unsigned char *, const char *);
static void LogPNGChunk(MagickBooleanType, const char *, size_t);
static void PNGLong(unsigned char *, size_t);
static unsigned long mng_get_long(const unsigned char *);
static int Magick_RenderingIntent_from_PNG_RenderingIntent(int);
static unsigned char ScaleCharToQuantum(unsigned char);
static void *CopyMagickMemory(void *, const void *, size_t);
static MagickBooleanType SetImageExtent(Image *, size_t, size_t);
static const PixelPacket *GetVirtualPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
static PixelPacket *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
static MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
static int FormatLocaleString(char *, size_t, const char *, ...);
static Image *ReadImage(const ImageInfo *, ExceptionInfo *);
static ImageInfo *DestroyImageInfo(ImageInfo *);
static Image *DestroyImage(Image *);
static ssize_t SeekBlob(Image *, ssize_t, WhenceType);
static char *ConcatenateMagickString(char *, const char *, size_t);
static void SetPixelOpacity(PixelPacket *, unsigned char);
static unsigned char GetPixelRed(const PixelPacket *);
static void SetPixelAlpha(PixelPacket *, unsigned char);
static unsigned char GetPixelOpacity(const PixelPacket *);