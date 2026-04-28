#include <assert.h>
#include <stddef.h>

#define MagickExport

typedef enum {
  BilevelType,
  GrayscaleType,
  GrayscaleAlphaType,
  PaletteType,
  PaletteBilevelAlphaType,
  PaletteAlphaType,
  TrueColorType,
  TrueColorAlphaType,
  ColorSeparationType,
  ColorSeparationAlphaType,
  OptimizeType,
  UndefinedType
} ImageType;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  GRAYColorspace,
  sRGBColorspace,
  CMYKColorspace,
  TransparentColorspace
} ColorspaceType;

typedef enum {
  UndefinedPixelTrait
} PixelTrait;

typedef enum {
  OpaqueAlphaChannel
} AlphaChannelType;

typedef enum {
  DirectClass
} ClassType;

typedef enum {
  AlphaChannel
} ChannelType;

typedef struct _ExceptionInfo ExceptionInfo;

typedef struct _Image {
  unsigned long signature;
  MagickBooleanType debug;
  ColorspaceType colorspace;
  ClassType storage_class;
  unsigned long colors;
  PixelTrait alpha_trait;
  int dither;
  ImageType type;
} Image;

typedef struct _ImageInfo {
  int dither;
} ImageInfo;

typedef struct _QuantizeInfo {
  unsigned long number_colors;
  ColorspaceType colorspace;
} QuantizeInfo;

#define MagickCoreSignature 0
#define QuantumRange 0
#define TraceEvent 0

extern const char *GetImageArtifact(const Image *, const char *);
extern MagickBooleanType SetImageMonochrome(Image *, ExceptionInfo *);
extern MagickBooleanType TransformImageColorspace(Image *, ColorspaceType, ExceptionInfo *);
extern MagickBooleanType NormalizeImage(Image *, ExceptionInfo *);
extern MagickBooleanType SetImageGray(Image *, ExceptionInfo *);
extern MagickBooleanType SetImageAlphaChannel(Image *, AlphaChannelType, ExceptionInfo *);
extern MagickBooleanType IssRGBCompatibleColorspace(ColorspaceType);
extern MagickBooleanType QuantizeImage(QuantizeInfo *, Image *, ExceptionInfo *);
extern MagickBooleanType SetImageStorageClass(Image *, ClassType, ExceptionInfo *);
extern MagickBooleanType BilevelImage(Image *, double, ExceptionInfo *);
extern ChannelType SetImageChannelMask(Image *, ChannelType);
extern ImageInfo *AcquireImageInfo(void);
extern ImageInfo *DestroyImageInfo(ImageInfo *);
extern QuantizeInfo *AcquireQuantizeInfo(ImageInfo *);
extern QuantizeInfo *DestroyQuantizeInfo(QuantizeInfo *);
extern void *GetMagickModule(void);
extern void LogMagickEvent(int, void *, const char *);
extern int SetImageOption(ImageInfo *, const char *, const char *);