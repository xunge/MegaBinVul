#include <stdlib.h>

#define STATIC static

struct super_block {
    void *s_fs_info;
};

struct xfs_stats {
    void *xs_stats;
};

struct xfs_mount {
    struct xfs_stats m_stats;
};

#define XFS_M(sb) ((struct xfs_mount *)((sb)->s_fs_info))
#define xfs_notice(mp, fmt, ...) 
#define xfs_filestream_unmount(mp) 
#define xfs_unmountfs(mp) 
#define xfs_freesb(mp) 
#define xfs_destroy_percpu_counters(mp) 
#define xfs_destroy_mount_workqueues(mp) 
#define xfs_close_devices(mp) 
#define xfs_free_fsname(mp) 
#define kfree(ptr) free(ptr)
#define free_percpu(ptr) free(ptr)