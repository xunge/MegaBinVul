#include <stddef.h>

typedef unsigned int MagickBooleanType;
typedef unsigned int MagickStatusType;
typedef double MagickRealType;
typedef unsigned int Quantum;

#define MagickFalse 0
#define MagickTrue 1
#define TransparentAlpha 0
#define NonZeroRule 0
#define RoundCap 0
#define UndefinedPrimitive 0
#define DrawEvent 0

typedef struct _Image {
    MagickBooleanType debug;
} Image;

typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef struct _StrokeInfo {
    MagickRealType alpha;
} StrokeInfo;

typedef struct _DrawInfo {
    StrokeInfo stroke;
    StrokeInfo fill;
    Image *stroke_pattern;
    Image *fill_pattern;
    double stroke_width;
    unsigned int fill_rule;
    unsigned int linecap;
} DrawInfo;

typedef struct _PrimitiveInfo {
    unsigned int primitive;
    size_t coordinates;
    PointInfo point;
    struct _PrimitiveInfo *next;
} PrimitiveInfo;

Image *CloneImage(Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
Image *DestroyImage(Image *);
void *RelinquishMagickMemory(void *);
DrawInfo *CloneDrawInfo(ImageInfo *, const DrawInfo *);
DrawInfo *DestroyDrawInfo(DrawInfo *);
unsigned int LogMagickEvent(unsigned int, const char *, const char *);
const char *GetMagickModule(void);
MagickBooleanType DrawPolygonPrimitive(Image *, DrawInfo *, PrimitiveInfo *, ExceptionInfo *);
PrimitiveInfo *TraceStrokePolygon(const DrawInfo *, const PrimitiveInfo *);
void DrawRoundLinecap(Image *, const DrawInfo *, const PrimitiveInfo *, ExceptionInfo *);