#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define XFS_SB_MAGIC 0x58465342
#define XFS_MAXLINK 32767U
#define BBSIZE 512
#define ENOMEM 12
#define ENOENT 2
#define EINVAL 22

struct super_block {
    unsigned long s_magic;
    unsigned long s_blocksize;
    unsigned long s_blocksize_bits;
    long long s_maxbytes;
    unsigned int s_max_links;
    unsigned int s_time_gran;
    unsigned long s_flags;
    void *s_fs_info;
    const void **s_xattr;
    const void *s_export_op;
    const void *s_qcop;
    unsigned int s_quota_types;
    const void *s_op;
    void *s_bdev;
    void *s_root;
};

struct inode;
struct dentry;
struct xfs_mount;
struct xfsstats;

struct xfs_sb {
    unsigned long sb_blocksize;
    unsigned long sb_rblocks;
    uint8_t sb_versionnum;
};

struct xfs_globals {
    int mount_delay;
};

extern struct xfs_globals xfs_globals;
extern const void *xfs_xattr_handlers[];
extern const void xfs_export_operations;
extern const void xfs_quotactl_operations;
extern const void xfs_super_operations;

#define QTYPE_MASK_USR 0x01
#define QTYPE_MASK_GRP 0x02
#define QTYPE_MASK_PRJ 0x04
#define XFS_MFSI_QUIET 0x40
#define XFS_MOUNT_DAX 0x8000
#define XFS_MOUNT_DISCARD 0x10000
#define SB_I_VERSION 0x00400000

struct xfs_mount {
    struct super_block *m_super;
    struct xfs_sb m_sb;
    unsigned int m_flags;
    struct {
        struct xfsstats *xs_stats;
    } m_stats;
    struct inode *m_rootip;
};

#define XFS_SB_VERSION_5 5
#define XFS_SB_VERSION_NUM(sb) ((sb)->sb_versionnum)
#define xfs_sb_version_hasreflink(sb) (0)
#define xfs_sb_version_hasrmapbt(sb) (0)

struct xfsstats {
    int dummy;
};

struct request_queue;

#define STATIC static

static inline struct inode *VFS_I(struct inode *inode) { return inode; }
static inline void msleep(unsigned int msecs) {}
static inline long long xfs_max_file_offset(int bits) { return 0; }
static inline void set_posix_acl_flag(struct super_block *sb) {}
static inline struct request_queue *bdev_get_queue(void *bdev) { return NULL; }
static inline int blk_queue_discard(struct request_queue *q) { return 0; }
static inline int bdev_dax_supported(struct super_block *sb, int blocksize) { return 0; }

struct xfs_mount *xfs_mount_alloc(struct super_block *sb) { return NULL; }
int xfs_parseargs(struct xfs_mount *mp, char *data) { return 0; }
void sb_min_blocksize(struct super_block *sb, int size) {}
int xfs_open_devices(struct xfs_mount *mp) { return 0; }
int xfs_init_mount_workqueues(struct xfs_mount *mp) { return 0; }
int xfs_init_percpu_counters(struct xfs_mount *mp) { return 0; }
int xfs_readsb(struct xfs_mount *mp, int flags) { return 0; }
int xfs_finish_flags(struct xfs_mount *mp) { return 0; }
int xfs_setup_devices(struct xfs_mount *mp) { return 0; }
int xfs_filestream_mount(struct xfs_mount *mp) { return 0; }
int xfs_mountfs(struct xfs_mount *mp) { return 0; }
void xfs_filestream_unmount(struct xfs_mount *mp) {}
void xfs_freesb(struct xfs_mount *mp) {}
void xfs_destroy_percpu_counters(struct xfs_mount *mp) {}
void xfs_destroy_mount_workqueues(struct xfs_mount *mp) {}
void xfs_close_devices(struct xfs_mount *mp) {}
void xfs_free_fsname(struct xfs_mount *mp) {}
void xfs_unmountfs(struct xfs_mount *mp) {}
void xfs_notice(struct xfs_mount *mp, const char *fmt, ...) {}
void xfs_warn(struct xfs_mount *mp, const char *fmt, ...) {}
void xfs_alert(struct xfs_mount *mp, const char *fmt, ...) {}

struct inode *igrab(struct inode *inode) { return NULL; }
struct dentry *d_make_root(struct inode *root) { return NULL; }
void *alloc_percpu(size_t size) { return malloc(size); }
void free_percpu(void *ptr) { free(ptr); }
void kfree(void *ptr) { free(ptr); }

#define alloc_percpu(type) malloc(sizeof(type))