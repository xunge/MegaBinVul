#include <assert.h>
#include <string.h>
#include <sys/types.h>

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef long long MagickOffsetType;

typedef enum
{
  TraceEvent
} LogEventType;

typedef enum
{
  CorruptImageError,
  CoderError,
  ResourceLimitError
} ExceptionType;

typedef enum
{
  ReadBinaryBlobMode
} BlobMode;

typedef enum
{
  NoCompression,
  COMPRESS_NONE,
  COMPRESS_RLE,
  COMPRESS_ZLIB,
  COMPRESS_FRACTAL
} CompressionType;

typedef enum
{
  GIMP_RGB,
  GIMP_GRAY,
  GIMP_INDEXED
} XCFImageType;

typedef enum
{
  PROP_END,
  PROP_COLORMAP,
  PROP_COMPRESSION,
  PROP_GUIDES,
  PROP_RESOLUTION,
  PROP_TATTOO,
  PROP_PARASITES,
  PROP_UNIT,
  PROP_PATHS,
  PROP_USER_UNIT
} PropType;

typedef enum
{
  GRAYColorspace
} ColorspaceType;

typedef enum
{
  OpaqueOpacity
} OpacityType;

typedef enum
{
  OverCompositeOp
} CompositeOperator;

typedef enum
{
  GrayscaleType
} ImageTypeEnum;

#define MagickSignature 0xabacadabUL
#define MagickMin(a,b) ((a) < (b) ? (a) : (b))
#define SEEK_SET 0

typedef struct _ImageInfo {
  unsigned long signature;
  MagickBooleanType debug;
  const char *filename;
  MagickBooleanType ping;
  unsigned long number_scenes;
} ImageInfo;

typedef struct _ExceptionInfo {
  unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
  unsigned long signature;
  size_t columns;
  size_t rows;
  CompressionType compression;
  unsigned depth;
  ColorspaceType colorspace;
  ExceptionInfo exception;
  const char *filename;
  ImageTypeEnum type;
} Image;

typedef struct _XCFDocInfo {
  ExceptionInfo *exception;
  size_t width;
  size_t height;
  XCFImageType image_type;
  size_t file_size;
  CompressionType compression;
  size_t number_layers;
} XCFDocInfo;

typedef struct _XCFLayerInfo {
  Image *image;
} XCFLayerInfo;

typedef struct _QuantizeInfo {
  ColorspaceType colorspace;
} QuantizeInfo;

static void *AcquireQuantumMemory(size_t count, size_t quantum);
static void *RelinquishMagickMemory(void *memory);
static void ResetMagickMemory(void *memory, int value, size_t size);
static void LogMagickEvent(LogEventType, const char *, const char *, ...);
static const char *GetMagickModule(void);
static int LocaleNCompare(const char *, const char *, size_t);
static void ThrowReaderException(ExceptionType, const char *, ...);
static void ThrowFileException(ExceptionInfo *, ExceptionType, const char *, const char *);
static void InheritException(ExceptionInfo *, ExceptionInfo *);
static Image *AcquireImage(const ImageInfo *);
static MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
static Image *DestroyImageList(Image *);
static ssize_t ReadBlob(Image *, size_t, unsigned char *);
static long ReadBlobMSBLong(Image *);
static signed long ReadBlobMSBSignedLong(Image *);
static int ReadBlobByte(Image *);
static char *ReadBlobStringWithLongSize(Image *, char *, size_t);
static MagickBooleanType DiscardBlobBytes(Image *, size_t);
static MagickBooleanType SetImageExtent(Image *, size_t, size_t);
static MagickBooleanType SetImageOpacity(Image *, OpacityType);
static void SetImageBackgroundColor(Image *);
static MagickOffsetType TellBlob(Image *);
static MagickOffsetType SeekBlob(Image *, MagickOffsetType, int);
static MagickBooleanType EOFBlob(const Image *);
static size_t GetBlobSize(Image *);
static Image *DestroyImage(Image *);
static Image *RemoveFirstImageFromList(Image **);
static Image *GetFirstImageInList(Image *);
static void CompositeImage(Image *, CompositeOperator, Image *, long, long);
static void GetQuantizeInfo(QuantizeInfo *);
static void QuantizeImage(QuantizeInfo *, Image *);
static void AppendImageToList(Image **, Image *);
static MagickBooleanType ReadOneLayer(const ImageInfo *, Image *, XCFDocInfo *, XCFLayerInfo *, int);
static void CloseBlob(Image *);