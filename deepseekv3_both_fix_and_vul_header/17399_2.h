#include <assert.h>
#include <string.h>
#include <sys/types.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  UndefinedSubtype,
  ARGB4444,
  ARGB1555,
  RGB555,
  RGB565
} BMPSubtype;

typedef enum {
  BI_RGB,
  BI_RLE8,
  BI_BITFIELDS
} BMPCompression;

typedef enum {
  UndefinedIntent,
  SaturationIntent,
  RelativeIntent,
  PerceptualIntent,
  AbsoluteIntent
} RenderingIntent;

typedef enum {
  UndefinedPixelTrait
} PixelTrait;

typedef enum {
  UndefinedResolution,
  PixelsPerInchResolution,
  PixelsPerCentimeterResolution
} ResolutionType;

typedef enum {
  NoCompression,
  RLECompression
} CompressionType;

typedef enum {
  PseudoClass,
  DirectClass
} ClassType;

typedef struct _Image Image;

typedef struct {
  unsigned int file_size;
  unsigned int offset_bits;
  unsigned int size;
  ssize_t width;
  ssize_t height;
  unsigned short planes;
  unsigned short bits_per_pixel;
  unsigned int compression;
  unsigned int image_size;
  unsigned int x_pixels;
  unsigned int y_pixels;
  unsigned int number_colors;
  unsigned int colors_important;
  unsigned int red_mask;
  unsigned int green_mask;
  unsigned int blue_mask;
  unsigned int alpha_mask;
  unsigned int ba_offset;
  struct {
    double x;
    double y;
    double z;
  } gamma_scale;
} BMPInfo;

typedef struct {
  double x;
  double y;
} PointInfo;

typedef struct {
  PointInfo red_primary;
  PointInfo green_primary;
  PointInfo blue_primary;
  PointInfo white_point;
} ChromaticityInfo;

typedef struct {
  const char *magick;
  const char *filename;
  CompressionType compression;
  MagickBooleanType adjoin;
  void *signature;
} ImageInfo;

struct _Image {
  const char *filename;
  ClassType storage_class;
  size_t columns;
  size_t rows;
  size_t colors;
  size_t depth;
  PixelTrait alpha_trait;
  MagickBooleanType debug;
  void *signature;
  ChromaticityInfo chromaticity;
  RenderingIntent rendering_intent;
  double gamma;
  struct {
    double x;
    double y;
  } resolution;
  ResolutionType units;
  struct {
    double red;
    double green;
    double blue;
  } *colormap;
  Image *previous;
  void *colorspace;
};

typedef struct {
  void *signature;
} ExceptionInfo;

typedef struct {
  void *blob;
} StringInfo;

typedef struct {
  void *blob;
} MemoryInfo;

typedef unsigned char Quantum;
typedef long long MagickOffsetType;

#define MagickCoreSignature ((void *)0)
#define TraceEvent 0
#define CoderEvent 1
#define WriteBinaryBlobMode 0
#define sRGBColorspace 0
#define ImageError 0
#define ResourceLimitError 0
#define SaveImageTag 0
#define SaveImagesTag 0
#define LCS_GM_BUSINESS 0
#define LCS_GM_GRAPHICS 0
#define LCS_GM_IMAGES 0
#define LCS_GM_ABS_COLORIMETRIC 0