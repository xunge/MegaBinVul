#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

struct xfs_mount;
struct xfs_perag {
    void *pag_ici_lock;
    void *pag_ici_root;
};
typedef struct xfs_trans xfs_trans_t;
struct xfs_inode {
    struct {
        uint64_t di_nblocks;
    } i_d;
    void *i_udquot;
    void *i_gdquot;
    void *i_pdquot;
};
struct inode {
    unsigned short i_mode;
};

typedef uint64_t xfs_ino_t;
typedef uint32_t xfs_agino_t;

#define XFS_INO_TO_AGINO(mp, i) ((xfs_agino_t)(i))
#define XFS_IGET_CREATE (1 << 0)
#define XFS_IGET_DONTCACHE (1 << 1)
#define XFS_INEW (1 << 2)
#define XFS_IDONTCACHE (1 << 3)
#define ENOMEM 12
#define EFSCORRUPTED 117
#define ENOENT 2
#define EAGAIN 11
#define EEXIST 17
#define GFP_NOFS 0

#define unlikely(x) (x)

static inline int radix_tree_preload(int gfp_mask) { return 0; }
static inline void radix_tree_preload_end(void) {}
static inline int radix_tree_insert(void *root, unsigned long index, void *item) { return 0; }

static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}

#define BUG() abort()
#define WARN_ON(cond) ((void)0)
#define trace_xfs_iget_miss(ip) ((void)0)
#define XFS_STATS_INC(mp, stat) ((void)0)
#define xfs_warn(mp, fmt, ...) ((void)0)

static inline struct inode *VFS_I(struct xfs_inode *ip) { return (struct inode *)ip; }
static inline void xfs_iflags_set(struct xfs_inode *ip, int flags) {}
static inline int xfs_ilock_nowait(struct xfs_inode *ip, int flags) { return 1; }
static inline void xfs_iunlock(struct xfs_inode *ip, int flags) {}
static inline void __destroy_inode(struct inode *inode) {}
static inline struct xfs_inode *xfs_inode_alloc(struct xfs_mount *mp, xfs_ino_t ino) { return malloc(sizeof(struct xfs_inode)); }
static inline void xfs_inode_free(struct xfs_inode *ip) { free(ip); }
static inline int xfs_iread(struct xfs_mount *mp, xfs_trans_t *tp, struct xfs_inode *ip, int flags) { return 0; }
static inline int xfs_inode_verify_forks(struct xfs_inode *ip) { return 1; }