#include <assert.h>
#include <math.h>
#include <string.h>
#include <stddef.h>

#define MagickExport
#define MagickCoreSignature 0xabacadabUL
#define MagickPathExtent 4096

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  UndefinedGravity,
  NorthWestGravity,
  NorthGravity,
  NorthEastGravity,
  WestGravity,
  CenterGravity,
  EastGravity,
  SouthWestGravity,
  SouthGravity,
  SouthEastGravity
} GravityType;

typedef enum {
  LeftAlign,
  CenterAlign,
  RightAlign
} AlignType;

typedef enum {
  OverlineDecoration,
  UnderlineDecoration,
  LineThroughDecoration
} DecorateType;

typedef enum {
  DirectClass,
  PseudoClass
} ClassType;

typedef enum {
  sRGBColorspace,
  GrayColorspace
} ColorspaceType;

typedef enum {
  TransparentAlpha,
  OpaqueAlpha
} AlphaType;

typedef long ssize_t;

typedef struct _AffineMatrix {
  double sx, rx, ry, sy, tx, ty;
} AffineMatrix;

typedef struct _PixelInfo {
  double red, green, blue, alpha;
} PixelInfo;

typedef struct _PointInfo {
  double x, y;
} PointInfo;

typedef struct _RectangleInfo {
  size_t width, height;
  double x, y;
} RectangleInfo;

typedef struct _TypeMetric {
  double ascent, descent, width, underline_position, underline_thickness;
  PointInfo origin;
} TypeMetric;

typedef struct _GeometryInfo {
  double xi, psi;
} GeometryInfo;

typedef struct _Image {
  unsigned long signature;
  char *filename;
  ColorspaceType colorspace;
  RectangleInfo page;
} Image;

typedef struct _DrawInfo {
  unsigned long signature;
  char *text;
  char *geometry;
  char *primitive;
  PixelInfo fill;
  PixelInfo stroke;
  PixelInfo undercolor;
  AffineMatrix affine;
  GravityType gravity;
  AlignType align;
  DecorateType decorate;
  double pointsize;
  double interline_spacing;
} DrawInfo;

typedef struct _ExceptionInfo {
  int dummy;
} ExceptionInfo;

typedef struct _ImageInfo {
  int dummy;
} ImageInfo;

typedef struct _MagickModule {
  const char *name;
} MagickModule;

typedef enum {
  TraceEvent
} EventType;

typedef enum {
  AllCompliance
} ComplianceType;