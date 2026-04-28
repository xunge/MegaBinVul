#include <stdbool.h>

#define EINVAL 22
#define EPERM 1

#define MS_BIND 4096
#define MNT_USER_SETTABLE_MASK 0
#define MNT_PROPAGATION_MASK 0
#define CAP_SYS_ADMIN 21

struct path {
    struct vfsmount *mnt;
    struct dentry *dentry;
};

struct vfsmount {
    struct mount *mnt;
    struct super_block *mnt_sb;
    struct dentry *mnt_root;
    unsigned int mnt_flags;
};

struct mount {
    struct vfsmount mnt;
    struct mnt_namespace *mnt_ns;
};

struct super_block {
    struct {
        int dummy;
    } s_umount;
};

struct mnt_namespace {};

static inline struct mount *real_mount(struct vfsmount *mnt)
{
    return (struct mount *)mnt;
}

static inline bool check_mnt(struct mount *mnt)
{
    return true;
}

static inline int security_sb_remount(struct super_block *sb, void *data)
{
    return 0;
}

static inline int change_mount_flags(struct vfsmount *mnt, int flags)
{
    return 0;
}

static inline int do_remount_sb(struct super_block *sb, int flags, void *data, int force)
{
    return 0;
}

static inline void down_write(void *sem) {}
static inline void up_write(void *sem) {}
static inline void lock_mount_hash(void) {}
static inline void unlock_mount_hash(void) {}
static inline void touch_mnt_namespace(struct mnt_namespace *ns) {}
static inline bool capable(int cap) { return true; }