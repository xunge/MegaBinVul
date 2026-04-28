#include <stddef.h>

typedef enum {
  Raw,
  RLE,
  ZipWithPrediction,
  ZipWithoutPrediction
} PSDCompressionType;

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;

typedef struct _ChannelInfo {
  int type;
  size_t size;
} ChannelInfo;

typedef struct {
  int width;
  int height;
} PageInfo;

typedef struct {
  int flags;
  PageInfo page;
  Image *image;
} MaskInfo;

typedef struct {
  ChannelInfo *channel_info;
  int channels;
  MaskInfo mask;
} LayerInfo;

typedef struct {
  int channels;
} PSDInfo;

typedef unsigned int MagickBooleanType;
typedef long long MagickOffsetType;

#define MagickTrue 1
#define MagickFalse 0

#define GetImageOption(info, option) NULL
#define IsStringTrue(option) MagickFalse
#define CloneImage(image, w, h, b, exc) NULL
#define SetImageType(image, type, exc)
#define SeekBlob(image, offset, whence)
#define TellBlob(image) 0
#define ReadPSDChannelRaw(image, channels, type, exc) MagickFalse
#define ReadPSDRLESizes(image, psd_info, rows) NULL
#define ReadPSDChannelRLE(image, psd_info, type, sizes, exc) MagickFalse
#define RelinquishMagickMemory(ptr) NULL
#define ReadPSDChannelZip(image, channels, type, compression, size, exc) MagickFalse
#define ThrowMagickException(exc, module, warning, reason, ...) 0
#define GetMagickModule() NULL
#define ThrowBinaryException(type, reason, filename) MagickFalse
#define DestroyImage(image)