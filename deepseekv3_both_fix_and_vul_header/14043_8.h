#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef unsigned long MagickSizeType;
typedef unsigned long long MagickOffsetType;
typedef int MagickBooleanType;
typedef void (*LogHandler)(const char *,const char *);
typedef MagickBooleanType (*MagickProgressMonitor)(const char *,
  const MagickOffsetType,const MagickSizeType,void *);

#define MagickFalse 0
#define MagickTrue 1
#define MaxMap 65535
#define MagickCoreSignature 0xabacadabUL
#define CompositePixelChannel 3
#define SyncChannels 0x01
#define PseudoClass 1

typedef enum
{
  UndefinedPixelChannel,
  RedPixelChannel,
  GreenPixelChannel,
  BluePixelChannel,
  AlphaPixelChannel
} PixelChannel;

typedef enum
{
  UndefinedPixelTrait,
  CopyPixelTrait,
  UpdatePixelTrait,
  BlendPixelTrait
} PixelTrait;

typedef struct _ExceptionInfo
{
  char
    *reason,
    *description;
} ExceptionInfo;

typedef struct _QuantumInfo QuantumInfo;
typedef struct _Image Image;
typedef struct _CacheView CacheView;

typedef double Quantum;
typedef struct _PixelPacket
{
  Quantum
    red,
    green,
    blue,
    alpha;
} PixelPacket;

struct _Image
{
  unsigned long
    signature;
  MagickBooleanType
    debug;
  char
    *filename;
  unsigned long
    columns,
    rows;
  PixelPacket
    *colormap;
  unsigned long
    colors;
  unsigned long
    channel_mask;
  unsigned long
    storage_class;
  MagickProgressMonitor
    progress_monitor;
  QuantumInfo
    *quantum_info;
};

#define GetPixelChannels(image)  (4)
#define GetPixelChannelChannel(image,channel)  (channel)
#define GetPixelChannelTraits(image,channel)  (UpdatePixelTrait)
#define GetPixelRedTraits(image)  (UpdatePixelTrait)
#define GetPixelGreenTraits(image)  (UpdatePixelTrait)
#define GetPixelBlueTraits(image)  (UpdatePixelTrait)
#define GetPixelAlphaTraits(image)  (UpdatePixelTrait)
#define GetPixelWriteMask(image,q)  (1)

#define AcquireQuantumMemory(size,quantum) malloc(size)
#define RelinquishMagickMemory(memory) (free(memory), NULL)
#define ThrowBinaryException(severity,tag,reason) ((void) 0)
#define LogMagickEvent(event,module,format,...) ((void) 0)
#define TraceEvent 0
#define GetMagickModule() ""
#define ResourceLimitError 0
#define MemoryAllocationFailed ""

static inline void *ResetMagickMemory(void *memory,int value,size_t size)
{
  return memset(memory,value,size);
}

static inline Quantum ClampToQuantum(const double value)
{
  return (Quantum)value;
}

static inline double GetPixelIntensity(const Image *image,const Quantum *p)
{
  return (double)(*p);
}

static inline ssize_t ScaleQuantumToMap(const Quantum quantum)
{
  return (ssize_t)quantum;
}

static inline Quantum ScaleMapToQuantum(const double value)
{
  return (Quantum)value;
}

static inline CacheView *AcquireVirtualCacheView(Image *image,
  ExceptionInfo *exception)
{
  return (CacheView *)NULL;
}

static inline CacheView *AcquireAuthenticCacheView(Image *image,
  ExceptionInfo *exception)
{
  return (CacheView *)NULL;
}

static inline const Quantum *GetCacheViewVirtualPixels(const CacheView *view,
  const ssize_t x,const ssize_t y,const size_t columns,const size_t rows,
  ExceptionInfo *exception)
{
  return (const Quantum *)NULL;
}

static inline Quantum *GetCacheViewAuthenticPixels(const CacheView *view,
  const ssize_t x,const ssize_t y,const size_t columns,const size_t rows,
  ExceptionInfo *exception)
{
  return (Quantum *)NULL;
}

static inline MagickBooleanType SyncCacheViewAuthenticPixels(CacheView *view,
  ExceptionInfo *exception)
{
  return MagickFalse;
}

static inline CacheView *DestroyCacheView(CacheView *view)
{
  if (view) free(view);
  return (CacheView *)NULL;
}

static inline MagickBooleanType SetImageProgress(Image *image,const char *tag,
  const MagickOffsetType offset,const MagickSizeType span)
{
  return MagickFalse;
}

static inline MagickBooleanType AccelerateEqualizeImage(Image *image,
  ExceptionInfo *exception)
{
  return MagickFalse;
}

#define MagickExport
#define magick_restrict