#include <assert.h>
#include <string.h>
#include <sys/types.h>

typedef long MagickOffsetType;
typedef ssize_t MagickSizeType;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  UndefinedResolution,
  PixelsPerInchResolution, 
  PixelsPerCentimeterResolution
} ResolutionType;

typedef enum {
  UndefinedPixelTrait
} PixelTrait;

typedef enum {
  BI_RGB,
  BI_RLE8,
  BI_BITFIELDS
} CompressionType;

typedef enum {
  DirectClass,
  PseudoClass
} ClassType;

typedef enum {
  NoCompression
} CompressionMethod;

typedef enum {
  sRGBColorspace
} ColorspaceType;

typedef enum {
  TraceEvent
} EventType;

typedef enum {
  ResourceLimitError
} ErrorType;

typedef enum {
  SaveImageTag
} ProgressTag;

typedef enum {
  WriteBinaryBlobMode
} BlobMode;

typedef unsigned long MagickCoreSignatureType;
#define MagickCoreSignature 0xabacadabUL

typedef struct _ImageInfo {
  MagickCoreSignatureType signature;
  unsigned int depth;
  CompressionMethod compression;
  char *filename;
} ImageInfo;

typedef struct _Image {
  MagickCoreSignatureType signature;
  ClassType storage_class;
  PixelTrait alpha_trait;
  MagickBooleanType debug;
  size_t columns;
  size_t rows;
  ResolutionType units;
  struct {
    double x;
    double y;
  } resolution;
  size_t colors;
  struct {
    double red;
    double green;
    double blue;
  } *colormap;
  char *filename;
} Image;

typedef struct _ExceptionInfo {
  MagickCoreSignatureType signature;
} ExceptionInfo;

typedef struct _DIBInfo {
  unsigned int size;
  int width;
  int height;
  unsigned short planes;
  unsigned short bits_per_pixel;
  unsigned int compression;
  unsigned int image_size;
  unsigned int x_pixels;
  unsigned int y_pixels;
  unsigned int number_colors;
  unsigned int colors_important;
} DIBInfo;

typedef double Quantum;

unsigned char ScaleQuantumToChar(Quantum);
unsigned char ScaleColor8to5(unsigned char);
unsigned char ScaleColor8to6(unsigned char);
Quantum ClampToQuantum(Quantum);
Quantum GetPixelRed(const Image *, const Quantum *);
Quantum GetPixelGreen(const Image *, const Quantum *);
Quantum GetPixelBlue(const Image *, const Quantum *);
Quantum GetPixelAlpha(const Image *, const Quantum *);
unsigned short GetPixelIndex(const Image *, const Quantum *);
size_t GetPixelChannels(const Image *);
const Quantum *GetVirtualPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
MagickBooleanType CloseBlob(Image *);
MagickBooleanType SetImageMonochrome(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, ProgressTag, MagickOffsetType, size_t);
MagickBooleanType TransformImageColorspace(Image *, ColorspaceType, ExceptionInfo *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
void WriteBlob(Image *, size_t, const unsigned char *);
void WriteBlobLSBLong(Image *, unsigned int);
void WriteBlobLSBShort(Image *, unsigned short);
void LogMagickEvent(EventType, const char *, const char *, const char *);
void ThrowWriterException(ErrorType, const char *);
size_t EncodeImage(Image *, size_t, unsigned char *, unsigned char *);
size_t MagickMin(size_t, size_t);