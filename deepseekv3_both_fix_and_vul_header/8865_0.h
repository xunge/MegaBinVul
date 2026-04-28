#include <stdint.h>
#include <string.h>

#define FIVEBAND_NUMBANDS 5
#define EINVAL 22

#define EQ_PARAM_NUM_BANDS 0
#define EQ_PARAM_CUR_PRESET 1
#define EQ_PARAM_GET_NUM_OF_PRESETS 2
#define EQ_PARAM_BAND_LEVEL 3
#define EQ_PARAM_GET_BAND 4
#define EQ_PARAM_LEVEL_RANGE 5
#define EQ_PARAM_BAND_FREQ_RANGE 6
#define EQ_PARAM_CENTER_FREQ 7
#define EQ_PARAM_GET_PRESET_NAME 8
#define EQ_PARAM_PROPERTIES 9

typedef struct EffectContext EffectContext;

int EqualizerGetBandLevel(EffectContext *pContext, int32_t band);
int32_t EqualizerGetCentreFrequency(EffectContext *pContext, int32_t band);
void EqualizerGetBandFreqRange(EffectContext *pContext, int32_t band, uint32_t *min, uint32_t *max);
int32_t EqualizerGetBand(EffectContext *pContext, int32_t frequency);
int32_t EqualizerGetPreset(EffectContext *pContext);
int32_t EqualizerGetNumPresets();
char* EqualizerGetPresetName(int32_t preset);