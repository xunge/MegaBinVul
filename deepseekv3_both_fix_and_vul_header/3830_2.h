#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <time.h>

typedef uint32_t __be32;
typedef uint32_t __u32;
typedef uint8_t u8;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;
typedef int64_t s64;
typedef int64_t loff_t;

struct svc_rqst;
struct svc_fh {
    struct dentry *fh_dentry;
    struct svc_export *fh_export;
};
struct iattr {
    unsigned int ia_valid;
    unsigned short ia_mode;
    loff_t ia_size;
    struct timespec ia_atime;
    struct timespec ia_mtime;
};
struct dentry;
struct inode {
    struct timespec i_atime;
    struct timespec i_mtime;
    loff_t i_size;
};
struct svc_export;

#define NFSD_MAY_EXEC 0x01
#define NFSD_MAY_CREATE 0x02
#define S_IFDIR 0040000
#define S_IFREG 0100000
#define ATTR_MODE 1
#define ATTR_SIZE 2
#define ATTR_MTIME 4
#define ATTR_ATIME 8
#define ATTR_MTIME_SET 16
#define ATTR_ATIME_SET 32

#define NFS3_CREATE_UNCHECKED 0
#define NFS3_CREATE_GUARDED 1
#define NFS3_CREATE_EXCLUSIVE 2
#define NFS4_CREATE_EXCLUSIVE4_1 3

#define nfserr_perm ((__be32)1)
#define nfserr_exist ((__be32)6)

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define d_is_reg(x) 1
#define d_really_is_negative(x) 1
#define d_really_is_positive(x) 0
#define d_inode(x) ((struct inode*)0)
#define I_MUTEX_PARENT 0

static inline __be32 nfserrno(int err) { return (__be32)err; }
static inline int fh_want_write(struct svc_fh *fhp) { return 0; }
static inline void fh_lock_nested(struct svc_fh *fhp, int flags) {}
static inline void fh_unlock(struct svc_fh *fhp) {}
static inline void fh_drop_write(struct svc_fh *fhp) {}
static inline __be32 fh_verify(struct svc_rqst *rqstp, struct svc_fh *fhp, int type, int access) { return 0; }
static inline __be32 fh_compose(struct svc_fh *resfhp, struct svc_export *exp, struct dentry *dentry, struct svc_fh *fhp) { return 0; }
static inline struct dentry *lookup_one_len(const char *name, struct dentry *parent, int len) { return NULL; }
static inline int vfs_create(struct inode *dir, struct dentry *dentry, unsigned short mode, bool want_excl) { return 0; }
static inline void dput(struct dentry *dentry) {}
static inline int commit_metadata(struct svc_fh *fhp) { return 0; }
static inline __be32 fh_update(struct svc_fh *fhp) { return 0; }
static inline bool nfsd_create_is_exclusive(int createmode) { return false; }
static inline void nfsd_check_ignore_resizing(struct iattr *iap) {}
static inline __be32 nfsd_create_setattr(struct svc_rqst *rqstp, struct svc_fh *resfhp, struct iattr *iap) { return 0; }
static inline int isdotent(const char *name, int len) { return 0; }