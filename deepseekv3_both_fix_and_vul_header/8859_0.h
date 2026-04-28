#include <stdint.h>
#include <string.h>

#define FIVEBAND_NUMBANDS 5
#define PRESET_CUSTOM -1
#define EINVAL 22

#define EQ_PARAM_NUM_BANDS 0
#define EQ_PARAM_LEVEL_RANGE 1
#define EQ_PARAM_BAND_LEVEL 2
#define EQ_PARAM_CENTER_FREQ 3
#define EQ_PARAM_BAND_FREQ_RANGE 4
#define EQ_PARAM_GET_BAND 5
#define EQ_PARAM_CUR_PRESET 6
#define EQ_PARAM_GET_NUM_OF_PRESETS 7
#define EQ_PARAM_GET_PRESET_NAME 8
#define EQ_PARAM_PROPERTIES 9

typedef struct EffectContext EffectContext;

int16_t EqualizerGetBandLevel(EffectContext *pContext, int32_t band);
int32_t EqualizerGetCentreFrequency(EffectContext *pContext, int32_t band);
void EqualizerGetBandFreqRange(EffectContext *pContext, int32_t band, uint32_t *pLow, uint32_t *pHigh);
int32_t EqualizerGetBand(EffectContext *pContext, int32_t freq);
int32_t EqualizerGetPreset(EffectContext *pContext);
int32_t EqualizerGetNumPresets();
char* EqualizerGetPresetName(int32_t preset);

#define ALOGV(...)
#define ALOGW(...)
#define ALOGE(...)
#define android_errorWriteLog(...)