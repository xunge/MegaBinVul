#include <stdint.h>

typedef int32_t EAS_I32;
typedef uint32_t EAS_U32;
typedef int EAS_BOOL;

#define EAS_FALSE 0
#define EAS_TRUE 1

#define SYNTH_UPDATE_PERIOD_IN_BITS 0
#define NUM_PHASE_FRAC_BITS 0
#define GET_PHASE_INT_PART(x) (x)

typedef struct {
    EAS_U32 phaseIncrement;
} S_WT_FRAME;

typedef struct {
    S_WT_FRAME frame;
    EAS_I32 numSamples;
} S_WT_INT_FRAME;

typedef struct {
    EAS_U32 phaseFrac;
    EAS_U32 phaseAccum;
    EAS_U32 loopEnd;
} S_WT_VOICE;