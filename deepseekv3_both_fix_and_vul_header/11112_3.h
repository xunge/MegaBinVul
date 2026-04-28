#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>

typedef void *xfs_failaddr_t;
typedef uint64_t xfs_ino_t;

#define XFS_DINODE_MAGIC 0x494e
#define XFS_DINODE_CRC_OFF 0
#define XFS_DIR3_FT_UNKNOWN 0
#define XFS_DIFLAG_REALTIME (1 << 0)
#define XFS_DIFLAG2_REFLINK (1 << 0)
#define XFS_DIFLAG2_COWEXTSIZE (1 << 1)
#define XFS_DIFLAG2_DAX (1 << 2)
#define XFS_DINODE_FMT_DEV 0
#define XFS_DINODE_FMT_LOCAL 1
#define XFS_DINODE_FMT_EXTENTS 2
#define XFS_DINODE_FMT_BTREE 3
#define XFS_DATA_FORK 0
#define XFS_ATTR_FORK 1
#define S_IFMT 0170000
#define S_IFREG 0100000
#define S_IFDIR 0040000
#define S_IFLNK 0120000
#define S_IFBLK 0060000
#define S_IFCHR 0020000
#define S_IFIFO 0010000
#define S_IFSOCK 0140000

#define S_ISLNK(mode) (((mode) & S_IFMT) == S_IFLNK)
#define S_ISDIR(mode) (((mode) & S_IFMT) == S_IFDIR)
#define S_ISREG(mode) (((mode) & S_IFMT) == S_IFREG)

struct xfs_sb {
    uint32_t sb_inodesize;
    uint8_t sb_versionnum;
    uint8_t sb_meta_uuid[16];
};

struct xfs_mount {
    struct xfs_sb m_sb;
    void *m_rtdev_targp;
};

struct xfs_dinode {
    uint16_t di_magic;
    uint16_t di_mode;
    uint8_t di_version;
    uint64_t di_ino;
    uint8_t di_uuid[16];
    uint32_t di_nextents;
    uint16_t di_anextents;
    uint64_t di_nblocks;
    uint32_t di_extsize;
    uint32_t di_cowextsize;
    uint16_t di_flags;
    uint64_t di_flags2;
    uint8_t di_format;
    uint8_t di_aformat;
    uint64_t di_size;
};

#define __this_address NULL

static inline uint16_t be16_to_cpu(uint16_t x) { return x; }
static inline uint32_t be32_to_cpu(uint32_t x) { return x; }
static inline uint64_t be64_to_cpu(uint64_t x) { return x; }
static inline uint16_t cpu_to_be16(uint16_t x) { return x; }

static inline int xfs_sb_version_hascrc(struct xfs_sb *sb) { return 0; }
static inline int xfs_sb_version_hasreflink(struct xfs_sb *sb) { return 0; }
static inline int xfs_verify_cksum(char *p, int len, int off) { return 0; }
static inline int uuid_equal(uint8_t u1[16], uint8_t u2[16]) { return 0; }
static inline int xfs_mode_to_ftype(uint16_t mode) { return 0; }
static inline xfs_failaddr_t xfs_dinode_verify_fork(struct xfs_dinode *dip, struct xfs_mount *mp, int fork) { return NULL; }
static inline xfs_failaddr_t xfs_inode_validate_extsize(struct xfs_mount *mp, uint32_t extsize, uint16_t mode, uint16_t flags) { return NULL; }
static inline xfs_failaddr_t xfs_inode_validate_cowextsize(struct xfs_mount *mp, uint32_t cowextsize, uint16_t mode, uint16_t flags, uint64_t flags2) { return NULL; }
#define XFS_DFORK_BOFF(dip) 0
#define XFS_DFORK_Q(dip) 0
#define XFS_DFORK_DSIZE(dip, mp) 0