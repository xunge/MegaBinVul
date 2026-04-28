#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <sys/types.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef unsigned int MagickStatusType;

typedef enum {
  UndefinedPrimitive
} PrimitiveType;

typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;

typedef struct _PointInfo {
  double x, y;
} PointInfo;

typedef struct _PrimitiveInfo {
  PrimitiveType primitive;
  PointInfo point;
  size_t coordinates;
} PrimitiveInfo;

typedef struct _DrawInfo {
  double dash_pattern[1];
  double dash_offset;
  double miterlimit;
  struct {
    double matrix[6];
  } affine;
} DrawInfo;

typedef struct _Image {
  MagickBooleanType debug;
} Image;

extern void *AcquireQuantumMemory(size_t count, size_t size);
extern void *RelinquishMagickMemory(void *memory);
extern DrawInfo *CloneDrawInfo(ImageInfo *image_info, const DrawInfo *draw_info);
extern DrawInfo *DestroyDrawInfo(DrawInfo *draw_info);
extern MagickBooleanType DrawStrokePolygon(Image *image, DrawInfo *draw_info, PrimitiveInfo *primitive_info, ExceptionInfo *exception);
extern void LogMagickEvent(int event, const char *module, const char *format, ...);
extern const char *GetMagickModule(void);

#define DrawEvent 0
#define MagickEpsilon 1.0e-10

static double ExpandAffine(const void *affine);