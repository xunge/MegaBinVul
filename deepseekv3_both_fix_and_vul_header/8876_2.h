#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef unsigned long MagickSizeType;
typedef int64_t MagickOffsetType;

typedef struct _MemoryInfo MemoryInfo;

typedef enum
{
  NoCompression,
  RLECompression
} CompressionType;

typedef enum
{
  PseudoClass,
  DirectClass
} ClassType;

typedef enum
{
  UndefinedPixelTrait,
  BlendPixelTrait
} AlphaTraitType;

typedef struct _Image
{
  unsigned long signature;
  CompressionType compression;
  size_t columns;
  size_t rows;
  size_t depth;
  ClassType storage_class;
  size_t colors;
  AlphaTraitType alpha_trait;
  struct _Image *previous;
  unsigned long scene;
  char *filename;
} Image;

typedef struct _ImageInfo
{
  unsigned long signature;
  MagickBooleanType debug;
  char *filename;
  MagickBooleanType ping;
  unsigned long number_scenes;
  unsigned long scene;
} ImageInfo;

typedef struct _ExceptionInfo
{
  unsigned long signature;
} ExceptionInfo;

typedef enum
{
  ReadBinaryBlobMode
} BlobMode;

typedef enum
{
  TraceEvent
} LogEventType;

typedef enum
{
  CorruptImageError,
  ResourceLimitError
} ExceptionType;

typedef enum
{
  LoadImageTag,
  LoadImagesTag
} ProgressMonitorType;

typedef unsigned char Quantum;

typedef struct
{
  unsigned short magic;
  unsigned char storage;
  unsigned char bytes_per_pixel;
  unsigned short dimension;
  unsigned short columns;
  unsigned short rows;
  unsigned short depth;
  unsigned long minimum_value;
  unsigned long maximum_value;
  unsigned long sans;
  char name[80];
  unsigned long pixel_format;
  unsigned char filler[404];
} SGIInfo;

#define MagickCoreSignature 0xabacadabUL
#define MAGICKCORE_QUANTUM_DEPTH 16
#define OpaqueAlpha 65535U

static size_t MagickMin(size_t a, size_t b) { return a < b ? a : b; }
static ssize_t ReadBlobMSBSignedLong(Image *image) { return 0; }
static unsigned short ReadBlobMSBShort(Image *image) { return 0; }
static unsigned char ReadBlobByte(Image *image) { return 0; }
static unsigned long ReadBlobMSBLong(Image *image) { return 0; }
static ssize_t ReadBlob(Image *image, size_t size, unsigned char *data) { return 0; }
static void ThrowReaderException(ExceptionType type, const char *reason) {}
static void LogMagickEvent(LogEventType event, const char *module, const char *format, ...) {}
static const char *GetMagickModule(void) { return ""; }
static MagickBooleanType SetImageProperty(Image *image, const char *property, const char *value, ExceptionInfo *exception) { return MagickFalse; }
static MagickBooleanType EOFBlob(const Image *image) { return MagickFalse; }
static MagickBooleanType SetImageExtent(Image *image, size_t columns, size_t rows, ExceptionInfo *exception) { return MagickFalse; }
static MemoryInfo *AcquireVirtualMemory(size_t width, size_t height) { return NULL; }
static void *GetVirtualMemoryBlob(MemoryInfo *memory_info) { return NULL; }
static void *AcquireQuantumMemory(size_t size, size_t count) { return NULL; }
static void *RelinquishMagickMemory(void *memory) { return NULL; }
static MemoryInfo *RelinquishVirtualMemory(MemoryInfo *memory_info) { return NULL; }
static ssize_t TellBlob(const Image *image) { return 0; }
static ssize_t SeekBlob(Image *image, ssize_t offset, int whence) { return 0; }
static MagickBooleanType SGIDecode(size_t bytes_per_pixel, ssize_t count, unsigned char *packets, ssize_t columns, unsigned char *pixels) { return MagickFalse; }
static Quantum *QueueAuthenticPixels(Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception) { return NULL; }
static MagickBooleanType SyncAuthenticPixels(Image *image, ExceptionInfo *exception) { return MagickFalse; }
static MagickBooleanType SetImageProgress(Image *image, ProgressMonitorType monitor, MagickOffsetType offset, size_t span) { return MagickFalse; }
static unsigned short ScaleShortToQuantum(unsigned short value) { return 0; }
static unsigned short ScaleCharToQuantum(unsigned char value) { return 0; }
static void SetPixelRed(Image *image, Quantum red, Quantum *pixel) {}
static void SetPixelGreen(Image *image, Quantum green, Quantum *pixel) {}
static void SetPixelBlue(Image *image, Quantum blue, Quantum *pixel) {}
static void SetPixelAlpha(Image *image, Quantum alpha, Quantum *pixel) {}
static size_t GetPixelChannels(const Image *image) { return 0; }
static MagickBooleanType AcquireImageColormap(Image *image, size_t colors, ExceptionInfo *exception) { return MagickFalse; }
static void SetPixelIndex(Image *image, Quantum index, Quantum *pixel) {}
static MagickBooleanType SyncImage(Image *image, ExceptionInfo *exception) { return MagickFalse; }
static void ThrowFileException(ExceptionInfo *exception, ExceptionType type, const char *reason, const char *description) {}
static Image *GetNextImageInList(const Image *image) { return NULL; }
static Image *SyncNextImageInList(Image *image) { return NULL; }
static MagickOffsetType GetBlobSize(const Image *image) { return 0; }
static MagickBooleanType CloseBlob(Image *image) { return MagickFalse; }
static Image *GetFirstImageInList(const Image *image) { return NULL; }
static void AcquireNextImage(const ImageInfo *image_info, Image *image, ExceptionInfo *exception) {}
static Image *AcquireImage(const ImageInfo *image_info, ExceptionInfo *exception) { return NULL; }
static MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image, BlobMode mode, ExceptionInfo *exception) { return MagickFalse; }
static Image *DestroyImageList(Image *image) { return NULL; }