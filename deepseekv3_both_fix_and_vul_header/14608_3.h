#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <errno.h>

#define CHECK_ATTR(x) 0
#define BPF_F_LOCK (1 << 0)
#define FMODE_CAN_READ (1 << 0)
#define FMODE_CAN_WRITE (1 << 1)
#define GFP_USER 0
#define __GFP_NOWARN 0

#define BPF_MAP_TYPE_QUEUE 1
#define BPF_MAP_TYPE_STACK 2
#define BPF_MAP_TYPE_HASH 3
#define BPF_MAP_TYPE_PERCPU_HASH 4
#define BPF_MAP_TYPE_LRU_HASH 5
#define BPF_MAP_TYPE_LRU_PERCPU_HASH 6
#define BPF_MAP_LOOKUP_AND_DELETE_ELEM 0

#define ENOTSUPP ENOTSUP

typedef uint32_t u32;
typedef uint64_t u64;

struct fd {
    int dummy;
};

struct bpf_map {
    int map_type;
    u32 key_size;
    struct bpf_map_ops *ops;
};

struct bpf_map_ops {
    int (*map_pop_elem)(struct bpf_map *map, void *value);
    int (*map_lookup_and_delete_elem)(struct bpf_map *map, void *key, void *value, int flags);
};

union bpf_attr {
    u64 key;
    u64 value;
    int map_fd;
    int flags;
};

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)-1000L)
#define PTR_ERR(x) ((int)(uintptr_t)(x))
#define __user

static inline void *u64_to_user_ptr(u64 addr) {
    return (void *)(uintptr_t)addr;
}

static inline struct fd fdget(int fd) {
    struct fd f = {0};
    return f;
}

static inline void fdput(struct fd f) {}

static inline struct bpf_map *__bpf_map_get(struct fd f) {
    return NULL;
}

static inline int map_get_sys_perms(struct bpf_map *map, struct fd f) {
    return 0;
}

static inline bool map_value_has_spin_lock(struct bpf_map *map) {
    return false;
}

static inline u32 bpf_map_value_size(struct bpf_map *map) {
    return 0;
}

static inline void *__bpf_copy_key(void *ukey, u32 key_size) {
    return NULL;
}

static inline void *kvmalloc(size_t size, int flags) {
    return NULL;
}

static inline void kvfree(void *addr) {}

static inline bool bpf_map_is_dev_bound(struct bpf_map *map) {
    return false;
}

static inline void bpf_disable_instrumentation(void) {}
static inline void bpf_enable_instrumentation(void) {}

static inline int copy_to_user(void *to, const void *from, unsigned long n) {
    return 0;
}

static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}