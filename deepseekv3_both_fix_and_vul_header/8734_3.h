#include <assert.h>
#include <string.h>

#define restrict __restrict

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  UndefinedCache,
  MemoryCache,
  MapCache,
  DiskCache,
  DistributedCache,
  PingCache
} CacheType;

typedef enum {
  UndefinedClass,
  DirectClass,
  PseudoClass
} ClassType;

typedef enum {
  ReadMode,
  WriteMode,
  IOMode
} MapMode;

typedef enum {
  WidthResource,
  HeightResource,
  AreaResource,
  MemoryResource,
  DiskResource,
  MapResource
} ResourceType;

typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef struct _CacheInfo CacheInfo;
typedef struct _DistributeCacheInfo DistributeCacheInfo;
typedef void *Cache;
typedef unsigned long MagickSizeType;
typedef long ssize_t;
typedef unsigned char Quantum;

#define MagickCoreSignature 0xabacadabUL
#define MagickPathExtent 4096
#define MaxPixelChannels 64

struct _CacheInfo {
  unsigned long signature;
  char filename[MagickPathExtent];
  char cache_filename[MagickPathExtent];
  CacheType type;
  MagickBooleanType mapped;
  Quantum *pixels;
  void *metacontent;
  size_t metacontent_extent;
  size_t number_channels;
  size_t rows;
  size_t columns;
  MagickSizeType length;
  MagickSizeType offset;
  int file;
  MapMode mode;
  DistributeCacheInfo *server_info;
  ClassType storage_class;
  int colorspace;
  int alpha_trait;
  int read_mask;
  int write_mask;
  int channel_map[MaxPixelChannels];
};

struct _Image {
  unsigned long signature;
  char *filename;
  MagickBooleanType debug;
  MagickBooleanType ping;
  size_t columns;
  size_t rows;
  Cache cache;
  ClassType storage_class;
  int colorspace;
  int alpha_trait;
  int read_mask;
  int write_mask;
  size_t metacontent_extent;
  int channel_map[MaxPixelChannels];
};

extern const int TraceEvent;
extern const int CacheEvent;
extern const int CacheError;
extern const int ImageError;
extern const int ResourceLimitError;

extern const int MagickCacheOptions[];

void *AcquireAlignedMemory(size_t, size_t);
void *MagickAssumeAligned(void *);
void RelinquishPixelCachePixels(CacheInfo *);
MagickBooleanType AcquireMagickResource(ResourceType, MagickSizeType);
void RelinquishMagickResource(ResourceType, MagickSizeType);
void *MapBlob(int, MapMode, MagickSizeType, size_t);
void ThrowBinaryException(int, const char *, const char *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
void ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
void LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
const char *CommandOptionToMnemonic(const int *, ssize_t);
void FormatLocaleString(char *, size_t, const char *, ...);
void FormatMagickSize(MagickSizeType, MagickBooleanType, const char *, size_t, char *);
MagickBooleanType ClonePixelCacheRepository(CacheInfo *, CacheInfo *, ExceptionInfo *);
MagickBooleanType OpenDistributePixelCache(DistributeCacheInfo *, Image *);
MagickBooleanType ClosePixelCacheOnDisk(CacheInfo *);
MagickBooleanType OpenPixelCacheOnDisk(CacheInfo *, MapMode);
MagickBooleanType SetPixelCacheExtent(Image *, MagickSizeType);
DistributeCacheInfo *AcquireDistributeCacheInfo(ExceptionInfo *);
DistributeCacheInfo *DestroyDistributeCacheInfo(DistributeCacheInfo *);
const char *GetDistributeCacheHostname(DistributeCacheInfo *);
int GetDistributeCachePort(DistributeCacheInfo *);
int GetDistributeCacheFile(DistributeCacheInfo *);
void InitializePixelChannelMap(Image *);
size_t GetPixelChannels(Image *);
size_t GetImageIndexInList(Image *);

/* Fix for magick_restrict keyword */
#define magick_restrict restrict