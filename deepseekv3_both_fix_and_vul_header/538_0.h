#include <stdlib.h>

typedef struct {
    int channels;
    int previous_length;
    float **channel_buffers;
    float **previous_window;
    int samples_output;
} stb_vorbis;

static float *get_window(stb_vorbis *f, int n);