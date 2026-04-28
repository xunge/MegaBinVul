#include <stdint.h>

#define MAPTRACK_TAIL 0

struct vcpu {
    uint32_t maptrack_head;
    uint32_t maptrack_tail;
    int maptrack_freelist_lock;
};

static inline void spin_lock_init(int *lock)
{
    *lock = 0;
}