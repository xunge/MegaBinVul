#include <stddef.h>

struct super_block {
    void *s_fs_info;
};

struct shrink_control;
struct xfs_mount;

#define WARN_ON_ONCE(condition) (condition ? 0 : 0)

static inline struct xfs_mount *XFS_M(struct super_block *sb) { return NULL; }
static inline long xfs_reclaim_inodes_count(struct xfs_mount *mp) { return 0; }