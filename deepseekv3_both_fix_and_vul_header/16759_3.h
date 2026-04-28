#include <stddef.h>
#include <string.h>
#include <sys/types.h>

typedef unsigned short umode_t;

struct fuse_entry_out {
    unsigned long nodeid;
    unsigned long generation;
    struct {
        umode_t mode;
    } attr;
};

struct fuse_args {
    unsigned long nodeid;
    int out_numargs;
    struct {
        size_t size;
        void *value;
    } out_args[1];
};

struct fuse_mount {
    void *fc;
};

struct inode {
    void *i_sb;
};

struct dentry;
struct fuse_forget_link;

#define ENOMEM 12
#define EIO 5
#define S_IFMT 0170000
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

static void *kfree(void *ptr) { return NULL; }
static void *fuse_alloc_forget(void) { return NULL; }
static int fuse_simple_request(struct fuse_mount *fm, struct fuse_args *args) { return 0; }
static int invalid_nodeid(unsigned long nodeid) { return 0; }
static int fuse_invalid_attr(void *attr) { return 0; }
static void fuse_queue_forget(void *fc, struct fuse_forget_link *forget, unsigned long nodeid, int nlookup) {}
static void d_drop(struct dentry *entry) {}
static struct dentry *d_splice_alias(struct inode *inode, struct dentry *entry) { return NULL; }
static void dput(struct dentry *dentry) {}
static void fuse_change_entry_timeout(struct dentry *entry, struct fuse_entry_out *outarg) {}
static void fuse_dir_changed(struct inode *dir) {}
static unsigned long get_node_id(struct inode *inode) { return 0; }
static long entry_attr_timeout(struct fuse_entry_out *outarg) { return 0; }
static struct inode *fuse_iget(void *sb, unsigned long nodeid, unsigned long generation, void *attr, long entry_attr_timeout, int dummy) { return NULL; }