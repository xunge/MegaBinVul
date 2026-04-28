#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

typedef uint64_t xfs_fileoff_t;
typedef uint64_t xfs_ufsize_t;
typedef uint64_t xfs_off_t;
typedef uint64_t xfs_fsblock_t;
typedef uint64_t xfs_filblks_t;
typedef uint64_t sector_t;
typedef long ssize_t;

struct inode {
    unsigned long i_blkbits;
    unsigned long i_size;
    void *i_mapping;
};

struct super_block {
    unsigned long s_maxbytes;
};

struct buffer_head {
    unsigned long b_size;
    void *b_bdev;
    int b_state;
};

struct xfs_inode {
    struct inode vfs_inode;
    struct xfs_mount *i_mount;
};

struct xfs_mount {
    struct super_block *m_super;
};

struct xfs_bmbt_irec {
    xfs_fileoff_t br_startoff;
    xfs_fsblock_t br_startblock;
    xfs_filblks_t br_blockcount;
    int br_state;
};

enum {
    XFS_ILOCK_SHARED,
    XFS_ILOCK_EXCL
};

#define XFS_I(inode) ((struct xfs_inode *)(inode))
#define XFS_FORCED_SHUTDOWN(mp) (0)
#define XFS_B_TO_FSB(mp, b) (0)
#define XFS_B_TO_FSBT(mp, b) (0)
#define HOLESTARTBLOCK (-1)
#define DELAYSTARTBLOCK (-2)
#define ISUNWRITTEN(imap) (0)
#define IS_DAX(inode) (0)
#define VFS_I(ip) (&(ip)->vfs_inode)
#define STATIC static
#define BUG_ON(condition) do { if (condition) ; } while(0)
#define ASSERT(condition) do { if (!(condition)) ; } while(0)
#define WARN_ON_ONCE(condition) do { if (condition) ; } while(0)
#define XFS_BMAPI_ENTIRE (0)
#define XFS_IO_UNWRITTEN (0)
#define XFS_IO_DELALLOC (0)
#define XFS_IO_OVERWRITE (0)
#define EIO (-5)

static inline unsigned long i_size_read(struct inode *inode) { return inode->i_size; }
static inline bool mapping_mapped(void *mapping) { return false; }

extern int xfs_ilock_data_map_shared(struct xfs_inode *ip);
extern int xfs_is_reflink_inode(struct xfs_inode *ip);
extern bool xfs_reflink_find_cow_mapping(struct xfs_inode *ip, xfs_off_t offset, struct xfs_bmbt_irec *imap, bool *need_alloc);
extern int xfs_bmapi_read(struct xfs_inode *ip, xfs_fileoff_t bno, xfs_filblks_t len, struct xfs_bmbt_irec *mval, int *nmap, int flags);
extern void xfs_reflink_trim_irec_to_next_cow(struct xfs_inode *ip, xfs_fileoff_t offset_fsb, struct xfs_bmbt_irec *imap);
extern int xfs_iomap_write_direct(struct xfs_inode *ip, xfs_off_t offset, ssize_t count, struct xfs_bmbt_irec *imap, int *nimaps);
extern void xfs_ilock_demote(struct xfs_inode *ip, int lock_mode);
extern void xfs_iunlock(struct xfs_inode *ip, int lock_mode);
extern void xfs_map_trim_size(struct inode *inode, sector_t iblock, struct buffer_head *bh_result, struct xfs_bmbt_irec *imap, xfs_off_t offset, ssize_t size);
extern void xfs_map_buffer(struct inode *inode, struct buffer_head *bh_result, struct xfs_bmbt_irec *imap, xfs_off_t offset);
extern int xfs_bounce_unaligned_dio_write(struct xfs_inode *ip, xfs_fileoff_t offset_fsb, struct xfs_bmbt_irec *imap);
extern void xfs_map_direct(struct inode *inode, struct buffer_head *bh_result, struct xfs_bmbt_irec *imap, xfs_off_t offset, bool is_cow);
extern void *xfs_find_bdev_for_inode(struct inode *inode);
extern void set_buffer_unwritten(struct buffer_head *bh);
extern void set_buffer_new(struct buffer_head *bh);
extern bool buffer_mapped(struct buffer_head *bh);
extern bool buffer_uptodate(struct buffer_head *bh);
extern void trace_xfs_get_blocks_alloc(struct xfs_inode *ip, xfs_off_t offset, ssize_t size, int type, struct xfs_bmbt_irec *imap);
extern void trace_xfs_get_blocks_found(struct xfs_inode *ip, xfs_off_t offset, ssize_t size, int type, struct xfs_bmbt_irec *imap);
extern void trace_xfs_get_blocks_notfound(struct xfs_inode *ip, xfs_off_t offset, ssize_t size);