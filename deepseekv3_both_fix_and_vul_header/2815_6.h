#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#define restrict __restrict

typedef unsigned char Quantum;
typedef unsigned int MagickBooleanType;
typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;
typedef double MagickRealType;
typedef void (*MagickProgressMonitor)(const char*, MagickOffsetType, MagickSizeType);

typedef struct _MemoryInfo MemoryInfo;
typedef struct _CacheView CacheView;
typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char* filename;
    size_t columns;
    size_t rows;
    size_t storage_class;
    MagickProgressMonitor progress_monitor;
} Image;

typedef enum {
    UndefinedPixelTrait,
    RedPixelChannel,
    GreenPixelChannel,
    BluePixelChannel
} PixelChannel;

typedef enum {
    UndefinedTrait,
    UpdatePixelTrait,
    CopyPixelTrait,
    BlendPixelTrait
} PixelTrait;

typedef enum {
    ResourceLimitError
} ExceptionType;

typedef enum {
    TraceEvent
} LogEventType;

typedef enum {
    WidthResource
} ResourceType;

typedef enum {
    DirectClass
} StorageClass;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBool;

#define MagickCoreSignature 0x12345678
#define MAGICKCORE_OPENCL_SUPPORT
#define MAGICKCORE_OPENMP_SUPPORT
#define AddNoiseImageTag "AddNoise"

#define MagickExport

static inline size_t MagickMax(const size_t a, const size_t b) {
    return (a > b) ? a : b;
}

void* AcquireQuantumMemory(size_t, size_t);
void* AcquireVirtualMemory(size_t, size_t);
void* DestroyCacheView(CacheView*);
void* DestroyImage(Image*);
const Quantum* GetCacheViewAuthenticPixels(const CacheView*, ssize_t, ssize_t, size_t, size_t, ExceptionInfo*);
void* GetVirtualMemoryBlob(MemoryInfo*);
void* RelinquishMagickMemory(void*);
void* RelinquishVirtualMemory(MemoryInfo*);
MagickBooleanType SetImageProgress(Image*, const char*, MagickOffsetType, size_t);

CacheView* AcquireAuthenticCacheView(const Image*, ExceptionInfo*);
Image* AccelerateWaveletDenoiseImage(const Image*, double, ExceptionInfo*);
Image* CloneImage(const Image*, ssize_t, ssize_t, MagickBooleanType, ExceptionInfo*);
MagickBooleanType AcquireMagickResource(ResourceType, size_t);
MagickBooleanType SetImageStorageClass(Image*, StorageClass, ExceptionInfo*);
MagickBooleanType SyncCacheViewAuthenticPixels(CacheView*, ExceptionInfo*);
PixelTrait GetPixelChannelTraits(const Image*, PixelChannel);
size_t GetOpenMPMaximumThreads();
size_t GetPixelChannels(const Image*);
ssize_t GetOpenMPThreadId();
ssize_t GetPixelChannelOffset(const Image*, PixelChannel);
void HatTransform(float*, ssize_t, size_t, size_t, float*);
void LogMagickEvent(LogEventType, const char*, const char*, const char*);
void ThrowImageException(ExceptionType, const char*);

#define GetMagickModule() "MagickCore"
#define GetPixelChannelChannel(image,channel) (channel)
#define ClampToQuantum(x) ((Quantum) (x))

/* Remove magick_restrict keyword */
#define magick_restrict

/* Fix const correctness for SetImageProgress */
static inline MagickBooleanType WaveletDenoiseSetImageProgress(const Image *image, const char *tag, MagickOffsetType offset, size_t span) {
    return SetImageProgress((Image *)image, tag, offset, span);
}