#include <assert.h>
#include <string.h>
#include <sys/types.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  UndefinedCompression,
  NoCompression
} CompressionType;

typedef enum {
  UndefinedPixelTrait
} PixelTrait;

typedef enum {
  TrueColorType
} ImageType;

typedef enum {
  sRGBColorspace
} ColorspaceType;

typedef enum {
  ImageError,
  ResourceLimitError
} ExceptionType;

typedef enum {
  TraceEvent
} LogEventType;

typedef enum {
  WriteBinaryBlobMode
} BlobMode;

typedef enum {
  SaveImageTag,
  SaveImagesTag
} ProgressTag;

typedef struct _ImageInfo {
  unsigned long signature;
  CompressionType compression;
  ImageType type;
  MagickBooleanType adjoin;
} ImageInfo;

typedef struct _Image {
  unsigned long signature;
  unsigned long columns;
  unsigned long rows;
  unsigned long depth;
  PixelTrait alpha_trait;
  CompressionType compression;
  MagickBooleanType debug;
  char *filename;
  struct _Image *previous;
  struct _Image *next;
} Image;

typedef struct _ExceptionInfo {
  unsigned long signature;
} ExceptionInfo;

typedef struct _MemoryInfo {
  void *blob;
} MemoryInfo;

typedef struct _SGIInfo {
  unsigned short magic;
  unsigned char storage;
  unsigned char bytes_per_pixel;
  unsigned short dimension;
  unsigned short columns;
  unsigned short rows;
  unsigned short depth;
  size_t minimum_value;
  size_t maximum_value;
  unsigned int sans;
  char name[80];
  unsigned int pixel_format;
  unsigned char filler[404];
} SGIInfo;

typedef long long MagickOffsetType;
typedef unsigned long long MagickSizeType;
typedef unsigned char Quantum;

#define MagickCoreSignature 0x1234
#define QuantumRange 255
#define ScaleQuantumToChar(x) ((unsigned char)(x))
#define ScaleQuantumToShort(x) ((unsigned short)(x))

MemoryInfo *AcquireVirtualMemory(size_t, size_t);
void *GetVirtualMemoryBlob(MemoryInfo *);
MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);
const Quantum *GetVirtualPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
unsigned long GetPixelChannels(Image *);
Quantum GetPixelRed(Image *, const Quantum *);
Quantum GetPixelGreen(Image *, const Quantum *);
Quantum GetPixelBlue(Image *, const Quantum *);
Quantum GetPixelAlpha(Image *, const Quantum *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
MagickBooleanType CloseBlob(Image *);
void WriteBlobByte(Image *, unsigned char);
void WriteBlobMSBShort(Image *, unsigned short);
void WriteBlobMSBLong(Image *, unsigned int);
void WriteBlob(Image *, size_t, const unsigned char *);
MagickBooleanType SetImageProgress(Image *, ProgressTag, MagickOffsetType, size_t);
Image *SyncNextImageInList(Image *);
Image *GetNextImageInList(const Image *);
size_t GetImageListLength(const Image *);
MagickBooleanType TransformImageColorspace(Image *, ColorspaceType, ExceptionInfo *);
MagickBooleanType SetImageGray(Image *, ExceptionInfo *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
size_t SGIEncode(const unsigned char *, size_t, unsigned char *);
void ThrowWriterException(ExceptionType, const char *);
void LogMagickEvent(LogEventType, const char *, const char *, ...);
char *GetImageProperty(const Image *, const char *, ExceptionInfo *);
char *CopyMagickString(char *, const char *, size_t);
const char *GetMagickModule(void);