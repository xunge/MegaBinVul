#include <stddef.h>
#include <stdint.h>
#include <pthread.h>

#define XENMEMF_get_address_bits(flags) ((flags) & 0xff)
#define XENMEMF_get_node(flags) (((flags) >> 8) & 0xff)
#define XENMEMF_vnode (1 << 16)
#define XENMEMF_exact_node_request (1 << 17)

#define PAGE_SHIFT 12
#define NUMA_NO_NODE (-1)
#define EINVAL 22

typedef int nodeid_t;

struct xen_memory_reservation {
    uint64_t extent_start;
    unsigned long nr_extents;
    unsigned int extent_order;
    unsigned int mem_flags;
};

struct memop_args {
    uint64_t extent_list;
    unsigned long nr_extents;
    unsigned int extent_order;
    unsigned int memflags;
    struct domain *domain;
};

struct vnuma_info {
    unsigned int nr_vnodes;
    nodeid_t *vnode_to_pnode;
};

struct domain {
    struct vnuma_info *vnuma;
    pthread_rwlock_t vnuma_rwlock;
};

static unsigned int get_order_from_pages(unsigned long pages) { return 0; }
static unsigned long max_page = 0;

#define MEMF_bits(bits) ((bits) << 0)
#define MEMF_node(node) ((node) << 8)
#define MEMF_exact_node (1 << 16)

static inline void read_lock(pthread_rwlock_t *lock) { pthread_rwlock_rdlock(lock); }
static inline void read_unlock(pthread_rwlock_t *lock) { pthread_rwlock_unlock(lock); }