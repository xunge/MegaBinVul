#include <stdint.h>

typedef int32_t EAS_I32;
typedef int16_t EAS_I16;
typedef EAS_I16 EAS_PCM;

typedef struct {
    EAS_I16 z1;
    EAS_I16 z2;
} S_FILTER_CONTROL;

typedef struct {
    EAS_I32 b1;
    EAS_I32 b2;
    EAS_I32 k;
} WT_FRAME;

typedef struct {
    EAS_PCM *pAudioBuffer;
    EAS_I32 numSamples;
    WT_FRAME frame;
} S_WT_INT_FRAME;

#define ALOGE(x)