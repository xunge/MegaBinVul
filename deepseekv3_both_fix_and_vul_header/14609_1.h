#include <stdbool.h>
#include <pthread.h>

#define EINVAL 22
#define ENOTSUPP 95
#define EBUSY 16
#define EPERM 1

union bpf_attr {
    int map_fd;
};

struct fd {
    int dummy;
};

struct bpf_map {
    int map_type;
    int writecnt;
    bool frozen;
    pthread_mutex_t freeze_mutex;
};

#define BPF_MAP_TYPE_STRUCT_OPS 0
#define BPF_MAP_FREEZE 0

#define CHECK_ATTR(x) 0
#define IS_ERR(x) 0
#define PTR_ERR(x) 0
#define READ_ONCE(x) (x)
#define WRITE_ONCE(x, val) (x = val)

static inline bool map_value_has_timer(struct bpf_map *map) { return false; }
static inline bool bpf_capable(void) { return false; }
static inline struct fd fdget(int fd) { struct fd f = {0}; return f; }
static inline void fdput(struct fd f) {}
static inline struct bpf_map *__bpf_map_get(struct fd f) { return NULL; }
static inline void mutex_lock(pthread_mutex_t *mutex) {}
static inline void mutex_unlock(pthread_mutex_t *mutex) {}