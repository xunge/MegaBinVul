#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long Quantum;
typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;
typedef unsigned int MagickBooleanType;
typedef void *CacheView;
typedef void *ExceptionInfo;
typedef void (*MagickProgressMonitor)(const char *,const MagickOffsetType,const MagickSizeType,void *);

#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define MaxMap 65535UL
#define QuantumRange 65535UL
#define DefaultChannels 0x7ffffff
#define PseudoClass 1
#define GRAYColorspace 1
#define UpdatePixelTrait 0x001
#define TraceEvent 0
#define ResourceLimitError 1

typedef enum {
  UndefinedPixelChannel,
  RedPixelChannel,
  GreenPixelChannel,
  BluePixelChannel,
  AlphaPixelChannel
} PixelChannel;

typedef unsigned int PixelTrait;

typedef struct {
  Quantum red;
  Quantum green;
  Quantum blue;
  Quantum alpha;
} PixelPacket;

struct _Image {
  PixelPacket *colormap;
  unsigned long colors;
  unsigned long columns;
  unsigned long rows;
  unsigned long signature;
  unsigned long storage_class;
  unsigned long channel_mask;
  unsigned long debug;
  char *filename;
  MagickProgressMonitor progress_monitor;
};

typedef struct _Image Image;

#define MagickExport
#define ScaleQuantumToMap(x) ((unsigned short) (x))
#define ScaleMapToQuantum(x) ((Quantum) (x))
#define ClampToQuantum(x) ((Quantum) (x))
#define PerceptibleReciprocal(x) (1.0/(x))
#define GetPixelIntensity(image,p) (0.0)
#define GetPixelChannels(image) (4)
#define GetPixelChannelOffset(image,channel) (channel)
#define GetPixelChannelTraits(image,channel) (UpdatePixelTrait)
#define GetPixelChannelChannel(image,offset) (offset)
#define GetPixelWriteMask(image,q) (1)
#define GetPixelRedTraits(image) (UpdatePixelTrait)
#define GetPixelGreenTraits(image) (UpdatePixelTrait)
#define GetPixelBlueTraits(image) (UpdatePixelTrait)
#define GetPixelAlphaTraits(image) (UpdatePixelTrait)

#define magick_restrict __restrict

void *AcquireQuantumMemory(size_t count, size_t quantum);
void *RelinquishMagickMemory(void *memory);
void *ResetMagickMemory(void *memory, int c, size_t n);
void ThrowBinaryException(unsigned int, const char *, const char *);
CacheView *AcquireVirtualCacheView(Image *, ExceptionInfo *);
CacheView *AcquireAuthenticCacheView(Image *, ExceptionInfo *);
void *DestroyCacheView(CacheView *);
const Quantum *GetCacheViewVirtualPixels(CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
Quantum *GetCacheViewAuthenticPixels(CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
MagickBooleanType SyncCacheViewAuthenticPixels(CacheView *, ExceptionInfo *);
MagickBooleanType SetImageGray(Image *, ExceptionInfo *);
MagickBooleanType SetImageColorspace(Image *, unsigned int, ExceptionInfo *);
MagickBooleanType SyncImagePixelCache(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, const char *, MagickOffsetType, MagickSizeType);
void LogMagickEvent(unsigned int, const char *, const char *, ...);
const char *GetMagickModule(void);