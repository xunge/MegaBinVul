#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <sys/types.h>

typedef struct _Image {
    unsigned long signature;
    char *filename;
    unsigned int alpha_trait;
    unsigned int compose;
    size_t columns;
    size_t rows;
    void *border_color;
    void *background_color;
    struct {
        size_t width;
        size_t height;
    } page;
} Image;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef struct _RectangleInfo {
    size_t width;
    size_t height;
    long x;
    long y;
} RectangleInfo;

typedef enum _MagickBooleanType {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum _PixelTrait {
    UndefinedPixelTrait
} PixelTrait;

typedef enum _CompositeOperator {
    CopyCompositeOp
} CompositeOperator;

typedef enum _AlphaChannelOption {
    OpaqueAlphaChannel
} AlphaChannelOption;

typedef double MagickRealType;

#define MagickExport
#define MagickCoreSignature 0xABACADABUL
#define DirectClass 0
#define ResourceLimitError 0
#define TraceEvent 0

extern Image *IntegralRotateImage(const Image *, size_t, ExceptionInfo *);
extern void ThrowImageException(unsigned int, const char *);
extern MagickBooleanType SetImageStorageClass(Image *, unsigned int, ExceptionInfo *);
extern MagickBooleanType SetImageAlphaChannel(Image *, AlphaChannelOption, ExceptionInfo *);
extern Image *BorderImage(Image *, RectangleInfo *, CompositeOperator, ExceptionInfo *);
extern Image *DestroyImage(Image *);
extern MagickBooleanType XShearImage(Image *, double, size_t, size_t, ssize_t, ssize_t, ExceptionInfo *);
extern MagickBooleanType YShearImage(Image *, double, size_t, size_t, ssize_t, ssize_t, ExceptionInfo *);
extern MagickBooleanType CropToFitImage(Image **, double, double, MagickRealType, MagickRealType, MagickBooleanType, ExceptionInfo *);
extern MagickBooleanType IsEventLogging(void);
extern void *LogMagickEvent(unsigned int, const char *, const char *, ...);
extern const char *GetMagickModule(void);
extern double DegreesToRadians(double);
extern long CastDoubleToLong(double);