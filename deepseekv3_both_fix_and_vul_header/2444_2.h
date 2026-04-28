#include <assert.h>
#include <string.h>
#include <stdio.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  UndefinedPixelTrait,
  BlendPixelTrait
} PixelTrait;

typedef enum {
  GRAYColorspace,
  CMYKColorspace,
  LabColorspace,
  RGBColorspace
} ColorspaceType;

typedef struct _ImageInfo {
  unsigned long signature;
  char *filename;
  MagickBooleanType debug;
} ImageInfo;

typedef struct _Image {
  unsigned long signature;
  size_t columns;
  size_t rows;
  unsigned long depth;
  PixelTrait alpha_trait;
  ColorspaceType colorspace;
  char *filename;
} Image;

typedef struct _ExceptionInfo {
  unsigned long signature;
} ExceptionInfo;

typedef unsigned char Quantum;
typedef unsigned long QuantumAny;
typedef long ssize_t;
typedef double MagickRealType;

typedef struct {
  MagickRealType red;
  MagickRealType green;
  MagickRealType blue;
  MagickRealType black;
  MagickRealType alpha;
} PixelInfo;

#define MagickCoreSignature 0x12345678
#define MagickPathExtent 4096
#define MagickID "MagickImage"
#define ReadBinaryBlobMode 0
#define CorruptImageError 1
#define LoadImagesTag "LoadImages"

const char *MagickColorspaceOptions[] = {
  "RGB",
  "GRAY",
  "CMYK",
  "Lab",
  NULL
};

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
void *ResetMagickMemory(void *, int, size_t);
char *ReadBlobString(Image *, char *);
int LocaleNCompare(const char *, const char *, size_t);
void ThrowReaderException(int, const char *);
unsigned long GetQuantumRange(unsigned long);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
char *LocaleLower(char *);
int ParseCommandOption(const char **, MagickBooleanType, const char *);
MagickBooleanType SetImageBackgroundColor(Image *, ExceptionInfo *);
MagickBooleanType SetImageColorspace(Image *, ColorspaceType, ExceptionInfo *);
void GetPixelInfo(Image *, PixelInfo *);
Quantum *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
void SetPixelViaPixelInfo(Image *, const PixelInfo *, Quantum *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType EOFBlob(const Image *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
Image *AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
Image *GetNextImageInList(const Image *);
Image *SyncNextImageInList(Image *);
MagickBooleanType SetImageProgress(Image *, const char *, ssize_t, ssize_t);
ssize_t TellBlob(const Image *);
ssize_t GetBlobSize(const Image *);
MagickBooleanType CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
QuantumAny ScaleAnyToQuantum(QuantumAny, QuantumAny);

void LogMagickEvent(int, const char *, const char *, ...);
#define TraceEvent 0
const char *GetMagickModule(void);