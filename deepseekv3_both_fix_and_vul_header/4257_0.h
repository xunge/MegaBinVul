#include <stdint.h>

typedef int32_t EAS_I32;
typedef int16_t EAS_PCM;
typedef uint32_t EAS_U32;

#define PHASE_ONE 0x10000
#define MULT_AUDIO_COEF(a, b) ((a) * (b) >> 16)
#define GET_PHASE_INT_PART(x) ((x) >> 16)
#define GET_PHASE_FRAC_PART(x) ((x) & 0xffff)

typedef struct {
    EAS_U32 phaseAccum;
    EAS_U32 loopEnd;
    EAS_U32 phaseFrac;
} S_WT_VOICE;

typedef struct {
    EAS_I32 numSamples;
    EAS_PCM *pAudioBuffer;
    struct {
        EAS_I32 phaseIncrement;
    } frame;
} S_WT_INT_FRAME;

#define ALOGE(x)