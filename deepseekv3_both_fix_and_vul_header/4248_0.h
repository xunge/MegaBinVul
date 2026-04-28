#include <stdint.h>

typedef int32_t EAS_I32;
typedef uint32_t EAS_U32;
typedef int16_t EAS_I16;
typedef int16_t EAS_SAMPLE;
typedef int16_t EAS_PCM;

#define NUM_PHASE_FRAC_BITS 16
#define PHASE_FRAC_MASK 0xFFFF

typedef struct {
    EAS_U32 phaseAccum;
    EAS_U32 phaseFrac;
    void* loopEnd;
    void* loopStart;
} S_WT_VOICE;

typedef struct {
    EAS_PCM* pAudioBuffer;
    EAS_I32 numSamples;
    struct {
        EAS_I32 phaseIncrement;
    } frame;
} S_WT_INT_FRAME;