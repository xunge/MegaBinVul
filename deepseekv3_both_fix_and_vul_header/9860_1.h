#include <string.h>

#define MAX_MIXER_DEV 32
#define KERN_ERR ""

struct mixer_volume {
    char name[32];
    int num;
    int levels[32];
};

extern struct mixer_volume mixer_vols[MAX_MIXER_DEV];
extern int num_mixer_volumes;

int printk(const char *fmt, ...);