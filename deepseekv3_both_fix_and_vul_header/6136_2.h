#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef unsigned long ulong;

#define __user
#define __percpu
#define GFP_USER 0
#define __GFP_NOWARN 0
#define BPF_F_LOCK 4
#define EINVAL 22
#define EFAULT 14
#define ENOENT 2
#define ENOMEM 12
#define ENOSPC 28

struct bpf_map {
    unsigned int key_size;
    unsigned int value_size;
};

struct bpf_lru_node {};
struct bpf_lru {
    struct bpf_lru_node node;
};

struct hlist_nulls_node {
    struct hlist_nulls_node *next, **pprev;
};

struct hlist_nulls_head {
    struct hlist_nulls_node *first;
};

struct htab_elem {
    union {
        struct hlist_nulls_node hash_node;
        struct {
            void *batch_flink;
            struct bpf_lru_node lru_node;
        };
    };
    void *key;
};

struct bucket {
    struct hlist_nulls_head head;
};

struct bpf_htab {
    struct bpf_map map;
    u32 n_buckets;
    struct bucket *buckets;
    struct bpf_lru lru;
};

union bpf_attr {
    struct {
        u64 values;
        u64 keys;
        u64 in_batch;
        u64 out_batch;
        u32 count;
        u32 elem_flags;
        u64 flags;
    } batch;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define u64_to_user_ptr(x) ((void __user *)(uintptr_t)(x))

#define round_up(x, y) ((((x) + (y) - 1) / (y)) * (y))

static inline int num_possible_cpus(void) { return 1; }

static inline void *kvmalloc(size_t size, int flags) { return malloc(size); }
static inline void kvfree(void *ptr) { free(ptr); }

static inline void bpf_disable_instrumentation(void) {}
static inline void bpf_enable_instrumentation(void) {}

static inline int htab_lock_bucket(struct bpf_htab *htab, struct bucket *b, u32 batch, unsigned long *flags) { return 0; }
static inline void htab_unlock_bucket(struct bpf_htab *htab, struct bucket *b, u32 batch, unsigned long flags) {}

static inline bool map_value_has_spin_lock(struct bpf_map *map) { return false; }
static inline void copy_map_value(struct bpf_map *map, void *dst, void *src) { memcpy(dst, src, map->value_size); }
static inline void copy_map_value_locked(struct bpf_map *map, void *dst, void *src, bool lock) { memcpy(dst, src, map->value_size); }
static inline void check_and_init_map_lock(struct bpf_map *map, void *dst) {}

static inline void free_htab_elem(struct bpf_htab *htab, struct htab_elem *l) { free(l); }
static inline void bpf_lru_push_free(struct bpf_lru *lru, struct bpf_lru_node *node) {}
static inline void *htab_elem_get_ptr(struct htab_elem *l, u32 key_size) { return l->key + key_size; }

#define hlist_nulls_for_each_entry_rcu(pos, n, head, member) \
    for ((n) = (head)->first; \
         (n) && ((pos) = container_of(n, typeof(*(pos)), member), 1); \
         (n) = (n)->next)

#define hlist_nulls_for_each_entry_safe(pos, n, head, member) \
    for ((n) = (head)->first; \
         (n) && ((pos) = container_of(n, typeof(*(pos)), member), 1); \
         (n) = (n)->next)

#define for_each_possible_cpu(cpu) for ((cpu) = 0; (cpu) < 1; (cpu)++)

static inline void bpf_long_memcpy(void *dst, void *src, size_t size) {
    memcpy(dst, src, size);
}

static inline int put_user(unsigned long x, void __user *ptr) {
    *(unsigned long *)ptr = x;
    return 0;
}

static inline int copy_from_user(void *dst, const void __user *src, size_t size) {
    memcpy(dst, src, size);
    return 0;
}

static inline int copy_to_user(void __user *dst, const void *src, size_t size) {
    memcpy(dst, src, size);
    return 0;
}