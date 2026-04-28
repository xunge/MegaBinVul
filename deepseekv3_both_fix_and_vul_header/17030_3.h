#include <sys/types.h>
#include <stddef.h>

typedef unsigned long sector_t;

struct kiocb {
    struct file *ki_filp;
    loff_t ki_pos;
};

struct iov_iter {
    size_t count;
    int rw;
};

struct address_space {
    struct inode *host;
};

struct file {
    struct address_space *f_mapping;
};

struct inode {
    struct super_block *i_sb;
    void *i_private;
};

struct super_block {
    void *s_fs_info;
    struct block_device *s_bdev;
};

struct block_device;

struct ocfs2_super;
struct ocfs2_inode_info {
    unsigned int ip_dyn_features;
};

typedef int (*get_block_t)(struct inode *, sector_t, void *, int);
typedef void (*dio_iodone_t)(struct kiocb *, loff_t, ssize_t, void *);

#define OCFS2_SB(sb) ((struct ocfs2_super *)(sb->s_fs_info))
#define OCFS2_I(inode) ((struct ocfs2_inode_info *)(inode->i_private))
#define OCFS2_INLINE_DATA_FL (1 << 1)
#define READ 0

extern int ocfs2_lock_get_block(struct inode *, sector_t, void *, int);
extern int ocfs2_dio_wr_get_block(struct inode *, sector_t, void *, int); 
extern int ocfs2_get_block(struct inode *, sector_t, void *, int);
extern int ocfs2_dio_get_block(struct inode *, sector_t, void *, int);
extern int ocfs2_supports_append_dio(struct ocfs2_super *);
extern void ocfs2_dio_end_io(struct kiocb *, loff_t, ssize_t, void *);
extern ssize_t __blockdev_direct_IO(struct kiocb *, struct inode *,
    struct block_device *, struct iov_iter *, get_block_t, dio_iodone_t,
    void *, int);
extern loff_t i_size_read(struct inode *);
extern int iov_iter_rw(struct iov_iter *);