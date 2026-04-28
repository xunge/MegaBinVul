#include <stdint.h>

#define NUM_OUTPUT_CHANNELS 2
#define SYNTH_UPDATE_PERIOD_IN_BITS 16
#define NUM_MIXER_GUARD_BITS 8
#define ALOGE(x)

typedef int32_t EAS_I32;
typedef int16_t EAS_PCM;

typedef struct {
    EAS_I32 gainLeft;
    EAS_I32 gainRight;
} S_WT_VOICE;

typedef struct {
    EAS_I32 numSamples;
    EAS_I32 *pMixBuffer;
    EAS_PCM *pAudioBuffer;
    struct {
        EAS_I32 gainTarget;
    } frame;
    EAS_I32 prevGain;
} S_WT_INT_FRAME;