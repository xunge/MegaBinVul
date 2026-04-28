#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>

typedef unsigned int uint;
typedef uint16_t __be16;

struct xfs_buf;

struct xfs_buf_ops {
    void (*verify_read)(struct xfs_buf *);
};

struct xfs_buf {
    struct xfs_mount *b_mount;
    unsigned int b_length;
    unsigned int b_flags;
    int b_error;
    struct xfs_buf_ops *b_ops;
};

struct xlog {
    struct xfs_mount *l_mp;
};

struct xfs_mount {
    void *m_ddev_targp;
    struct M_IGEO *m_geo;
};

struct xfs_buf_log_format {
    uint blf_flags;
    uint64_t blf_blkno;
    uint blf_len;
};

struct xlog_recover_item {
    struct {
        void *i_addr;
    } ri_buf[1];
};

struct list_head;

typedef uint64_t xfs_lsn_t;

#define XFS_BLF_CANCEL        (1 << 0)
#define XFS_BLF_INODE_BUF     (1 << 1)
#define XFS_BLF_UDQUOT_BUF    (1 << 2)
#define XFS_BLF_PDQUOT_BUF    (1 << 3)
#define XFS_BLF_GDQUOT_BUF    (1 << 4)

#define XBF_UNMAPPED          (1 << 0)
#define _XBF_LOGRECOVERY      (1 << 1)

#define XFS_DINODE_MAGIC      0x494e
#define BBTOB(x)             ((x) << 9)
#define NULLCOMMITLSN        ((xfs_lsn_t)-1)

#define XFS_LSN_CMP(a, b)    ((int64_t)((a) - (b)))

struct M_IGEO {
    unsigned int inode_cluster_size;
};

#define STATIC static
#define ASSERT(x) assert(x)

static inline uint16_t be16_to_cpu(uint16_t x) { return x; }
static inline void *xfs_buf_offset(struct xfs_buf *bp, int offset) { return NULL; }
static inline struct M_IGEO *M_IGEO(struct xfs_mount *mp) { return mp->m_geo; }