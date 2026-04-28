#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdint.h>
#ifdef HAVE_MMAP
#include <sys/mman.h>
#endif
#ifdef _WIN32
#include <windows.h>
#include <io.h>
#endif
#if (HAVE_POSIX_FADVISE) && defined(POSIX_FADV_WILLNEED)
#include <fcntl.h>
#endif

typedef int FcBool;
#define FcFalse 0
#define FcTrue 1

#define FC_CACHE_MAGIC_MMAP 0xFC123456
#define FC_CACHE_VERSION_NUMBER 1
#define FC_CACHE_MIN_MMAP 4096
#define FC_CACHE_MAGIC_ALLOC 0xFC654321

typedef struct FcCache {
    uint32_t magic;
    uint32_t version;
    intptr_t size;
    /* other members... */
} FcCache;

typedef struct FcConfig FcConfig;

FcCache *FcCacheFindByStat(struct stat *);
FcBool FcCacheTimeValid(FcConfig *, FcCache *, struct stat *);
void FcDirCacheUnload(FcCache *);
FcBool FcCacheIsMmapSafe(int);
FcBool FcCacheInsert(FcCache *, struct stat *);