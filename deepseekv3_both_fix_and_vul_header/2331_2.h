#include <stdint.h>
#include <stddef.h>

#define EINVAL 22
#define ENOENT 2

typedef unsigned int ioservid_t;

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = list_entry((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = list_entry(pos->member.next, typeof(*pos), member))

#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

struct rangeset {
    // dummy definition
};

struct hvm_ioreq_server {
    ioservid_t id;
    struct rangeset *range[3];
    struct list_head list_entry;
};

struct spinlock {
    int lock;
};

struct arch_hvm_domain {
    struct {
        struct list_head list;
        struct spinlock lock;
    } ioreq_server;
    struct hvm_ioreq_server *default_ioreq_server;
};

struct arch_domain {
    struct arch_hvm_domain hvm_domain;
};

struct domain {
    struct arch_domain arch;
};

static inline void spin_lock_recursive(struct spinlock *lock) { }
static inline void spin_unlock_recursive(struct spinlock *lock) { }

int rangeset_contains_range(struct rangeset *r, uint64_t start, uint64_t end) { return 0; }
int rangeset_remove_range(struct rangeset *r, uint64_t start, uint64_t end) { return 0; }

#define XEN_DMOP_IO_RANGE_PORT 0
#define XEN_DMOP_IO_RANGE_MEMORY 1
#define XEN_DMOP_IO_RANGE_PCI 2