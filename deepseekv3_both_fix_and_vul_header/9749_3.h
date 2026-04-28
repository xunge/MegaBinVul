#include <sys/types.h>

typedef struct xfs_mount xfs_mount_t;
typedef __uint64_t xfs_ino_t;
typedef __uint64_t xfs_daddr_t;

#define __user
#define BULKSTAT_RV_NOTHING 0
#define STATIC static

int xfs_bulkstat_one_int(xfs_mount_t *mp, xfs_ino_t ino, void *buffer,
                        int ubsize, int (*fmt)(void *, const void *),
                        ...);

int xfs_bulkstat_one_fmt_compat(void *ubuffer, const void *buffer);