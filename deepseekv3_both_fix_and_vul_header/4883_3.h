#include <stddef.h>
#include <stdint.h>

struct list_head {
    struct list_head *next, *prev;
};

struct super_block {
    struct list_head s_mounts;
    int s_active;
};

struct dentry {
    // minimal definition
};

struct mount {
    struct list_head mnt_instance;
    struct list_head mnt_slave_list;
    struct list_head mnt_slave;
    struct list_head mnt_share;
    struct list_head mnt_expire;
    struct mount *mnt_master;
    struct dentry *mnt_mountpoint;
    struct dentry *mnt_root;
    struct super_block *mnt_sb;
    int mnt_group_id;
    struct {
        unsigned int mnt_flags;
        char *mnt_devname;
        struct super_block *mnt_sb;
        struct dentry *mnt_root;
    } mnt;
    struct mount *mnt_parent;
    char *mnt_devname;
};

#define CL_SLAVE 0x01
#define CL_PRIVATE 0x02
#define CL_SHARED_TO_SLAVE 0x04
#define CL_MAKE_SHARED 0x08
#define CL_UNPRIVILEGED 0x10
#define CL_EXPIRE 0x20

#define MNT_WRITE_HOLD 0x01
#define MNT_MARKED 0x02
#define MNT_LOCK_ATIME 0x04
#define MNT_READONLY 0x08
#define MNT_LOCK_READONLY 0x10
#define MNT_NODEV 0x20
#define MNT_LOCK_NODEV 0x40
#define MNT_NOSUID 0x80
#define MNT_LOCK_NOSUID 0x100
#define MNT_NOEXEC 0x200
#define MNT_LOCK_NOEXEC 0x400
#define MNT_LOCKED 0x800

#define IS_MNT_SHARED(m) (0)
#define IS_MNT_SLAVE(m) (0)
#define CLEAR_MNT_SHARED(m) do { } while (0)
#define set_mnt_shared(m) do { } while (0)

#define ENOMEM 12

static inline void atomic_inc(int *v) { (*v)++; }
static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
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

static inline void lock_mount_hash(void) {}
static inline void unlock_mount_hash(void) {}
static inline struct mount *alloc_vfsmnt(char *name) { return NULL; }
static inline void free_vfsmnt(struct mount *mnt) {}
static inline int mnt_alloc_group_id(struct mount *mnt) { return 0; }
static inline void mnt_free_id(struct mount *mnt) {}
static inline struct dentry *dget(struct dentry *dentry) { return NULL; }

#define ERR_PTR(err) ((void *)(intptr_t)(err))