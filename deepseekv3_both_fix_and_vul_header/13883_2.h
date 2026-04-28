#include <assert.h>
#include <stddef.h>
#include <sys/types.h>
#include <stdint.h>

#define MagickSignature 0xabacadabUL
#define MaxTextExtent 2048
#define MagickCacheOptions 1

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
  PseudoClass
} ClassType;

typedef enum {
  CMYKColorspace
} ColorspaceType;

typedef enum {
  ReadMode
} MapMode;

typedef enum {
  TraceEvent,
  CacheEvent
} EventType;

typedef enum {
  WidthResource,
  HeightResource,
  AreaResource,
  MemoryResource,
  DiskResource,
  MapResource
} ResourceType;

typedef enum {
  CacheError,
  ResourceLimitError
} ExceptionType;

typedef uint64_t MagickSizeType;
typedef uint32_t MagickStatusType;
typedef int64_t ssize_t;
typedef size_t size_t;

typedef struct _PixelPacket {
  unsigned char blue;
  unsigned char green;
  unsigned char red;
  unsigned char opacity;
} PixelPacket;

typedef struct _IndexPacket {
  unsigned char index;
} IndexPacket;

typedef struct _CacheInfo {
  uint32_t signature;
  int file;
  char filename[MaxTextExtent];
  char cache_filename[MaxTextExtent];
  MapMode mode;
  size_t rows;
  size_t columns;
  size_t channels;
  MagickBooleanType active_index_channel;
  MagickSizeType length;
  off_t offset;
  CacheType type;
  MagickBooleanType mapped;
  PixelPacket *pixels;
  IndexPacket *indexes;
  ClassType storage_class;
  ColorspaceType colorspace;
  void *server_info;
} CacheInfo;

typedef struct _Image {
  uint32_t signature;
  void *cache;
  MagickBooleanType debug;
  char *filename;
  size_t columns;
  size_t rows;
  size_t channels;
  ClassType storage_class;
  ColorspaceType colorspace;
  MagickBooleanType ping;
} Image;

typedef struct _ExceptionInfo {
  int severity;
  char *reason;
  char *description;
} ExceptionInfo;

typedef struct _DistributeCacheInfo {
  char *hostname;
  int port;
  int file;
} DistributeCacheInfo;

typedef void *Cache;

#define magick_restrict __restrict__