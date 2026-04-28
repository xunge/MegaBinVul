#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <assert.h>

typedef unsigned char png_byte;
typedef unsigned long png_uint_32;
typedef unsigned int uInt;
typedef unsigned char Quantum;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef struct _Image {
  struct {
    float red;
    float green;
    float blue;
    float alpha;
  } background_color;
  struct {
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
    struct {
      float x;
      float y;
    } white_point;
  } chromaticity;
  struct {
    double x;
    double y;
  } resolution;
  struct {
    ssize_t x;
    ssize_t y;
    size_t width;
    size_t height;
  } page;
  float gamma;
  int rendering_intent;
  int interlace;
  int alpha_trait;
  int units;
  size_t columns;
  size_t rows;
  char *filename;
  Quantum *(*GetAuthenticPixelQueue)(struct _Image *);
  struct _Image *(*GetNextImageInList)(struct _Image *);
  struct _Image *(*SyncNextImageInList)(struct _Image *);
} Image;

typedef struct _ImageInfo {
  int ping;
  char filename[4096];
} ImageInfo;

typedef struct _MngInfo {
  Image *image;
  int mng_type;
  size_t mng_width;
  size_t mng_height;
  ssize_t *x_off;
  ssize_t *y_off;
  int object_id;
  int image_found;
} MngInfo;

typedef struct _ExceptionInfo {
  int severity;
} ExceptionInfo;

#define MagickPathExtent 4096
#define PNG_UINT_31_MAX 0x7fffffffL
#define PNG_RESOLUTION_METER 1
#define OpaqueAlpha 1.0
#define UndefinedPixelTrait 0
#define BlendPixelTrait 1
#define NoInterlace 0
#define PNGInterlace 1
#define CoderEvent 0
#define LoadImagesTag 0
#define WriteBinaryBlobMode 0
#define PixelsPerCentimeterResolution 0
#define CorruptImageError 1
#define ResourceLimitError 2
#define SEEK_SET 0

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
static const char mng_IHDR[] = "IHDR";
static const char mng_IEND[] = "IEND";

unsigned long crc32(unsigned long crc, const unsigned char *buf, uInt len);
void *AcquireQuantumMemory(size_t count, size_t quantum);
void *AcquireMagickMemory(size_t size);
void *RelinquishMagickMemory(void *memory);
void GetImageInfo(ImageInfo *);
Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
ImageInfo *DestroyImageInfo(ImageInfo *);
Image *DestroyImage(Image *);
Image *DestroyImageList(Image *);
Image *ReadImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
MagickBooleanType CloseBlob(Image *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, ssize_t, ssize_t);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
ssize_t TellBlob(Image *);
ssize_t GetBlobSize(Image *);
ssize_t SeekBlob(Image *, ssize_t, int);
size_t ReadBlob(Image *, size_t, unsigned char *);
size_t WriteBlob(Image *, size_t, const unsigned char *);
unsigned int ReadBlobByte(Image *);
unsigned int ReadBlobMSBLong(Image *);
unsigned int WriteBlobMSBULong(Image *, size_t);
void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
void ConcatenateMagickString(char *, const char *, size_t);
void FormatLocaleString(char *, size_t, const char *, ...);
MagickBooleanType LogMagickEvent(int, const char *, const char *, ...);
void LogPNGChunk(MagickBooleanType, const char *, size_t);
void PNGLong(unsigned char *, size_t);
void PNGType(unsigned char *, const char *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
void SetPixelAlpha(Image *, Quantum, Quantum *);
Quantum GetPixelRed(const Image *, const Quantum *);
Quantum GetPixelGreen(const Image *, const Quantum *);
Quantum GetPixelBlue(const Image *, const Quantum *);
Quantum GetPixelAlpha(const Image *, const Quantum *);
Quantum *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
const Quantum *GetVirtualPixels(const Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
char *AcquireUniqueFilename(char *);
char *RelinquishUniqueFileResource(char *);
const char *GetMagickModule(void);
float ScaleCharToQuantum(unsigned char);
float mng_get_long(const unsigned char *);
int Magick_RenderingIntent_from_PNG_RenderingIntent(int);
void ThrowReaderException(int, const char *);
size_t GetPixelChannels(const Image *);
Quantum *GetAuthenticPixelQueue(Image *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);