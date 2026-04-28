#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  UndefinedPixelTrait,
  BlendPixelTrait
} PixelTrait;

typedef enum {
  NoCompression,
  RLECompression
} CompressionType;

typedef enum {
  PseudoClass,
  DirectClass
} ClassType;

typedef enum {
  TraceEvent
} EventType;

typedef enum {
  TGAColormap,
  TGARGB,
  TGAMonochrome,
  TGARLEColormap,
  TGARLERGB,
  TGARLEMonochrome
} TGAImageType;

typedef enum {
  ReadBinaryBlobMode
} BlobMode;

typedef enum {
  CorruptImageError,
  ResourceLimitError
} ExceptionType;

typedef enum {
  LoadImageTag
} ImageTag;

typedef enum {
  TransparentAlpha,
  OpaqueAlpha
} AlphaType;

typedef unsigned char Quantum;
typedef unsigned long QuantumAny;
typedef double MagickRealType;
typedef ptrdiff_t ssize_t;
typedef size_t MagickSizeType;
typedef long long MagickOffsetType;

typedef struct _PixelInfo {
  MagickRealType red;
  MagickRealType green;
  MagickRealType blue;
  MagickRealType alpha;
} PixelInfo;

typedef struct _ImageInfo {
  unsigned long signature;
  MagickBooleanType debug;
  const char *filename;
  MagickBooleanType ping;
} ImageInfo;

typedef struct _ExceptionInfo {
  unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
  size_t columns;
  size_t rows;
  PixelTrait alpha_trait;
  size_t depth;
  ClassType storage_class;
  CompressionType compression;
  size_t colors;
  const char *filename;
  struct _Image *previous;
  PixelInfo *colormap;
} Image;

typedef struct {
  unsigned char id_length;
  unsigned char colormap_type;
  TGAImageType image_type;
  unsigned short colormap_index;
  unsigned short colormap_length;
  unsigned char colormap_size;
  short x_origin;
  short y_origin;
  unsigned short width;
  unsigned short height;
  unsigned char bits_per_pixel;
  unsigned char attributes;
} TGAInfo;

#define MagickCoreSignature 0xABACADABUL
#define MagickPathExtent 4096

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
Image *DestroyImageList(Image *);
ssize_t ReadBlob(Image *, size_t, void *);
unsigned char ReadBlobByte(Image *);
unsigned short ReadBlobLSBShort(Image *);
void ThrowReaderException(ExceptionType, const char *);
MagickBooleanType EOFBlob(Image *);
MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
void *AcquireQuantumMemory(size_t, size_t);
MagickBooleanType SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
char *DestroyString(char *);
MagickBooleanType CloseBlob(Image *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
void *ResetMagickMemory(void *, int, size_t);
unsigned char ScaleCharToQuantum(unsigned char);
QuantumAny GetQuantumRange(size_t);
MagickRealType ScaleAnyToQuantum(QuantumAny, QuantumAny);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
ssize_t ConstrainColormapIndex(Image *, ssize_t, ExceptionInfo *);
void SetPixelIndex(Image *, Quantum, Quantum *);
Quantum ClampToQuantum(MagickRealType);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
void SetPixelAlpha(Image *, Quantum, Quantum *);
size_t GetPixelChannels(Image *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, ImageTag, MagickOffsetType, size_t);
void ThrowFileException(ExceptionInfo *, ExceptionType, const char *, const char *);
Image *GetFirstImageInList(Image *);
const char *GetMagickModule(void);
MagickBooleanType LogMagickEvent(EventType, const char *, const char *, ...);