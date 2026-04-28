#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned char png_byte;
typedef unsigned long png_uint_32;
typedef unsigned int uInt;
typedef long ssize_t;
typedef unsigned long size_t;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    CoderEvent,
    LoadImagesTag
} MagickEventType;

typedef enum {
    CorruptImageError,
    ResourceLimitError
} ExceptionType;

typedef enum {
    PixelsPerCentimeterResolution
} ResolutionType;

typedef enum {
    NoInterlace,
    PNGInterlace
} InterlaceType;

typedef enum {
    WidthResource,
    HeightResource
} ResourceType;

typedef enum {
    WriteBinaryBlobMode
} BlobMode;

typedef struct _ExceptionInfo {
    int severity;
    char *reason;
    char *description;
} ExceptionInfo;

typedef struct _Chromaticity {
    struct {
        float x;
        float y;
    } white_point;
    struct {
        float x;
        float y;
    } red_primary;
    struct {
        float x;
        float y;
    } green_primary;
    struct {
        float x;
        float y;
    } blue_primary;
} Chromaticity;

typedef struct _Image {
    png_uint_32 columns;
    png_uint_32 rows;
    ExceptionInfo *exception;
    MagickBooleanType matte;
    InterlaceType interlace;
    struct {
        ssize_t x;
        ssize_t y;
        png_uint_32 width;
        png_uint_32 height;
    } page;
    Chromaticity chromaticity;
    struct {
        float red;
        float green;
        float blue;
    } background_color;
    float gamma;
    float x_resolution;
    float y_resolution;
    ResolutionType units;
    int rendering_intent;
    char filename[4096];
} Image;

typedef struct _ImageInfo {
    MagickBooleanType ping;
    char filename[4096];
} ImageInfo;

typedef struct _MngInfo {
    Image *image;
    int mng_type;
    png_uint_32 mng_width;
    png_uint_32 mng_height;
    ssize_t *x_off;
    ssize_t *y_off;
    int object_id;
    int image_found;
} MngInfo;

typedef struct _PixelPacket {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char opacity;
} PixelPacket;

#define MaxTextExtent 4096
#define PNG_UINT_31_MAX 0x7fffffffL
#define PNG_RESOLUTION_METER 1
#define QuantumRange 255
#define OpaqueOpacity 255

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

/* CRC32 implementation */
static unsigned long crc32_table[256];
static int crc32_table_computed = 0;

static void make_crc32_table(void) {
    unsigned long c;
    int n, k;
    for (n = 0; n < 256; n++) {
        c = (unsigned long) n;
        for (k = 0; k < 8; k++) {
            if (c & 1)
                c = 0xedb88320L ^ (c >> 1);
            else
                c = c >> 1;
        }
        crc32_table[n] = c;
    }
    crc32_table_computed = 1;
}

unsigned long crc32(unsigned long crc, const unsigned char *buf, uInt len) {
    unsigned long c = crc ^ 0xffffffffL;
    uInt n;

    if (!crc32_table_computed)
        make_crc32_table();
    for (n = 0; n < len; n++) {
        c = crc32_table[(c ^ buf[n]) & 0xff] ^ (c >> 8);
    }
    return c ^ 0xffffffffL;
}

/* Function prototypes */
MagickBooleanType LogMagickEvent(MagickEventType, const char *, const char *, ...);
const char *GetMagickModule(void);
PixelPacket *GetAuthenticPixelQueue(Image *);
MagickBooleanType AcquireNextImage(const ImageInfo *, Image *);
Image *GetNextImageInList(Image *);
Image *DestroyImageList(Image *);
Image *SyncNextImageInList(Image *);
MagickBooleanType SetImageProgress(Image *, MagickEventType, size_t, size_t);
size_t TellBlob(Image *);
size_t GetBlobSize(Image *);
void ConcatenateMagickString(char *, const char *, size_t);
size_t ReadBlobMSBLong(Image *);
size_t ReadBlob(Image *, size_t, unsigned char *);
void DestroyJNG(void *, Image **, ImageInfo **, Image **, ImageInfo **);
void ThrowReaderException(ExceptionType, const char *);
void *AcquireQuantumMemory(size_t, size_t);
int ReadBlobByte(Image *);
void *RelinquishMagickMemory(void *);
size_t GetMagickResourceLimit(ResourceType);
void *AcquireMagickMemory(size_t);
void GetImageInfo(ImageInfo *);
Image *AcquireImage(ImageInfo *);
void AcquireUniqueFilename(char *);
MagickBooleanType OpenBlob(ImageInfo *, Image *, BlobMode, ExceptionInfo *);
Image *DestroyImage(Image *);
ImageInfo *DestroyImageInfo(ImageInfo *);
void WriteBlob(Image *, size_t, const unsigned char *);
void WriteBlobMSBULong(Image *, size_t);
void PNGType(unsigned char *, const char *);
void LogPNGChunk(MagickBooleanType, const char *, size_t);
void PNGLong(unsigned char *, png_uint_32);
unsigned char ScaleCharToQuantum(unsigned char);
int Magick_RenderingIntent_from_PNG_RenderingIntent(int);
void SeekBlob(Image *, size_t, int);
void FormatLocaleString(char *, size_t, const char *, ...);
Image *ReadImage(ImageInfo *, ExceptionInfo *);
void RelinquishUniqueFileResource(char *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t);
void InheritException(ExceptionInfo *, ExceptionInfo *);
const PixelPacket *GetVirtualPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
PixelPacket *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
void CopyMagickMemory(void *, const void *, size_t);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
void SetPixelOpacity(PixelPacket *, unsigned char);
unsigned char GetPixelRed(const PixelPacket *);
void SetPixelAlpha(PixelPacket *, unsigned char);
unsigned char GetPixelOpacity(const PixelPacket *);
png_uint_32 mng_get_long(const unsigned char *);