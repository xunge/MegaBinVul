#include <math.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stddef.h>

typedef long ssize_t;
typedef long long MagickOffsetType;
typedef unsigned long long MagickSizeType;

#define MagickExport
#define magick_restrict __restrict__

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum
{
  UndefinedPixelTrait,
  OpaqueAlphaChannel,
  sRGBColorspace,
  OpaqueAlpha
} ChannelType;

typedef enum
{
  AlphaPrimitive,
  ColorPrimitive,
  ImagePrimitive,
  PointPrimitive,
  TextPrimitive,
  UndefinedPrimitive
} PrimitiveType;

typedef enum
{
  PointMethod,
  ReplaceMethod,
  FloodfillMethod,
  FillToBorderMethod,
  ResetMethod
} DrawMethod;

typedef enum
{
  SVGCompliance
} ComplianceType;

typedef enum
{
  AlphaChannel,
  WritePixelMask,
  CompositePixelMask
} ChannelMask;

typedef enum
{
  RoundCap,
  RoundJoin
} LineCapJoin;

typedef enum
{
  OverCompositeOp,
  SrcOverCompositeOp
} CompositeOperator;

typedef enum
{
  DrawEvent,
  FileOpenError
} MagickEventType;

typedef struct _AffineMatrix
{
  double sx, rx, ry, sy, tx, ty;
} AffineMatrix;

typedef struct _PixelInfo
{
  double red, green, blue, alpha;
} PixelInfo;

typedef struct _RectangleInfo
{
  ssize_t x, y, width, height;
} RectangleInfo;

typedef struct _Image
{
  ChannelType alpha_trait;
  ChannelType colorspace;
  ssize_t rows;
  ssize_t columns;
  ChannelType *channels;
  double filter;
  ChannelType gravity;
  ChannelType interpolate;
  size_t recursion_depth;
} Image;

typedef struct _DrawInfo
{
  MagickBooleanType debug;
  AffineMatrix affine;
  ComplianceType compliance;
  Image *clipping_mask;
  Image *composite_mask;
  PixelInfo fill;
  PixelInfo stroke;
  PixelInfo border_color;
  Image *stroke_pattern;
  double *dash_pattern;
  double stroke_width;
  LineCapJoin linecap;
  LineCapJoin linejoin;
  Image *image_info;
  ChannelType alpha;
  CompositeOperator compose;
  char *text;
  char *geometry;
  ChannelType gravity;
} DrawInfo;

typedef struct _PrimitiveInfo
{
  PrimitiveType primitive;
  DrawMethod method;
  char *text;
  ssize_t coordinates;
  MagickBooleanType closed_subpath;
  struct
  {
    double x, y;
  } point;
} PrimitiveInfo;

typedef struct _ExceptionInfo
{
  int dummy;
} ExceptionInfo;

typedef struct _CacheView
{
  int dummy;
} CacheView;

typedef struct _ImageInfo
{
  char *filename;
  char *size;
  char *extract;
  char *magick;
  char *geometry;
  char *text;
  size_t recursion_depth;
} ImageInfo;

typedef MagickBooleanType MagickStatusType;
typedef double Quantum;
typedef double MagickRealType;
typedef void (*MagickProgressMonitor)(const char *, MagickOffsetType, MagickSizeType, void *);

#define MagickPathExtent 4096
#define MagickEpsilon 1.0e-10
#define TransparentAlpha 0
#define TileVirtualPixelMethod 0