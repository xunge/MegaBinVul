#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _MngInfo MngInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _PixelPacket PixelPacket;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef unsigned long png_uint_32;
typedef unsigned char png_byte;
typedef long ssize_t;

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
  WriteBinaryBlobMode
} OpenBlobMode;

typedef enum {
  CorruptImageError,
  ResourceLimitError
} ErrorType;

typedef enum {
  PNG_RESOLUTION_METER
} PNGResolutionType;

typedef struct {
  float x, y;
} PointInfo;

typedef struct {
  PointInfo red_primary;
  PointInfo green_primary;
  PointInfo blue_primary;
  PointInfo white_point;
} ChromaticityInfo;

struct _PixelPacket {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
  unsigned char opacity;
  unsigned char alpha;
};

struct _ExceptionInfo {
  ErrorType severity;
  char *reason;
};

struct _ImageInfo {
  ChromaticityInfo chromaticity;
  float gamma;
  ResolutionType units;
  double x_resolution;
  double y_resolution;
  MagickBooleanType ping;
  char filename[256];
};

struct _MngInfo {
  png_uint_32 mng_width;
  png_uint_32 mng_height;
  Image *image;
  int object_id;
  int image_found;
  int x_off[1];
  int y_off[1];
  int mng_type;
};

struct _Image {
  size_t columns;
  size_t rows;
  InterlaceType interlace;
  PixelPacket *pixels;
  MagickBooleanType matte;
  struct {
    ssize_t x;
    ssize_t y;
    size_t width;
    size_t height;
  } page;
  struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
  } background_color;
  ChromaticityInfo chromaticity;
  float gamma;
  double x_resolution;
  double y_resolution;
  ResolutionType units;
  unsigned int rendering_intent;
  char filename[256];
  ExceptionInfo exception;
  Image *next;
};

#define MaxTextExtent 256
#define PNG_UINT_31_MAX 0x7fffffffL
#define OpaqueOpacity 0
#define QuantumRange 255
#define WidthResource 0
#define HeightResource 1
#define SEEK_SET 0
#define EOF (-1)

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
static const char mng_IEND[4] = {'I','E','N','D'};
static const char mng_IHDR[4] = {'I','H','D','R'};

typedef unsigned long uInt;
typedef unsigned long uLong;

unsigned long crc32(unsigned long crc, const unsigned char *buf, uInt len);
void *AcquireQuantumMemory(size_t count, size_t quantum);
void *AcquireMagickMemory(size_t size);
void *RelinquishMagickMemory(void *memory);
void GetImageInfo(ImageInfo *image_info);
Image *AcquireImage(const ImageInfo *image_info);
Image *DestroyImage(Image *image);
ImageInfo *DestroyImageInfo(ImageInfo *image_info);
Image *SyncNextImageInList(Image *image);
Image *GetNextImageInList(const Image *image);
Image *DestroyImageList(Image *image);
MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image, OpenBlobMode mode, ExceptionInfo *exception);
MagickBooleanType SetImageProgress(Image *image, ProgressMonitorTag tag, ssize_t offset, ssize_t extent);
MagickBooleanType LogMagickEvent(LogEventType event, const char *module, const char *format, ...);
const char *GetMagickModule(void);
ssize_t TellBlob(const Image *image);
ssize_t GetBlobSize(const Image *image);
ssize_t ReadBlob(Image *image, size_t length, unsigned char *data);
int ReadBlobByte(Image *image);
ssize_t WriteBlob(Image *image, size_t length, const unsigned char *data);
int SeekBlob(Image *image, ssize_t offset, int whence);
void AcquireNextImage(const ImageInfo *image_info, Image *image);
PixelPacket *GetAuthenticPixelQueue(const Image *image);
PixelPacket *GetAuthenticPixels(Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception);
const PixelPacket *GetVirtualPixels(const Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception);
MagickBooleanType SyncAuthenticPixels(Image *image, ExceptionInfo *exception);
MagickBooleanType SetImageExtent(Image *image, size_t columns, size_t rows);
void InheritException(ExceptionInfo *exception, ExceptionInfo *inherited_exception);
void ThrowReaderException(ErrorType error, const char *reason);
void DestroyJNG(void *chunk, Image **color_image, ImageInfo **color_image_info, Image **alpha_image, ImageInfo **alpha_image_info);
Image *ReadImage(const ImageInfo *image_info, ExceptionInfo *exception);
long ReadBlobMSBLong(Image *image);
void WriteBlobMSBULong(Image *image, size_t value);
void PNGLong(unsigned char *data, png_uint_32 value);
void PNGType(unsigned char *data, const char *type);
void LogPNGChunk(MagickBooleanType logging, const char *type, size_t length);
png_uint_32 mng_get_long(const unsigned char *p);
unsigned char ScaleCharToQuantum(unsigned char value);
int AcquireUniqueFilename(char *filename);
void RelinquishUniqueFileResource(const char *filename);
long GetMagickResourceLimit(int resource);
int ConcatenateMagickString(char *destination, const char *source, size_t size);
int FormatLocaleString(char *string, size_t length, const char *format, ...);
unsigned int Magick_RenderingIntent_from_PNG_RenderingIntent(unsigned char intent);
void SetPixelOpacity(PixelPacket *pixel, unsigned char opacity);
void SetPixelAlpha(PixelPacket *pixel, unsigned char alpha);
unsigned char GetPixelRed(const PixelPacket *pixel);
unsigned char GetPixelOpacity(const PixelPacket *pixel);