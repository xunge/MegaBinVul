#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

typedef unsigned int u32;

struct inode {
    struct dentry *dentry;
    void *i_sb;
    void *i_mapping;
    unsigned int i_diskflags;
};

struct dentry {
    struct inode *d_inode;
};

struct file {
    struct {
        struct dentry *dentry;
        void *mnt;
    } f_path;
};

struct gfs2_inode {
    void *i_gl;
    unsigned int i_diskflags;
};

struct gfs2_sbd {
};

struct buffer_head {
    void *b_data;
};

struct gfs2_holder {
};

#define GFS2_I(inode) ((struct gfs2_inode *)(inode))
#define GFS2_SB(inode) ((struct gfs2_sbd *)((inode)->i_sb))

#define GFS2_FLAGS_USER_SET 0
#define GFS2_DIF_IMMUTABLE 0
#define GFS2_DIF_APPENDONLY 0
#define GFS2_DIF_JDATA 0

#define LM_ST_EXCLUSIVE 0
#define RES_DINODE 0

#define EACCES 1
#define EINVAL 2
#define EPERM 3

#define MAY_WRITE 0
#define CAP_LINUX_IMMUTABLE 0

#define IS_IMMUTABLE(inode) 0
#define IS_APPEND(inode) 0

extern int mnt_want_write(void *mnt);
extern void mnt_drop_write(void *mnt);
extern int gfs2_glock_nq_init(void *gl, int state, int flags, struct gfs2_holder *gh);
extern void gfs2_glock_dq_uninit(struct gfs2_holder *gh);
extern int gfs2_permission(struct inode *inode, int mask);
extern int gfs2_trans_begin(struct gfs2_sbd *sdp, unsigned int blocks, unsigned int revokes);
extern void gfs2_trans_end(struct gfs2_sbd *sdp);
extern int gfs2_meta_inode_buffer(struct gfs2_inode *ip, struct buffer_head **bhp);
extern void gfs2_trans_add_bh(void *gl, struct buffer_head *bh, int meta);
extern void gfs2_dinode_out(struct gfs2_inode *ip, void *buf);
extern void gfs2_set_inode_flags(struct inode *inode);
extern void gfs2_set_aops(struct inode *inode);
extern void gfs2_log_flush(struct gfs2_sbd *sdp, void *gl);
extern int is_owner_or_cap(struct inode *inode);
extern int capable(int cap);
extern int filemap_fdatawrite(void *mapping);
extern int filemap_fdatawait(void *mapping);
extern void brelse(struct buffer_head *bh);