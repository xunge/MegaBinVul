#include <assert.h>
#include <string.h>
#include <stddef.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef struct _ImageInfo ImageInfo;
typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _StringInfo StringInfo;
typedef struct _PSDInfo PSDInfo;

typedef enum {
  UndefinedPixelTrait,
  BlendPixelTrait
} PixelTrait;

typedef enum {
  UndefinedColorspace,
  RGBColorspace,
  sRGBColorspace,
  CMYKColorspace,
  GRAYColorspace
} ColorspaceType;

typedef enum {
  UndefinedType,
  TrueColorType,
  TrueColorAlphaType
} ImageType;

typedef enum {
  UndefinedClass,
  DirectClass,
  PseudoClass
} ClassType;

typedef enum {
  UndefinedMode,
  BitmapMode,
  GrayscaleMode,
  IndexedMode,
  RGBMode,
  CMYKMode
} PSDModeType;

typedef enum {
  NoCompression,
  RLECompression
} CompressionType;

typedef enum {
  NoCompositeOp,
  OverCompositeOp
} CompositeOperator;

struct _Image {
  unsigned long columns;
  unsigned long rows;
  unsigned long depth;
  MagickBooleanType alpha_trait;
  ColorspaceType colorspace;
  ClassType storage_class;
  unsigned long colors;
  struct {
    double red;
    double green;
    double blue;
  } *colormap;
  MagickBooleanType debug;
  char *filename;
  CompressionType compression;
  struct {
    long x;
    long y;
  } page;
  CompositeOperator compose;
  unsigned long signature;
};

struct _PSDInfo {
  int version;
};

struct _ExceptionInfo {
  unsigned long signature;
};

struct _ImageInfo {
  unsigned long signature;
  char *magick;
  ImageType type;
  ColorspaceType colorspace;
};

struct _StringInfo {
  unsigned char *datum;
  size_t length;
};

#define MagickCoreSignature 0xabacadabUL
#define MagickPathExtent 4096
#define TraceEvent 0
#define WriteBinaryBlobMode 1

typedef long ssize_t;
typedef long long MagickOffsetType;

size_t PSDQuantum(size_t length);
void WritePascalString(Image *image, const char *string, size_t length);
void WriteResolutionResourceBlock(Image *image);
void RemoveICCProfileFromResourceBlock(StringInfo *profile);
void RemoveResolutionFromResourceBlock(StringInfo *profile);
MagickBooleanType WriteImageChannels(PSDInfo *psd_info, const ImageInfo *image_info, Image *image, Image *next_image, MagickBooleanType write_mask, ExceptionInfo *exception);
MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image, int mode, ExceptionInfo *exception);
void WriteBlob(Image *image, size_t length, const unsigned char *data);
void WriteBlobByte(Image *image, unsigned char value);
void WriteBlobMSBShort(Image *image, unsigned short value);
void WriteBlobMSBLong(Image *image, unsigned int value);
MagickBooleanType SetImageGray(Image *image, ExceptionInfo *exception);
MagickBooleanType SetImageStorageClass(Image *image, ClassType storage_class, ExceptionInfo *exception);
MagickBooleanType TransformImageColorspace(Image *image, ColorspaceType colorspace, ExceptionInfo *exception);
MagickBooleanType IsImageGray(const Image *image);
MagickBooleanType IsImageMonochrome(const Image *image);
unsigned char ScaleQuantumToChar(double quantum);
StringInfo *GetImageProfile(const Image *image, const char *name);
StringInfo *CloneStringInfo(const StringInfo *string_info);
StringInfo *DestroyStringInfo(StringInfo *string_info);
size_t GetStringInfoLength(const StringInfo *string_info);
unsigned char *GetStringInfoDatum(const StringInfo *string_info);
const char *GetImageProperty(const Image *image, const char *property, ExceptionInfo *exception);
Image *GetNextImageInList(const Image *image);
void SetPSDSize(PSDInfo *psd_info, Image *image, size_t size);
const char *CompositeOperatorToPSDBlendMode(CompositeOperator compose);
void LogMagickEvent(int event, const char *module, const char *format, ...);
const char *GetMagickModule(void);
MagickBooleanType CloseBlob(Image *image);
int LocaleCompare(const char *p, const char *q);
int FormatLocaleString(char *string, const size_t length, const char *format, ...);