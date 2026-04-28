#include <stddef.h>

struct evtchn {
    int lock;
};

typedef struct evtchn evtchn;

void spin_lock(int *lock);