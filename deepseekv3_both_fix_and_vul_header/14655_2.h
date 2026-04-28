#include <stddef.h>
#include <unistd.h>

#define MagickExport

typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef long long MagickOffsetType;

typedef enum
{
  AlignedVirtualMemory,
  MapVirtualMemory,
  UnalignedVirtualMemory
} VirtualMemoryType;

typedef enum
{
  ReadMode,
  WriteMode,
  IOMode
} MapMode;

typedef enum
{
  MemoryResource,
  MapResource,
  DiskResource
} ResourceType;

typedef enum
{
  UndefinedFatalError = 0,
  ResourceLimitFatalError = 300,
  TypeFatalError,
  OptionFatalError,
  DelegateFatalError,
  MissingDelegateFatalError,
  CorruptImageFatalError,
  FileOpenFatalError,
  BlobFatalError,
  StreamFatalError,
  CacheFatalError,
  CoderFatalError,
  ModuleFatalError,
  DrawFatalError,
  ImageFatalError,
  XServerFatalError,
  MonitorFatalError,
  RegistryFatalError,
  ConfigureFatalError,
  PolicyFatalError,
  ErrorFatalError
} ExceptionType;

typedef struct _MemoryInfo
{
  size_t length;
  void *blob;
  VirtualMemoryType type;
  unsigned long signature;
  char filename[4096];
} MemoryInfo;

extern MagickBooleanType CheckMemoryOverflow(size_t,size_t);
extern void *MagickAssumeAligned(void *);
extern void *AcquireAlignedMemory(size_t,size_t);
extern void ThrowFatalException(ExceptionType,const char *);
extern void *ResetMagickMemory(void *,int,size_t);
extern MagickBooleanType AcquireMagickResource(ResourceType,size_t);
extern void RelinquishMagickResource(ResourceType,size_t);
extern void *MapBlob(int,MapMode,MagickOffsetType,size_t);
extern int AcquireUniqueFileResource(char *);
extern void RelinquishUniqueFileResource(const char *);
extern void *AcquireMagickMemory(size_t);
extern MemoryInfo *RelinquishVirtualMemory(MemoryInfo *);

#define MagickSignature 0xabacadabUL