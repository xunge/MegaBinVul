#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <time.h>

typedef uint64_t xfs_ino_t;
typedef uint16_t xfs_nlink_t;
typedef uint32_t prid_t;
typedef unsigned int umode_t;

struct timespec64 {
    time_t tv_sec;
    long tv_nsec;
};

struct xfs_trans {
    struct xfs_mount *t_mountp;
};

struct xfs_inode {
    xfs_ino_t i_ino;
    struct {
        prid_t di_projid;
        uint64_t di_size;
        uint32_t di_nblocks;
        uint32_t di_extsize;
        uint32_t di_dmevmask;
        uint16_t di_dmstate;
        uint16_t di_flags;
        uint16_t di_flags2;
        uint32_t di_cowextsize;
        struct timespec64 di_crtime;
    } i_d;
    struct {
        uint8_t if_format;
        uint16_t if_flags;
        uint32_t if_nextents;
        uint32_t if_bytes;
        struct {
            void *if_root;
        } if_u1;
    } i_df;
};

struct xfs_mount {
    unsigned int m_flags;
    struct {
        uint16_t new_diflags2;
    } m_ino_geo;
    struct {
        int dummy;
    } m_sb;
};

struct inode {
    umode_t i_mode;
    xfs_nlink_t i_nlink;
    unsigned int i_uid;
    unsigned int i_gid;
    dev_t i_rdev;
    struct timespec64 i_mtime;
    struct timespec64 i_atime;
    struct timespec64 i_ctime;
};

#define XFS_IGET_CREATE 0
#define XFS_ILOCK_EXCL 0
#define XFS_ILOG_CORE 0
#define XFS_ILOG_DEV 0
#define XFS_DINODE_FMT_DEV 0
#define XFS_DINODE_FMT_EXTENTS 0
#define XFS_IFEXTENTS 0
#define XFS_DIFLAG_ANY 0
#define XFS_DIFLAG2_ANY 0
#define EFSCORRUPTED 0
#define XFS_MOUNT_GRPID 0

#define xfs_verify_dir_ino(mp, ino) (1)
#define xfs_alert(mp, fmt, ...) do {} while (0)
#define xfs_iget(mp, tp, ino, flags, lock_flags, ipp) (0)
#define xfs_inode_inherit_flags(ip, pip) do {} while (0)
#define xfs_inode_inherit_flags2(ip, pip) do {} while (0)
#define xfs_trans_ijoin(tp, ip, flags) do {} while (0)
#define xfs_trans_log_inode(tp, ip, flags) do {} while (0)
#define xfs_setup_inode(ip) do {} while (0)
#define xfs_sb_version_has_v3inode(sb) (0)
#define XFS_INHERIT_GID(pip) (0)
#define VFS_I(ip) ((struct inode *)0)
#define ASSERT(cond) do {} while (0)
#define set_nlink(inode, nlink) do {} while (0)
#define inode_init_owner(inode, dir, mode) do {} while (0)
#define in_group_p(gid) (0)
#define current_time(inode) ((struct timespec64){0})
#define inode_set_iversion(inode, version) do {} while (0)
#define current_fsuid() (0)
#define current_fsgid() (0)

extern int irix_sgid_inherit;