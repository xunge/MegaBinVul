#include <assert.h>
#include <string.h>
#include <stddef.h>

typedef unsigned char Quantum;
typedef unsigned short MagickBooleanType;
typedef signed long ssize_t;
typedef unsigned long MagickOffsetType;

#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1

typedef enum {
  UndefinedResolution,
  PixelsPerInchResolution, 
  PixelsPerCentimeterResolution
} ResolutionType;

typedef enum {
  UndefinedPixelTrait
} PixelTrait;

typedef enum {
  DirectClass,
  PseudoClass
} ClassType;

typedef enum {
  BI_RGB,
  BI_RLE8,
  BI_BITFIELDS
} CompressionType;

typedef enum {
  NoCompression
} CompressionOption;

typedef enum {
  sRGBColorspace
} ColorspaceType;

typedef enum {
  TraceEvent
} EventType;

typedef enum {
  WriteBinaryBlobMode
} BlobMode;

typedef enum {
  ResourceLimitError
} ErrorType;

typedef enum {
  SaveImageTag
} ProgressTag;

struct _ImageInfo {
  unsigned int signature;
  ResolutionType units;
  struct {
    double x;
    double y;
  } resolution;
  CompressionOption compression;
  unsigned int depth;
  MagickBooleanType debug;
  char *filename;
};

struct _Image {
  unsigned int signature;
  ClassType storage_class;
  PixelTrait alpha_trait;
  size_t columns;
  size_t rows;
  size_t colors;
  struct {
    Quantum red;
    Quantum green;
    Quantum blue;
  } *colormap;
  MagickBooleanType debug;
  char *filename;
  ResolutionType units;
  struct {
    double x;
    double y;
  } resolution;
};

struct _ExceptionInfo {
  unsigned int signature;
};

typedef struct _ImageInfo ImageInfo;
typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;

typedef struct {
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

#define MagickMax(a,b) ((a) > (b) ? (a) : (b))
#define MagickMin(a,b) ((a) < (b) ? (a) : (b))

void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
const Quantum *GetVirtualPixels(const Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
MagickBooleanType CloseBlob(Image *);
MagickBooleanType SetImageMonochrome(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, ProgressTag, MagickOffsetType, size_t);
MagickBooleanType TransformImageColorspace(Image *, ColorspaceType, ExceptionInfo *);
void LogMagickEvent(EventType, const char *, const char *, const char *);
void ThrowWriterException(ErrorType, const char *);
void WriteBlob(Image *, size_t, const unsigned char *);
void WriteBlobLSBLong(Image *, unsigned int);
void WriteBlobLSBShort(Image *, unsigned short);
size_t EncodeImage(const Image *, size_t, const unsigned char *, unsigned char *);
unsigned char ScaleQuantumToChar(Quantum);
unsigned char ScaleColor8to5(unsigned char);
unsigned char ScaleColor8to6(unsigned char);
Quantum GetPixelRed(const Image *, const Quantum *);
Quantum GetPixelGreen(const Image *, const Quantum *);
Quantum GetPixelBlue(const Image *, const Quantum *);
Quantum GetPixelAlpha(const Image *, const Quantum *);
Quantum GetPixelIndex(const Image *, const Quantum *);
size_t GetPixelChannels(const Image *);
Quantum ClampToQuantum(Quantum);
const char *GetMagickModule(void);