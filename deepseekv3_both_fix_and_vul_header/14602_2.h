#include <stddef.h>
#include <errno.h>

#define CHECK_ATTR(x) 0
#define FMODE_CAN_WRITE 0
#define IS_FD_PROG_ARRAY(x) 0
#define BPF_MAP_TYPE_STRUCT_OPS 0
#define BPF_MAP_DELETE_ELEM 0
#define EINVAL 22
#define EPERM 1

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))

typedef unsigned long u64;
typedef long ssize_t;

struct fd {
    int dummy;
};

struct bpf_map {
    size_t key_size;
    int map_type;
    struct bpf_map_ops *ops;
};

struct bpf_map_ops {
    int (*map_delete_elem)(struct bpf_map *map, void *key);
};

union bpf_attr {
    u64 key;
    int map_fd;
};

#define __user

static inline void *u64_to_user_ptr(u64 val) { return (void *)(unsigned long)val; }
static inline void kvfree(const void *addr) {}
static inline void bpf_disable_instrumentation(void) {}
static inline void bpf_enable_instrumentation(void) {}
static inline void maybe_wait_bpf_programs(struct bpf_map *map) {}

static inline struct fd fdget(int fd) { return (struct fd){0}; }
static inline void fdput(struct fd f) {}
static inline struct bpf_map *__bpf_map_get(struct fd f) { return NULL; }
static inline int map_get_sys_perms(struct bpf_map *map, struct fd f) { return 0; }
static inline void *__bpf_copy_key(void *ukey, size_t key_size) { return NULL; }
static inline int bpf_map_is_dev_bound(struct bpf_map *map) { return 0; }
static inline int bpf_map_offload_delete_elem(struct bpf_map *map, void *key) { return 0; }
static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}