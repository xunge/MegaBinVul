#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <sys/types.h>

#define MagickTrue 1
#define MagickFalse 0
#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define MagickEpsilon 1.0e-10
#define MagickImageFilterSignature 0x6889e3e2UL
#define QuantumRange 65535.0

typedef unsigned char MagickBooleanType;
typedef double Quantum;

struct _Image {
    size_t signature;
    size_t rows;
    size_t columns;
    size_t channels;
};

struct _CacheView;
struct _ExceptionInfo;

typedef struct _Image Image;
typedef struct _CacheView CacheView;
typedef struct _ExceptionInfo ExceptionInfo;

Image *GetNextImageInList(const Image *);
CacheView *AcquireVirtualCacheView(Image *,ExceptionInfo *);
CacheView *DestroyCacheView(CacheView *);
const Quantum *GetCacheViewVirtualPixels(CacheView *,ssize_t,ssize_t,size_t,size_t,ExceptionInfo *);
double GetPixelRed(const Image *,const Quantum *);
double GetPixelGreen(const Image *,const Quantum *);
double GetPixelBlue(const Image *,const Quantum *);
void ConvertRGBToHSL(double,double,double,double *,double *,double *);
int FormatLocaleString(char *,size_t,const char *,...);
int SetImageProperty(Image *,const char *,const char *,ExceptionInfo *);
size_t GetPixelChannels(const Image *);

#define ModuleExport