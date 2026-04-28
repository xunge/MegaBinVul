#include <stddef.h>

typedef unsigned char MagickBooleanType;
#define MagickTrue 1
#define MagickFalse 0

typedef struct _Image {
    size_t rows;
    size_t columns;
} Image;

typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _CacheView CacheView;
typedef double Quantum;
typedef ptrdiff_t ssize_t;

#define QuantumRange 65535.0
#define QuantumScale (1.0/QuantumRange)
#define magick_restrict __restrict

double GetPixela(const Image *, const Quantum *);
double GetPixelb(const Image *, const Quantum *);
void SetPixela(Image *, Quantum, Quantum *);
void SetPixelb(Image *, Quantum, Quantum *);
size_t GetPixelChannels(const Image *);
CacheView *AcquireAuthenticCacheView(Image *, ExceptionInfo *);
Quantum *GetCacheViewAuthenticPixels(CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
MagickBooleanType SyncCacheViewAuthenticPixels(CacheView *, ExceptionInfo *);
CacheView *DestroyCacheView(CacheView *);