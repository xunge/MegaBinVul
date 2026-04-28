#include <stddef.h>

#define CTL_MAIN_VOLUME 7
#define CTL_PAN 10

struct channel_info {
    int pgm_num;
    int bender_range;
    int controllers[16];
};

struct voice_info {
    int bender;
    int bender_range;
    int volume;
    int panning;
};

struct synth_info {
    struct channel_info *chn_info;
};

struct synth_dev {
    int nr_voice;
    struct voice_info *voc;
};

extern struct synth_dev *devc;
extern struct synth_info **synth_devs;

void opl3_set_instr(int dev, int voice, int pgm_num);