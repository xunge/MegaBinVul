#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>
#include <stdbool.h>

typedef struct downmix_object_s {
    int state;
} downmix_object_t;

typedef struct downmix_module_s {
    downmix_object_t context;
} downmix_module_t;

typedef downmix_module_t* effect_handle_t;

typedef struct effect_config_s {
    uint32_t dummy;
} effect_config_t;

typedef struct effect_param_s {
    int32_t status;
    uint32_t psize;
    uint32_t vsize;
    uint8_t data[];
} effect_param_t;

enum {
    DOWNMIX_STATE_UNINITIALIZED,
    DOWNMIX_STATE_INITIALIZED,
    DOWNMIX_STATE_ACTIVE
};

enum {
    EFFECT_CMD_INIT,
    EFFECT_CMD_SET_CONFIG,
    EFFECT_CMD_RESET,
    EFFECT_CMD_GET_PARAM,
    EFFECT_CMD_SET_PARAM,
    EFFECT_CMD_SET_PARAM_DEFERRED,
    EFFECT_CMD_SET_PARAM_COMMIT,
    EFFECT_CMD_ENABLE,
    EFFECT_CMD_DISABLE,
    EFFECT_CMD_SET_DEVICE,
    EFFECT_CMD_SET_VOLUME,
    EFFECT_CMD_SET_AUDIO_MODE,
    EFFECT_CMD_SET_CONFIG_REVERSE,
    EFFECT_CMD_SET_INPUT_DEVICE
};

#define ALOGV(...)
#define ALOGW(...)
#define android_errorWriteLog(...)

static int Downmix_Init(downmix_module_t *pDwmModule) { return 0; }
static int Downmix_Configure(downmix_module_t *pDwmModule, effect_config_t *config, bool isReset) { return 0; }
static void Downmix_Reset(downmix_object_t *pDownmixer, bool isReset) {}
static int Downmix_getParameter(downmix_object_t *pDownmixer, int32_t param, uint32_t *size, void *value) { return 0; }
static int Downmix_setParameter(downmix_object_t *pDownmixer, int32_t param, uint32_t size, void *value) { return 0; }