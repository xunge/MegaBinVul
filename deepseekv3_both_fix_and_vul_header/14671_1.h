#include <assert.h>
#include <math.h>
#include <string.h>

#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define MagickEpsilon 1.0e-10
#define TraceEvent 0

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
} Image;

typedef struct _DrawInfo {
    char *text;
    char *geometry;
    double pointsize;
    double stroke_width;
    GravityType gravity;
    GravityType direction;
} DrawInfo;

typedef struct _TypeMetric {
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

const char *GetMagickModule(void);
Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
void *DestroyString(char *);
char *InterpretImageProperties(ImageInfo *, Image *, const char *, ExceptionInfo *);
void LogMagickEvent(int, const char *, const char *, ...);
void *ResetImagePage(Image *, const char *);
void *SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
const char *GetImageProperty(Image *, const char *, ExceptionInfo *);
DrawInfo *CloneDrawInfo(const ImageInfo *, DrawInfo *);
char *ConstantString(const char *);
MagickBooleanType GetMultilineTypeMetrics(Image *, DrawInfo *, TypeMetric *, ExceptionInfo *);
char *FormatLocaleString(char *, size_t, const char *, ...);
char *CloneString(char **, const char *);
void *DestroyDrawInfo(DrawInfo *);
Image *DestroyImageList(Image *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
MagickBooleanType SetImageBackgroundColor(Image *, ExceptionInfo *);
char *AcquireString(const char *);
MagickBooleanType AnnotateImage(Image *, DrawInfo *, ExceptionInfo *);
Image *GetFirstImageInList(Image *);