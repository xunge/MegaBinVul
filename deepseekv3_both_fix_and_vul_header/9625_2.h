#include <stddef.h>

#define LOOKUP_FOLLOW 0x0001
#define LOOKUP_DIRECTORY 0x0002
#define LOOKUP_CONTINUE 0x0004
#define LOOKUP_PARENT 0x0008
#define FS_REVAL_DOT 0x0001

#define ENOENT 2
#define ENOTDIR 20
#define ESTALE 116

struct path {
    void *mnt;
    struct dentry *dentry;
};

struct qstr {
    const unsigned char *name;
    unsigned int len;
    unsigned long hash;
};

struct dentry {
    struct inode *d_inode;
    struct super_block *d_sb;
    struct dentry_operations *d_op;
};

struct inode {
    struct inode_operations *i_op;
};

struct super_block {
    struct file_system_type *s_type;
};

struct file_system_type {
    int fs_flags;
};

struct dentry_operations {
    int (*d_revalidate)(struct dentry *, void *);
};

struct inode_operations {
    int (*follow_link)(struct dentry *, void *);
    int (*lookup)(struct inode *, struct dentry *, void *);
};

struct nameidata {
    struct path path;
    unsigned int flags;
    int depth;
    struct qstr last;
    unsigned int last_type;
};

enum {
    LAST_NORM,
    LAST_DOT,
    LAST_DOTDOT
};

static unsigned long init_name_hash(void) { return 0; }
static unsigned long partial_name_hash(unsigned long c, unsigned long hash) { return 0; }
static unsigned long end_name_hash(unsigned long hash) { return 0; }
static int exec_permission(struct inode *inode) { return 0; }
static void follow_dotdot(struct nameidata *nd) {}
static int do_lookup(struct nameidata *nd, struct qstr *name, struct path *path) { return 0; }
static int do_follow_link(struct path *path, struct nameidata *nd) { return 0; }
static void path_to_nameidata(struct path *path, struct nameidata *nd) {}
static void path_put_conditional(struct path *path, struct nameidata *nd) {}
static void path_put(struct path *path) {}