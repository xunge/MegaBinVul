#include <assert.h>
#include <stddef.h>

typedef struct vorb {
    int blocksize_0;
    int blocksize_1;
    float *window[2];
} vorb;