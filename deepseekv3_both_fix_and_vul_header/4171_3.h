#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef void* effect_handle_t;

typedef struct {
    uint32_t psize;
    uint32_t vsize;
    int32_t status;
    char data[];
} effect_param_t;

typedef struct {
    struct {
        uint32_t samplingRate;
    } inputCfg;
    uint32_t outputCfg;
} effect_config_t;

typedef enum {
    LVREV_SUCCESS = 0,
    LVREV_FAILURE
} LVREV_ReturnStatus_en;

typedef struct {
    uint32_t T60;
} LVREV_ControlParams_st;

typedef int16_t LVM_INT16;

#define LVM_TRUE 1
#define LVM_FALSE 0
#define REVERB_UNIT_VOLUME 0x1000
#define EINVAL 22

enum {
    EFFECT_CMD_INIT,
    EFFECT_CMD_SET_CONFIG,
    EFFECT_CMD_GET_CONFIG,
    EFFECT_CMD_RESET,
    EFFECT_CMD_GET_PARAM,
    EFFECT_CMD_SET_PARAM,
    EFFECT_CMD_ENABLE,
    EFFECT_CMD_DISABLE,
    EFFECT_CMD_SET_VOLUME,
    EFFECT_CMD_SET_DEVICE,
    EFFECT_CMD_SET_AUDIO_MODE
};

#define ALOGV(...)
#define android_errorWriteLog(...)
#define LVM_ERROR_CHECK(...)

namespace android {
    enum {
        REVERB_VOLUME_OFF,
        REVERB_VOLUME_FLAT
    };

    struct ReverbContext {
        void* hInstance;
        effect_config_t config;
        int bEnabled;
        int SamplesToExitCount;
        int volumeMode;
        LVM_INT16 leftVolume;
        LVM_INT16 rightVolume;
    };

    int Reverb_setConfig(ReverbContext *pContext, effect_config_t *pCmdData);
    void Reverb_getConfig(ReverbContext *pContext, effect_config_t *pReplyData);
    int Reverb_getParameter(ReverbContext *pContext, void *data, size_t *vsize, void *value);
    int Reverb_setParameter(ReverbContext *pContext, void *data, void *value);
    LVREV_ReturnStatus_en LVREV_GetControlParameters(void* hInstance, LVREV_ControlParams_st* pParams);
}

using android::LVREV_GetControlParameters;