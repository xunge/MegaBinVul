#include <assert.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MagickSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define MaxTextExtent 2053
#define MagickEpsilon 1.0e-10
#define TraceEvent 0

typedef int MagickBooleanType;

typedef enum {
    UndefinedGravity,
    RightToLeftDirection
} GravityType;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    double pointsize;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
    int severity;
    char *reason;
    char *description;
} ExceptionInfo;

typedef struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    ExceptionInfo exception;
} Image;

typedef struct _DrawInfo {
    char *text;
    char *geometry;
    GravityType gravity;
    double pointsize;
    double stroke_width;
    double interline_spacing;
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

static const char *MagickGravityOptions[] = {"undefined", NULL};

static Image *AcquireImage(const ImageInfo *);
static DrawInfo *CloneDrawInfo(const ImageInfo *, DrawInfo *);
static DrawInfo *DestroyDrawInfo(DrawInfo *);
static Image *DestroyImageList(Image *);
static Image *GetFirstImageInList(Image *);
static char *AcquireString(const char *);
static char *DestroyString(char *);
static char *InterpretImageProperties(const ImageInfo *, Image *, const char *);
static const char *GetImageOption(const ImageInfo *, const char *);
static const char *GetImageProperty(Image *, const char *);
static MagickBooleanType AnnotateImage(Image *, DrawInfo *);
static ssize_t FormatMagickCaption(Image *, DrawInfo *, MagickBooleanType, TypeMetric *, char **);
static MagickBooleanType GetMultilineTypeMetrics(Image *, DrawInfo *, TypeMetric *);
static int LocaleNCompare(const char *, const char *, size_t);
static int LogMagickEvent(int, const char *, const char *, ...);
static int ParseCommandOption(const char *[], MagickBooleanType, const char *);
static MagickBooleanType ResetImagePage(Image *, const char *);
static MagickBooleanType SetImageBackgroundColor(Image *);
static MagickBooleanType SetImageExtent(Image *, size_t, size_t);
static MagickBooleanType SetImageProperty(Image *, const char *, const char *);
static char *ConstantString(const char *);
static char *CloneString(char **, const char *);
static int FormatLocaleString(char *, size_t, const char *, ...);
static void InheritException(ExceptionInfo *, ExceptionInfo *);
static const char *GetMagickModule(void);
static double MagickMax(double, double);