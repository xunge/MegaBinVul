#include <stdint.h>
#include <errno.h>
#include <stddef.h>

struct xfs_mount;
struct xfs_perag;
struct xfs_trans;
typedef struct xfs_trans xfs_trans_t;
struct xfs_inode;

struct xfs_dinode {
    unsigned short di_mode;
};

typedef uint64_t xfs_ino_t;
typedef uint32_t xfs_agino_t;
typedef uint64_t xfs_daddr_t;

#define XFS_INO_TO_AGINO(mp, i) ((i) & (1ULL << 32) - 1)
#define XFS_INODE_CLUSTER_SIZE(mp) (1)

#define XFS_IGET_CREATE (1 << 0)
#define XFS_INEW (1 << 1)

struct xfs_mount {
    struct {
        int sb_inodelog;
    } m_sb;
};

struct xfs_perag {
    void *pag_ici_lock;
    void *pag_ici_root;
};

struct xfs_inode {
    struct xfs_dinode i_d;
    void *i_udquot;
    void *i_gdquot;
    unsigned long i_flags;
};

#define xfs_iflags_set(ip, flag) ((ip)->i_flags |= (flag))
#define xfs_ilock_nowait(ip, flags) (1)
#define xfs_iunlock(ip, flags) do {} while (0)
#define xfs_itrace_entry(ip) do {} while (0)
#define XFS_STATS_INC(stat) do {} while (0)
#define trace_xfs_iget_alloc(ip) do {} while (0)
#define WARN_ON(cond) do {} while (0)
#define BUG() do {} while (0)
#define unlikely(cond) (cond)

static inline struct xfs_inode *xfs_inode_alloc(struct xfs_mount *mp, xfs_ino_t ino) { return NULL; }
static inline void xfs_inode_free(struct xfs_inode *ip) {}
static inline int xfs_iread(struct xfs_mount *mp, struct xfs_trans *tp, struct xfs_inode *ip, int flags, ...) { return 0; }
static inline void __destroy_inode(void *vfs_inode) {}
#define VFS_I(ip) ((void *)ip)
#define write_lock(lock) do {} while (0)
#define write_unlock(lock) do {} while (0)
#define radix_tree_preload(flags) (0)
#define radix_tree_preload_end() do {} while (0)
#define radix_tree_insert(root, index, item) (0)
#define GFP_KERNEL 0