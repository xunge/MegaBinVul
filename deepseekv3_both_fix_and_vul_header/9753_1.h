#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <assert.h>

typedef unsigned long long xfs_ino_t;
typedef unsigned long long xfs_daddr_t;
#define __user

struct xfs_bstat {
    unsigned long long bs_nlink;
    unsigned int bs_projid;
    xfs_ino_t bs_ino;
    unsigned short bs_mode;
    unsigned int bs_uid;
    unsigned int bs_gid;
    unsigned long long bs_size;
    struct timespec bs_atime;
    struct timespec bs_mtime;
    struct timespec bs_ctime;
    unsigned long long bs_xflags;
    unsigned int bs_extsize;
    unsigned int bs_extents;
    unsigned int bs_gen;
    unsigned int bs_pad[7];
    unsigned int bs_dmevmask;
    unsigned short bs_dmstate;
    unsigned short bs_aextents;
    unsigned int bs_forkoff;
    unsigned int bs_rdev;
    unsigned int bs_blksize;
    unsigned long long bs_blocks;
};

struct xfs_icdinode {
    unsigned short di_mode;
    unsigned char di_format;
    unsigned char di_nlink;
    unsigned int di_uid;
    unsigned int di_gid;
    unsigned long long di_size;
    unsigned int di_projid;
    unsigned int di_extsize;
    unsigned int di_nextents;
    unsigned int di_gen;
    unsigned int di_dmevmask;
    unsigned short di_dmstate;
    unsigned short di_anextents;
    unsigned long long di_nblocks;
};

struct xfs_imap {
    unsigned long long im_blkno;
};

struct inode {
    struct timespec i_atime;
    struct timespec i_mtime;
    struct timespec i_ctime;
};

struct xfs_inode {
    struct xfs_icdinode i_d;
    struct xfs_imap i_imap;
    struct inode *i_vnode;
    unsigned long long i_delayed_blks;
    union {
        struct {
            unsigned int if_rdev;
        } if_u2;
    } i_df;
};

struct xfs_mount {
    struct {
        unsigned int sb_blocklog;
        unsigned int sb_blocksize;
    } m_sb;
};

typedef int (*bulkstat_one_fmt_pf)(void *, int, int *, struct xfs_bstat *);

#define XFS_ERROR(err) (err)
#define EINVAL 22
#define ENOMEM 12
#define KM_SLEEP 0
#define KM_MAYFAIL 0
#define XFS_IGET_UNTRUSTED 0
#define XFS_ILOCK_SHARED 0
#define BULKSTAT_RV_NOTHING 0
#define BULKSTAT_RV_DIDONE 1
#define XFS_DINODE_FMT_DEV 0
#define XFS_DINODE_FMT_LOCAL 1
#define XFS_DINODE_FMT_UUID 2
#define XFS_DINODE_FMT_EXTENTS 3
#define XFS_DINODE_FMT_BTREE 4
#define BLKDEV_IOSIZE 512
#define XFS_IFORK_BOFF(ip) 0
#define VFS_I(ip) ((ip)->i_vnode)
#define ASSERT(x) assert(x)

static inline int xfs_internal_inum(struct xfs_mount *mp, xfs_ino_t ino) { return 0; }
static inline int xfs_ip2xflags(struct xfs_inode *ip) { return 0; }
static inline void *kmem_alloc(size_t size, int flags) { return malloc(size); }
static inline void kmem_free(void *ptr) { free(ptr); }
static inline int xfs_iget(struct xfs_mount *mp, void *p, xfs_ino_t ino, int flags1, int flags2, struct xfs_inode **ipp, ...) { return 0; }
static inline void xfs_iput(struct xfs_inode *ip, int flags) {}