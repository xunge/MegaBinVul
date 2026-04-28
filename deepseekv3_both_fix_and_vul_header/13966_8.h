#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef unsigned char MagickBooleanType;
typedef unsigned char Quantum;

#define MagickCoreSignature 0
#define MaxColormapSize 256
#define MagickFalse 0
#define MagickTrue 1
#define GRAYColorspace 0
#define GrayscaleType 0
#define PseudoClass 0
#define BilevelType 0
#define ResourceLimitError 0

typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _CacheView CacheView;
typedef struct _PixelInfo PixelInfo;
typedef struct _Image Image;

struct _Image {
    unsigned long signature;
    int type;
    int storage_class;
    char *filename;
    size_t colors;
    PixelInfo *colormap;
    size_t rows;
    size_t columns;
    int (*GetPixelChannels)(Image *);
};

struct _PixelInfo {
    double red;
    double green;
    double blue;
    double alpha;
};

#define ThrowBinaryException(a,b,c) 
#define AcquireQuantumMemory(a,b) malloc((a)*(b))
#define ResetMagickMemory(a,b,c) memset(a,b,c)
#define AcquireImageColormap(a,b,c) MagickTrue
#define AcquireAuthenticCacheView(a,b) NULL
#define GetCacheViewAuthenticPixels(a,b,c,d,e,f) NULL
#define SyncCacheViewAuthenticPixels(a,b) MagickFalse
#define DestroyCacheView(a) NULL
#define ScaleQuantumToMap(a) 0
#define GetPixelRed(a,b) 0
#define GetPixelGreen(a,b) 0
#define GetPixelBlue(a,b) 0
#define SetPixelIndex(a,b,c) 
#define GetPixelIndex(a,b) 0
#define RelinquishMagickMemory(a) (free(a), NULL)
#define SetImageMonochrome(a,b) MagickFalse
#define IsPixelInfoEquivalent(a,b) 0
#define TransformImageColorspace(a,b,c) MagickTrue

int IntensityCompare(const void *a, const void *b);

static int GetPixelChannels(Image *image) {
    return 0;
}

#define magick_restrict