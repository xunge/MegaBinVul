#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef int OMX_ERRORTYPE;
#define OMX_ErrorNone 0
#define OMX_ErrorUndefined 1
#define OMX_ErrorBadParameter 2
#define OMX_COLOR_FormatYUV420Planar 0

#define CHECK(expr)
#define ALOGE(...)

typedef struct tagvideoEncControls {
    // dummy structure
} tagvideoEncControls;

typedef struct tagvideoEncOptions {
    int encMode;
    int encWidth[1];
    int encHeight[1];
    int encFrameRate[1];
    int rcType;
    float vbvDelay;
    int profile_level;
    int packetSize;
    int rvlcEnable;
    int numLayers;
    int timeIncRes;
    int64_t tickPerSrc;
    int bitRate[1];
    int iQuant[1];
    int pQuant[1];
    int quantType[1];
    int noFrameSkipped;
    int intraPeriod;
    int numIntraMB;
    int sceneDetect;
    int searchRange;
    int mv8x8Enable;
    int gobHeaderInterval;
    int useACPred;
    int intraDCVlcTh;
} tagvideoEncOptions;

#define VBR_1 1
#define CORE_PROFILE_LEVEL2 2
#define PV_OFF 0
#define PV_ON 1

int PVGetDefaultEncOption(tagvideoEncOptions* options, int mode);

class SoftMPEG4Encoder {
public:
    tagvideoEncControls* mHandle;
    tagvideoEncOptions* mEncParams;
    int mEncodeMode;
    int mWidth;
    int mHeight;
    int mFramerate;
    int mBitrate;
    int mColorFormat;
    bool mInputDataIsMeta;
    uint8_t* mInputFrameData;
    int mIDRFrameRefreshIntervalInSec;
    
    OMX_ERRORTYPE initEncParams();
};