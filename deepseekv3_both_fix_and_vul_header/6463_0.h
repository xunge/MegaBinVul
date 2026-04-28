#include <stdlib.h>

typedef int dwtcoef;

enum VC2TransformType {
    VC2_TRANSFORM_9_7,
    VC2_TRANSFORM_5_3,
    VC2_TRANSFORM_HAAR,
    VC2_TRANSFORM_HAAR_S,
    VC2_TRANSFORMS_NB
};

typedef struct VC2TransformContext {
    void (*vc2_subband_dwt[VC2_TRANSFORMS_NB])(void);
    dwtcoef *buffer;
    int padding;
} VC2TransformContext;

#define av_cold
#define av_calloc calloc

void vc2_subband_dwt_97(void);
void vc2_subband_dwt_53(void);
void vc2_subband_dwt_haar(void);
void vc2_subband_dwt_haar_shift(void);