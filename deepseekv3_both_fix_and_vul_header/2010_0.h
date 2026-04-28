#include <stdlib.h>

struct voice_struct {
    int panning;
};

struct synth_devc {
    int nr_voice;
    struct voice_struct *voc;
};

extern struct synth_devc *devc;