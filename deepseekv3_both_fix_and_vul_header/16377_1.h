#include <stddef.h>
#include <stdbool.h>

struct snd_rawmidi_runtime {
    char *buffer;
    size_t buffer_size;
    int buffer_ref;
    int lock;
    unsigned int avail_min;
};

struct snd_rawmidi_params {
    size_t buffer_size;
    unsigned int avail_min;
};

#define GFP_KERNEL 0
#define ENOMEM 12
#define EBUSY 16
#define EINVAL 22

void *kvzalloc(size_t size, int flags);
void kvfree(const void *addr);
void spin_lock_irq(int *lock);
void spin_unlock_irq(int *lock);
void __reset_runtime_ptrs(struct snd_rawmidi_runtime *runtime, bool is_input);