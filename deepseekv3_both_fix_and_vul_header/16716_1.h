#include <stdatomic.h>

struct xt_recseq {
    _Atomic unsigned int sequence;
};

extern struct xt_recseq xt_recseq;

#define __this_cpu_read(var) atomic_load(&(var))
#define __this_cpu_add(var, val) atomic_fetch_add(&(var), (val))
#define smp_wmb() atomic_thread_fence(memory_order_release)