#include <stdint.h>
#include <errno.h>

typedef struct ReverbContext {
    int preset;
    uint16_t nextPreset;
} ReverbContext;

typedef struct t_reverb_settings {
    int16_t roomLevel;
    int16_t roomHFLevel;
    uint32_t decayTime;
    int16_t decayHFRatio;
    int16_t reverbLevel;
    int16_t diffusion;
    int16_t density;
} t_reverb_settings;

#define REVERB_PARAM_PRESET 1
#define REVERB_PRESET_LAST 10
#define REVERB_PARAM_PROPERTIES 2
#define REVERB_PARAM_ROOM_LEVEL 3
#define REVERB_PARAM_ROOM_HF_LEVEL 4
#define REVERB_PARAM_DECAY_TIME 5
#define REVERB_PARAM_DECAY_HF_RATIO 6
#define REVERB_PARAM_REVERB_LEVEL 7
#define REVERB_PARAM_DIFFUSION 8
#define REVERB_PARAM_DENSITY 9
#define REVERB_PARAM_REFLECTIONS_LEVEL 10
#define REVERB_PARAM_REFLECTIONS_DELAY 11
#define REVERB_PARAM_REVERB_DELAY 12

#define ALOGV(...)

void ReverbSetRoomLevel(struct ReverbContext *pContext, int16_t level);
void ReverbSetRoomHfLevel(struct ReverbContext *pContext, int16_t level);
void ReverbSetDecayTime(struct ReverbContext *pContext, uint32_t time);
void ReverbSetDecayHfRatio(struct ReverbContext *pContext, int16_t ratio);
void ReverbSetReverbLevel(struct ReverbContext *pContext, int16_t level);
void ReverbSetDiffusion(struct ReverbContext *pContext, int16_t ratio);
void ReverbSetDensity(struct ReverbContext *pContext, int16_t ratio);