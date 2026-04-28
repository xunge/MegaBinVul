#include <stdbool.h>
#include <stddef.h>

typedef unsigned int u32;
typedef struct { bool is_kernel; } bpfptr_t;
typedef unsigned int gfp_t;

struct bpf_map {
    u32 key_size;
    u32 value_size;
};

struct fd {
    int fd;
};

union bpf_attr {
    void *key;
    void *value;
    int map_fd;
    int flags;
};

#define CHECK_ATTR(x) 0
#define BPF_MAP_UPDATE_ELEM 0
#define BPF_F_LOCK 0
#define FMODE_CAN_WRITE 0
#define GFP_USER 0
#define __GFP_NOWARN 0
#define EINVAL 1
#define EPERM 1
#define ENOMEM 1
#define EFAULT 1

#define IS_ERR(x) 0
#define PTR_ERR(x) 0

static inline bpfptr_t make_bpfptr(void *ptr, bool is_kernel) { return (bpfptr_t){is_kernel}; }
static inline struct fd fdget(int fd) { struct fd f = {.fd = fd}; return f; }
static inline void fdput(struct fd f) {}
static inline struct bpf_map *__bpf_map_get(struct fd f) { return NULL; }
static inline int map_get_sys_perms(struct bpf_map *map, struct fd f) { return 0; }
static inline bool map_value_has_spin_lock(struct bpf_map *map) { return false; }
static inline void *___bpf_copy_key(bpfptr_t ukey, size_t size) { return NULL; }
static inline u32 bpf_map_value_size(struct bpf_map *map) { return map ? map->value_size : 0; }
static inline void *kvmalloc(size_t size, gfp_t flags) { return NULL; }
static inline int copy_from_bpfptr(void *dst, bpfptr_t src, size_t size) { return 0; }
static inline int bpf_map_update_value(struct bpf_map *map, struct fd f, void *key, void *value, int flags) { return 0; }
static inline void kvfree(void *ptr) {}