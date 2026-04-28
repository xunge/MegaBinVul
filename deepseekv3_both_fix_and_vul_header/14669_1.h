#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>

#define MagickExport

typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef long long MagickOffsetType;

typedef enum {
  AlignedVirtualMemory,
  MapVirtualMemory,
  UnalignedVirtualMemory
} MemoryType;

typedef enum {
  ResourceLimitFatalError
} ExceptionType;

typedef enum {
  MemoryResource,
  MapResource,
  DiskResource
} ResourceType;

typedef enum {
  IOMode
} MapMode;

typedef struct _MemoryInfo {
  void *blob;
  size_t length;
  MemoryType type;
  unsigned long signature;
  char filename[4096];
} MemoryInfo;

extern MagickBooleanType CheckMemoryOverflow(size_t, size_t);
extern void *MagickAssumeAligned(void *);
extern void *AcquireAlignedMemory(size_t, size_t);
extern void ThrowFatalException(ExceptionType, const char *);
extern void *ResetMagickMemory(void *, int, size_t);
extern MagickBooleanType AcquireMagickResource(ResourceType, size_t);
extern void RelinquishMagickResource(ResourceType, size_t);
extern void *MapBlob(int, MapMode, off_t, size_t);
extern int AcquireUniqueFileResource(char *);
extern void RelinquishUniqueFileResource(const char *);
extern void *AcquireMagickMemory(size_t);
extern MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);

#define MagickCoreSignature 0xabacadabUL