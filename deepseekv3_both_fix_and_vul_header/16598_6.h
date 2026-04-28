#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <sys/types.h>

typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;
typedef unsigned int MagickBooleanType;

#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define OpaqueAlpha 0
#define OpaqueAlphaChannel 1
#define DirectClass 1
#define MagickPI 3.14159265358979323846
#define MAGICKCORE_OPENMP_SUPPORT

typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef struct _CacheView CacheView;
typedef struct _PointInfo PointInfo;

struct _PointInfo {
    double x;
    double y;
};

typedef enum {
    UndefinedPixelChannel
} PixelChannel;

typedef enum {
    UndefinedPixelTrait = 0
} PixelTrait;

typedef enum {
    UndefinedInterpolatePixel
} PixelInterpolateMethod;

typedef MagickBooleanType (*MagickProgressMonitor)(const char *,
    MagickOffsetType, const MagickSizeType, void *);

#define MagickExport

typedef unsigned char Quantum;

struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    unsigned long columns;
    unsigned long rows;
    PixelTrait alpha_trait;
    struct {
        unsigned int alpha;
    } background_color;
    MagickProgressMonitor progress_monitor;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _CacheView {
    void *dummy;
};

Image *CloneImage(const Image *,size_t,size_t,MagickBooleanType,ExceptionInfo *);
MagickBooleanType SetImageAlphaChannel(Image *,int,ExceptionInfo *);
MagickBooleanType SetImageStorageClass(Image *,int,ExceptionInfo *);
Image *DestroyImage(Image *);
CacheView *AcquireVirtualCacheView(const Image *,ExceptionInfo *);
CacheView *AcquireAuthenticCacheView(Image *,ExceptionInfo *);
const Quantum *GetCacheViewVirtualPixels(const CacheView *,ssize_t,ssize_t,size_t,size_t,ExceptionInfo *);
Quantum *QueueCacheViewAuthenticPixels(CacheView *,ssize_t,ssize_t,size_t,size_t,ExceptionInfo *);
MagickBooleanType InterpolatePixelChannels(const Image *,CacheView *,Image *,PixelInterpolateMethod,double,double,Quantum *,ExceptionInfo *);
MagickBooleanType SyncCacheViewAuthenticPixels(CacheView *,ExceptionInfo *);
MagickBooleanType SetImageProgress(const Image *,const char *,MagickOffsetType,MagickSizeType);
CacheView *DestroyCacheView(CacheView *);

#define GetPixelChannels(image) 0
#define GetPixelChannelChannel(image,channel) UndefinedPixelChannel
#define GetPixelChannelTraits(image,channel) UndefinedPixelTrait
#define SetPixelChannel(image,channel,value,q) 
#define LogMagickEvent(event,module,format,...) (void)0
#define TraceEvent 0
#define GetMagickModule() ""

#define magick_restrict