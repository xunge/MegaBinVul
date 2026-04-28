#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>

#define MagickExport

typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef long long MagickOffsetType;

typedef enum {
  ResourceLimitFatalError
} ExceptionType;

typedef enum {
  AlignedVirtualMemory,
  MapVirtualMemory,
  UnalignedVirtualMemory
} MemoryType;

typedef enum {
  ReadMode,
  WriteMode,
  IOMode
} MapMode;

typedef struct _MemoryInfo {
  void *blob;
  size_t length;
  unsigned long signature;
  MemoryType type;
  char filename[4096];
} MemoryInfo;

extern int HeapOverflowSanityCheck(size_t, size_t);
extern void *MagickAssumeAligned(void *);
extern void *AcquireAlignedMemory(size_t, size_t);
extern void ThrowFatalException(ExceptionType, const char *);
extern void *ResetMagickMemory(void *, int, size_t);
extern char *GetPolicyValue(const char *);
extern char *DestroyString(char *);
extern int LocaleCompare(const char *, const char *);
extern MagickBooleanType AcquireMagickResource(const char *, size_t);
extern void RelinquishMagickResource(const char *, size_t);
extern void *MapBlob(int, MapMode, MagickOffsetType, size_t);
extern int AcquireUniqueFileResource(char *);
extern void RelinquishUniqueFileResource(const char *);
extern void *AcquireMagickMemory(size_t);
extern MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);

#define MagickSignature 0xabacadabUL
#define MemoryResource "memory"
#define MapResource "map"
#define DiskResource "disk"