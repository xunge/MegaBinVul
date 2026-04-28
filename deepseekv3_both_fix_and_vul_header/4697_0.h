#include <math.h>
#include <stdlib.h>

typedef enum
{
  UndefinedPrimitive,
  BevelJoin,
  MiterJoin,
  RoundJoin,
  SquareCap
} PrimitiveType;

typedef struct _PointInfo
{
  double
    x,
    y;
} PointInfo;

typedef struct _PrimitiveInfo
{
  PrimitiveType
    primitive;
  size_t
    coordinates;
  PointInfo
    point;
} PrimitiveInfo;

typedef struct _DrawInfo
{
  PrimitiveType
    linejoin,
    linecap;
  double
    stroke_width,
    miterlimit;
  struct
  {
    double
      tx,
      ty,
      sx,
      sy,
      rx,
      ry;
  } affine;
} DrawInfo;

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

#define MagickEpsilon  1.0e-10
#define MagickPI  3.14159265358979323846264338327950288419716939937510
#define BezierQuantum  10

extern void *AcquireQuantumMemory(size_t count,size_t size);
extern void *ResizeQuantumMemory(void *memory,size_t count,size_t size);
extern void *RelinquishMagickMemory(void *memory);
extern void CopyMagickMemory(void *destination,const void *source,size_t size);
extern double DrawEpsilonReciprocal(double x);
extern double ExpandAffine(const void *affine);
extern double DegreesToRadians(double degrees);
extern void TraceSquareLinecap(PrimitiveInfo *primitive_info,size_t number_vertices,double mid);