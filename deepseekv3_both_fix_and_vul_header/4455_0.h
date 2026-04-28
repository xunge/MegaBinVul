#include <stdatomic.h>

struct ld_semaphore {
    atomic_long count;
};