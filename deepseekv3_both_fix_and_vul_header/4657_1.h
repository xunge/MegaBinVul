#include <stdatomic.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>

#define BPF_MAX_REFCNT INT_MAX
#define ERR_PTR(err) ((void *)(long)(err))

struct bpf_map {
    _Atomic int refcnt;
    _Atomic int usercnt;
};

static inline int atomic_inc_return(_Atomic int *v) {
    return atomic_fetch_add(v, 1) + 1;
}

static inline void atomic_inc(_Atomic int *v) {
    atomic_fetch_add(v, 1);
}

static inline void atomic_dec(_Atomic int *v) {
    atomic_fetch_sub(v, 1);
}