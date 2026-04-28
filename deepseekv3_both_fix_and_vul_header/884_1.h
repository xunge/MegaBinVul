#include <math.h>
#include <stddef.h>
#include <sys/types.h>

typedef enum { MagickFalse, MagickTrue } MagickBooleanType;

typedef struct _PointInfo {
    double x, y;
} PointInfo;

typedef struct _PrimitiveInfo {
    PointInfo point;
    size_t coordinates;
    MagickBooleanType closed_subpath;
    int primitive;
} PrimitiveInfo;

typedef struct _ExceptionInfo {
    int severity;
    char *reason;
    char *description;
} ExceptionInfo;

typedef struct _MVGInfo {
    PrimitiveInfo **primitive_info;
    size_t offset;
    ExceptionInfo *exception;
} MVGInfo;

#define SSIZE_MAX ((ssize_t)((size_t)-1 >> 1))
#define BezierQuantum 100
#define ResourceLimitError 1

extern const char *GetMagickModule(void);
extern MagickBooleanType ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, const char *);
extern void *AcquireQuantumMemory(size_t, size_t);
extern void *RelinquishMagickMemory(void *);
extern ssize_t Permutate(ssize_t, ssize_t);
extern MagickBooleanType CheckPrimitiveExtent(MVGInfo *, size_t);
extern MagickBooleanType TracePoint(PrimitiveInfo *, PointInfo);
#define MagickMin(x,y) ((x) < (y) ? (x) : (y))