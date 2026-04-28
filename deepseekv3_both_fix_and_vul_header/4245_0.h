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
    uint32_t phaseFrac;
    uint32_t phaseAccum;
    uint32_t loopEnd;
} S_WT_VOICE;

typedef struct {
    struct {
        uint32_t phaseIncrement;
    } frame;
    int32_t numSamples;
} S_WT_INT_FRAME;