#include <stdlib.h>

typedef struct Plane {
    void *buffers[2];
} Plane;

typedef struct Indeo3DecodeContext {
    int width;
    int height;
    Plane planes[3];
} Indeo3DecodeContext;

#define av_freep(p) free(*(p)); *(p) = NULL
#define av_cold