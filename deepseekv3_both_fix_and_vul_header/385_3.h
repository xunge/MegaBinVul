#include <assert.h>
#include <string.h>
#include <stddef.h>

#define MagickExport
typedef int MagickBooleanType;
#define MagickPathExtent 4096
#define MagickCoreSignature 0
#define MagickFalse 0
#define MagickTrue 1
#define TraceEvent 0
#define DirectClass 0
#define sRGBColorspace 0
#define TransparentAlpha 0

typedef long ssize_t;

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef struct _RectangleInfo {
    size_t width;
    size_t height;
    double x;
    double y;
} RectangleInfo;

typedef struct _AffineMatrix {
    double sx;
    double rx;
    double ry;
    double sy;
    double tx;
    double ty;
} AffineMatrix;

typedef struct _TypeMetric {
    double width;
    double ascent;
    double descent;
    double underline_position;
    double underline_thickness;
    PointInfo origin;
} TypeMetric;

typedef struct _GeometryInfo {
    double xi;
    double psi;
} GeometryInfo;

typedef struct _PixelPacket {
    unsigned long alpha;
} PixelPacket;

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    int colorspace;
    RectangleInfo page;
} Image;

typedef struct _DrawInfo {
    unsigned long signature;
    char *text;
    char *geometry;
    AffineMatrix affine;
    int gravity;
    int align;
    int decorate;
    double interline_spacing;
    PixelPacket undercolor;
    PixelPacket fill;
    char *primitive;
} DrawInfo;

typedef struct _ExceptionInfo {
    int dummy;
} ExceptionInfo;

typedef struct _ImageInfo {
    int dummy;
} ImageInfo;

enum GravityType {
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
};

enum AlignType {
    LeftAlign,
    CenterAlign,
    RightAlign
};

enum DecorationType {
    NoDecoration,
    UnderlineDecoration,
    OverlineDecoration,
    LineThroughDecoration
};

extern const char* GetMagickModule(void);
extern int LogMagickEvent(int,const char*,const char*,...);
extern DrawInfo* CloneDrawInfo(ImageInfo*,const DrawInfo*);
extern void* AcquireQuantumMemory(size_t,size_t);
extern DrawInfo* DestroyDrawInfo(DrawInfo*);
extern void SetGeometry(Image*,RectangleInfo*);
extern void SetGeometryInfo(GeometryInfo*);
extern int ParsePageGeometry(Image*,const char*,RectangleInfo*,ExceptionInfo*);
extern int ParseGeometry(const char*,GeometryInfo*);
extern MagickBooleanType SetImageStorageClass(Image*,int,ExceptionInfo*);
extern int IsGrayColorspace(int);
extern int SetImageColorspace(Image*,int,ExceptionInfo*);
extern int GetTypeMetrics(Image*,DrawInfo*,TypeMetric*,ExceptionInfo*);
extern int FormatLocaleString(char*,size_t,const char*,...);
extern int DrawImage(Image*,DrawInfo*,ExceptionInfo*);
extern MagickBooleanType RenderType(Image*,DrawInfo*,PointInfo*,TypeMetric*,ExceptionInfo*);
extern void* RelinquishMagickMemory(void*);
extern int CloneString(char**,const char*);