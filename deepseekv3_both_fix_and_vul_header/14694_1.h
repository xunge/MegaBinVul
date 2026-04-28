#include <stddef.h>
#include <stdio.h>

typedef long long MagickOffsetType;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  Raw,
  RLE,
  ZipWithPrediction,
  ZipWithoutPrediction
} PSDCompressionType;

typedef enum {
  ResourceLimitError,
  CoderError
} ExceptionType;

typedef enum {
  MissingDelegateWarning,
  TypeWarning
} WarningType;

typedef struct _ChannelInfo {
  int type;
  size_t size;
} ChannelInfo;

typedef struct _RectangleInfo {
  size_t width;
  size_t height;
} RectangleInfo;

typedef struct _LayerMaskInfo {
  RectangleInfo page;
  int flags;
  void *image;
} LayerMaskInfo;

typedef struct _LayerInfo {
  ChannelInfo *channel_info;
  size_t channels;
  LayerMaskInfo mask;
} LayerInfo;

typedef struct _PSDInfo {
  size_t channels;
} PSDInfo;

typedef struct _ExceptionInfo {
  // Exception info members
} ExceptionInfo;

typedef struct _ImageInfo {
  // Image info members
} ImageInfo;

typedef struct _Image {
  char *filename;
  size_t rows;
  int matte;
  // Other image members
} Image;

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

MagickBooleanType ReadPSDChannelRaw(Image *, size_t, int, ExceptionInfo *);
MagickOffsetType *ReadPSDRLESizes(Image *, const PSDInfo *, size_t);
MagickBooleanType ReadPSDChannelRLE(Image *, const PSDInfo *, int, MagickOffsetType *, ExceptionInfo *);
MagickBooleanType ReadPSDChannelZip(Image *, size_t, int, PSDCompressionType, size_t, ExceptionInfo *);
Image *CloneImage(const Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
void DestroyImage(Image *);
void *RelinquishMagickMemory(void *);
void SeekBlob(Image *, MagickOffsetType, int);
MagickOffsetType TellBlob(Image *);
const char *GetImageOption(const ImageInfo *, const char *);
MagickBooleanType IsStringTrue(const char *);
void ThrowBinaryException(ExceptionType, const char *, const char *);
void ThrowMagickException(ExceptionInfo *, const void *, WarningType, const char *, const char *, ...);
const void *GetMagickModule(void);