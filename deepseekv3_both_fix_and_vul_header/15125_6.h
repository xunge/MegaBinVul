#include <stddef.h>

struct dentry {
    struct inode *d_inode;
    void *d_op;
    void *d_sb;
    struct dentry *(*d_parent);
};

struct inode {
    void *i_mutex;
};

struct qstr {
    const char *name;
    unsigned int len;
    unsigned long hash;
};

struct file {
    struct {
        struct dentry *dentry;
    } f_path;
};

struct nfs_fh {
    unsigned int size;
};

struct nfs_fattr {
    unsigned int valid;
};

struct nfs_server {
    unsigned int namelen;
};

struct nfs_proto {
    void *dentry_ops;
};

#define NFS_ATTR_FATTR 0x01
#define NFS_FILEID(inode) ((unsigned long)(inode))
#define NFS_FH(inode) ((struct nfs_fh *)NULL)

struct nfs_entry {
    char *name;
    unsigned int len;
    unsigned long ino;
    struct nfs_fh *fh;
    struct nfs_fattr *fattr;
};

typedef struct nfs_readdir_descriptor_t {
    struct file *file;
    struct nfs_entry *entry;
    int plus;
} nfs_readdir_descriptor_t;

static inline struct dentry *dget_parent(struct dentry *d) { return d; }
static inline struct dentry *dget(struct dentry *d) { return d; }
static inline unsigned long full_name_hash(const char *name, unsigned int len) { return 0; }
static inline struct dentry *d_lookup(struct dentry *d, struct qstr *q) { return NULL; }
static inline int d_mountpoint(struct dentry *d) { return 0; }
static inline int nfs_compare_fh(struct nfs_fh *a, struct nfs_fh *b) { return 0; }
static inline void d_drop(struct dentry *d) {}
static inline void dput(struct dentry *d) {}
static inline struct nfs_server *NFS_SERVER(struct inode *i) { return NULL; }
static inline struct dentry *d_alloc(struct dentry *d, struct qstr *q) { return NULL; }
static inline struct nfs_proto *NFS_PROTO(struct inode *i) { return NULL; }
static inline struct inode *nfs_fhget(void *sb, struct nfs_fh *fh, struct nfs_fattr *fattr) { return NULL; }
static inline int IS_ERR(const void *ptr) { return 0; }
static inline struct dentry *d_materialise_unique(struct dentry *d, struct inode *i) { return NULL; }
static inline void nfs_renew_times(struct dentry *d) {}
static inline void nfs_set_verifier(struct dentry *d, unsigned long v) {}
static inline unsigned long nfs_save_change_attribute(struct inode *i) { return 0; }
static inline void nfs_refresh_verifier(struct dentry *d, unsigned long v) {}