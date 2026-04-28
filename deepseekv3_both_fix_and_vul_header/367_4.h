#include <assert.h>
#include <string.h>
#include <stddef.h>

#define MagickExport
typedef unsigned int MagickBooleanType;

typedef struct _AffineMatrix {
    double tx;
    double ty;
    double sx;
    double sy;
    double rx;
    double ry;
} AffineMatrix;

typedef struct _ColorInfo {
    unsigned int alpha;
    double red;
    double green;
    double blue;
} ColorInfo;

typedef struct _PageInfo {
    double x;
    double y;
} PageInfo;

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    PageInfo page;
    int colorspace;
} Image;

typedef struct _DrawInfo {
    unsigned long signature;
    char *text;
    char *geometry;
    AffineMatrix affine;
    int gravity;
    int align;
    int decorate;
    ColorInfo undercolor;
    ColorInfo fill;
    double interline_spacing;
    char *primitive;
} DrawInfo;

typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _ImageInfo ImageInfo;

typedef struct _GeometryInfo {
    double xi;
    double psi;
} GeometryInfo;

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef struct _RectangleInfo {
    double width;
    double height;
} RectangleInfo;

typedef struct _TypeMetric {
    double width;
    double ascent;
    double descent;
    double underline_position;
    double underline_thickness;
    PointInfo origin;
} TypeMetric;

#define MagickCoreSignature 0
#define MagickPathExtent 4096
#define MagickFalse 0
#define MagickTrue 1
#define TraceEvent 0
#define DirectClass 0
#define sRGBColorspace 0
#define TransparentAlpha 0
#define NorthWestGravity 1
#define UndefinedGravity 0
#define NorthGravity 2
#define NorthEastGravity 3
#define WestGravity 4
#define CenterGravity 5
#define EastGravity 6
#define SouthWestGravity 7
#define SouthGravity 8
#define SouthEastGravity 9
#define LeftAlign 1
#define CenterAlign 2
#define RightAlign 3
#define OverlineDecoration 1
#define UnderlineDecoration 2
#define LineThroughDecoration 3

typedef long ssize_t;

DrawInfo *CloneDrawInfo(ImageInfo *, const DrawInfo *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
void SetGeometry(Image *, RectangleInfo *);
void SetGeometryInfo(GeometryInfo *);
MagickBooleanType ParsePageGeometry(Image *, const char *, RectangleInfo *, ExceptionInfo *);
void ParseGeometry(const char *, GeometryInfo *);
MagickBooleanType SetImageStorageClass(Image *, int, ExceptionInfo *);
MagickBooleanType IsGrayColorspace(int);
MagickBooleanType SetImageColorspace(Image *, int, ExceptionInfo *);
void GetTypeMetrics(Image *, DrawInfo *, TypeMetric *, ExceptionInfo *);
char *CloneString(char **, const char *);
int FormatLocaleString(char *, size_t, const char *, ...);
MagickBooleanType DrawImage(Image *, DrawInfo *, ExceptionInfo *);
DrawInfo *DestroyDrawInfo(DrawInfo *);
MagickBooleanType RenderType(Image *, DrawInfo *, PointInfo *, TypeMetric *, ExceptionInfo *);
void *LogMagickEvent(int, const char *, const char *, const char *);
const char *GetMagickModule(void);