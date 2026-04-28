#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long Quantum;
typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;
typedef unsigned char MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

#define MagickCoreSignature 0xabacadabUL
#define MaxMap 65535
#define QuantumRange ((Quantum) 65535UL)
#define ScaleQuantumToMap(x) ((unsigned short) (((double) (x)*MaxMap)/QuantumRange))
#define ScaleMapToQuantum(x) ((Quantum) (((double) (x)*QuantumRange)/MaxMap))
#define ClampToQuantum(x) ((Quantum) ((x) < 0 ? 0 : ((x) > QuantumRange ? QuantumRange : (x))))

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
  UpdatePixelTrait
} PixelTrait;

typedef enum
{
  UndefinedColorspace,
  GRAYColorspace
} ColorspaceType;

typedef enum
{
  UndefinedClass,
  PseudoClass
} ClassType;

typedef enum
{
  UndefinedException,
  ResourceLimitError
} ExceptionType;

typedef enum
{
  DefaultChannels = 0x7ffffff
} ChannelType;

typedef enum
{
  TraceEvent
} LogEventType;

typedef struct _ExceptionInfo
{
  ExceptionType severity;
} ExceptionInfo;

typedef struct _Image
{
  unsigned long signature;
  MagickBooleanType debug;
  char *filename;
  size_t rows;
  size_t columns;
  ClassType storage_class;
  size_t colors;
  ChannelType channel_mask;
  struct _Colormap *colormap;
  void *progress_monitor;
} Image;

typedef struct _Colormap
{
  Quantum red;
  Quantum green;
  Quantum blue;
  Quantum alpha;
} Colormap;

typedef struct _CacheView CacheView;

typedef MagickBooleanType (*MagickProgressMonitor)(const char *, MagickOffsetType, MagickSizeType, void *);

#define GetPixelChannels(image) (4)
#define GetPixelChannelOffset(image,channel) (channel)
#define GetPixelChannelChannel(image,offset) (offset)
#define GetPixelChannelTraits(image,channel) (UpdatePixelTrait)
#define GetPixelRedTraits(image) (UpdatePixelTrait)
#define GetPixelGreenTraits(image) (UpdatePixelTrait)
#define GetPixelBlueTraits(image) (UpdatePixelTrait)
#define GetPixelAlphaTraits(image) (UpdatePixelTrait)
#define GetPixelReadMask(image,q) (1)
#define GetPixelIntensity(image,p) (0.0)

#define magick_restrict

extern void *AcquireQuantumMemory(size_t count, size_t quantum);
extern void *RelinquishMagickMemory(void *memory);
extern void *ResetMagickMemory(void *memory, int c, size_t n);
extern MagickBooleanType LogMagickEvent(LogEventType event,const char *module,const char *format,...);
extern MagickBooleanType SetImageGray(Image *image,ExceptionInfo *exception);
extern MagickBooleanType SetImageColorspace(Image *image,ColorspaceType colorspace,ExceptionInfo *exception);
extern CacheView *AcquireVirtualCacheView(const Image *image,ExceptionInfo *exception);
extern const Quantum *GetCacheViewVirtualPixels(const CacheView *cache_view,const ssize_t x,const ssize_t y,const size_t columns,const size_t rows,ExceptionInfo *exception);
extern CacheView *DestroyCacheView(CacheView *cache_view);
extern CacheView *AcquireAuthenticCacheView(Image *image,ExceptionInfo *exception);
extern Quantum *GetCacheViewAuthenticPixels(CacheView *cache_view,const ssize_t x,const ssize_t y,const size_t columns,const size_t rows,ExceptionInfo *exception);
extern MagickBooleanType SyncCacheViewAuthenticPixels(CacheView *cache_view,ExceptionInfo *exception);
extern MagickBooleanType SetImageProgress(Image *image,const char *tag,const MagickOffsetType offset,const MagickSizeType span);
extern void ThrowBinaryException(ExceptionType severity,const char *reason,const char *description);
extern const char *GetMagickModule(void);
extern double PerceptibleReciprocal(const double x);

#define MagickExport