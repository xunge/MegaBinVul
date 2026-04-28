#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>

typedef unsigned char Quantum;
typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;
typedef double MagickRealType;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  UndefinedPixelTrait,
  BlendPixelTrait
} PixelTrait;

typedef enum {
  PseudoClass,
  DirectClass
} ClassType;

typedef enum {
  TraceEvent
} EventType;

typedef enum {
  CorruptImageError,
  ResourceLimitError,
  CoderError
} ExceptionType;

typedef enum {
  ReadBinaryBlobMode
} BlobMode;

typedef enum {
  LoadImageTag,
  LoadImagesTag
} ProgressTag;

typedef struct _ImageInfo {
  unsigned long signature;
  MagickBooleanType debug;
  char *filename;
  MagickBooleanType ping;
  unsigned long number_scenes;
  unsigned long scene;
} ImageInfo;

typedef struct _ExceptionInfo {
  unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
  unsigned long columns;
  unsigned long rows;
  unsigned long depth;
  unsigned long colors;
  ClassType storage_class;
  PixelTrait alpha_trait;
  struct _Image *previous;
  struct _Image *next;
  unsigned long scene;
  char *filename;
  struct _ColormapInfo *colormap;
} Image;

typedef struct _ColormapInfo {
  MagickRealType red;
  MagickRealType green;
  MagickRealType blue;
} ColormapInfo;

#define MAGICKCORE_QUANTUM_DEPTH 16
#define MagickCoreSignature 0xabacadabUL

void *AcquireQuantumMemory(size_t count, size_t quantum);
void *RelinquishMagickMemory(void *memory);
void *ResetMagickMemory(void *memory, int c, size_t n);
void *CopyMagickMemory(void *destination, const void *source, size_t size);
unsigned long ReadBlobMSBLong(Image *image);
ssize_t ReadBlob(Image *image, size_t length, void *data);
MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image, BlobMode mode, ExceptionInfo *exception);
Image *AcquireImage(const ImageInfo *image_info, ExceptionInfo *exception);
Image *DestroyImageList(Image *image);
Image *GetFirstImageInList(Image *image);
Image *GetNextImageInList(Image *image);
Image *SyncNextImageInList(Image *image);
MagickBooleanType AcquireImageColormap(Image *image, unsigned long colors, ExceptionInfo *exception);
MagickBooleanType SetImageExtent(Image *image, unsigned long columns, unsigned long rows, ExceptionInfo *exception);
MagickBooleanType SetImageProgress(Image *image, const char *tag, MagickOffsetType offset, MagickOffsetType span);
MagickBooleanType SyncAuthenticPixels(Image *image, ExceptionInfo *exception);
Quantum *QueueAuthenticPixels(Image *image, long x, long y, unsigned long columns, unsigned long rows, ExceptionInfo *exception);
void SetPixelIndex(Image *image, Quantum index, Quantum *pixel);
void SetPixelRed(Image *image, Quantum red, Quantum *pixel);
void SetPixelGreen(Image *image, Quantum green, Quantum *pixel);
void SetPixelBlue(Image *image, Quantum blue, Quantum *pixel);
void SetPixelAlpha(Image *image, Quantum alpha, Quantum *pixel);
Quantum GetPixelRed(const Image *image, const Quantum *pixel);
Quantum GetPixelGreen(const Image *image, const Quantum *pixel);
Quantum GetPixelBlue(const Image *image, const Quantum *pixel);
unsigned long GetPixelChannels(const Image *image);
MagickBooleanType SyncImage(Image *image, ExceptionInfo *exception);
MagickBooleanType EOFBlob(const Image *image);
void ThrowReaderException(ExceptionType severity, const char *reason);
void ThrowFileException(ExceptionInfo *exception, ExceptionType severity, const char *reason, const char *description);
void LogMagickEvent(EventType event, const char *module, const char *format, ...);
const char *GetMagickModule(void);
MagickBooleanType CloseBlob(Image *image);
long TellBlob(Image *image);
long GetBlobSize(Image *image);
MagickBooleanType DecodeImage(unsigned char *source, size_t source_length, unsigned char *destination, size_t destination_length);
MagickBooleanType HeapOverflowSanityCheck(unsigned long width, unsigned long depth);
MagickBooleanType AcquireNextImage(const ImageInfo *image_info, Image *image, ExceptionInfo *exception);

Quantum ScaleCharToQuantum(unsigned char value);
Quantum ClampToQuantum(double value);
Quantum ConstrainColormapIndex(Image *image, unsigned char index, ExceptionInfo *exception);