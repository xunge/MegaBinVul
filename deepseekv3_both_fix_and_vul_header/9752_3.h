#include <stdint.h>

typedef uint64_t xfs_ino_t;
typedef uint64_t xfs_daddr_t;
typedef struct xfs_mount xfs_mount_t;

#define __user

int xfs_bulkstat_one_int(xfs_mount_t *mp, xfs_ino_t ino, void *buffer, int ubsize, int fmt, ...);
int xfs_bulkstat_one_fmt;