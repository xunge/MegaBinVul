#include <stdint.h>
#include <errno.h>
#include <stddef.h>

typedef uint32_t ioservid_t;

#define XEN_DMOP_IO_RANGE_PORT   0
#define XEN_DMOP_IO_RANGE_MEMORY 1
#define XEN_DMOP_IO_RANGE_PCI    2

struct list_head {
    struct list_head *next, *prev;
};

typedef struct {
    int lock;
} spinlock_t;

struct rangeset;

struct hvm_ioreq_server {
    ioservid_t id;
    struct rangeset *range[3];
    struct list_head list_entry;
};

struct ioreq_server {
    struct list_head list;
    spinlock_t lock;
    struct hvm_ioreq_server *default_ioreq_server;
};

struct hvm_domain {
    struct ioreq_server ioreq_server;
    struct hvm_ioreq_server *default_ioreq_server;
};

struct domain {
    struct {
        struct hvm_domain hvm_domain;
    } arch;
};

#define spin_lock_recursive(lock) ((void)0)
#define spin_unlock_recursive(lock) ((void)0)

#define list_for_each_entry(pos, head, member) \
    for (pos = (struct hvm_ioreq_server*)((head)->next); \
         &pos->member != (head); \
         pos = (struct hvm_ioreq_server*)(pos->member.next))

int rangeset_overlaps_range(struct rangeset *r, uint64_t start, uint64_t end);
int rangeset_add_range(struct rangeset *r, uint64_t start, uint64_t end);