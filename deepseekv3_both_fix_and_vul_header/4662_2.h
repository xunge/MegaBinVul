#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>

enum bpf_type {
    BPF_TYPE_PROG,
    BPF_TYPE_MAP
};

struct bpf_prog_aux {
    _Atomic int refcnt;
};

struct bpf_prog {
    struct bpf_prog_aux *aux;
};

#define WARN_ON_ONCE(cond) (void)(cond)

static inline void atomic_inc(_Atomic int *ptr) {
    (*ptr)++;
}

void *bpf_prog_inc(void *raw);
void *bpf_map_inc(void *raw, bool flag);