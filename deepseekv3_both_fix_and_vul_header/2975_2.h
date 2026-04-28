#include <stdatomic.h>
#include <stddef.h>
#include <errno.h>

#define CL_SLAVE 0x01
#define CL_PRIVATE 0x02
#define CL_SHARED_TO_SLAVE 0x04
#define CL_MAKE_SHARED 0x08
#define CL_UNPRIVILEGED 0x10
#define CL_EXPIRE 0x20

#define MNT_WRITE_HOLD 0x01
#define MNT_READONLY 0x02
#define MNT_LOCK_READONLY 0x04

#define IS_MNT_SHARED(mnt) (0)
#define IS_MNT_SLAVE(mnt) (0)
#define CLEAR_MNT_SHARED(mnt) do { } while (0)
#define set_mnt_shared(mnt) do { } while (0)

struct dentry;
struct super_block;

struct list_head {
    struct list_head *next, *prev;
};

struct vfsmount {
    struct dentry *mnt_root;
    struct super_block *mnt_sb;
    int mnt_flags;
};

struct mount {
    struct vfsmount mnt;
    struct dentry *mnt_mountpoint;
    struct mount *mnt_parent;
    struct mount *mnt_master;
    int mnt_group_id;
    char *mnt_devname;
    struct list_head mnt_slave_list;
    struct list_head mnt_slave;
    struct list_head mnt_share;
    struct list_head mnt_instance;
    struct list_head mnt_expire;
};

struct super_block {
    atomic_int s_active;
    struct list_head s_mounts;
};

static inline void *ERR_PTR(long error) {
    return (void *)error;
}

static inline void atomic_inc(atomic_int *v) {
    (*v)++;
}

static inline void list_add(struct list_head *new, struct list_head *head) {
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
}

static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

static inline int list_empty(const struct list_head *head) {
    return head->next == head;
}

struct mount *alloc_vfsmnt(const char *name);
void free_vfsmnt(struct mount *mnt);
int mnt_alloc_group_id(struct mount *mnt);
void br_write_lock(void *lock);
void br_write_unlock(void *lock);
struct dentry *dget(struct dentry *dentry);

void *vfsmount_lock;