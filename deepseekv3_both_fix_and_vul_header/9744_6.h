#include <stdint.h>
#include <stddef.h>
#include <endian.h>

#define STATIC static

typedef uint32_t xfs_agino_t;
typedef uint32_t xfs_agnumber_t;
typedef uint64_t xfs_ino_t;

#define NULLAGINO ((xfs_agino_t)-1)
#define XBF_LOCK 0
#define XFS_AGINO_TO_INO(mp, a, b) ((xfs_ino_t)((uint64_t)(a) << 32 | (b)))

struct xfs_mount;
struct xfs_buf;
struct xfs_dinode {
    uint32_t di_next_unlinked;
};
struct xfs_inode {
    struct {
        uint16_t di_nlink;
        uint16_t di_mode;
        uint32_t di_dmevmask;
    } i_d;
};

#define ASSERT(cond) ((void)0)
#define IRELE(ip) ((void)0)

static inline uint32_t be32_to_cpu(uint32_t x) {
    return be32toh(x);
}

int xfs_iget(struct xfs_mount *mp, void *null, xfs_ino_t ino, int a, int b, struct xfs_inode **ip, ...);
int xfs_itobp(struct xfs_mount *mp, void *null, struct xfs_inode *ip, struct xfs_dinode **dip, struct xfs_buf **ibp, int flags);
void xfs_buf_relse(struct xfs_buf *bp);
void xlog_recover_clear_agi_bucket(struct xfs_mount *mp, xfs_agnumber_t agno, int bucket);