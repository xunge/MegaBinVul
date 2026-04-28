#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>

typedef struct xfs_sb {
    uint64_t sb_features2;
    uint64_t sb_bad_features2;
    uint32_t sb_agcount;
    uint32_t sb_logblocks;
    uint64_t sb_logstart;
    uint32_t sb_blocklog;
    uint32_t sb_blocksize;
    uint32_t sb_qflags;
    uint8_t sb_uuid[16];
    uint8_t sb_inprogress;
    uint64_t sb_rootino;
} xfs_sb_t;

typedef struct xfs_inode {
    struct {
        unsigned int di_mode;
    } i_d;
    uint64_t i_ino;
} xfs_inode_t;

typedef struct xfs_mount {
    xfs_sb_t m_sb;
    unsigned int m_flags;
    unsigned int m_update_flags;
    uint64_t *m_fixedfsid;
    uint32_t m_dmevmask;
    uint32_t m_attr_magicpct;
    uint32_t m_maxagi;
    uint32_t m_inode_cluster_size;
    uint64_t m_maxioffset;
    void *m_rootip;
    void *m_perag_tree;
    void *m_perag_lock;
    void *m_logdev_targp;
    void *m_ddev_targp;
    char m_fsname[1];
    uint32_t m_qflags;
} xfs_mount_t;

#define CE_WARN 0
#define CE_NOTE 0
#define XFS_SB_FEATURES2 0
#define XFS_SB_BAD_FEATURES2 0
#define XFS_SB_VERSIONNUM 0
#define XFS_MOUNT_NOATTR2 0
#define XFS_MOUNT_ATTR2 0
#define XFS_MOUNT_RDONLY 0
#define XFS_IS_QUOTA_RUNNING(mp) 0
#define XFS_IS_QUOTA_ON(mp) 0
#define XFS_ALL_QUOTA_ACCT 0
#define XFS_ERRLEVEL_LOW 0
#define XFS_ERROR(err) (err)
#define EFSCORRUPTED 0
#define S_IFMT 0
#define S_IFDIR 0
#define XFS_ILOCK_EXCL 0
#define XFS_DATA_FORK 0
#define XFS_ATTR_FORK 0
#define XFS_INODE_BIG_CLUSTER_SIZE 0
#define XFS_LAST_UNMOUNT_WAS_CLEAN(mp) 0
#define GFP_ATOMIC 0
#define unlikely(x) (x)

#define INIT_RADIX_TREE(tree, gfp_mask) 
#define spin_lock_init(lock) 
#define cmn_err(level, fmt, ...) 
#define ASSERT(expr) 
#define IRELE(ip) 
#define XFS_BUFTARG_NAME(targp) ""
#define XFS_FSB_TO_DADDR(mp, fsbno) ((fsbno) << (mp)->m_sb.sb_blocklog)
#define XFS_FSB_TO_BB(mp, fsbno) ((fsbno) << ((mp)->m_sb.sb_blocklog - 9))

static inline int xfs_mount_common(xfs_mount_t *mp, xfs_sb_t *sbp) { return 0; }
static inline int xfs_sb_has_mismatched_features2(xfs_sb_t *sbp) { return 0; }
static inline int xfs_sb_version_hasattr2(xfs_sb_t *sbp) { return 0; }
static inline int xfs_sb_version_haslazysbcount(xfs_sb_t *sbp) { return 0; }
static inline void xfs_sb_version_removeattr2(xfs_sb_t *sbp) {}
static inline int xfs_update_alignment(xfs_mount_t *mp) { return 0; }
static inline void xfs_alloc_compute_maxlevels(xfs_mount_t *mp) {}
static inline void xfs_bmap_compute_maxlevels(xfs_mount_t *mp, int fork) {}
static inline void xfs_ialloc_compute_maxlevels(xfs_mount_t *mp) {}
static inline void xfs_set_maxicount(xfs_mount_t *mp) {}
static inline uint64_t xfs_max_file_offset(uint32_t blocklog) { return 0; }
static inline int xfs_uuid_mount(xfs_mount_t *mp) { return 0; }
static inline void xfs_set_rw_sizes(xfs_mount_t *mp) {}
static inline void xfs_set_inoalignment(xfs_mount_t *mp) {}
static inline int xfs_check_sizes(xfs_mount_t *mp) { return 0; }
static inline int xfs_rtmount_init(xfs_mount_t *mp) { return 0; }
static inline void uuid_getnodeuniq(uint8_t (*uuid)[16], uint64_t *fsid) {}
static inline void xfs_dir_mount(xfs_mount_t *mp) {}
static inline void xfs_trans_init(xfs_mount_t *mp) {}
static inline int xfs_initialize_perag(xfs_mount_t *mp, uint32_t agcount, uint32_t *maxagi) { return 0; }
static inline void XFS_ERROR_REPORT(const char *msg, int level, xfs_mount_t *mp) {}
static inline int xfs_log_mount(xfs_mount_t *mp, void *targp, uint64_t daddr, uint64_t bblocks) { return 0; }
static inline int xfs_initialize_perag_data(xfs_mount_t *mp, uint32_t agcount) { return 0; }
static inline int xfs_iget(xfs_mount_t *mp, void *tp, uint64_t ino, int flags, int lock_flags, xfs_inode_t **ipp, ...) { return 0; }
static inline void xfs_iunlock(xfs_inode_t *ip, int lock_flags) {}
static inline int xfs_rtmount_inodes(xfs_mount_t *mp) { return 0; }
static inline int xfs_mount_log_sb(xfs_mount_t *mp, unsigned int flags) { return 0; }
static inline int xfs_qm_newmount(xfs_mount_t *mp, uint *amount, uint *flags) { return 0; }
static inline int xfs_mount_reset_sbqflags(xfs_mount_t *mp) { return 0; }
static inline int xfs_log_mount_finish(xfs_mount_t *mp) { return 0; }
static inline void xfs_qm_mount_quotas(xfs_mount_t *mp) {}
static inline uint64_t xfs_default_resblks(xfs_mount_t *mp) { return 0; }
static inline int xfs_reserve_blocks(xfs_mount_t *mp, uint64_t *resblks, void *null) { return 0; }
static inline void xfs_rtunmount_inodes(xfs_mount_t *mp) {}
static inline void xfs_log_unmount(xfs_mount_t *mp) {}
static inline void xfs_free_perag(xfs_mount_t *mp) {}
static inline void xfs_uuid_unmount(xfs_mount_t *mp) {}