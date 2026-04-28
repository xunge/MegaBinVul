#include <stdint.h>
#include <errno.h>
#include <stddef.h>
#include <string.h>

typedef struct xfs_mount {
    void *m_ddev_targp;
    char *m_fsname;
    struct {
        int sb_inodelog;
    } m_sb;
} xfs_mount_t;

typedef struct xfs_trans xfs_trans_t;
typedef struct xfs_buf xfs_buf_t;

typedef struct xfs_dinode {
    uint16_t di_magic;
    uint8_t di_version;
} xfs_dinode_t;

struct xfs_imap {
    uint64_t im_blkno;
    uint32_t im_len;
};

#define XFS_DINODE_MAGIC 0x494e
#define XFS_DINODE_GOOD_VERSION(v) ((v) >= 1 && (v) <= 3)
#define XFS_ERROR(err) (-(err))
#define XBF_TRYLOCK (1 << 0)
#define XFS_IGET_UNTRUSTED (1 << 0)
#define XFS_IGET_BULKSTAT (1 << 1)
#define XFS_ERRTAG_ITOBP_INOTOBP 0
#define XFS_RANDOM_ITOBP_INOTOBP 0
#define XFS_ERRLEVEL_HIGH 1
#define B_FS_INO 1
#define CE_WARN 0
#define CE_PANIC 1
#define EFSCORRUPTED EIO

#define STATIC static
typedef unsigned int uint;

#define ASSERT(cond) ((void)0)
#define XFS_TEST_ERROR(cond, mp, tag, rand) (cond)
#define XFS_CORRUPTION_ERROR(msg, level, mp, ptr) ((void)0)
#define XFS_BUFTARG_NAME(targp) ""
#define BBTOB(bb) ((bb) << 9)
#define be16_to_cpu(val) (val)
#define unlikely(x) (x)

static inline void cmn_err(int level, const char *fmt, ...) {}
static inline int xfs_trans_read_buf(xfs_mount_t *mp, xfs_trans_t *tp, void *targp, uint64_t blkno, int len, uint flags, xfs_buf_t **bpp) { return 0; }
static inline void xfs_trans_brelse(xfs_trans_t *tp, xfs_buf_t *bp) {}
static inline void xfs_inobp_check(xfs_mount_t *mp, xfs_buf_t *bp) {}
static inline void *xfs_buf_offset(xfs_buf_t *bp, int offset) { return NULL; }
#define XFS_BUF_SET_VTYPE(bp, type) ((void)0)