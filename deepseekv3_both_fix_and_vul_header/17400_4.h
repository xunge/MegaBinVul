#include <assert.h>
#include <string.h>
#include <stddef.h>

typedef long ssize_t;
typedef unsigned char Quantum;
typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;
typedef unsigned int MagickStatusType;
typedef unsigned int MagickCoreSignatureType;
typedef double MagickRealType;

#define MagickCoreSignature 0xABACADAB
#define GetMagickModule() "DIB"

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  BI_RGB,
  BI_RLE8,
  BI_RLE4,
  BI_BITFIELDS,
  BI_JPEG,
  BI_PNG
} CompressionType;

typedef enum {
  UndefinedPixelTrait,
  BlendPixelTrait
} PixelTrait;

typedef enum {
  PseudoClass,
  DirectClass
} ClassType;

typedef enum {
  PixelsPerCentimeterResolution
} ResolutionType;

typedef enum {
  ReadBinaryBlobMode
} BlobMode;

typedef enum {
  TraceEvent
} EventType;

typedef enum {
  CorruptImageError,
  ResourceLimitError,
  CoderError
} ExceptionType;

typedef enum {
  WidthValue,
  HeightValue
} GeometryFlags;

typedef enum {
  LoadImageTag
} ImageTag;

typedef enum {
  TransparentAlpha,
  OpaqueAlpha
} AlphaType;

typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef struct _MemoryInfo MemoryInfo;
typedef struct _RectangleInfo RectangleInfo;
typedef struct _DIBInfo DIBInfo;

struct _ImageInfo {
  MagickCoreSignatureType signature;
  MagickBooleanType debug;
  char *filename;
  char *size;
  char *magick;
};

struct _ExceptionInfo {
  MagickCoreSignatureType signature;
};

struct _Image {
  MagickCoreSignatureType signature;
  size_t columns;
  size_t rows;
  unsigned depth;
  PixelTrait alpha_trait;
  ClassType storage_class;
  size_t colors;
  Image *previous;
  char *filename;
  struct {
    double x;
    double y;
  } resolution;
  ResolutionType units;
  struct {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
  } *colormap;
};

struct _DIBInfo {
  unsigned long size;
  long width;
  long height;
  unsigned short planes;
  unsigned short bits_per_pixel;
  unsigned long compression;
  unsigned long image_size;
  unsigned long x_pixels;
  unsigned long y_pixels;
  unsigned long number_colors;
  unsigned long colors_important;
  unsigned short red_mask;
  unsigned short green_mask;
  unsigned short blue_mask;
};

struct _RectangleInfo {
  size_t width;
  size_t height;
};

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
Image *DestroyImageList(Image *);
unsigned long ReadBlobLSBLong(Image *);
long ReadBlobLSBSignedLong(Image *);
short ReadBlobLSBShort(Image *);
void ThrowReaderException(ExceptionType, const char *);
MagickBooleanType EOFBlob(Image *);
size_t MagickAbsoluteValue(ssize_t);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
void *AcquireQuantumMemory(size_t, size_t);
ssize_t ReadBlob(Image *, size_t, void *);
void *RelinquishMagickMemory(void *);
MagickStatusType ParseAbsoluteGeometry(const char *, RectangleInfo *);
MemoryInfo *AcquireVirtualMemory(size_t, size_t);
void *GetVirtualMemoryBlob(MemoryInfo *);
MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);
MagickBooleanType DecodeImage(Image *, MagickBooleanType, unsigned char *, size_t);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
void SetPixelIndex(Image *, Quantum, Quantum *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, ImageTag, MagickOffsetType, size_t);
MagickBooleanType SyncImage(Image *, ExceptionInfo *);
Quantum ConstrainColormapIndex(Image *, ssize_t, ExceptionInfo *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
unsigned char ScaleColor5to8(unsigned char);
unsigned char ScaleColor6to8(unsigned char);
Quantum ScaleCharToQuantum(unsigned char);
int ReadBlobByte(Image *);
void SetPixelAlpha(Image *, AlphaType, Quantum *);
void ThrowFileException(ExceptionInfo *, ExceptionType, const char *, const char *);
Image *FlipImage(Image *, ExceptionInfo *);
void DuplicateBlob(Image *, Image *);
Image *DestroyImage(Image *);
MagickBooleanType CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
void LogMagickEvent(EventType, const char *, const char *, ...);
size_t MagickMax(size_t, size_t);
size_t GetPixelChannels(Image *);
Quantum *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);

#define magick_restrict __restrict