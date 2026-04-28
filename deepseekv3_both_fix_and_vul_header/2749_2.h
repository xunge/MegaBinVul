#include <stdint.h>
#include <sys/uio.h>

typedef uint64_t u64;
typedef uint32_t u32;

struct vhost_memory_region {
    u64 guest_phys_addr;
    u64 memory_size;
    u64 userspace_addr;
};

struct vhost_memory {
    unsigned int nregions;
    struct vhost_memory_region regions[];
};

struct vhost_dev {
    struct vhost_memory *memory;
};

static const struct vhost_memory_region *find_region(struct vhost_memory *mem, u64 addr, u32 len);

#define rcu_read_lock()
#define rcu_read_unlock()
#define rcu_dereference(p) (p)
#define unlikely(x) (x)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define __user

#define ENOBUFS 105
#define EFAULT 14