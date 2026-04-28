struct inode {
    unsigned long i_ctime;
    struct inode *d_inode;
    unsigned long i_nlink;
};

struct dentry {
    struct inode *d_inode;
};

#define KERN_ERR ""

extern struct dentry *ecryptfs_dentry_to_lower(struct dentry *dentry);
extern struct inode *ecryptfs_inode_to_lower(struct inode *inode);
extern struct dentry *lock_parent(struct dentry *dentry);
extern void unlock_dir(struct dentry *dentry);
extern int vfs_unlink(struct inode *dir, struct dentry *dentry);
extern void fsstack_copy_attr_times(struct inode *dest, struct inode *src);
extern void d_drop(struct dentry *dentry);
extern int printk(const char *fmt, ...);