#include <assert.h>
#include <math.h>
#include <string.h>

#define MaxTextExtent 4096
#define MagickSignature 0xabacadabUL
#define MagickFalse 0
#define MagickEpsilon 1.0e-10

typedef enum {
    UndefinedGravity,
    RightToLeftDirection
} GravityType;

typedef struct _ImageInfo {
    unsigned long signature;
    int debug;
    char *filename;
    double pointsize;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
    size_t columns;
    size_t rows;
    ExceptionInfo exception;
} Image;

typedef struct _DrawInfo {
    char *text;
    char *geometry;
    double stroke_width;
    double pointsize;
    GravityType gravity;
    GravityType direction;
} DrawInfo;

typedef struct {
    double width;
    double height;
    double ascent;
    double descent;
    struct {
        double x1;
        double x2;
    } bounds;
} TypeMetric;

typedef int MagickBooleanType;

#define TraceEvent 0
#define GetMagickModule() ""