#include <assert.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define MagickSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define MaxTextExtent 4096
#define MagickEpsilon 1.0e-10
#define TraceEvent 0

typedef enum {
    UndefinedGravity,
    RightToLeftDirection
} GravityType;

typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef struct _DrawInfo DrawInfo;
typedef struct _TypeMetric TypeMetric;

typedef int MagickBooleanType;

typedef struct _Bounds {
    double x1;
    double x2;
} Bounds;

struct _TypeMetric {
    Bounds bounds;
    double ascent;
    double descent;
    double width;
    double height;
};

struct _DrawInfo {
    char *text;
    GravityType gravity;
    char *geometry;
    double pointsize;
    double stroke_width;
    double interline_spacing;
    GravityType direction;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _Image {
    size_t columns;
    size_t rows;
    struct _ExceptionInfo exception;
};

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    double pointsize;
};

static const char *MagickGravityOptions[] = {NULL};

static int LocaleNCompare(const char *s1, const char *s2, size_t n) {
    return strncmp(s1, s2, n);
}

static char *GetImageProperty(Image *image, const char *property) {
    return NULL;
}

static double MagickMax(double x, double y) {
    return x > y ? x : y;
}

static int FormatLocaleString(char *str, size_t size, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int ret = vsnprintf(str, size, format, args);
    va_end(args);
    return ret;
}

static Image *AcquireImage(const ImageInfo *image_info) { return NULL; }
static void ResetImagePage(Image *image, const char *page) {}
static const char *GetImageOption(const ImageInfo *image_info, const char *option) { return NULL; }
static char *InterpretImageProperties(const ImageInfo *image_info, Image *image, const char *text) { return NULL; }
static int SetImageProperty(Image *image, const char *property, const char *value) { return 0; }
static char *DestroyString(char *str) { free(str); return NULL; }
static char *ConstantString(const char *str) { return str ? strdup(str) : NULL; }
static DrawInfo *CloneDrawInfo(const ImageInfo *image_info, DrawInfo *draw_info) { return NULL; }
static int CloneString(char **destination, const char *source) { return 0; }
static int ParseCommandOption(const char **options, MagickBooleanType, const char *option) { return 0; }
static char *AcquireString(const char *str) { return str ? strdup(str) : NULL; }
static int FormatMagickCaption(Image *image, DrawInfo *draw_info, MagickBooleanType split, TypeMetric *metrics, char **text) { return 0; }
static MagickBooleanType GetMultilineTypeMetrics(Image *image, DrawInfo *draw_info, TypeMetric *metrics) { return MagickFalse; }
static MagickBooleanType SetImageExtent(Image *image, size_t columns, size_t rows) { return MagickFalse; }
static DrawInfo *DestroyDrawInfo(DrawInfo *draw_info) { return NULL; }
static void InheritException(ExceptionInfo *exception, ExceptionInfo *inherited) {}
static Image *DestroyImageList(Image *image) { return NULL; }
static MagickBooleanType SetImageBackgroundColor(Image *image) { return MagickFalse; }
static MagickBooleanType AnnotateImage(Image *image, DrawInfo *draw_info) { return MagickFalse; }
static Image *GetFirstImageInList(Image *image) { return image; }
static void LogMagickEvent(int event, const char *module, const char *format, ...) {}
static const char *GetMagickModule(void) { return ""; }