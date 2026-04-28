#include <stddef.h>

struct kobject {
    // Minimal kobject definition
    int dummy;
};

struct mapped_device {
    struct {
        struct kobject kobj;
    } kobj_holder;
    unsigned long flags;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

extern int _minor_lock;
#define spin_lock(lock) (void)0
#define spin_unlock(lock) (void)0
#define DMF_FREEING 0
#define test_bit(nr, addr) ((*(addr) & (1UL << (nr))) != 0)

int dm_deleting_md(struct mapped_device *md);
void dm_get(struct mapped_device *md);