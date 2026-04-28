#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <inttypes.h>
#include <errno.h>

#define VISUALIZER_STATE_UNINITIALIZED 0
#define VISUALIZER_STATE_INITIALIZED 1
#define VISUALIZER_STATE_ACTIVE 2

#define EFFECT_CMD_INIT 0
#define EFFECT_CMD_SET_CONFIG 1
#define EFFECT_CMD_GET_CONFIG 2
#define EFFECT_CMD_RESET 3
#define EFFECT_CMD_ENABLE 4
#define EFFECT_CMD_DISABLE 5
#define EFFECT_CMD_GET_PARAM 6
#define EFFECT_CMD_SET_PARAM 7
#define EFFECT_CMD_SET_DEVICE 8
#define EFFECT_CMD_SET_VOLUME 9
#define EFFECT_CMD_SET_AUDIO_MODE 10

#define VISUALIZER_CMD_CAPTURE 11
#define VISUALIZER_CMD_MEASURE 12

#define VISUALIZER_PARAM_CAPTURE_SIZE 0
#define VISUALIZER_PARAM_SCALING_MODE 1
#define VISUALIZER_PARAM_LATENCY 2
#define VISUALIZER_PARAM_MEASUREMENT_MODE 3

#define VISUALIZER_CAPTURE_SIZE_MAX 1024
#define MAX_LATENCY_MS 1000
#define MAX_STALL_TIME_MS 2000
#define CAPTURE_BUF_SIZE 2048
#define MEASUREMENT_COUNT 2
#define DISCARD_MEASUREMENTS_TIME_MS 2000

#define MEASUREMENT_IDX_RMS 0
#define MEASUREMENT_IDX_PEAK 1

typedef struct audio_config_s {
    uint32_t samplingRate;
    uint32_t channels;
    uint32_t format;
    uint32_t mask;
} audio_config_t;

typedef struct effect_config_s {
    audio_config_t inputCfg;
    audio_config_t outputCfg;
} effect_config_t;

typedef struct effect_param_s {
    uint32_t status;
    uint32_t psize;
    uint32_t vsize;
    uint8_t data[];
} effect_param_t;

typedef struct VisualizerContext {
    uint32_t mState;
    uint32_t mCaptureSize;
    uint32_t mScalingMode;
    uint32_t mMeasurementMode;
    uint32_t mLatency;
    uint32_t mCaptureIdx;
    uint32_t mLastCaptureIdx;
    struct timespec mBufferUpdateTime;
    uint8_t mCaptureBuf[CAPTURE_BUF_SIZE];
    uint32_t mMeasurementWindowSizeInBuffers;
    uint32_t mMeasurementBufferIdx;
    struct {
        bool mIsValid;
        uint16_t mPeakU16;
        float mRmsSquared;
    } mPastMeasurements[MEASUREMENT_COUNT];
    effect_config_t mConfig;
} VisualizerContext;

typedef void* effect_handle_t;

int Visualizer_init(VisualizerContext *pContext);
int Visualizer_setConfig(VisualizerContext *pContext, effect_config_t *pCmdData);
void Visualizer_getConfig(VisualizerContext *pContext, effect_config_t *pReplyData);
void Visualizer_reset(VisualizerContext *pContext);
uint32_t Visualizer_getDeltaTimeMsFromUpdatedTime(VisualizerContext *pContext);

#define ALOGV(...)
#define ALOGW(...)
#define android_errorWriteLog(...)