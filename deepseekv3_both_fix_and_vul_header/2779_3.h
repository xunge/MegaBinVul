#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdatomic.h>

typedef uint64_t xfs_daddr_t;
typedef uint64_t xfs_off_t;
typedef unsigned int xfs_buf_flags_t;

struct rb_node {
    struct rb_node *rb_left;
    struct rb_node *rb_right;
};

struct rb_root {
    struct rb_node *rb_node;
};

struct spinlock {
    int lock;
};
#define spin_lock(lock) ((void)0)
#define spin_unlock(lock) ((void)0)

struct xfs_buftarg {
    int bt_sshift;
    xfs_off_t bt_smask;
    struct xfs_mount *bt_mount;
};

struct xfs_buf_map {
    xfs_daddr_t bm_bn;
    int bm_len;
};

struct xfs_perag {
    struct spinlock pag_buf_lock;
    struct rb_root pag_buf_tree;
};

struct xfs_buf {
    struct rb_node b_rbnode;
    xfs_daddr_t b_bn;
    int b_length;
    xfs_buf_flags_t b_flags;
    atomic_int b_hold;
    struct xfs_perag *b_pag;
    void *b_ops;
    void *b_iodone;
};
typedef struct xfs_buf xfs_buf_t;

struct xfs_mount {
    struct {
        uint64_t sb_dblocks;
        int sb_blocklog;
    } m_sb;
};

#define XBF_STALE       (1 << 0)
#define XBF_TRYLOCK     (1 << 1)
#define _XBF_DELWRI_Q   (1 << 2)
#define _XBF_KMEM       (1 << 3)
#define _XBF_PAGES      (1 << 4)

#define BBTOB(bb)       ((bb) << 9)
#define XFS_FSB_TO_BB(mp, fsb) ((fsb) << (mp)->m_sb.sb_blocklog)
#define XFS_STATS_INC(x) do {} while (0)

#define ASSERT(expr) do { if (!(expr)) abort(); } while (0)
#define _RET_IP_ ((void*)0)

static inline void atomic_inc(atomic_int *v) {
    (*v)++;
}

static inline xfs_daddr_t xfs_daddr_to_agno(struct xfs_mount *mp, xfs_daddr_t d) { return 0; }

static inline struct xfs_perag *xfs_perag_get(struct xfs_mount *mp, xfs_daddr_t agno) { return NULL; }
static inline void xfs_perag_put(struct xfs_perag *pag) {}

static inline void xfs_buf_rele(struct xfs_buf *bp) {}
static inline int xfs_buf_trylock(struct xfs_buf *bp) { return 0; }
static inline void xfs_buf_lock(struct xfs_buf *bp) {}

static inline void xfs_alert(struct xfs_mount *mp, const char *fmt, ...) {}
static inline void trace_xfs_buf_find(struct xfs_buf *bp, xfs_buf_flags_t flags, void *ip) {}

static inline void rb_link_node(struct rb_node *node, struct rb_node *parent, struct rb_node **rb_link) {}
static inline void rb_insert_color(struct rb_node *node, struct rb_root *root) {}
#define rb_entry(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))