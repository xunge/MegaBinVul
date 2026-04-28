#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

typedef double MagickRealType;

typedef enum {
    NoneDispose,
    BackgroundDispose,
    PreviousDispose,
    DelDispose,
    DupDispose
} DisposeType;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    OptimizeLayer,
    OptimizeImageLayer,
    OptimizePlusLayer
} LayerMethod;

typedef enum {
    BlendPixelTrait
} AlphaTraitType;

typedef enum {
    TransparentAlpha = 0,
    OpaqueAlpha = 1
} AlphaType;

typedef enum {
    CompareAnyLayer,
    CompareClearLayer,
    CompareOverlayLayer
} LayerCompareType;

typedef enum {
    OptionError,
    ResourceLimitError
} ExceptionType;

typedef struct {
    int x;
    int y;
    unsigned long width;
    unsigned long height;
} RectangleInfo;

typedef struct {
    AlphaTraitType alpha_trait;
    MagickRealType alpha;
} PixelInfo;

typedef struct Image {
    RectangleInfo page;
    PixelInfo background_color;
    DisposeType dispose;
    unsigned long delay;
    unsigned long ticks_per_second;
    struct Image *previous;
    unsigned long columns;
    unsigned long rows;
    MagickBooleanType debug;
    char *filename;
    unsigned long signature;
} Image;

typedef struct {
    unsigned long signature;
} ExceptionInfo;

#define MagickCoreSignature 0xabacadabUL
#define TraceEvent 0

Image *CloneImage(const Image *, unsigned long, unsigned long, MagickBooleanType, ExceptionInfo *);
Image *DestroyImage(Image *);
Image *DestroyImageList(Image *);
Image *NewImageList(void);
Image *GetFirstImageInList(const Image *);
Image *GetNextImageInList(const Image *);
Image *CropImage(Image *, const RectangleInfo *, ExceptionInfo *);
Image *ReferenceImage(const Image *);

void AppendImageToList(Image **, Image *);
void ClearBounds(Image *, const RectangleInfo *, ExceptionInfo *);
void ThrowImageException(ExceptionType, const char *);

size_t GetImageListLength(const Image *);
RectangleInfo CompareImagesBounds(const Image *, const Image *, LayerCompareType, ExceptionInfo *);
MagickBooleanType IsBoundsCleared(const Image *, const Image *, const RectangleInfo *, ExceptionInfo *);
MagickBooleanType SetImageBackgroundColor(Image *, ExceptionInfo *);

void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);

ExceptionInfo *AcquireExceptionInfo(void);
ExceptionInfo *DestroyExceptionInfo(ExceptionInfo *);

void LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
const char *CommandOptionToMnemonic(const void *, DisposeType);