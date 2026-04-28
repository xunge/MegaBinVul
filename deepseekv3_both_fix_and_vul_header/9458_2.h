#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;

struct inode {
    unsigned long i_ino;
    void *i_dentry;
    void *i_lock;
};

struct dentry {
    void *d_fsdata;
    void *d_alias;
};

static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}

#define hlist_for_each_entry(pos, head, member) for (pos = NULL; pos != NULL; pos = NULL)