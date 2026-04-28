#include <stdint.h>
#include <stddef.h>

typedef struct xfs_inode xfs_inode_t;
typedef uint64_t xfs_ino_t;
typedef unsigned int uint;

struct xfs_name {
    char *name;
};

#define XFS_FORCED_SHUTDOWN(mp) (0)
#define XFS_ERROR(err) (err)
#define EIO 5

#define xfs_itrace_entry(ip) 
#define xfs_ilock_map_shared(ip) (0)
#define xfs_iunlock_map_shared(ip, mode) 
#define xfs_dir_lookup(tp, dp, name, inum, ci_name) (0)
#define xfs_iget(mp, tp, inum, flags, lock_flags, ipp, ...) (0)
#define kmem_free(ptr) 