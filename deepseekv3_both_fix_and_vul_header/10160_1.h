#include <assert.h>
#include <math.h>
#include <string.h>

#define MaxTextExtent 4096
#define MagickEpsilon 1.0e-10
#define MagickSignature 0xabacadabUL

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  UndefinedGravity,
  RightToLeftDirection
} GravityType;

typedef struct _ImageInfo {
  unsigned long signature;
  MagickBooleanType debug;
  char *filename;
  double pointsize;
} ImageInfo;

typedef struct _ExceptionInfo {
  unsigned long signature;
  void *exception;
} ExceptionInfo;

typedef struct _Image {
  size_t columns;
  size_t rows;
  ExceptionInfo exception;
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

Image *AcquireImage(const ImageInfo *);
void *DestroyString(void *);
char *InterpretImageProperties(const ImageInfo *, Image *, const char *);
void *ResetImagePage(Image *, const char *);
void *SetImageProperty(Image *, const char *, const char *);
const char *GetImageProperty(const Image *, const char *);
DrawInfo *CloneDrawInfo(const ImageInfo *, DrawInfo *);
const char *ConstantString(const char *);
MagickBooleanType GetMultilineTypeMetrics(Image *, DrawInfo *, TypeMetric *);
char *FormatLocaleString(char *, const size_t, const char *, ...);
char *CloneString(char **, const char *);
void *DestroyDrawInfo(DrawInfo *);
void InheritException(ExceptionInfo *, ExceptionInfo *);
Image *DestroyImageList(Image *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t);
MagickBooleanType SetImageBackgroundColor(Image *);
MagickBooleanType AnnotateImage(Image *, DrawInfo *);
Image *GetFirstImageInList(Image *);
void *LogMagickEvent(int, const char *, const char *, const char *);
char *AcquireString(const char *);

#define TraceEvent 0
#define GetMagickModule() "LABEL"