#include <assert.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _Image {
    size_t columns;
    size_t rows;
    char *filename;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    char *filename;
    double pointsize;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef enum {
    UndefinedGravity = 0,
    NorthWestGravity = 1,
    WestGravity = 4,
    SouthWestGravity = 7
} GravityType;

typedef enum {
    RightToLeftDirection = 1
} DirectionType;

typedef struct _DrawInfo {
    double pointsize;
    char *text;
    double stroke_width;
    GravityType gravity;
    char *geometry;
    DirectionType direction;
} DrawInfo;

typedef struct _TypeMetric {
    double width;
    double height;
    double ascent;
    double underline_position;
    struct {
        double x1;
        double x2;
        double y1;
        double y2;
    } bounds;
} TypeMetric;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

#define MagickCoreSignature 0x12345678
#define MagickPathExtent 4096
#define WidthResource "WidthResource"
#define ImageError "ImageError"
#define MagickEpsilon 1.0e-10

#define GetMagickModule() "MagickCore"
#define TraceEvent 0

#define MagickMax(a,b) ((a) > (b) ? (a) : (b))

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
void *DestroyImageList(Image *);
void *DestroyDrawInfo(DrawInfo *);
void *DestroyString(char *);
char *InterpretImageProperties(ImageInfo *, Image *, const char *, ExceptionInfo *);
void SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
DrawInfo *CloneDrawInfo(const ImageInfo *, DrawInfo *);
MagickBooleanType AcquireMagickResource(const char *, size_t);
char *ConstantString(const char *);
MagickBooleanType GetMultilineTypeMetrics(Image *, DrawInfo *, TypeMetric *, ExceptionInfo *);
void AdjustTypeMetricBounds(TypeMetric *);
const char *GetImageOption(const ImageInfo *, const char *);
double StringToDouble(const char *, char **);
char *FormatLocaleString(char *, size_t, const char *, ...);
char *CloneString(char **, const char *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
MagickBooleanType SetImageBackgroundColor(Image *, ExceptionInfo *);
MagickBooleanType AnnotateImage(Image *, DrawInfo *, ExceptionInfo *);
void FormatImageProperty(Image *, const char *, const char *, ...);
Image *GetFirstImageInList(Image *);
MagickBooleanType IsEventLogging(void);
void LogMagickEvent(int, const char *, const char *, ...);
void ResetImagePage(Image *, const char *);
void ThrowReaderException(const char *, const char *);