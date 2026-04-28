#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define CHECK_ATTR(x) (0)
#define BPF_MAP_LOOKUP_BATCH 0
#define BPF_MAP_LOOKUP_AND_DELETE_BATCH 1
#define BPF_MAP_UPDATE_BATCH 2
#define BPF_MAP_DELETE_BATCH 3
#define BPF_MAP_BATCH 0
#define EINVAL 22
#define EPERM 1
#define FMODE_CAN_READ O_RDONLY
#define FMODE_CAN_WRITE O_WRONLY
#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)
#define BPF_DO_BATCH(x) (0)

union bpf_attr {
    struct {
        int map_fd;
    } batch;
};

struct bpf_map {
    struct {
        int (*map_lookup_batch)(void);
        int (*map_lookup_and_delete_batch)(void);
        int (*map_update_batch)(void);
        int (*map_delete_batch)(void);
    } *ops;
};

struct fd {
    int fd;
};

static inline struct bpf_map *__bpf_map_get(struct fd f) { return NULL; }
static inline void bpf_map_write_active_inc(struct bpf_map *map) {}
static inline void bpf_map_write_active_dec(struct bpf_map *map) {}
static inline int map_get_sys_perms(struct bpf_map *map, struct fd f) { return 0; }
static inline struct fd fdget(int fd) { return (struct fd){fd}; }
static inline void fdput(struct fd f) {}

#define __user