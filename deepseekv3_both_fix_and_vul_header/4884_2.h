#include <stdbool.h>

#define MNT_LOCK_READONLY    0x01
#define MNT_LOCK_NODEV       0x02
#define MNT_LOCK_NOSUID      0x04
#define MNT_LOCK_NOEXEC      0x08
#define MNT_LOCK_ATIME       0x10
#define MNT_READONLY         0x20
#define MNT_NODEV            0x40
#define MNT_NOSUID           0x80
#define MNT_NOEXEC           0x100
#define MNT_ATIME_MASK       0x600
#define MNT_USER_SETTABLE_MASK 0x7E0
#define MS_BIND              0x1000
#define CAP_SYS_ADMIN        21
#define EINVAL               22
#define EPERM                1

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

static int security_sb_remount(struct super_block *sb, void *data)
{
    return 0;
}

static int change_mount_flags(struct vfsmount *mnt, int flags)
{
    return 0;
}

static int do_remount_sb(struct super_block *sb, int flags, void *data, int force)
{
    return 0;
}

static int capable(int cap)
{
    return 1;
}

static void down_write(void *sem) {}
static void up_write(void *sem) {}
static void lock_mount_hash(void) {}
static void unlock_mount_hash(void) {}
static void touch_mnt_namespace(struct mnt_namespace *ns) {}