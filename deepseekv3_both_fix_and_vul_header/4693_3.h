#include <math.h>
#include <string.h>
#include <stddef.h>

typedef ptrdiff_t ssize_t;

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum
{
  UndefinedPrimitive,
  AlphaPrimitive,
  ColorPrimitive,
  ImagePrimitive,
  PointPrimitive,
  TextPrimitive
} PrimitiveType;

typedef enum
{
  UndefinedMethod,
  PointMethod,
  ReplaceMethod,
  FloodfillMethod,
  FillToBorderMethod,
  ResetMethod
} PaintMethod;

typedef enum
{
  UndefinedChannelTrait,
  AlphaChannel,
  OpaqueAlphaChannel,
  sRGBColorspace
} ChannelType;

typedef enum
{
  UndefinedAlphaTrait,
  UndefinedPixelTrait,
  OpaqueAlpha,
  TransparentAlpha
} AlphaTrait;

typedef enum
{
  OverCompositeOp
} CompositeOperator;

typedef enum
{
  TileVirtualPixelMethod
} VirtualPixelMethod;

typedef enum
{
  RoundCap
} LineCap;

typedef enum
{
  RoundJoin
} LineJoin;

typedef enum
{
  DrawEvent
} LogEventType;

typedef struct _PointInfo
{
  double x, y;
} PointInfo;

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
  ssize_t x, y;
  size_t width, height;
} RectangleInfo;

typedef struct _Image
{
  size_t rows;
  size_t columns;
  ChannelType colorspace;
  AlphaTrait alpha_trait;
  void *filter;
  void *interpolate;
  MagickBooleanType debug;
  void *gravity;
} Image;

typedef struct _ImageInfo
{
  char *filename;
} ImageInfo;

typedef struct _DrawInfo
{
  AffineMatrix affine;
  PixelInfo fill;
  PixelInfo stroke;
  PixelInfo border_color;
  double *dash_pattern;
  double stroke_width;
  AlphaTrait alpha;
  CompositeOperator compose;
  void *gravity;
  char *text;
  char *geometry;
  LineCap linecap;
  LineJoin linejoin;
  Image *stroke_pattern;
} DrawInfo;

typedef struct _PrimitiveInfo
{
  PrimitiveType primitive;
  PaintMethod method;
  PointInfo point;
  char *text;
  size_t coordinates;
} PrimitiveInfo;

typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _CacheView CacheView;

typedef unsigned long MagickStatusType;
typedef double Quantum;
typedef double MagickRealType;
typedef void (*MagickProgressMonitor)(const char *,const size_t,const size_t);

#define MagickExport
#define MagickPathExtent 4096
#define MagickEpsilon 1.0e-10
#define magick_restrict restrict

MagickBooleanType LogMagickEvent(LogEventType, const char *, const char *, ...);
const char *GetMagickModule(void);
MagickBooleanType IsGrayColorspace(ChannelType);
MagickBooleanType IsPixelInfoGray(const PixelInfo *);
MagickBooleanType SetImageColorspace(Image *, ChannelType, ExceptionInfo *);
CacheView *AcquireAuthenticCacheView(Image *, ExceptionInfo *);
MagickBooleanType SetImageAlphaChannel(Image *, ChannelType, ExceptionInfo *);
Quantum *GetCacheViewAuthenticPixels(CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
void GetFillColor(const DrawInfo *, ssize_t, ssize_t, PixelInfo *, ExceptionInfo *);
void SetPixelAlpha(Image *, Quantum, Quantum *);
Quantum ClampToQuantum(double);
MagickBooleanType SyncCacheViewAuthenticPixels(CacheView *, ExceptionInfo *);
void GetOneCacheViewVirtualPixelInfo(CacheView *, ssize_t, ssize_t, PixelInfo *, ExceptionInfo *);
void GetPixelInfo(Image *, PixelInfo *);
void GetPixelInfoPixel(Image *, const Quantum *, PixelInfo *);
MagickBooleanType IsFuzzyEquivalencePixelInfo(const PixelInfo *, const PixelInfo *);
size_t GetPixelChannels(const Image *);
void GetOneVirtualPixelInfo(Image *, VirtualPixelMethod, ssize_t, ssize_t, PixelInfo *, ExceptionInfo *);
ChannelType SetImageChannelMask(Image *, ChannelType);
MagickBooleanType FloodfillPaintImage(Image *, const DrawInfo *, const PixelInfo *, ssize_t, ssize_t, MagickBooleanType, ExceptionInfo *);
void SetPixelViaPixelInfo(Image *, const PixelInfo *, Quantum *);
ImageInfo *AcquireImageInfo(void);
int LocaleNCompare(const char *, const char *, size_t);
Image *ReadInlineImage(ImageInfo *, const char *, ExceptionInfo *);
void CopyMagickString(char *, const char *, size_t);
Image *ReadImage(ImageInfo *, ExceptionInfo *);
ImageInfo *DestroyImageInfo(ImageInfo *);
void SetImageProgressMonitor(Image *, MagickProgressMonitor, void *);
void FormatLocaleString(char *, size_t, const char *, ...);
void TransformImage(Image **, const char *, const char *, ExceptionInfo *);
void SetImageAlpha(Image *, AlphaTrait, ExceptionInfo *);
void SetGeometry(Image *, RectangleInfo *);
void ParseGravityGeometry(Image *, const char *, RectangleInfo *, ExceptionInfo *);
void DrawAffineImage(Image *, Image *, const AffineMatrix *, ExceptionInfo *);
MagickBooleanType CompositeImage(Image *, Image *, CompositeOperator, MagickBooleanType, ssize_t, ssize_t, ExceptionInfo *);
Image *DestroyImage(Image *);
void CompositePixelOver(Image *, const PixelInfo *, double, Quantum *, double, Quantum *);
double GetPixelAlpha(const Image *, const Quantum *);
DrawInfo *CloneDrawInfo(const ImageInfo *, const DrawInfo *);
void CloneString(char **, const char *);
MagickBooleanType AnnotateImage(Image *, const DrawInfo *, ExceptionInfo *);
DrawInfo *DestroyDrawInfo(DrawInfo *);
MagickBooleanType IsEventLogging(void);
void LogPrimitiveInfo(const PrimitiveInfo *);
double ExpandAffine(const AffineMatrix *);
MagickBooleanType DrawPolygonPrimitive(Image *, const DrawInfo *, const PrimitiveInfo *, ExceptionInfo *);
void DrawDashPolygon(const DrawInfo *, const PrimitiveInfo *, Image *, ExceptionInfo *);
MagickBooleanType DrawStrokePolygon(Image *, const DrawInfo *, const PrimitiveInfo *, ExceptionInfo *);
CacheView *DestroyCacheView(CacheView *);