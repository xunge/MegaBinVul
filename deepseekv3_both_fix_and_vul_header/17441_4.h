#include <stdint.h>
#include <stddef.h>
#include <string.h>

#define EINVAL 22
#define ENOMEM 12
#define BPF_MAP_TYPE_UNSPEC 0
#define BPF_MAP_TYPE_HASH 1
#define BPF_MAP_TYPE_ARRAY 2
#define NSIM_BPF_MAX_KEYS 1000
#define GFP_USER 0
#define WARN_ON(condition) (condition)
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef uint32_t u32;

struct list_head {
    struct list_head *next, *prev;
};

struct nsim_dev {
    struct list_head bpf_bound_maps;
};

struct netdevsim {
    struct nsim_dev *nsim_dev;
};

struct bpf_map {
    unsigned int map_type;
    unsigned int max_entries;
    unsigned int map_flags;
    unsigned int value_size;
};

struct bpf_offloaded_map {
    struct bpf_map map;
    void *dev_priv;
    const void *dev_ops;
};

struct mutex {
    int dummy;
};

struct nsim_bpf_bound_map {
    struct netdevsim *ns;
    struct bpf_offloaded_map *map;
    struct mutex mutex;
    struct list_head l;
    struct {
        u32 *key;
        void *value;
    } entry[NSIM_BPF_MAX_KEYS];
};

struct bpf_map_dev_ops {
    int dummy;
};

extern const struct bpf_map_dev_ops nsim_bpf_map_ops;
extern int nsim_map_alloc_elem(struct bpf_offloaded_map *offmap, int i);

static inline void mutex_init(struct mutex *lock) { (void)lock; }
static inline void list_add_tail(struct list_head *new, struct list_head *head) { (void)new; (void)head; }
static inline void *kzalloc(size_t size, int flags) { (void)size; (void)flags; return NULL; }
static inline void kfree(const void *objp) { (void)objp; }