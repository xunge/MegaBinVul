#include <assert.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  UndefinedGravity,
  NorthWestGravity,
  WestGravity,
  SouthWestGravity,
  RightToLeftDirection
} GravityType;

typedef struct _ImageInfo {
  unsigned long signature;
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
  double pointsize;
  char *text;
  GravityType gravity;
  char *geometry;
  double stroke_width;
  double interline_spacing;
  GravityType direction;
} DrawInfo;

typedef struct {
  struct {
    double x1;
    double x2;
    double y1;
    double y2;
  } bounds;
  double ascent;
  double descent;
  double width;
  double height;
  double underline_position;
} TypeMetric;

#define MagickCoreSignature 0
#define MagickPathExtent 4096
#define MagickEpsilon 1.0E-10

enum {
  TraceEvent,
  WidthResource,
  ImageError
};

enum {
  MagickGravityOptions
};

extern int IsEventLogging(void);
extern void *LogMagickEvent(int, const char *, const char *, ...);
extern const char *GetMagickModule(void);
extern Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
extern void ResetImagePage(Image *, const char *);
extern int SetImageBackgroundColor(Image *, ExceptionInfo *);
extern const char *GetImageOption(const ImageInfo *, const char *);
extern char *InterpretImageProperties(ImageInfo *, Image *, const char *, ExceptionInfo *);
extern void SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
extern DrawInfo *CloneDrawInfo(const ImageInfo *, DrawInfo *);
extern int AcquireMagickResource(int, size_t);
extern char *DestroyString(char *);
extern DrawInfo *DestroyDrawInfo(DrawInfo *);
extern void ThrowReaderException(int, const char *);
extern char *CloneString(char **, const char *);
extern int ParseCommandOption(int, int, const char *);
extern int IsStringTrue(const char *);
extern void *memset(void *, int, size_t);
extern char *AcquireString(const char *);
extern ssize_t FormatMagickCaption(Image *, DrawInfo *, MagickBooleanType, TypeMetric *, char **, ExceptionInfo *);
extern void AdjustTypeMetricBounds(TypeMetric *);
extern int GetMultilineTypeMetrics(Image *, DrawInfo *, TypeMetric *, ExceptionInfo *);
extern int SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
extern double StringToDouble(const char *, char **);
extern int FormatLocaleString(char *, size_t, const char *, ...);
extern int AnnotateImage(Image *, DrawInfo *, ExceptionInfo *);
extern int GetMagickPrecision(void);
extern void FormatImageProperty(Image *, const char *, const char *, ...);
extern Image *DestroyImageList(Image *);
extern Image *GetFirstImageInList(Image *);
extern int LocaleNCompare(const char *, const char *, size_t);
extern double MagickMax(double, double);