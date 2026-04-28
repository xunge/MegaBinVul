#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

#define QuantumRange 255
#define restrict __restrict
#define magick_restrict __restrict

typedef unsigned char Quantum;
typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;
typedef enum { MagickFalse, MagickTrue } MagickBooleanType;

#define MagickExport

typedef struct _Image {
    size_t signature;
    MagickBooleanType debug;
    char *filename;
    size_t rows;
    size_t columns;
    size_t type;
    void (*progress_monitor)(const char *, const MagickOffsetType, const MagickSizeType);
} Image;

typedef struct _ExceptionInfo {
    size_t signature;
} ExceptionInfo;

typedef struct _CacheView CacheView;

typedef void (*MagickProgressMonitor)(const char *, const MagickOffsetType, const MagickSizeType);

typedef enum {
    UndefinedPixelTrait,
    CopyPixelTrait
} PixelTrait;

typedef enum {
    MaxPixelChannels = 32
} PixelChannel;

typedef enum {
    TraceEvent
} LogEventType;

typedef enum {
    DirectClass
} ClassType;

#define MagickCoreSignature 0xabacadabUL

extern void *GetMagickModule(void);
extern Image *CloneImage(const Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
extern MagickBooleanType SetImageStorageClass(Image *, ClassType, ExceptionInfo *);
extern Image *DestroyImage(Image *);
extern CacheView *AcquireVirtualCacheView(const Image *, ExceptionInfo *);
extern CacheView *AcquireAuthenticCacheView(Image *, ExceptionInfo *);
extern const Quantum *GetCacheViewVirtualPixels(CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
extern Quantum *QueueCacheViewAuthenticPixels(CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
extern MagickBooleanType SyncCacheViewAuthenticPixels(CacheView *, ExceptionInfo *);
extern void *DestroyCacheView(CacheView *);
extern MagickBooleanType SetImageProgress(const Image *, const char *, MagickOffsetType, MagickSizeType);
extern void LogMagickEvent(LogEventType, void *, const char *, ...);
extern size_t GetPixelChannels(const Image *);
extern PixelChannel GetPixelChannelChannel(const Image *, ssize_t);
extern PixelTrait GetPixelChannelTraits(const Image *, PixelChannel);
extern void SetPixelChannel(Image *, PixelChannel, Quantum, Quantum *);