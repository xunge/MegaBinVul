#include <limits.h>

#define MULTIPLIER 31
#define SNDRV_CTL_ELEM_ID_NAME_MAXLEN 44

struct snd_ctl_elem_id {
    unsigned int iface;
    unsigned int device;
    unsigned int subdevice;
    char name[SNDRV_CTL_ELEM_ID_NAME_MAXLEN];
    unsigned int index;
};