#include <assert.h>
#include <string.h>
#include <sys/types.h>

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef long long MagickOffsetType;
typedef ssize_t ssize_t;

typedef struct _ImageInfo
{
  unsigned long signature;
  MagickBooleanType debug;
  const char *filename;
  MagickBooleanType ping;
  unsigned long number_scenes;
} ImageInfo;

typedef struct _ExceptionInfo
{
  unsigned long signature;
} ExceptionInfo;

typedef struct _Image
{
  unsigned long columns;
  unsigned long rows;
  int compression;
  unsigned long depth;
  ExceptionInfo exception;
  const char *filename;
  unsigned long type;
  int colorspace;
} Image;

typedef struct
{
  ExceptionInfo *exception;
  unsigned long width;
  unsigned long height;
  size_t image_type;
  MagickOffsetType file_size;
  int compression;
  size_t number_layers;
} XCFDocInfo;

typedef struct
{
  Image *image;
  int offset_x;
  int offset_y;
  int visible;
} XCFLayerInfo;

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
} ImageType;

#define MagickSignature 0xabacadabUL
#define OpaqueOpacity 1.0
#define TraceEvent 0
#define CorruptImageError 1
#define CoderError 2
#define ResourceLimitError 3
#define NotEnoughPixelData 4
#define GRAYColorspace 5
#define NoCompression 6
#define OverCompositeOp 7
#define ReadBinaryBlobMode 8
#define SEEK_SET 0
#define GrayscaleType 1

#define MagickMin(a,b) ((a) < (b) ? (a) : (b))