#include <stddef.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/mount.h>
#include <linux/capability.h>

struct vfsmount {
    struct super_block *mnt_sb;
};

struct list_head {
    struct list_head *next, *prev;
};

struct path {
    struct vfsmount *mnt;
};

struct semaphore {
    int count;
};

struct mount {
    struct vfsmount mnt;
    struct list_head mnt_list;
    int mnt_expiry_mark;
};

struct super_block {
    unsigned long s_flags;
    struct super_operations *s_op;
    struct rw_semaphore {
        struct semaphore sem;
    } s_umount;
    struct mount *mnt_sb;
};

struct super_operations {
    void (*umount_begin)(struct super_block *);
};

struct fs_struct {
    struct path root;
};

struct task_struct {
    struct fs_struct *fs;
};

#define MS_RDONLY 1
#define MNT_EXPIRE (1 << 0)
#define MNT_FORCE (1 << 1)
#define MNT_DETACH (1 << 2)
#define EINVAL 22
#define EBUSY 16
#define EAGAIN 11
#define EPERM 1

extern struct task_struct *current;
extern int event;
extern int capable(int cap);
extern int security_sb_umount(struct vfsmount *mnt, int flags);
extern void lock_mount_hash(void);
extern void unlock_mount_hash(void);
extern int mnt_get_count(struct mount *mnt);
extern void namespace_lock(void);
extern void namespace_unlock(void);
extern void umount_tree(struct mount *mnt, int how);
extern void shrink_submounts(struct mount *mnt);
extern int propagate_mount_busy(struct mount *mnt, int refcnt);
extern int do_remount_sb(struct super_block *sb, int flags, void *data, int force);
extern void down_write(struct rw_semaphore *sem);
extern void up_write(struct rw_semaphore *sem);
extern int xchg(int *ptr, int new);
extern int list_empty(struct list_head *head);