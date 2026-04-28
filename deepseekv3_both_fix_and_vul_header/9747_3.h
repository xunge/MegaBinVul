#include <stdint.h>
#include <errno.h>

typedef unsigned int uint;

typedef struct xfs_mount xfs_mount_t;
typedef struct xfs_trans xfs_trans_t;
typedef struct xfs_inode xfs_inode_t;
typedef struct xfs_buf xfs_buf_t;
typedef struct xfs_dinode xfs_dinode_t;
typedef struct xfs_imap xfs_imap_t;
typedef uint64_t xfs_daddr_t;

struct xfs_imap {
    xfs_daddr_t im_blkno;
    uint64_t im_boffset;
};

struct xfs_dinode {
    uint16_t di_magic;
    uint8_t di_version;
    uint32_t di_gen;
    uint16_t di_flushiter;
    uint16_t di_mode;
    uint16_t di_onlink;
    uint32_t di_nlink;
    uint16_t di_projid;
    uint64_t di_size;
};

struct xfs_bmbt_rec {
    uint64_t l0, l1;
};
typedef struct xfs_bmbt_rec xfs_bmbt_rec_t;

struct xfs_inode {
    uint64_t i_ino;
    struct xfs_imap i_imap;
    struct xfs_dinode i_d;
    struct {
        uint if_ext_max;
    } i_df;
    uint64_t i_delayed_blks;
    uint64_t i_size;
};

#define XFS_DINODE_MAGIC 0x494e
#define XFS_ERROR(err) (err)
#define XFS_INO_REF 1
#define XBF_LOCK 0x01
#define CE_ALERT 1
#define DEBUG 1

#define ASSERT(expr) ((void)0)
#define be16_to_cpu(val) (val)
#define be32_to_cpu(val) (val)

static inline void XFS_BUF_SET_REF(xfs_buf_t *bp, int ref) {
    (void)bp;
    (void)ref;
}

int xfs_imap(xfs_mount_t *mp, xfs_trans_t *tp, uint64_t ino, xfs_imap_t *imap, uint flags);
int xfs_imap_to_bp(xfs_mount_t *mp, xfs_trans_t *tp, xfs_imap_t *imap, xfs_buf_t **bpp, int flags, uint iget_flags);
void *xfs_buf_offset(xfs_buf_t *bp, uint64_t offset);
void xfs_dinode_from_disk(struct xfs_dinode *to, struct xfs_dinode *from);
int xfs_iformat(xfs_inode_t *ip, xfs_dinode_t *dip);
void xfs_fs_cmn_err(int level, xfs_mount_t *mp, const char *fmt, ...);
void xfs_trans_brelse(xfs_trans_t *tp, xfs_buf_t *bp);

#define XFS_IFORK_DSIZE(ip) (sizeof(xfs_bmbt_rec_t))