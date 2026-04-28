#include <stddef.h>

#define NULLFSINO ((xfs_ino_t)-1)
#define ASSERT(expr) ((void)0)

typedef unsigned long long xfs_ino_t;

typedef struct xfs_sb {
    xfs_ino_t sb_rbmino;
    xfs_ino_t sb_rsumino;
} xfs_sb_t;

typedef struct xfs_mount {
    xfs_sb_t m_sb;
    void *m_rbmip;
    void *m_rsumip;
} xfs_mount_t;

int xfs_iget(xfs_mount_t *mp, void *p, xfs_ino_t ino, int a, int b, void **ipp, ...);
void IRELE(void *ip);