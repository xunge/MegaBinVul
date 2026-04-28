#include <string.h>
#include <errno.h>

struct snd_rawmidi_substream;
struct snd_rawmidi_runtime {
    unsigned char *buffer;
    unsigned int buffer_size;
    unsigned int appl_ptr;
    unsigned int avail;
    int lock;
};
struct snd_rawmidi_substream {
    struct snd_rawmidi_runtime *runtime;
    int append;
    void (*trigger)(struct snd_rawmidi_substream *substream, int up);
};

#define spin_lock_irqsave(lock, flags) ((void)0)
#define spin_unlock_irqrestore(lock, flags) ((void)0)
#define snd_BUG_ON(cond) (0)
#define __user
#define EINVAL (-22)
#define EAGAIN (-11)
#define EFAULT (-14)