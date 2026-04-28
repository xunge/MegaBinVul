#include <sys/types.h>
#include <stdint.h>
#include <stddef.h>

typedef uint16_t umode_t;

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct mutex {
    int dummy;
};

struct inode {
    struct {
        struct hlist_node first;
    } i_dentry;
    struct mutex i_mutex;
};

struct dentry {
    char d_iname[256];
    union {
        struct hlist_node d_alias;
    } d_u;
    struct hlist_node d_alias;
};

#define hlist_entry(ptr, type, member) \
    ((type *)((char *)(&(ptr)) - offsetof(type, member)))

extern struct dentry *trace_instance_dir;
extern int new_instance_create(const char *name);

#define WARN_ON_ONCE(condition) (condition)
#define ENOENT 2

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}