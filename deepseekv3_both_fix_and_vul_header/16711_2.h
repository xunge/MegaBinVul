#include <stdint.h>
#include <stddef.h>
#include <stdatomic.h>
#include <pthread.h>

#define NUMA_NO_NODE (-1)
#define BPF_MAP_TYPE_STRUCT_OPS 0
#define BPF_MAP_CREATE 0
#define EINVAL 22
#define EACCES 13
#define BPF_OBJ_NAME_LEN 16
#define nr_node_ids 1

struct bpf_map {
    const struct bpf_map_ops *ops;
    struct btf *btf;
    uint32_t btf_key_type_id;
    uint32_t btf_value_type_id;
    uint32_t btf_vmlinux_value_type_id;
    char name[BPF_OBJ_NAME_LEN];
    _Atomic uint64_t refcnt;
    _Atomic uint64_t usercnt;
    pthread_mutex_t freeze_mutex;
    int spin_lock_off;
};

struct bpf_map_ops {
    void (*map_free)(struct bpf_map *map);
};

union bpf_attr {
    uint32_t map_type;
    uint32_t btf_key_type_id;
    uint32_t btf_value_type_id;
    uint32_t btf_vmlinux_value_type_id;
    uint32_t btf_fd;
    uint32_t map_flags;
    char map_name[BPF_OBJ_NAME_LEN];
};

struct btf {
    unsigned int id;
};

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)-4096)
#define PTR_ERR(x) ((int)(intptr_t)(x))

static inline int node_online(int node) { return 1; }
static inline void atomic64_set(_Atomic uint64_t *v, uint64_t i) { *v = i; }
static inline void mutex_init(pthread_mutex_t *mutex) { pthread_mutex_init(mutex, NULL); }
static inline struct btf *btf_get_by_fd(uint32_t fd) { return NULL; }

static inline int bpf_map_attr_numa_node(union bpf_attr *attr) { return 0; }
static inline int CHECK_ATTR(int type) { return 0; }
static inline int bpf_get_file_flag(uint32_t flags) { return 0; }
static inline struct bpf_map *find_and_alloc_map(union bpf_attr *attr) { return NULL; }
static inline int bpf_obj_name_cpy(char *dst, const char *src, size_t size) { return 0; }
static inline int btf_is_kernel(struct btf *btf) { return 0; }
static inline void btf_put(struct btf *btf) {}
static inline int map_check_btf(struct bpf_map *map, struct btf *btf, uint32_t key_id, uint32_t value_id) { return 0; }
static inline int security_bpf_map_alloc(struct bpf_map *map) { return 0; }
static inline void security_bpf_map_free(struct bpf_map *map) {}
static inline int bpf_map_alloc_id(struct bpf_map *map) { return 0; }
static inline void bpf_map_save_memcg(struct bpf_map *map) {}
static inline int bpf_map_new_fd(struct bpf_map *map, int flags) { return 0; }
static inline void bpf_map_put_with_uref(struct bpf_map *map) {}