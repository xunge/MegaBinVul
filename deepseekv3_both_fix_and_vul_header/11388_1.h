#include <stdlib.h>
#include <stdint.h>

#define GFP_KERNEL 0
#define EINVAL 22
#define ENOMEM 12

struct snd_rawmidi_substream {
    struct snd_rawmidi_runtime *runtime;
};

struct snd_rawmidi_params {
    size_t buffer_size;
    size_t avail_min;
};

struct snd_rawmidi_runtime {
    char *buffer;
    size_t buffer_size;
    size_t appl_ptr;
    size_t hw_ptr;
    size_t avail_min;
    int lock;
};

void spin_lock_irq(int *lock);
void spin_unlock_irq(int *lock);
int snd_rawmidi_drain_input(struct snd_rawmidi_substream *substream);