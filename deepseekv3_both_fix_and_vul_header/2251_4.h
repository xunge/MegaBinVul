#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

typedef void* effect_handle_t;
typedef int16_t LVM_INT16;

typedef enum {
    LVREV_SUCCESS = 0,
    LVREV_NULLADDRESS,
    LVREV_OUTOFRANGE,
    LVREV_INVALIDNUMSAMPLES,
    LVREV_INVALIDNUMTAPS,
    LVREV_INVALIDGAIN,
    LVREV_INVALIDBUFFERSIZE,
    LVREV_INVALIDBUFFER,
    LVREV_INVALIDBUFFERPOINTER,
    LVREV_INVALIDBUFFERHANDLE,
    LVREV_INVALIDBUFFERALIGNMENT,
    LVREV_INVALIDBUFFERMODE,
    LVREV_INVALIDBUFFERSIZEALIGNMENT,
    LVREV_INVALIDBUFFERALLOCATION,
    LVREV_INVALIDBUFFERPOINTERALIGNMENT,
    LVREV_INVALIDBUFFERHANDLEALIGNMENT,
    LVREV_INVALIDBUFFERMODEALIGNMENT,
    LVREV_INVALIDBUFFERSIZEALIGNMENTALIGNMENT,
    LVREV_INVALIDBUFFERALLOCATIONALIGNMENT
} LVREV_ReturnStatus_en;

typedef struct {
    uint32_t T60;
} LVREV_ControlParams_st;

typedef enum {
    LVM_FALSE = 0,
    LVM_TRUE
} LVM_BOOL;

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
} effect_config_t;

static void android_errorWriteLog(int, const char*) {}

namespace android {
    enum {
        REVERB_VOLUME_OFF,
        REVERB_VOLUME_FLAT
    };

    struct ReverbContext {
        LVM_BOOL bEnabled;
        LVM_INT16 leftVolume;
        LVM_INT16 rightVolume;
        int volumeMode;
        void* hInstance;
        uint32_t SamplesToExitCount;
        effect_config_t config;
    };

    int Reverb_setConfig(ReverbContext *pContext, effect_config_t *config);
    int Reverb_getConfig(ReverbContext *pContext, effect_config_t *config);
    int Reverb_getParameter(ReverbContext *pContext, void *data, uint32_t *vsize, void *value);
    int Reverb_setParameter(ReverbContext *pContext, void *data, void *value, uint32_t vsize);
    int Reverb_setParameter(ReverbContext *pContext, void *data, void *value);
}

static LVREV_ReturnStatus_en LVREV_GetControlParameters(void*, LVREV_ControlParams_st*) {
    return LVREV_SUCCESS;
}

#define ALOGV(...) 
#define LVM_ERROR_CHECK(status, func, context)