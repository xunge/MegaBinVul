#include <stdatomic.h>
#include <stdbool.h>

struct bpf_map {
    _Atomic long refcnt;
    struct btf *btf;
    bool free_after_mult_rcu_gp;
    void *rcu;
};

struct btf;

void bpf_map_free_id(struct bpf_map *map);
void btf_put(struct btf *btf);
void call_rcu_tasks_trace(void *rcu, void (*func)(void *));
void bpf_map_free_mult_rcu_gp(void *map);
void bpf_map_free_in_work(struct bpf_map *map);

#define READ_ONCE(x) (x)
#define atomic64_dec_and_test(ptr) (atomic_fetch_sub(ptr, 1) == 1)