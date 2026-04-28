#include <stdlib.h>
#include <stddef.h>

#define GFP_KERNEL 0
#define EBUSY 16
#define EINVAL 22
#define ENOMEM 12

struct snd_rawmidi_substream;
struct snd_rawmidi_params;
struct snd_rawmidi_runtime {
    char *buffer;
    size_t buffer_size;
    size_t avail;
    size_t avail_min;
    size_t appl_ptr;
    size_t hw_ptr;
    int lock;
};

struct snd_rawmidi_substream {
    struct snd_rawmidi_runtime *runtime;
    int append;
    int use_count;
    int active_sensing;
};

struct snd_rawmidi_params {
    size_t buffer_size;
    size_t avail_min;
    int no_active_sensing;
};

void snd_rawmidi_drain_output(struct snd_rawmidi_substream *substream);
void spin_lock_irq(int *lock);
void spin_unlock_irq(int *lock);
void *kmalloc(size_t size, int flags);
void kfree(void *ptr);