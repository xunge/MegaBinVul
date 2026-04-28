#include <stdint.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

typedef int effect_handle_t;

typedef struct effect_context_s {
    int state;
    int offload_enabled;
    int out_handle;
    struct {
        int (*init)(struct effect_context_s *context);
        int (*reset)(struct effect_context_s *context);
        int (*enable)(struct effect_context_s *context);
        int (*disable)(struct effect_context_s *context);
        int (*get_parameter)(struct effect_context_s *context, void *param, uint32_t *size);
        int (*set_parameter)(struct effect_context_s *context, void *param, uint32_t size);
        int (*set_device)(struct effect_context_s *context, uint32_t device);
        int (*command)(struct effect_context_s *context, uint32_t cmdCode, uint32_t cmdSize,
                      void *pCmdData, uint32_t *replySize, void *pReplyData);
    } ops;
} effect_context_t;

typedef struct effect_config_s {
    uint32_t samplingRate;
    uint32_t channels;
    uint32_t bufferSize;
} effect_config_t;

typedef struct effect_param_s {
    uint32_t psize;
    uint32_t vsize;
    uint8_t data[];
} effect_param_t;

typedef struct effect_offload_param_s {
    int isOffload;
    int ioHandle;
} effect_offload_param_t;

typedef struct output_context_s output_context_t;

enum {
    EFFECT_STATE_UNINITIALIZED,
    EFFECT_STATE_INITIALIZED,
    EFFECT_STATE_ACTIVE
};

enum {
    EFFECT_CMD_INIT,
    EFFECT_CMD_SET_CONFIG,
    EFFECT_CMD_GET_CONFIG,
    EFFECT_CMD_RESET,
    EFFECT_CMD_ENABLE,
    EFFECT_CMD_DISABLE,
    EFFECT_CMD_GET_PARAM,
    EFFECT_CMD_SET_PARAM,
    EFFECT_CMD_SET_DEVICE,
    EFFECT_CMD_SET_VOLUME,
    EFFECT_CMD_SET_AUDIO_MODE,
    EFFECT_CMD_OFFLOAD,
    EFFECT_CMD_FIRST_PROPRIETARY = 0x10000
};

extern pthread_mutex_t lock;

static inline int effect_exists(effect_context_t *context) {
    return 1;
}

static inline int set_config(effect_context_t *context, effect_config_t *config) {
    return 0;
}

static inline void get_config(effect_context_t *context, effect_config_t *config) {
}

static inline output_context_t *get_output(int handle) {
    return NULL;
}

static inline void remove_effect_from_output(output_context_t *out_ctxt, effect_context_t *context) {
}

static inline void add_effect_to_output(output_context_t *out_ctxt, effect_context_t *context) {
}

#define ALOGV(...)
#define ALOGW(...)