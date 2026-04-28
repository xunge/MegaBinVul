#include <stdint.h>

typedef int32_t EAS_I32;
typedef int16_t EAS_I16;
typedef int8_t EAS_I8;

#define SYNTH_UPDATE_PERIOD_IN_BITS 16
#define NUM_EG1_FRAC_BITS 16
#define NUM_PHASE_FRAC_BITS 16
#define PHASE_FRAC_MASK 0xFFFF

typedef struct {
    EAS_I8 *pPhaseAccum;
    EAS_I32 phaseFrac;
    EAS_I8 *pLoopStart;
    const EAS_I8 *pLoopEnd;
    EAS_I16 gain;
} S_WT_VOICE;

typedef struct {
    EAS_I32 *pMixBuffer;
    EAS_I32 numSamples;
    EAS_I32 gainTarget;
    EAS_I32 prevGain;
    EAS_I32 phaseIncrement;
} S_WT_INT_FRAME;