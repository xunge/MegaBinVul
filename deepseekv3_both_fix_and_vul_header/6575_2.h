#include <assert.h>
#include <errno.h>
#include <time.h>

typedef void *Cache;
typedef void *ExceptionInfo;
typedef void *SemaphoreInfo;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    ReadMode,
    IOMode,
    DiskCache,
    UndefinedType
} CacheMode;

typedef unsigned long long MagickSizeType;

#define MagickResourceInfinity ((MagickSizeType) -1)

typedef struct _CacheInfo {
    unsigned long reference_count;
    CacheMode mode;
    CacheMode type;
    SemaphoreInfo semaphore;
} CacheInfo;

typedef struct _Image {
    Cache cache;
    SemaphoreInfo semaphore;
    unsigned long reference_count;
    CacheMode type;
} Image;

static MagickSizeType cache_epoch = 0;

enum {
    ThrottleResource,
    TimeResource,
    ResourceLimitFatalError
};

extern MagickSizeType GetMagickResourceLimit(int);
extern void MagickDelay(MagickSizeType);
extern void ThrowFatalException(int, const char *);
extern void LockSemaphoreInfo(SemaphoreInfo);
extern void UnlockSemaphoreInfo(SemaphoreInfo);
extern SemaphoreInfo AllocateSemaphoreInfo(void);
extern void DestroySemaphoreInfo(SemaphoreInfo *);
extern Cache ClonePixelCache(CacheInfo *);
extern MagickBooleanType OpenPixelCache(Image *, CacheMode, ExceptionInfo);
extern MagickBooleanType ClonePixelCacheRepository(CacheInfo *, CacheInfo *, ExceptionInfo);
extern CacheInfo *DestroyPixelCache(CacheInfo *);
extern MagickBooleanType ValidatePixelCacheMorphology(Image *);
extern int ClosePixelCacheOnDisk(CacheInfo *);

#define magick_restrict