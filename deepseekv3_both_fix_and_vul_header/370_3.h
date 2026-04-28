#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <sys/types.h>

#define restrict __restrict
#define magick_restrict __restrict

typedef enum {
  AddComplexOperator,
  ConjugateComplexOperator,
  DivideComplexOperator,
  MagnitudePhaseComplexOperator,
  MultiplyComplexOperator,
  RealImaginaryComplexOperator,
  SubtractComplexOperator
} ComplexOperator;

typedef unsigned char MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef long long MagickOffsetType;
typedef unsigned long long MagickSizeType;

#define MagickExport

typedef struct _Image Image;
typedef struct _CacheView CacheView;
typedef struct _ExceptionInfo ExceptionInfo;
typedef void *(*MagickProgressMonitor)(const char *, MagickOffsetType, MagickSizeType, void *);

#define MagickCoreSignature 0xabacadabUL
typedef double Quantum;
#define QuantumScale (1.0)
#define MagickPI 3.14159265358979323846264338327950288419716939937510
#define MAGICKCORE_OPENMP_SUPPORT

static inline size_t MagickMax(const size_t a, const size_t b) {
    return (a > b) ? a : b;
}

typedef struct _PixelPacket {
    Quantum pixel[16];
} PixelPacket;

typedef struct _Image {
  unsigned long signature;
  MagickBooleanType debug;
  char *filename;
  Image *next;
  size_t rows;
  size_t columns;
  unsigned long depth;
  MagickProgressMonitor progress_monitor;
} Image;

typedef struct _CacheView {
  // Implementation details not provided
} CacheView;

typedef struct _ExceptionInfo {
  unsigned long signature;
} ExceptionInfo;

#define GetMagickModule() ""
#define TraceEvent 0
#define ImageError 0
#define ImageSequenceRequired ""
#define DirectClass 0

Image *CloneImage(const Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
MagickBooleanType SetImageStorageClass(Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
Image *NewImageList(void);
void AppendImageToList(Image **, Image *);
const char *GetImageArtifact(const Image *, const char *);
double StringToDouble(const char *, char **);
CacheView *AcquireVirtualCacheView(const Image *, ExceptionInfo *);
CacheView *AcquireAuthenticCacheView(const Image *, ExceptionInfo *);
const Quantum *GetCacheViewVirtualPixels(CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
Quantum *QueueCacheViewAuthenticPixels(CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
ssize_t GetPixelChannels(const Image *);
MagickBooleanType SyncCacheViewAuthenticPixels(CacheView *, ExceptionInfo *);
void *DestroyCacheView(CacheView *);
MagickBooleanType SetImageProgress(const Image *, const char *, MagickOffsetType, MagickOffsetType);
void LogMagickEvent(int, const char *, const char *, ...);
void *ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
double PerceptibleReciprocal(double);