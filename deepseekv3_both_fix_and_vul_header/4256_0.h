#include <stdint.h>

#define NUM_PHASE_FRAC_BITS 16
#define PHASE_FRAC_MASK ((1 << NUM_PHASE_FRAC_BITS) - 1)
#define ALOGE(x)

typedef int32_t EAS_I32;
typedef uint32_t EAS_U32;
typedef int16_t EAS_I16;
typedef int16_t EAS_SAMPLE;
typedef int16_t EAS_PCM;

typedef struct {
    EAS_U32 phaseAccum;
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