#include <stdint.h>

typedef int32_t EAS_I32;
typedef uint32_t EAS_U32;
typedef int16_t EAS_PCM;

#define PHASE_ONE (1L << 30)
#define MULT_AUDIO_COEF(a, b) ((EAS_I32)(((int64_t)(a) * (int64_t)(b)) >> 30))
#define GET_PHASE_INT_PART(phase) ((phase) >> 30)
#define GET_PHASE_FRAC_PART(phase) ((phase) & ((1L << 30) - 1))

typedef struct {
    EAS_U32 phaseAccum;
    EAS_U32 loopEnd;
    EAS_U32 phaseFrac;
} S_WT_VOICE;

typedef struct {
    EAS_I32 phaseIncrement;
} S_WT_FRAME;

typedef struct {
    EAS_PCM *pAudioBuffer;
    EAS_I32 numSamples;
    S_WT_FRAME frame;
} S_WT_INT_FRAME;