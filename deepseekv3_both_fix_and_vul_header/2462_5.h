#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define MagickExport
#define magick_restrict restrict

typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _CacheView CacheView;
typedef struct _PointInfo PointInfo;
typedef struct _GeometryInfo GeometryInfo;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;
typedef unsigned int MagickStatusType;

typedef void (*MagickProgressMonitor)(const char *,const MagickOffsetType,
  const MagickSizeType,void *);

typedef enum {
  UndefinedPixelTrait
} PixelTrait;

typedef enum {
  SigmaValue
} GeometryFlags;

typedef enum {
  TraceEvent
} LogEventType;

typedef enum {
  ImageError,
  ResourceLimitError
} ExceptionType;

typedef enum {
  PixelChannelRed,
  PixelChannelGreen,
  PixelChannelBlue,
  PixelChannelAlpha
} PixelChannel;

typedef double Quantum;
#define QuantumRange 1.0
#define MagickEpsilon 1.0E-10
#define MagickCoreSignature 0x1234

#define GetMagickModule() ""
#define LogMagickEvent(a,b,c,d) (void)0
#define ThrowImageException(a,b) abort()
#define CloneImage(a,b,c,d,e) NULL
#define DestroyImage(a) NULL
#define GetImageArtifact(a,b) NULL
#define ParseGeometry(a,b) 0
#define AcquireQuantumMemory(a,b) malloc((a)*(b))
static inline void *RelinquishMagickMemory(void *p) { free(p); return NULL; }
#define AcquireVirtualCacheView(a,b) NULL
#define AcquireAuthenticCacheView(a,b) NULL
#define DestroyCacheView(a) NULL
#define GetCacheViewVirtualPixels(a,b,c,d,e,f) NULL
#define QueueCacheViewAuthenticPixels(a,b,c,d,e,f) NULL
#define SyncCacheViewAuthenticPixels(a,b) MagickFalse
#define SetImageProgress(a,b,c,d) MagickFalse
#define GetPixelWriteMask(a,b) 0
#define GetPixelChannels(a) 4
#define GetPixelChannelChannel(a,b) (PixelChannel)b
#define GetPixelChannelTraits(a,b) UndefinedPixelTrait
#define SetPixelChannel(a,b,c,d) (void)0

struct _PointInfo {
  double x;
  double y;
};

struct _GeometryInfo {
  double rho;
  double sigma;
};

struct _Image {
  size_t columns;
  size_t rows;
  char *filename;
  MagickBooleanType debug;
  unsigned int signature;
  int type;
  MagickProgressMonitor progress_monitor;
};

struct _ExceptionInfo {
  unsigned int signature;
};

#define MAGICKCORE_OPENMP_SUPPORT