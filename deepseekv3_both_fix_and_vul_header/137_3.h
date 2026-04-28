#include <assert.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char Quantum;
typedef int MagickBooleanType;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef struct _CacheView CacheView;
typedef struct _PixelInfo PixelInfo;

#define MagickCoreSignature 0xabacadabUL
#define GrayscaleType 0
#define GRAYColorspace 0
#define PseudoClass 0
#define MagickFalse 0
#define MagickTrue 1
#define MaxColormapSize 256
#define MaxMap 256
#define ResourceLimitError 0
#define BilevelType 0

struct _PixelInfo {
    double red;
    double green;
    double blue;
    double alpha;
};

struct _Image {
    unsigned long signature;
    int type;
    int storage_class;
    char *filename;
    size_t colors;
    PixelInfo *colormap;
    size_t rows;
    size_t columns;
    size_t depth;
};

struct _CacheView {
    Image *image;
};

struct _ExceptionInfo {
    int severity;
};

#define MagickMax(a,b) ((a) > (b) ? (a) : (b))

static void *AcquireQuantumMemory(size_t count, size_t quantum) { return malloc(count * quantum); }
static void *RelinquishMagickMemory(void *memory) { free(memory); return NULL; }
static MagickBooleanType AcquireImageColormap(Image *image, size_t depth, ExceptionInfo *exception) { return MagickTrue; }
static CacheView *AcquireAuthenticCacheView(Image *image, ExceptionInfo *exception) { return (CacheView *)image; }
static Quantum *GetCacheViewAuthenticPixels(CacheView *image_view, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception) { return (Quantum *)image_view->image; }
static MagickBooleanType SyncCacheViewAuthenticPixels(CacheView *image_view, ExceptionInfo *exception) { return MagickTrue; }
static CacheView *DestroyCacheView(CacheView *image_view) { return NULL; }
static size_t ScaleQuantumToMap(Quantum quantum) { return quantum; }
static Quantum GetPixelRed(const Image *image, const Quantum *p) { return *p; }
static Quantum GetPixelGreen(const Image *image, const Quantum *p) { return *p; }
static Quantum GetPixelBlue(const Image *image, const Quantum *p) { return *p; }
static void SetPixelIndex(const Image *image, Quantum index, Quantum *p) { *p = index; }
static size_t GetPixelChannels(const Image *image) { return 1; }
static Quantum GetPixelIndex(const Image *image, const Quantum *p) { return *p; }
static int IsPixelInfoEquivalent(const PixelInfo *a, const PixelInfo *b) { return 1; }
static int IntensityCompare(const void *x, const void *y) { return 0; }
static MagickBooleanType TransformImageColorspace(Image *image, int colorspace, ExceptionInfo *exception) { return MagickTrue; }
static MagickBooleanType SetImageMonochrome(Image *image, ExceptionInfo *exception) { return MagickTrue; }
static void ThrowBinaryException(int error, const char *reason, const char *description) {}

#define magick_restrict