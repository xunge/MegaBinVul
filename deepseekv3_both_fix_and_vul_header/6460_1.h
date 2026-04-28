#include <stdlib.h>

typedef int dwtcoef;

enum {
    VC2_TRANSFORM_9_7,
    VC2_TRANSFORM_5_3
};

typedef struct VC2TransformContext {
    void (*vc2_subband_dwt[2])(void);
    dwtcoef *buffer;
    int padding;
} VC2TransformContext;

#define av_cold
#define av_calloc calloc

void vc2_subband_dwt_97(void);
void vc2_subband_dwt_53(void);