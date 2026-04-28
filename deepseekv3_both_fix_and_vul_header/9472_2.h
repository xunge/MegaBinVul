#include <stddef.h>

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct dentry {
    struct list_head d_subdirs;
    struct list_head d_child;
    struct {
        struct list_head d_child;
    } d_u;
    struct dentry *d_parent;
    void *d_sb;
    struct {
        int dep_map;
    } d_lock;
};

struct autofs_sb_info {
    int lookup_lock;
};

#define DENTRY_D_LOCK_NESTED 1
#define _RET_IP_ (unsigned long)0

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline int spin_trylock(int *lock) { return 1; }
static inline void spin_lock_nested(int *lock, int subclass) {}
static inline void cpu_relax(void) {}
static inline void lock_set_subclass(int *dep_map, int subclass, unsigned long ip) {}
static inline struct dentry *dget(struct dentry *dentry) { return dentry; }
static inline void dput(struct dentry *dentry) {}
static inline void dget_dlock(struct dentry *dentry) {}
static inline int simple_positive(struct dentry *dentry) { return 1; }
static inline struct autofs_sb_info *autofs4_sbi(void *sb) { return NULL; }