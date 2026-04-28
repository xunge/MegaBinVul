#include <stdlib.h>

typedef unsigned short cmsUInt16Number;
typedef struct _cmsContext_struct* cmsContext;
typedef struct _cms_curve_struct cmsToneCurve;

typedef struct {
    int nCurves;
    int nElements;
    cmsUInt16Number** Curves;
} Curves16Data;

#define FROM_8_TO_16(j) ((cmsUInt16Number) (((j) << 8) | (j)))
#define _cmsMallocZero(ctx, size) calloc(1, size)
#define _cmsCalloc(ctx, count, size) calloc(count, size)
cmsUInt16Number cmsEvalToneCurve16(const cmsToneCurve* Curve, cmsUInt16Number v);