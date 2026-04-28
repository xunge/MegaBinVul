#include <stddef.h>
#include <unistd.h>
#include <errno.h>

#define MagickExport

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum
{
  UndefinedVirtualMemory,
  AlignedVirtualMemory,
  MapVirtualMemory,
  UnalignedVirtualMemory
} VirtualMemoryType;

typedef enum
{
  UndefinedResource,
  MemoryResource,
  MapResource,
  DiskResource
} ResourceType;

typedef enum
{
  UndefinedIOMode,
  ReadMode,
  WriteMode,
  ReadWriteMode
} IOMode;

typedef struct _MemoryInfo
{
  size_t
    length;

  void
    *blob;

  VirtualMemoryType
    type;

  char
    filename[4096];

  unsigned long
    signature;
} MemoryInfo;

#define MagickSignature 0xabacadabUL
#define ResourceLimitFatalError 1

static const IOMode DefaultIOMode = ReadWriteMode;

extern void *AcquireAlignedMemory(const size_t,const size_t);
extern void *AcquireMagickMemory(const size_t);
extern void *MapBlob(const int,const IOMode,const off_t,const size_t);
extern int AcquireUniqueFileResource(char *);
extern MagickBooleanType AcquireMagickResource(const ResourceType,const size_t);
extern void RelinquishMagickResource(const ResourceType,const size_t);
extern MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);
extern void ThrowFatalException(const size_t,const char *);
extern void *MagickAssumeAligned(void *);
extern void *ResetMagickMemory(void *,int,size_t);

#define IOMode ReadWriteMode