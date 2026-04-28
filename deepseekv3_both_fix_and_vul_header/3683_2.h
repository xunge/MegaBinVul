#include <stddef.h>
#include <string.h>

struct mutex {
    int dummy;
};

struct snd_kcontrol {
    void *private_data;
};

struct snd_ctl_elem_value {
    void *value;
};

struct user_element {
    void *elem_data;
    size_t elem_data_size;
    struct {
        struct mutex user_ctl_lock;
    } *card;
};

static inline void mutex_lock(struct mutex *lock) { (void)lock; }
static inline void mutex_unlock(struct mutex *lock) { (void)lock; }