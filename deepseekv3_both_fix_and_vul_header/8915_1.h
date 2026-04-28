#include <stddef.h>

struct path {
    void *mnt;
    void *dentry;
};

struct dentry {
    struct dentry *d_parent;
    void *d_name;
};

struct vfsmount {
    void *mnt_root;
};

struct mount {
    struct mount *mnt_parent;
    void *mnt_mountpoint;
    struct vfsmount mnt;
};

typedef struct {
    int dummy;
} seqlock_t;

extern seqlock_t mount_lock;
extern seqlock_t rename_lock;

#define IS_ROOT(x) (0)
#define ACCESS_ONCE(x) (x)
#define prefetch(x) do { } while (0)
#define ENAMETOOLONG 1

static void rcu_read_lock(void) {}
static void rcu_read_unlock(void) {}
static unsigned read_seqbegin_or_lock(seqlock_t *lock, unsigned *seq) { return 0; }
static int need_seqretry(seqlock_t *lock, unsigned seq) { return 0; }
static void done_seqretry(seqlock_t *lock, unsigned seq) {}
static int is_mounted(struct vfsmount *mnt) { return 0; }
static int prepend_name(char **buffer, int *buflen, void *name) { return 0; }
static struct mount *real_mount(struct vfsmount *mnt) { return NULL; }