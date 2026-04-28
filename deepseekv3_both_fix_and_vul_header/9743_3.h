#include <stdint.h>
#include <sys/types.h>

typedef struct xfs_mount {
    int m_maxagi;
} xfs_mount_t;
typedef struct xfs_trans xfs_trans_t;
typedef struct xfs_inode xfs_inode_t;
typedef struct xfs_perag xfs_perag_t;

typedef uint64_t xfs_ino_t;
typedef uint32_t xfs_agino_t;
typedef uint64_t xfs_daddr_t;
typedef unsigned int uint;

#define XFS_INO_TO_AGNO(mp, i) ((i) >> 21)
#define XFS_INO_TO_AGINO(mp, i) ((i) & 0x1fffff)
#define EINVAL 22
#define EAGAIN 11
#define XFS_INEW 0x01
#define XFS_STATS_INC(x)
#define ASSERT(x)

struct xfs_ifork {
    int if_ext_max;
};
struct xfs_dinode {
    uint16_t di_mode;
};
struct xfs_inode {
    struct xfs_ifork i_df;
    struct xfs_dinode i_d;
};

struct xfs_perag {
    int pag_ici_lock;
    void *pag_ici_root;
};

int xfs_iget_cache_hit(xfs_perag_t *pag, xfs_inode_t *ip, uint flags, uint lock_flags);
int xfs_iget_cache_miss(xfs_mount_t *mp, xfs_perag_t *pag, xfs_trans_t *tp, xfs_ino_t ino, xfs_inode_t **ipp, uint flags, uint lock_flags, ...);
xfs_perag_t *xfs_perag_get(xfs_mount_t *mp, int agno);
void xfs_perag_put(xfs_perag_t *pag);
void xfs_setup_inode(xfs_inode_t *ip);
int xfs_iflags_test(xfs_inode_t *ip, int flag);
void read_lock(int *lock);
void read_unlock(int *lock);
void *radix_tree_lookup(void *root, xfs_agino_t agino);
void delay(int ticks);