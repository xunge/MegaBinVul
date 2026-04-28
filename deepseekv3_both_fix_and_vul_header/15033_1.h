struct dentry;
struct qstr;
struct nameidata;
struct inode;

struct mutex {
    // dummy implementation
};

#define mutex_lock(lock) 
#define mutex_unlock(lock) 

#define ERR_PTR(err) ((void*)(err))
#define ENOMEM 12
#define ENOENT 2

struct dentry_operations {
    int (*d_revalidate)(struct dentry *, struct nameidata *);
};

struct dentry {
    struct inode *d_inode;
    struct dentry_operations *d_op;
};

struct inode {
    struct mutex i_mutex;
    struct inode_operations *i_op;
};

struct inode_operations {
    struct dentry *(*lookup)(struct inode *, struct dentry *, struct nameidata *);
};

static struct dentry *d_lookup(struct dentry *parent, struct qstr *name) { return 0; }
static struct dentry *d_alloc(struct dentry *parent, struct qstr *name) { return 0; }
static void dput(struct dentry *dentry) {}
static struct dentry *do_revalidate(struct dentry *dentry, struct nameidata *nd) { return 0; }