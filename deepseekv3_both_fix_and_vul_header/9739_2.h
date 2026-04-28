#include <stdint.h>
#include <string.h>

#define NULLFSINO ((xfs_ino_t)-1)
#define B_FALSE 0
#define B_TRUE 1
#define FS_QSTAT_VERSION 1

typedef unsigned int xfs_ino_t;
typedef int boolean_t;

struct xfs_sb {
    xfs_ino_t sb_uquotino;
    xfs_ino_t sb_gquotino;
};

struct xfs_dinode {
    unsigned int di_nblocks;
    unsigned int di_nextents;
};

struct xfs_inode {
    struct xfs_dinode i_d;
};

struct xfs_quotainfo {
    struct xfs_inode *qi_uquotaip;
    struct xfs_inode *qi_gquotaip;
    unsigned int qi_dquots;
    unsigned int qi_btimelimit;
    unsigned int qi_itimelimit;
    unsigned int qi_rtbtimelimit;
    unsigned int qi_bwarnlimit;
    unsigned int qi_iwarnlimit;
};

struct xfs_mount {
    struct xfs_sb m_sb;
    struct xfs_quotainfo *m_quotainfo;
    unsigned int m_qflags;
};

struct fs_quota_stat {
    unsigned int qs_version;
    unsigned short qs_flags;
    short qs_pad;
    struct {
        xfs_ino_t qfs_ino;
        unsigned int qfs_nblks;
        unsigned int qfs_nextents;
    } qs_uquota, qs_gquota;
    unsigned int qs_incoredqs;
    unsigned int qs_btimelimit;
    unsigned int qs_itimelimit;
    unsigned int qs_rtbtimelimit;
    unsigned int qs_bwarnlimit;
    unsigned int qs_iwarnlimit;
};

typedef struct fs_quota_stat fs_quota_stat_t;

#define XFS_ALL_QUOTA_ACCT 0x0001
#define XFS_ALL_QUOTA_ENFD 0x0002

unsigned int xfs_qm_export_flags(unsigned int flags);
int xfs_sb_version_hasquota(struct xfs_sb *sb);
int xfs_iget(struct xfs_mount *mp, void *null, xfs_ino_t ino, int zero1, int zero2, struct xfs_inode **ipp, ...);
void IRELE(struct xfs_inode *ip);