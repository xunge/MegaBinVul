#include <assert.h>
#include <math.h>
#include <stddef.h>

typedef long ssize_t;

#define MagickExport

typedef enum
{
  NoValue = 0x0000,
  XValue = 0x0001,
  YValue = 0x0002,
  WidthValue = 0x0004,
  HeightValue = 0x0008,
  AllValues = 0x000F,
  XNegative = 0x0010,
  YNegative = 0x0020,
  PercentValue = 0x0040,
  AspectValue = 0x0080,
  LessValue = 0x0100,
  GreaterValue = 0x0200,
  AreaValue = 0x0400,
  MinimumValue = 0x0800,
  RhoValue = 0x1000,
  SigmaValue = 0x2000,
  XiValue = 0x4000,
  PsiValue = 0x8000,
  ChiValue = 0x10000,
  AspectRatioValue = 0x20000
} MagickStatusType;

typedef struct _GeometryInfo
{
  double rho;
  double sigma;
  double xi;
  double psi;
  double chi;
} GeometryInfo;

typedef struct _PointInfo
{
  double x;
  double y;
} PointInfo;

typedef enum
{
  MagickFalse = 0,
  MagickTrue = 1
} MagickBooleanType;

extern MagickBooleanType IsEventLogging(void);
extern void LogMagickEvent(int,const char *,const char *,...);
extern int TraceEvent;
extern const char *GetMagickModule(void);
extern void SetGeometryInfo(GeometryInfo *);
extern MagickStatusType GetGeometry(const char *,ssize_t *,ssize_t *,size_t *,size_t *);
extern MagickStatusType ParseGeometry(const char *,GeometryInfo *);
extern double PerceptibleReciprocal(double);
extern unsigned int CastDoubleToUnsigned(double);
extern double MagickMax(double,double);
extern double MagickEpsilon;