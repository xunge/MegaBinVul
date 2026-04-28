#include <stdlib.h>

typedef struct VC2TransformContext {
    int padding;
    void *buffer;
} VC2TransformContext;

#define av_free free
#define av_cold