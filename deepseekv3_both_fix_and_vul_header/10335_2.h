#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MagickExport

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    AlignedVirtualMemory,
    MapVirtualMemory,
    UnalignedVirtualMemory
} VirtualMemoryType;

typedef enum {
    MemoryResource,
    MapResource,
    DiskResource
} MagickResourceType;

typedef enum {
    ReadMode,
    WriteMode,
    IOMode
} MapMode;

typedef enum {
    UndefinedException,
    ResourceLimitFatalError
} ExceptionType;

typedef struct _MemoryInfo {
    size_t length;
    unsigned long signature;
    void *blob;
    VirtualMemoryType type;
    char filename[4096];
} MemoryInfo;

#define MagickSignature 0xabacadabUL

void *AcquireAlignedMemory(size_t, size_t);
void *AcquireMagickMemory(size_t);
void *MapBlob(int, MapMode, off_t, size_t);
void *MagickAssumeAligned(void *);
void ThrowFatalException(ExceptionType, const char *);
void RelinquishMagickResource(MagickResourceType, size_t);
int AcquireMagickResource(MagickResourceType, size_t);
int AcquireUniqueFileResource(char *);
int RelinquishUniqueFileResource(const char *);
void *ResetMagickMemory(void *, int, size_t);
MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);