#include <assert.h>
#include <stdlib.h>

#define MagickExport
#define MagickSignature 0x12345678

typedef enum
{
  AlignedVirtualMemory,
  MapVirtualMemory,
  UnalignedVirtualMemory
} VirtualMemoryType;

typedef enum
{
  MemoryResource,
  MapResource,
  DiskResource
} ResourceType;

typedef struct _MemoryInfo
{
  unsigned long signature;
  void *blob;
  size_t length;
  VirtualMemoryType type;
  char *filename;
} MemoryInfo;

extern void *RelinquishAlignedMemory(void *);
extern void RelinquishMagickResource(ResourceType, size_t);
extern void *RelinquishMagickMemory(void *);
extern int UnmapBlob(void *, size_t);
extern int RelinquishUniqueFileResource(char *);