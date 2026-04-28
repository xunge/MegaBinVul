#include <assert.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    PingCache,
    MemoryCache,
    MapCache
} CacheType;

typedef enum {
    ReadMode,
    WriteMode
} CacheMode;

typedef struct _ExceptionInfo ExceptionInfo;

typedef struct _CacheInfo {
    CacheType type;
    size_t columns;
    size_t rows;
    MagickBooleanType active_index_channel;
    void *pixels;
    void *indexes;
    MagickBooleanType debug;
} CacheInfo;

typedef struct _NexusInfo {
    void *pixels;
    void *indexes;
    size_t length;
} NexusInfo;

typedef struct _PixelPacket PixelPacket;

typedef struct _RectangleInfo {
    size_t width;
    size_t height;
    ssize_t x;
    ssize_t y;
} RectangleInfo;

#define GetMagickResourceLimit(resource) 0
#define ThreadResource 0
#define ResourceLimitFatalError 0
#define MagickCacheOptions 0
#define CacheEvent 0
#define MaxTextExtent 256
#define MAGICKCORE_OPENMP_SUPPORT

static void ThrowFatalException(int error, const char *message) {}
static NexusInfo **AcquirePixelCacheNexus(size_t threads) { return NULL; }
static NexusInfo **DestroyPixelCacheNexus(NexusInfo **nexus, size_t threads) { return NULL; }
static void CopyPixels(void *dst, void *src, size_t count) {}
static PixelPacket *SetPixelCacheNexusPixels(CacheInfo *cache, CacheMode mode, RectangleInfo *region, MagickBooleanType sync, NexusInfo *nexus, ExceptionInfo *exception) { return NULL; }
static MagickBooleanType ReadPixelCachePixels(CacheInfo *cache, NexusInfo *nexus, ExceptionInfo *exception) { return MagickFalse; }
static MagickBooleanType WritePixelCachePixels(CacheInfo *cache, NexusInfo *nexus, ExceptionInfo *exception) { return MagickFalse; }
static MagickBooleanType ReadPixelCacheIndexes(CacheInfo *cache, NexusInfo *nexus, ExceptionInfo *exception) { return MagickFalse; }
static MagickBooleanType WritePixelCacheIndexes(CacheInfo *cache, NexusInfo *nexus, ExceptionInfo *exception) { return MagickFalse; }
static void *ResetMagickMemory(void *dst, int c, size_t n) { return NULL; }
static const char *CommandOptionToMnemonic(int options, ssize_t type) { return NULL; }
static void LogMagickEvent(int event, const char *module, const char *format, ...) {}
static int FormatLocaleString(char *str, size_t size, const char *format, ...) { return 0; }
static const char *GetMagickModule() { return NULL; }
static int GetOpenMPThreadId() { return 0; }
static size_t MagickMin(size_t a, size_t b) { return a < b ? a : b; }