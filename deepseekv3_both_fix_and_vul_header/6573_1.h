#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef struct _StringInfo StringInfo;

typedef unsigned char Quantum;
typedef long ssize_t;
typedef unsigned long size_t;

#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define DefaultResolution 72.0
#define QuantumRange 65535
#define UndefinedResolution 0
#define PixelsPerInchResolution 1
#define UndefinedPixelTrait 0
#define BlendPixelTrait 1
#define PseudoClass 1
#define DirectClass 2
#define TraceEvent 0
#define CoderEvent 1
#define CorruptImageError 1
#define ResourceLimitError 2
#define FileOpenError 3
#define ReadBinaryBlobMode 0
#define CopyCompositeOp 0
#define LoadImageTag "LoadImage"

typedef struct {
  ssize_t left;
  ssize_t right;
  ssize_t top;
  ssize_t bottom;
} PICTRectangle;

typedef struct {
  ssize_t bits_per_pixel;
  ssize_t component_count;
  ssize_t component_size;
  double horizontal_resolution;
  double vertical_resolution;
} PICTPixmap;

typedef struct {
  const char *name;
  const char *description;
  ssize_t length;
} PICTCommand;

extern PICTCommand codes[];

typedef struct {
  Quantum red;
  Quantum green;
  Quantum blue;
} PixelPacket;

typedef struct {
  double x;
  double y;
} PointInfo;

struct _Image {
  PixelPacket *colormap;
  PixelPacket background_color;
  size_t colors;
  size_t columns;
  size_t rows;
  size_t depth;
  PointInfo resolution;
  int units;
  int storage_class;
  int alpha_trait;
  int compression;
  int colorspace;
  char filename[MagickPathExtent];
  MagickBooleanType debug;
  void *signature;
  size_t scene;
};

struct _ImageInfo {
  void *signature;
  MagickBooleanType debug;
  MagickBooleanType ping;
  size_t number_scenes;
  size_t scene;
  char filename[MagickPathExtent];
};

struct _ExceptionInfo {
  void *signature;
};

struct _StringInfo {
  unsigned char *datum;
  size_t length;
};

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
int ReadBlobByte(Image *);
int ReadBlobMSBShort(Image *);
int ReadBlobMSBSignedShort(Image *);
MagickBooleanType ReadRectangle(Image *, PICTRectangle *);
void ThrowReaderException(int, const char *);
int LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
MagickBooleanType ReadPixmap(Image *, PICTPixmap *);
MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
unsigned char *DecodeImage(Image *, Image *, size_t, unsigned int, size_t *, ExceptionInfo *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
Quantum ConstrainColormapIndex(Image *, unsigned char, ExceptionInfo *);
void SetPixelIndex(Image *, Quantum, Quantum *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
void SetPixelAlpha(Image *, Quantum, Quantum *);
size_t GetPixelChannels(Image *);
MagickBooleanType SetImageProgress(Image *, const char *, ssize_t, ssize_t);
MagickBooleanType CompositeImage(Image *, Image *, int, MagickBooleanType, ssize_t, ssize_t, ExceptionInfo *);
Image *CloneImage(const Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
StringInfo *BlobToStringInfo(const void *, size_t);
void SetStringInfoDatum(StringInfo *, const unsigned char *);
MagickBooleanType SetImageProfile(Image *, const char *, StringInfo *, ExceptionInfo *);
StringInfo *DestroyStringInfo(StringInfo *);
int EOFBlob(const Image *);
ssize_t TellBlob(Image *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
int CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
ImageInfo *CloneImageInfo(const ImageInfo *);
void SetImageInfoBlob(ImageInfo *, void *, size_t);
int AcquireUniqueFileResource(char *);
void CopyMagickString(char *, const char *, size_t);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
Image *ReadImage(const ImageInfo *, ExceptionInfo *);
ImageInfo *DestroyImageInfo(ImageInfo *);
int FormatLocaleString(char *, size_t, const char *, ...);
MagickBooleanType TransformImageColorspace(Image *, int, ExceptionInfo *);
int ReadBlobMSBLong(Image *);
Quantum ScaleShortToQuantum(unsigned short);
Quantum ScaleCharToQuantum(unsigned char);
void SetImageBackgroundColor(Image *, ExceptionInfo *);
Image *DestroyImage(Image *);
size_t MagickMin(size_t, size_t);
size_t MagickMax(size_t, size_t);