#include <assert.h>
#include <stddef.h>

#define MagickExport
#define restrict __restrict

typedef unsigned int MagickBooleanType;
typedef void (*MagickProgressMonitor)(const char *, long, unsigned long, void *);

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    size_t rows;
    size_t columns;
    size_t channels;
    MagickProgressMonitor progress_monitor;
} Image;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _CacheView CacheView;

typedef struct _PixelInfo {
    double red;
    double green;
    double blue;
    double black;
    double alpha;
} PixelInfo;

typedef long MagickOffsetType;
typedef unsigned long MagickSizeType;
typedef size_t ssize_t;
typedef double Quantum;

#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define MagickEpsilon 1.0e-10
#define QuantumScale (1.0/QuantumRange)
#define QuantumRange 65535.0
#define TraceEvent 0
#define DirectClass 1

extern Image *CloneImage(const Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
extern Image *DestroyImage(Image *);
extern MagickBooleanType SetImageStorageClass(Image *, int, ExceptionInfo *);
extern CacheView *AcquireVirtualCacheView(const Image *, ExceptionInfo *);
extern CacheView *AcquireAuthenticCacheView(Image *, ExceptionInfo *);
extern const Quantum *GetCacheViewVirtualPixels(const CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
extern Quantum *QueueCacheViewAuthenticPixels(CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
extern MagickBooleanType SyncCacheViewAuthenticPixels(CacheView *, ExceptionInfo *);
extern CacheView *DestroyCacheView(CacheView *);
extern void GetPixelInfo(const Image *, PixelInfo *);
extern void GetPixelInfoPixel(const Image *, const Quantum *, PixelInfo *);
extern void SetPixelViaPixelInfo(const Image *, const PixelInfo *, Quantum *);
extern size_t GetPixelChannels(const Image *);
extern Quantum GetPixelRed(const Image *, const Quantum *);
extern Quantum GetPixelGreen(const Image *, const Quantum *);
extern Quantum GetPixelBlue(const Image *, const Quantum *);
extern Quantum GetPixelBlack(const Image *, const Quantum *);
extern Quantum GetPixelAlpha(const Image *, const Quantum *);
extern MagickBooleanType SetImageProgress(const Image *, const char *, MagickOffsetType, MagickOffsetType);
extern void *LogMagickEvent(unsigned int, const char *, const char *, ...);
extern const char *GetMagickModule(void);

/* Remove magick_restrict keyword */
#define magick_restrict