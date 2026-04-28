#include <stdlib.h>

#define errInternal 1
#define errSyntaxWarning 2

typedef enum {
  PT_XYZ,
  PT_LAB,
  PT_LUV,
  PT_YCbCr,
  PT_YUV,
  PT_RGB,
  PT_GRAY,
  PT_HSV,
  PT_HLS,
  PT_CMYK,
  PT_CMY,
  PT_2CLR,
  PT_3CLR,
  PT_4CLR,
  PT_5CLR,
  PT_6CLR,
  PT_7CLR,
  PT_8CLR,
  PT_9CLR,
  PT_ACLR,
  PT_BCLR,
  PT_CCLR,
  PT_DCLR,
  PT_ECLR,
  PT_FCLR
} GfxColorSpaceType;

typedef void* cmsHTRANSFORM;
typedef void* cmsHPROFILE;
typedef int cmsColorSpaceSignature;

#define TYPE_XYZ_DBL 0
#define COLORSPACE_SH(x) (x)
#define CHANNELS_SH(x) (x)
#define BYTES_SH(x) (x)
#define INTENT_RELATIVE_COLORIMETRIC 0
#define LCMS_FLAGS 0

class GfxColorTransform {
public:
  GfxColorTransform(cmsHTRANSFORM transform, int intent, GfxColorSpaceType srcType, GfxColorSpaceType destType);
};

class GfxColorSpace {
private:
  void *displayProfile;
  GfxColorTransform *XYZ2DisplayTransform;
  GfxColorSpaceType displayPixelType;

  GfxColorSpaceType getCMSColorSpaceType(cmsColorSpaceSignature sig);
  unsigned int getCMSNChannels(cmsColorSpaceSignature sig);
public:
  void setDisplayProfile(void *displayProfileA);
};

void error(int type, int code, const char* msg);
cmsColorSpaceSignature cmsGetColorSpace(void* profile);
cmsHPROFILE cmsCreateXYZProfile();
cmsHTRANSFORM cmsCreateTransform(cmsHPROFILE input, int inputFormat,
                                cmsHPROFILE output, int outputFormat,
                                int intent, int flags);
void cmsCloseProfile(cmsHPROFILE hProfile);