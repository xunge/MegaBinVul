#include <stdint.h>
#include <string.h>

#define EFFECT_CMD_INIT 0
#define EFFECT_CMD_SET_CONFIG 1
#define EFFECT_CMD_GET_CONFIG 2
#define EFFECT_CMD_RESET 3
#define EFFECT_CMD_GET_PARAM 4
#define EFFECT_CMD_SET_PARAM 5
#define EFFECT_CMD_ENABLE 6
#define EFFECT_CMD_DISABLE 7
#define EFFECT_CMD_SET_DEVICE 8
#define EFFECT_CMD_SET_INPUT_DEVICE 9
#define EFFECT_CMD_SET_VOLUME 10
#define EFFECT_CMD_SET_AUDIO_MODE 11

#define EFFECT_STATE_ACTIVE 0
#define EFFECT_STATE_CONFIG 1

#define EINVAL 22
#define ENOSYS 38

typedef void* effect_handle_t;

struct effect_s {
    int state;
    void* session;
};

typedef struct {
    // config fields
} effect_config_t;

typedef struct {
    int status;
    uint32_t psize;
    // other fields
} effect_param_t;

extern int session_set_config(void* session, effect_config_t* config);
extern int session_get_config(void* session, effect_config_t* config);
extern int effect_set_state(struct effect_s* effect, int state);