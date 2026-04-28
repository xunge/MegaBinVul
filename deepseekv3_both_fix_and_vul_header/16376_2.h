#include <string.h>
#include <errno.h>

struct snd_rawmidi_substream {
    struct snd_rawmidi_runtime *runtime;
};

struct snd_rawmidi_runtime {
    int lock;
    unsigned int buffer_size;
    unsigned int avail;
    unsigned int appl_ptr;
    unsigned char *buffer;
};

#define spin_lock_irqsave(lock, flags) ((void)0)
#define spin_unlock_irqrestore(lock, flags) ((void)0)
#define __user
#define copy_to_user(dest, src, count) (memcpy((dest), (src), (count)), 0)