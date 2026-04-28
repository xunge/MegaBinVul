#include <stddef.h>

struct evtchn {
    void *lock;
};

static inline void spin_unlock(void *lock) {}