#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <sys/types.h>

typedef enum {
    sRGBColorspace
} ColorspaceType;

typedef enum {
    UndefinedPixelTrait,
    BlendPixelTrait
} AlphaTraitType;

typedef struct _PixelInfo {
    AlphaTraitType alpha_trait;
    double alpha;
} PixelInfo;

typedef struct _RectangleInfo {
    size_t width;
    size_t height;
    off_t x;
    off_t y;
} RectangleInfo;

typedef struct _Image {
    unsigned long signature;
    char *filename;
    ColorspaceType colorspace;
    AlphaTraitType alpha_trait;
    PixelInfo border_color;
    PixelInfo background_color;
    size_t rows;
    size_t columns;
    struct {
        size_t width;
        size_t height;
        off_t x;
        off_t y;
    } page;
} Image;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _CacheView CacheView;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    AlphaChannel
} ChannelType;

typedef enum {
    EdgeVirtualPixelMethod
} VirtualPixelMethod;

typedef enum {
    OpaqueAlphaChannel
} AlphaChannelOption;

typedef enum {
    OverCompositeOp
} CompositeOperator;

typedef enum {
    AllCompliance
} ComplianceType;

typedef enum {
    TraceEvent
} LogEventType;

typedef double Quantum;
typedef Quantum * QuantumPtr;

#define restrict __restrict__

#define MagickCoreSignature 0x12345678
#define MagickExport
#define GetMagickModule() ""
#define IsEventLogging() MagickFalse
#define LogMagickEvent(a,b,c,d) 0
#define IsGrayColorspace(c) MagickFalse
#define GetPixelAlpha(image,q) 0
#define GetPixelChannels(image) 0
#define SetPixelViaPixelInfo(image,color,q)
#define QueueCacheViewAuthenticPixels(view,x,y,width,height,exception) ((QuantumPtr)NULL)
#define SyncCacheViewAuthenticPixels(view,exception) MagickFalse
#define AcquireAuthenticCacheView(image,exception) ((CacheView *)NULL)
#define DestroyCacheView(view) ((CacheView *)NULL)
#define CloneImage(image,width,height,clone,exception) ((Image *)NULL)
#define DestroyImage(image) ((Image *)NULL)
#define BorderImage(image,border_info,composite,exception) ((Image *)NULL)
#define SetImageAlphaChannel(image,alpha,exception) MagickFalse
#define SetImageChannelMask(image,channel) 0
#define SetPixelChannelMask(image,channel_mask) ((void)0)
#define BlurImage(image,radius,sigma,exception) ((Image *)NULL)
#define SetImageColorspace(image,colorspace,exception) MagickFalse
#define SetImageVirtualPixelMethod(image,method,exception) MagickFalse
#define QueryColorCompliance(color,compliance,border_color,exception) MagickFalse

/* Fix for magick_restrict q declaration */
#define magick_restrict __restrict__