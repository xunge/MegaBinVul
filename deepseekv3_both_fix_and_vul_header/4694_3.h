#include <assert.h>
#include <string.h>
#include <sys/types.h>

#define MagickExport
#define TraceEvent 0
#define AllCompliance 0
#define OpaqueAlpha 0
#define TransparentAlpha 1
#define MagickCoreSignature 0xabacadabUL
#define MagickFalse MagickFalse_
#define MagickTrue MagickTrue_

typedef unsigned long Quantum;
typedef double MagickRealType;

typedef enum
{
  UndefinedDirection,
  RightToLeftDirection,
  LeftToRightDirection
} DirectionType;

typedef enum
{
  UndefinedGravity,
  ForgetGravity,
  NorthWestGravity,
  NorthGravity,
  NorthEastGravity,
  WestGravity,
  CenterGravity,
  EastGravity,
  SouthWestGravity,
  SouthGravity,
  SouthEastGravity,
  StaticGravity
} GravityType;

typedef enum
{
  UndefinedStyle,
  NormalStyle,
  ItalicStyle,
  ObliqueStyle,
  AnyStyle
} StyleType;

typedef enum
{
  UndefinedRule,
  EvenOddRule,
  NonZeroRule
} FillRule;

typedef enum
{
  UndefinedCap,
  ButtCap,
  RoundCap,
  SquareCap
} LineCap;

typedef enum
{
  UndefinedJoin,
  MiterJoin,
  RoundJoin,
  BevelJoin
} LineJoin;

typedef enum
{
  UndefinedDecoration,
  NoDecoration,
  UnderlineDecoration,
  OverlineDecoration,
  LineThroughDecoration
} DecorateType;

typedef enum
{
  UndefinedCompositeOp,
  OverCompositeOp
} CompositeOperator;

typedef enum
{
  MagickFalse_,
  MagickTrue_
} MagickBooleanType;

typedef struct _AffineMatrix
{
  double sx, rx, ry, sy, tx, ty;
} AffineMatrix;

typedef struct _ExceptionInfo ExceptionInfo;

typedef struct _PixelPacket
{
  unsigned long alpha;
} PixelPacket;

typedef struct _ImageInfo
{
  char *font;
  char *density;
  char *server_name;
  double pointsize;
  MagickBooleanType antialias;
  PixelPacket border_color;
} ImageInfo;

typedef struct _DrawInfo
{
  char *primitive;
  char *font;
  char *text;
  AffineMatrix affine;
  double stroke_width;
  double pointsize;
  double interline_spacing;
  double interword_spacing;
  double kerning;
  size_t weight;
  char *encoding;
  char *family;
  char *density;
  char *server_name;
  MagickBooleanType stroke_antialias;
  MagickBooleanType text_antialias;
  MagickBooleanType debug;
  MagickBooleanType render;
  CompositeOperator compose;
  DirectionType direction;
  GravityType gravity;
  StyleType style;
  FillRule fill_rule;
  LineCap linecap;
  LineJoin linejoin;
  DecorateType decorate;
  unsigned long miterlimit;
  unsigned long alpha;
  PixelPacket fill;
  PixelPacket stroke;
  PixelPacket undercolor;
  PixelPacket border_color;
  unsigned long signature;
} DrawInfo;

extern const char *MagickDirectionOptions;
extern const char *MagickGravityOptions;
extern const char *MagickStyleOptions;
extern const char *MagickWeightOptions;

const char *GetMagickModule(void);
void LogMagickEvent(int,const char *,const char *,...);
void *ResetMagickMemory(void *,int,size_t);
ImageInfo *CloneImageInfo(const ImageInfo *);
void GetAffineMatrix(AffineMatrix *);
ExceptionInfo *AcquireExceptionInfo(void);
MagickBooleanType QueryColorCompliance(const char *,int,PixelPacket *,ExceptionInfo *);
MagickBooleanType IsEventLogging(void);
char *AcquireString(const char *);
const char *GetImageOption(const ImageInfo *,const char *);
ssize_t ParseCommandOption(const char *,MagickBooleanType,const char *);
MagickBooleanType CloneString(char **,const char *);
double StringToDouble(const char *,char **);
unsigned long StringToUnsignedLong(const char *);
ExceptionInfo *DestroyExceptionInfo(ExceptionInfo *);
ImageInfo *DestroyImageInfo(ImageInfo *);