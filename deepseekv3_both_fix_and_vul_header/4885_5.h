#include <errno.h>

struct path {
    // dummy definition
};

struct file_system_type {
    int fs_flags;
    // other members
};

struct user_namespace {
    // dummy definition
};

struct vfsmount {
    struct super_block *mnt_sb;
    // other members
};

struct super_block {
    char *s_subtype;
    // other members
};

struct nsproxy {
    struct mnt_namespace *mnt_ns;
    // other members
};

struct mnt_namespace {
    struct user_namespace *user_ns;
    // other members
};

struct mount {
    // dummy definition
};

struct task_struct {
    struct nsproxy *nsproxy;
    // other members
};

#define EINVAL 22
#define ENODEV 19
#define EPERM 1

#define FS_USERNS_MOUNT 0x0001
#define FS_USERNS_DEV_MOUNT 0x0002
#define FS_HAS_SUBTYPE 0x0004

#define MS_NODEV 0x0004
#define MNT_NODEV 0x0008
#define MNT_LOCK_NODEV 0x0010

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

extern struct task_struct *current;
extern struct user_namespace init_user_ns;
extern struct file_system_type *get_fs_type(const char *);
extern void put_filesystem(struct file_system_type *);
extern struct vfsmount *vfs_kern_mount(struct file_system_type *, int, const char *, void *);
extern struct vfsmount *fs_set_subtype(struct vfsmount *, const char *);
extern int do_add_mount(struct mount *, struct path *, int);
extern void mntput(struct vfsmount *);
extern struct mount *real_mount(struct vfsmount *);