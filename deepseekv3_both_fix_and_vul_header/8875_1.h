#include <assert.h>
#include <stddef.h>
#include <stdio.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef size_t MagickSizeType;
typedef ptrdiff_t MagickOffsetType;

typedef struct _MemoryInfo MemoryInfo;
typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _SGIInfo SGIInfo;

typedef unsigned char Quantum;

struct _ImageInfo {
  unsigned long signature;
  MagickBooleanType debug;
  char *filename;
  MagickBooleanType ping;
  size_t number_scenes;
  size_t scene;
};

struct _Image {
  unsigned long signature;
  size_t columns;
  size_t rows;
  size_t depth;
  unsigned int compression;
  unsigned int storage_class;
  size_t colors;
  size_t scene;
  Image *previous;
  unsigned int alpha_trait;
  char *filename;
};

struct _ExceptionInfo {
  unsigned long signature;
};

struct _SGIInfo {
  unsigned short magic;
  unsigned char storage;
  unsigned char bytes_per_pixel;
  unsigned short dimension;
  unsigned short columns;
  unsigned short rows;
  unsigned short depth;
  unsigned int minimum_value;
  unsigned int maximum_value;
  unsigned int sans;
  char name[80];
  unsigned int pixel_format;
  unsigned char filler[404];
};

enum {
  TraceEvent,
  LoadImageTag,
  LoadImagesTag
};

enum {
  NoCompression,
  RLECompression
};

enum {
  UndefinedPixelTrait,
  BlendPixelTrait
};

enum {
  PseudoClass,
  DirectClass
};

enum {
  ReadBinaryBlobMode
};

enum {
  CorruptImageError,
  ResourceLimitError,
  ImproperImageHeader,
  UnexpectedEndOfFile,
  MemoryAllocationFailed
};

#define MagickCoreSignature 0xabacadabUL
#define MAGICKCORE_QUANTUM_DEPTH 16
#define OpaqueAlpha 1.0

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
unsigned short ReadBlobMSBShort(Image *);
unsigned char ReadBlobByte(Image *);
unsigned int ReadBlobMSBLong(Image *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
void ThrowReaderException(int, const char *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
MemoryInfo *AcquireVirtualMemory(size_t, size_t);
void *GetVirtualMemoryBlob(MemoryInfo *);
MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);
MagickBooleanType EOFBlob(Image *);
ssize_t ReadBlobMSBSignedLong(Image *);
ssize_t TellBlob(Image *);
ssize_t SeekBlob(Image *, ssize_t, int);
MagickBooleanType SGIDecode(size_t, ssize_t, unsigned char *, long, unsigned char *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
unsigned short ScaleShortToQuantum(unsigned short);
unsigned char ScaleCharToQuantum(unsigned char);
MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
MagickBooleanType SyncImage(Image *, ExceptionInfo *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
MagickOffsetType GetBlobSize(Image *);
MagickBooleanType CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
void LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
MagickBooleanType SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
size_t MagickMin(size_t, size_t);
size_t GetPixelChannels(const Image *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
void SetPixelAlpha(Image *, double, Quantum *);
void SetPixelIndex(Image *, Quantum, Quantum *);
MagickBooleanType AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);