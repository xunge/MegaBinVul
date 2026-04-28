#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

typedef uint32_t __u32;
typedef uint32_t __be32;
typedef uint32_t u32;

#define MAY_CREATE 0x20
#define I_MUTEX_PARENT 1

#define ATTR_MODE 1
#define ATTR_SIZE 2
#define ATTR_UID 4
#define ATTR_GID 8
#define ATTR_MTIME 16
#define ATTR_ATIME 32
#define ATTR_MTIME_SET 64
#define ATTR_ATIME_SET 128

#define NFS3_CREATE_UNCHECKED 0
#define NFS3_CREATE_GUARDED 1
#define NFS3_CREATE_EXCLUSIVE 2

struct svc_rqst;
struct svc_fh {
    struct dentry *fh_dentry;
    void *fh_export;
};
struct dentry {
    struct inode *d_inode;
};
struct inode {
    struct inode_operations *i_op;
    mode_t i_mode;
    struct timespec i_atime;
    struct timespec i_mtime;
    loff_t i_size;
};
struct inode_operations {
    struct dentry *(*lookup)(struct inode *, struct dentry *, unsigned int);
};
struct iattr {
    unsigned int ia_valid;
    mode_t ia_mode;
    loff_t ia_size;
    struct timespec ia_atime;
    struct timespec ia_mtime;
};

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)-1000L)
#define PTR_ERR(x) ((long)(x))
#define IS_ERR_VALUE(x) ((unsigned long)(void *)(x) >= (unsigned long)-MAX_ERRNO)

static inline int isdotent(const char *name, int len) {
    return len == 1 && name[0] == '.' || 
           len == 2 && name[0] == '.' && name[1] == '.';
}

#define nfserr_perm ((__be32)1)
#define nfserr_exist ((__be32)11)
#define nfserr_notdir ((__be32)20)

static inline __be32 fh_verify(struct svc_rqst *rqstp, struct svc_fh *fhp, int type, int access) { return 0; }
static inline void fh_lock_nested(struct svc_fh *fhp, int subclass) {}
static inline struct dentry *lookup_one_len(const char *name, struct dentry *parent, int len) { return NULL; }
static inline __be32 fh_compose(struct svc_fh *resfhp, void *export, struct dentry *dentry, struct svc_fh *fhp) { return 0; }
static inline int vfs_create(struct inode *dir, struct dentry *dentry, mode_t mode, void *arg) { return 0; }
static inline int EX_ISSYNC(void *export) { return 0; }
static inline __be32 nfserrno(int err) { return 0; }
static inline int nfsd_sync_dir(struct dentry *dentry) { return 0; }
static inline __be32 nfsd_setattr(struct svc_rqst *rqstp, struct svc_fh *fhp, struct iattr *iap, int check, time_t time) { return 0; }
static inline __be32 fh_update(struct svc_fh *fhp) { return 0; }
static inline void fh_unlock(struct svc_fh *fhp) {}
static inline void dput(struct dentry *dentry) {}