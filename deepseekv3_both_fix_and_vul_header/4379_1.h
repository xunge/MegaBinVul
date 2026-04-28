#include <string.h>
#include <stdlib.h>

enum integrity_status {
    INTEGRITY_PASS,
    INTEGRITY_FAIL,
    INTEGRITY_NOLABEL,
    INTEGRITY_NOXATTRS,
    INTEGRITY_UNKNOWN
};

#define EVM_XATTR_HMAC 1
#define EVM_IMA_XATTR_DIGSIG 2
#define INTEGRITY_KEYRING_EVM 0

#define XATTR_NAME_EVM "security.evm"
#define GFP_NOFS 0
#define ENODATA 61
#define EOPNOTSUPP 95
#define EINVAL 22

#define IS_RDONLY(inode) 0
#define IS_IMMUTABLE(inode) 0

struct dentry;
struct inode;
struct integrity_iint_cache {
    enum integrity_status evm_status;
};

struct evm_ima_xattr_data {
    int type;
    char digest[64];
};

static int vfs_getxattr_alloc(struct dentry *dentry, const char *name, char **xattr_value, int xattr_value_len, int flags);
static int evm_find_protected_xattrs(struct dentry *dentry);
static int evm_calc_hmac(struct dentry *dentry, const char *xattr_name, char *xattr_value, size_t xattr_value_len, char *digest);
static int evm_calc_hash(struct dentry *dentry, const char *xattr_name, char *xattr_value, size_t xattr_value_len, char *digest);
static int integrity_digsig_verify(const char *keyring, const char *sig, int siglen, const char *digest, int digestlen);
static void evm_update_evmxattr(struct dentry *dentry, const char *xattr_name, char *xattr_value, size_t xattr_value_len);
static inline struct inode *d_backing_inode(struct dentry *dentry);