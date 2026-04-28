#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <time.h>
#include <stdint.h>

#define __user
#define ASSERT(x) assert(x)

typedef uint64_t __u64;
typedef uint32_t __u32;
typedef uint16_t __u16;
typedef uint8_t __u8;

struct xfs_bstat {
    __u64 bs_ino;
    __u16 bs_mode;
    __u16 bs_nlink;
    __u32 bs_uid;
    __u32 bs_gid;
    __u64 bs_size;
    struct timespec bs_atime;
    struct timespec bs_mtime;
    struct timespec bs_ctime;
    __u32 bs_xflags;
    __u32 bs_extsize;
    __u32 bs_extents;
    __u32 bs_gen;
    __u16 bs_projid;
    __u8 bs_pad[14];
    __u32 bs_dmevmask;
    __u16 bs_dmstate;
    __u16 bs_aextents;
    __u32 bs_forkoff;
    __u32 bs_rdev;
    __u32 bs_blksize;
    __u64 bs_blocks;
};

struct xfs_sb {
    __u32 sb_blocklog;
    __u32 sb_blocksize;
};

struct xfs_mount {
    struct xfs_sb m_sb;
};

struct xfs_imap {
    __u64 im_blkno;
};

struct xfs_ifork_u2 {
    __u32 if_rdev;
};

struct xfs_ifork {
    struct xfs_ifork_u2 if_u2;
};

struct xfs_icdinode {
    __u16 di_nlink;
    __u16 di_projid;
    __u16 di_mode;
    __u32 di_uid;
    __u32 di_gid;
    __u64 di_size;
    __u32 di_extsize;
    __u32 di_nextents;
    __u32 di_gen;
    __u32 di_dmevmask;
    __u16 di_dmstate;
    __u16 di_anextents;
    __u8 di_format;
    __u64 di_nblocks;
};

struct xfs_inode {
    struct xfs_imap i_imap;
    struct xfs_icdinode i_d;
    struct xfs_ifork i_df;
    __u64 i_delayed_blks;
};

struct inode {
    struct timespec i_atime;
    struct timespec i_mtime;
    struct timespec i_ctime;
};

typedef int (*bulkstat_one_fmt_pf)(void *, int, int *, struct xfs_bstat *);

#define XFS_ERROR(err) (err)
#define EINVAL 22
#define ENOMEM 12

#define KM_SLEEP 0
#define KM_MAYFAIL 0

#define XFS_IGET_UNTRUSTED 0
#define XFS_IGET_BULKSTAT 0
#define XFS_ILOCK_SHARED 0

#define BULKSTAT_RV_NOTHING 0
#define BULKSTAT_RV_DIDONE 1

#define BLKDEV_IOSIZE 4096

#define XFS_IFORK_BOFF(ip) 0
#define XFS_DINODE_FMT_DEV 0
#define XFS_DINODE_FMT_LOCAL 1
#define XFS_DINODE_FMT_UUID 2
#define XFS_DINODE_FMT_EXTENTS 3
#define XFS_DINODE_FMT_BTREE 4

typedef __u64 xfs_ino_t;
typedef __u64 xfs_daddr_t;

static inline struct inode *VFS_I(struct xfs_inode *ip) { return (struct inode *)ip; }
static inline int xfs_internal_inum(struct xfs_mount *mp, xfs_ino_t ino) { return 0; }
static inline void *kmem_alloc(size_t size, int flags) { return malloc(size); }
static inline void kmem_free(void *ptr) { free(ptr); }
static inline int xfs_iget(struct xfs_mount *mp, void *tp, xfs_ino_t ino, int flags, int lock_flags, struct xfs_inode **ipp, xfs_daddr_t bno) { return 0; }
static inline void xfs_iput(struct xfs_inode *ip, int lock_flags) {}
static inline __u32 xfs_ip2xflags(struct xfs_inode *ip) { return 0; }