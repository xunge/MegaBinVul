#include <string.h>

struct snd_seq_remove_events {
    int remove_mode;
};

#define SNDRV_SEQ_REMOVE_INPUT 1
#define SNDRV_SEQ_REMOVE_OUTPUT 2
#define USER_CLIENT 1
#define EFAULT 14

struct snd_seq_client {
    int type;
    int number;
    union {
        struct {
            void *fifo;
        } user;
    } data;
};

static inline int copy_from_user(void *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

void snd_seq_fifo_clear(void *fifo);
void snd_seq_queue_remove_cells(int number, struct snd_seq_remove_events *info);

#define __user