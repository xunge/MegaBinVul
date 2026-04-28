#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned char png_byte;
typedef unsigned long png_uint_32;
typedef unsigned int uInt;
typedef long ssize_t;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef double Quantum;

typedef struct _Image {
    Quantum *pixels;
    ssize_t columns;
    ssize_t rows;
    char filename[4096];
    struct {
        double x;
        double y;
    } resolution;
    struct {
        ssize_t x;
        ssize_t y;
        ssize_t width;
        ssize_t height;
    } page;
    struct {
        Quantum red;
        Quantum green;
        Quantum blue;
    } background_color;
    struct {
        struct {
            double x;
            double y;
        } red_primary;
        struct {
            double x;
            double y;
        } green_primary;
        struct {
            double x;
            double y;
        } blue_primary;
        struct {
            double x;
            double y;
        } white_point;
    } chromaticity;
    float gamma;
    unsigned int rendering_intent;
    unsigned int interlace;
    unsigned int alpha_trait;
    unsigned int units;
} Image;

typedef struct _ImageInfo {
    char filename[4096];
    MagickBooleanType ping;
} ImageInfo;

typedef struct _MngInfo {
    Image *image;
    png_uint_32 mng_width;
    png_uint_32 mng_height;
    unsigned int mng_type;
    ssize_t x_off[256];
    ssize_t y_off[256];
    unsigned int object_id;
    unsigned int image_found;
} MngInfo;

typedef struct _ExceptionInfo {
    int severity;
    char *reason;
} ExceptionInfo;

typedef enum {
    UndefinedPixelTrait,
    BlendPixelTrait
} PixelTrait;

typedef enum {
    NoInterlace,
    PNGInterlace
} InterlaceType;

typedef enum {
    PixelsPerCentimeterResolution
} ResolutionType;

typedef enum {
    CoderEvent
} LogEventType;

typedef enum {
    CorruptImageError,
    ResourceLimitError
} ErrorType;

typedef enum {
    LoadImagesTag
} ProgressTag;

typedef enum {
    WriteBinaryBlobMode
} FileMode;

enum {
    OpaqueAlpha = 255,
    WidthResource,
    HeightResource,
    PNG_RESOLUTION_METER = 1
};

#define MagickPathExtent 4096
#define PNG_UINT_31_MAX 0x7fffffffL

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

static unsigned long crc32(unsigned long crc, const unsigned char *buf, uInt len);
static void *AcquireQuantumMemory(size_t count, size_t quantum);
static void *RelinquishMagickMemory(void *memory);
static Image *DestroyImageList(Image *image);
static Image *DestroyImage(Image *image);
static ImageInfo *DestroyImageInfo(ImageInfo *image_info);
static Image *ReadImage(const ImageInfo *image_info, ExceptionInfo *exception);
static MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image, FileMode mode, ExceptionInfo *exception);
static MagickBooleanType CloseBlob(Image *image);
static MagickBooleanType SetImageProgress(Image *image, ProgressTag tag, ssize_t offset, ssize_t extent);
static MagickBooleanType LogMagickEvent(LogEventType event, const char *module, const char *format, ...);
static void ThrowReaderException(ErrorType error, const char *reason);
static void GetImageInfo(ImageInfo *image_info);
static Image *AcquireImage(const ImageInfo *image_info, ExceptionInfo *exception);
static void AcquireNextImage(const ImageInfo *image_info, Image *image, ExceptionInfo *exception);
static int ReadBlobByte(Image *image);
static unsigned int ReadBlob(Image *image, size_t length, unsigned char *data);
static ssize_t ReadBlobMSBLong(Image *image);
static MagickBooleanType WriteBlob(Image *image, size_t length, const unsigned char *data);
static ssize_t WriteBlobMSBULong(Image *image, unsigned long value);
static MagickBooleanType SeekBlob(Image *image, ssize_t offset, int whence);
static char *FormatLocaleString(char *string, size_t length, const char *format, ...);
static char *ConcatenateMagickString(char *destination, const char *source, size_t length);
static void *AcquireUniqueFileResource(char *filename);
static void RelinquishUniqueFileResource(const char *filename);
static png_uint_32 mng_get_long(const unsigned char *p);
static void PNGType(unsigned char *data, const char *type);
static void PNGLong(unsigned char *data, png_uint_32 value);
static void LogPNGChunk(MagickBooleanType logging, const char *type, size_t length);
static void DestroyJNG(unsigned char *chunk, Image **color_image, ImageInfo **color_image_info, Image **alpha_image, ImageInfo **alpha_image_info);
static int Magick_RenderingIntent_from_PNG_RenderingIntent(int intent);
static const Quantum *GetVirtualPixels(Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception);
static Quantum *GetAuthenticPixels(Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception);
static MagickBooleanType SyncAuthenticPixels(Image *image, ExceptionInfo *exception);
static const char *GetMagickModule(void);
static ssize_t GetBlobSize(Image *image);
static ssize_t TellBlob(Image *image);
static Quantum *GetAuthenticPixelQueue(Image *image);
static Image *GetNextImageInList(Image *image);
static Image *SyncNextImageInList(Image *image);
static long GetMagickResourceLimit(int resource);
static void *AcquireMagickMemory(size_t size);
static Quantum ScaleCharToQuantum(unsigned char value);
static void SetPixelRed(Image *image, Quantum value, Quantum *pixel);
static Quantum GetPixelRed(const Image *image, const Quantum *pixel);
static void SetPixelGreen(Image *image, Quantum value, Quantum *pixel);
static Quantum GetPixelGreen(const Image *image, const Quantum *pixel);
static void SetPixelBlue(Image *image, Quantum value, Quantum *pixel);
static Quantum GetPixelBlue(const Image *image, const Quantum *pixel);
static void SetPixelAlpha(Image *image, Quantum value, Quantum *pixel);
static Quantum GetPixelAlpha(const Image *image, const Quantum *pixel);
static size_t GetPixelChannels(const Image *image);