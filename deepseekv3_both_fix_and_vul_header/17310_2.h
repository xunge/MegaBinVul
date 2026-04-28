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
} ModeType;

typedef unsigned long long MagickSizeType;

#define MagickResourceInfinity ((MagickSizeType) -1)

typedef enum {
    ThrottleResource,
    TimeResource
} ResourceType;

typedef enum {
    ResourceLimitFatalError
} ExceptionType;

typedef struct _CacheInfo {
    unsigned long reference_count;
    ModeType mode;
    SemaphoreInfo semaphore;
    ModeType type;
} CacheInfo;

typedef struct _Image {
    Cache cache;
    SemaphoreInfo semaphore;
    unsigned long reference_count;
    ModeType type;
} Image;

static MagickSizeType cache_epoch = 0;

#define magick_restrict

extern MagickSizeType GetMagickResourceLimit(ResourceType);
extern void MagickDelay(MagickSizeType);
extern void ThrowFatalException(ExceptionType, const char *);
extern SemaphoreInfo *AllocateSemaphoreInfo(void);
extern void LockSemaphoreInfo(SemaphoreInfo);
extern void UnlockSemaphoreInfo(SemaphoreInfo);
extern void DestroySemaphoreInfo(SemaphoreInfo *);
extern Cache ClonePixelCache(CacheInfo *);
extern Cache DestroyPixelCache(CacheInfo *);
extern MagickBooleanType OpenPixelCache(Image *, ModeType, ExceptionInfo *);
extern MagickBooleanType ClonePixelCacheRepository(CacheInfo *, CacheInfo *, ExceptionInfo *);
extern MagickBooleanType ValidatePixelCacheMorphology(Image *);
extern int ClosePixelCacheOnDisk(CacheInfo *);