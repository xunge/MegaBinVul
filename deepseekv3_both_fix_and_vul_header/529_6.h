#include <assert.h>
#include <stddef.h>

typedef int MagickBooleanType;
typedef ptrdiff_t MagickOffsetType;
typedef ptrdiff_t ssize_t;
typedef size_t Quantum;
typedef void (*MagickProgressMonitor)(const char *, const MagickOffsetType, const MagickOffsetType);

typedef struct _ExceptionInfo {
    unsigned long signature;
    void *exception;
} ExceptionInfo;

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    size_t columns;
    size_t rows;
    MagickProgressMonitor progress_monitor;
    ExceptionInfo exception;
} Image;

typedef struct _CacheView CacheView;

typedef struct _MagickPixelPacket {
    double red;
    double green;
    double blue;
    double opacity;
} MagickPixelPacket;

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef struct _PixelPacket {
    double red;
    double green;
    double blue;
    double opacity;
} PixelPacket;

typedef unsigned char IndexPacket;

#define restrict __restrict

#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define QuantumScale (1.0/QuantumRange)
#define QuantumRange ((Quantum) 1 << 16)
#define ClampToQuantum(quantum) ((quantum) < 0.0 ? 0.0 : ((quantum) > QuantumRange ? QuantumRange : (quantum)))

#define MagickExport
#define MaxMeanShiftIterations 100
#define MeanShiftImageTag "MeanShift/Image"

enum {
    TraceEvent,
    DirectClass
};

double MagickRound(double);
Image *CloneImage(const Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
MagickBooleanType SetImageStorageClass(Image *, int);
void InheritException(ExceptionInfo *, ExceptionInfo *);
Image *DestroyImage(Image *);
CacheView *AcquireVirtualCacheView(const Image *, ExceptionInfo *);
CacheView *AcquireAuthenticCacheView(Image *, ExceptionInfo *);
const PixelPacket *GetCacheViewVirtualPixels(const CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
PixelPacket *GetCacheViewAuthenticPixels(CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
const IndexPacket *GetCacheViewVirtualIndexQueue(const CacheView *);
void GetMagickPixelPacket(const Image *, MagickPixelPacket *);
void SetMagickPixelPacket(const Image *, const PixelPacket *, const IndexPacket *, MagickPixelPacket *);
MagickBooleanType GetOneCacheViewVirtualPixel(CacheView *, ssize_t, ssize_t, PixelPacket *, ExceptionInfo *);
MagickBooleanType SyncCacheViewAuthenticPixels(CacheView *, ExceptionInfo *);
CacheView *DestroyCacheView(CacheView *);
MagickBooleanType SetImageProgress(const Image *, const char *, MagickOffsetType, MagickOffsetType);
void *LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);

/* Remove magick_restrict keyword */
#define magick_restrict