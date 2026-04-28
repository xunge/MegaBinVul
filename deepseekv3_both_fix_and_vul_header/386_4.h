#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>

typedef enum
{
  AddComplexOperator,
  ConjugateComplexOperator,
  DivideComplexOperator,
  MagnitudePhaseComplexOperator,
  MultiplyComplexOperator,
  RealImaginaryComplexOperator,
  SubtractComplexOperator
} ComplexOperator;

typedef int MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef int64_t MagickOffsetType;
typedef ptrdiff_t ssize_t;

typedef struct _Image {
  uint32_t signature;
  MagickBooleanType debug;
  char *filename;
  struct _Image *next;
  size_t rows;
  size_t columns;
  size_t depth;
  void (*progress_monitor)(const char *, MagickOffsetType, size_t, void *);
} Image;

typedef struct _ExceptionInfo {
  uint32_t signature;
} ExceptionInfo;

typedef struct _CacheView CacheView;
typedef uint32_t Quantum;

#define MagickCoreSignature 0xabacadabUL
#define MagickPI 3.14159265358979323846264338327950288419716939937510
#define QuantumScale 1.0
#define DirectClass 1
#define ImageError 1
#define TraceEvent 1

typedef void (*MagickProgressMonitor)(const char *, MagickOffsetType, size_t, void *);

Image *CloneImage(const Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
Image *DestroyImageList(Image *);
Image *NewImageList(void);
const char *GetImageArtifact(const Image *, const char *);
double StringToDouble(const char *, char **);
MagickBooleanType LogMagickEvent(unsigned int, const char *, const char *, ...);
MagickBooleanType SetImageProgress(const Image *, const char *, MagickOffsetType, size_t);
MagickBooleanType SetImageStorageClass(Image *, unsigned int, ExceptionInfo *);
MagickBooleanType SyncCacheViewAuthenticPixels(CacheView *, ExceptionInfo *);
MagickBooleanType ThrowMagickException(ExceptionInfo *, const char *, unsigned int, const char *, const char *, ...);
void AppendImageToList(Image **, Image *);
const char *GetMagickModule(void);
CacheView *AcquireAuthenticCacheView(Image *, ExceptionInfo *);
CacheView *AcquireVirtualCacheView(Image *, ExceptionInfo *);
CacheView *DestroyCacheView(CacheView *);
const Quantum *GetCacheViewVirtualPixels(CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
Quantum *QueueCacheViewAuthenticPixels(CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
size_t GetPixelChannels(const Image *);
double PerceptibleReciprocal(double);

#define MagickExport
#define restrict __restrict
#define magick_restrict __restrict