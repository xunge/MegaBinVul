#include <stdint.h>
#include <stddef.h>

typedef unsigned int cmsUInt32Number;
typedef int cmsBool;
typedef double cmsFloat64Number;
typedef void* cmsContext;
typedef void* cmsHPROFILE;
typedef void* cmsPipeline;

typedef enum {
    cmsSigXYZData,
    cmsSigLabData,
    cmsSigLinkClass,
    cmsSigAbstractClass,
    cmsSigNamedColorClass
} cmsProfileClassSignature;

typedef enum {
    cmsERROR_COLORSPACE_CHECK
} cmsErrorCodes;

typedef struct {
    double v[3][3];
} cmsMAT3;

typedef struct {
    double v[3];
} cmsVEC3;

typedef unsigned int cmsColorSpaceSignature;

#define TRUE 1
#define FALSE 0

cmsPipeline* cmsPipelineAlloc(cmsContext ContextID, int InputChannels, int OutputChannels);
void cmsPipelineFree(cmsPipeline* Lut);
cmsBool cmsPipelineCat(cmsPipeline* Dst, const cmsPipeline* Src);
cmsColorSpaceSignature cmsGetColorSpace(cmsHPROFILE hProfile);
cmsColorSpaceSignature cmsGetPCS(cmsHPROFILE hProfile);
cmsProfileClassSignature cmsGetDeviceClass(cmsHPROFILE hProfile);
void cmsSignalError(cmsContext ContextID, cmsErrorCodes ErrorCode, const char* ErrorText);
void cmsUNUSED_PARAMETER(cmsUInt32Number param);

cmsPipeline* _cmsReadDevicelinkLUT(cmsHPROFILE hProfile, cmsUInt32Number Intent);
cmsPipeline* _cmsReadInputLUT(cmsHPROFILE hProfile, cmsUInt32Number Intent);
cmsPipeline* _cmsReadOutputLUT(cmsHPROFILE hProfile, cmsUInt32Number Intent);
void _cmsMAT3identity(cmsMAT3* m);
void _cmsVEC3init(cmsVEC3* v, double x, double y, double z);

cmsBool ColorSpaceIsCompatible(cmsColorSpaceSignature a, cmsColorSpaceSignature b);
cmsBool ComputeConversion(int i, cmsHPROFILE hProfiles[], cmsUInt32Number Intent, cmsBool BPC, cmsFloat64Number AdaptationState, cmsMAT3* m, cmsVEC3* off);
cmsBool AddConversion(cmsPipeline* Result, cmsColorSpaceSignature CurrentColorSpace, cmsColorSpaceSignature ColorSpaceIn, cmsMAT3* m, cmsVEC3* off);