#include <assert.h>
#include <math.h>
#include <stddef.h>

typedef enum {
  AddComplexOperator,
  ConjugateComplexOperator,
  DivideComplexOperator,
  MagnitudePhaseComplexOperator,
  MultiplyComplexOperator,
  RealImaginaryComplexOperator,
  SubtractComplexOperator
} ComplexOperator;

typedef struct _Image {
  unsigned long signature;
  int debug;
  char *filename;
  struct _Image *next;
  size_t number_channels;
  size_t rows;
  size_t columns;
  unsigned long depth;
  void *progress_monitor;
} Image;

typedef struct _ExceptionInfo {
  unsigned long signature;
} ExceptionInfo;

typedef struct _CacheView CacheView;
typedef unsigned long Quantum;
typedef unsigned long size_t;
typedef long ssize_t;
typedef long MagickOffsetType;
typedef unsigned long long MagickSizeType;
typedef int MagickBooleanType;
typedef int (*MagickProgressMonitor)(const char *,const MagickOffsetType,const MagickSizeType,void *);

#define MagickCoreSignature 0x12345678
#define MagickFalse 0
#define MagickTrue 1
#define TraceEvent 0
#define ImageError 0
#define DirectClass 0
#define MAGICKCORE_OPENMP_SUPPORT 1
#define MagickPI 3.14159265358979323846
#define QuantumScale (1.0/QuantumRange)
#define QuantumRange ((Quantum) (~0UL))
#define magick_restrict restrict

#define MagickExport

const char *GetMagickModule(void);
MagickBooleanType LogMagickEvent(int,const char *,const char *,...);
MagickBooleanType ThrowMagickException(ExceptionInfo *,const char *,int,const char *,const char *,const char *);
Image *CloneImage(const Image *,const size_t,const size_t,const MagickBooleanType,ExceptionInfo *);
MagickBooleanType SetImageStorageClass(Image *,const int,ExceptionInfo *);
Image *NewImageList(void);
void AppendImageToList(Image **,Image *);
Image *DestroyImageList(Image *);
const char *GetImageArtifact(const Image *,const char *);
double StringToDouble(const char *,char **);
CacheView *AcquireVirtualCacheView(const Image *,ExceptionInfo *);
CacheView *AcquireAuthenticCacheView(const Image *,ExceptionInfo *);
const Quantum *GetCacheViewVirtualPixels(CacheView *,const ssize_t,const ssize_t,const size_t,const size_t,ExceptionInfo *);
Quantum *QueueCacheViewAuthenticPixels(CacheView *,const ssize_t,const ssize_t,const size_t,const size_t,ExceptionInfo *);
MagickBooleanType SyncCacheViewAuthenticPixels(CacheView *,ExceptionInfo *);
CacheView *DestroyCacheView(CacheView *);
MagickBooleanType SetImageProgress(const Image *,const char *,const MagickOffsetType,const size_t);
size_t GetPixelChannels(const Image *);
double PerceptibleReciprocal(double);
size_t MagickMin(size_t,size_t);