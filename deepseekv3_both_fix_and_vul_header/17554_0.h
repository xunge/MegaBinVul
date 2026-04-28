#include <stdatomic.h>

typedef struct {
    atomic_int cnts;
} rwlock_t;

#define _QR_BIAS (1 << 7)
#define preempt_enable()