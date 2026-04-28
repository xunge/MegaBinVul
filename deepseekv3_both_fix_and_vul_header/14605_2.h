#include <stddef.h>

#define ENOTSUPP 524
#define EINVAL 22
#define EPERM 1
#define EACCES 13

#define VM_SHARED 0x00000008
#define VM_WRITE 0x00000002
#define VM_MAYEXEC 0x00000010
#define VM_MAYWRITE 0x00000020
#define BPF_F_RDONLY_PROG 0x00000001

struct vm_area_struct;

struct mutex {
    int dummy;
};

struct vm_operations_struct {
    int dummy;
};

struct bpf_map {
    void *private_data;
    struct {
        int (*map_mmap)(struct bpf_map *, struct vm_area_struct *);
    } *ops;
    unsigned int frozen;
    unsigned int map_flags;
    struct mutex freeze_mutex;
    unsigned int writecnt;
};

struct vm_area_struct {
    unsigned long vm_flags;
    struct vm_operations_struct *vm_ops;
    void *vm_private_data;
};

struct file {
    struct bpf_map *private_data;
};

extern const struct vm_operations_struct bpf_map_default_vmops;

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline int map_value_has_spin_lock(struct bpf_map *map) { return 0; }
static inline int map_value_has_timer(struct bpf_map *map) { return 0; }