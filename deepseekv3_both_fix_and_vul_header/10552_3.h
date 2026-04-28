#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

typedef unsigned char png_byte;
typedef unsigned int png_uint_32;
typedef long ssize_t;
typedef unsigned int uInt;
typedef unsigned long uLong;
typedef unsigned char Quantum;

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
    double x;
    double y;
} ResolutionInfo;

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

typedef struct _ImageInfo {
    int ping;
    char filename[4096];
} ImageInfo;

typedef struct _Image {
    unsigned int columns;
    unsigned int rows;
    Quantum *pixels;
    char filename[4096];
    int interlace;
    struct {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
    } background_color;
    float gamma;
    ChromaticityInfo chromaticity;
    int rendering_intent;
    RectangleInfo page;
    ResolutionInfo resolution;
    int units;
    PixelTrait alpha_trait;
    struct _Image *next;
} Image;

typedef struct _ExceptionInfo {
    int severity;
} ExceptionInfo;

typedef struct _MngInfo {
    Image *image;
    unsigned int mng_type;
    unsigned int mng_width;
    unsigned int mng_height;
    ssize_t x_off[1];
    ssize_t y_off[1];
    unsigned int object_id;
    unsigned int image_found;
} MngInfo;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

#define MagickPathExtent 4096
#define PNG_UINT_31_MAX 0x7fffffffL
#define PNG_RESOLUTION_METER 1
#define OpaqueAlpha 255

static const char mng_JHDR[4] = {'J','H','D','R'};
static const char mng_JDAT[4] = {'J','D','A','T'};
static const char mng_JdAA[4] = {'J','d','A','A'};
static const char mng_IDAT[4] = {'I','D','A','T'};
static const char mng_JDAA[4] = {'J','D','A','A'};
static const char mng_JSEP[4] = {'J','S','E','P'};
static const char mng_bKGD[4] = {'b','K','G','D'};
static const char mng_gAMA[4] = {'g','A','M','A'};
static const char mng_cHRM[4] = {'c','H','R','M'};
static const char mng_sRGB[4] = {'s','R','G','B'};
static const char mng_oFFs[4] = {'o','F','F','s'};
static const char mng_pHYs[4] = {'p','H','Y','s'};
static const char mng_iCCP[4] = {'i','C','C','P'};
static const char mng_IEND[4] = {'I','E','N','D'};
static const char mng_IHDR[4] = {'I','H','D','R'};

static void *AcquireQuantumMemory(size_t count, size_t quantum) { return malloc(count * quantum); }
static void *RelinquishMagickMemory(void *memory) { free(memory); return NULL; }
static void *AcquireMagickMemory(size_t size) { return malloc(size); }
static Image *DestroyImageList(Image *image) { return NULL; }
static Image *SyncNextImageInList(Image *image) { return image; }
static Image *GetNextImageInList(Image *image) { return image->next; }
static Quantum *GetAuthenticPixelQueue(Image *image) { return image->pixels; }
static void AcquireNextImage(const ImageInfo *image_info, Image *image, ExceptionInfo *exception) {}
static void ThrowReaderException(ErrorType error, const char *reason) {}
static MagickBooleanType LogMagickEvent(LogEventType event, const char *module, const char *format, ...) { return MagickTrue; }
static const char *GetMagickModule() { return "JNG"; }
static size_t ReadBlobMSBLong(Image *image) { return 0; }
static size_t ReadBlob(Image *image, size_t length, unsigned char *data) { return 0; }
static unsigned char ReadBlobByte(Image *image) { return 0; }
static size_t GetBlobSize(Image *image) { return 0; }
static size_t TellBlob(Image *image) { return 0; }
static void SeekBlob(Image *image, ssize_t offset, int whence) {}
static void CloseBlob(Image *image) {}
static void GetImageInfo(ImageInfo *image_info) {}
static Image *AcquireImage(ImageInfo *image_info, ExceptionInfo *exception) { return NULL; }
static ImageInfo *DestroyImageInfo(ImageInfo *image_info) { return NULL; }
static Image *DestroyImage(Image *image) { return NULL; }
static void AcquireUniqueFilename(char *filename) {}
static MagickBooleanType OpenBlob(ImageInfo *image_info, Image *image, FileMode mode, ExceptionInfo *exception) { return MagickFalse; }
static void WriteBlob(Image *image, size_t length, const unsigned char *data) {}
static void WriteBlobMSBULong(Image *image, size_t value) {}
static void FormatLocaleString(char *string, size_t length, const char *format, ...) {}
static void ConcatenateMagickString(char *destination, const char *source, size_t length) {}
static void RelinquishUniqueFileResource(char *filename) {}
static Image *ReadImage(ImageInfo *image_info, ExceptionInfo *exception) { return NULL; }
static MagickBooleanType SetImageExtent(Image *image, size_t columns, size_t rows, ExceptionInfo *exception) { return MagickFalse; }
static const Quantum *GetVirtualPixels(Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception) { return NULL; }
static Quantum *GetAuthenticPixels(Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception) { return NULL; }
static MagickBooleanType SyncAuthenticPixels(Image *image, ExceptionInfo *exception) { return MagickFalse; }
static MagickBooleanType SetImageProgress(Image *image, ProgressTag tag, size_t offset, size_t extent) { return MagickFalse; }
static unsigned long crc32(unsigned long crc, const unsigned char *buf, uInt len) { return 0; }
static unsigned char ScaleCharToQuantum(unsigned char value) { return value; }
static unsigned long mng_get_long(const unsigned char *p) { return 0; }
static void PNGType(unsigned char *data, const char type[4]) {}
static void LogPNGChunk(MagickBooleanType logging, const char type[4], size_t length) {}
static void PNGLong(unsigned char *data, size_t value) {}
static int Magick_RenderingIntent_from_PNG_RenderingIntent(int intent) { return 0; }
static Quantum GetPixelRed(const Image *image, const Quantum *p) { return *p; }
static Quantum GetPixelGreen(const Image *image, const Quantum *p) { return *(p+1); }
static Quantum GetPixelBlue(const Image *image, const Quantum *p) { return *(p+2); }
static Quantum GetPixelAlpha(const Image *image, const Quantum *p) { return *(p+3); }
static void SetPixelRed(Image *image, Quantum value, Quantum *p) { *p = value; }
static void SetPixelGreen(Image *image, Quantum value, Quantum *p) { *(p+1) = value; }
static void SetPixelBlue(Image *image, Quantum value, Quantum *p) { *(p+2) = value; }
static void SetPixelAlpha(Image *image, Quantum value, Quantum *p) { *(p+3) = value; }