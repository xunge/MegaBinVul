#include <stdint.h>

#define EINVAL 22
#define FIVEBAND_NUMBANDS 5

enum {
    EQ_PARAM_CUR_PRESET,
    EQ_PARAM_BAND_LEVEL,
    EQ_PARAM_PROPERTIES
};

typedef struct EffectContext EffectContext;

int EqualizerGetNumPresets();
void EqualizerSetPreset(EffectContext *pContext, int preset);
void EqualizerSetBandLevel(EffectContext *pContext, int band, int level);