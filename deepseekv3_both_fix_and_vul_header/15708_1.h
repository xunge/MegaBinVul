#include <stddef.h>
#include <stdlib.h>

#define DM_MAX_TARGETS 1024
#define KEYS_PER_NODE 64
#define DM_TYPE_NONE 0
#define GFP_KERNEL 0
#define EOVERFLOW 75
#define ENOMEM 12

typedef unsigned int blk_mode_t;

struct list_head {
    struct list_head *next, *prev;
};

struct rw_semaphore {
    int dummy;
};

struct mapped_device;

struct dm_table {
    struct list_head devices;
    struct rw_semaphore devices_lock;
    int type;
    blk_mode_t mode;
    struct mapped_device *md;
};

void INIT_LIST_HEAD(struct list_head *list);
void init_rwsem(struct rw_semaphore *sem);
void *kzalloc(size_t size, int flags);
void kfree(const void *objp);
int dm_round_up(unsigned int num, unsigned int size);
int alloc_targets(struct dm_table *t, unsigned int num_targets);