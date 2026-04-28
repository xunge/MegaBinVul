#include <stdbool.h>
#include <stddef.h>

enum ovl_path_type {
    __OVL_PATH_UPPER  = (1 << 0),
    __OVL_PATH_MERGE  = (1 << 1),
    __OVL_PATH_PURE   = (1 << 2),
};

#define OVL_TYPE_UPPER(type) ((type) & __OVL_PATH_UPPER)
#define OVL_TYPE_MERGE(type) ((type) & __OVL_PATH_MERGE)
#define OVL_TYPE_PURE(type) ((type) & __OVL_PATH_PURE)
#define OVL_TYPE_MERGE_OR_LOWER(type) (OVL_TYPE_MERGE(type) || !OVL_TYPE_UPPER(type))
#define OVL_TYPE_PURE_UPPER(type) (OVL_TYPE_UPPER(type) && OVL_TYPE_PURE(type))

struct inode;
struct cred;

struct qstr {
    const char *name;
    unsigned int len;
};

struct dentry {
    struct inode *d_inode;
    struct dentry *d_parent;
    struct qstr d_name;
    unsigned int d_flags;
};

struct cred {
    unsigned int cap_effective;
};

#define RENAME_EXCHANGE    (1 << 0)
#define RENAME_NOREPLACE   (1 << 1)
#define RENAME_WHITEOUT    (1 << 2)

#define EINVAL             22
#define EXDEV              18
#define ENOMEM             12
#define ESTALE             116

#define CAP_SYS_ADMIN      21
#define CAP_DAC_OVERRIDE   1
#define CAP_FOWNER         3
#define CAP_FSETID         4
#define CAP_CHOWN          0

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

static inline bool d_is_dir(const struct dentry *dentry) { return false; }
static inline int ovl_check_sticky(struct dentry *dentry) { return 0; }
static inline enum ovl_path_type ovl_path_type(struct dentry *dentry) { return 0; }
static inline struct dentry *ovl_dentry_lower(struct dentry *dentry) { return NULL; }
static inline struct dentry *ovl_dentry_upper(struct dentry *dentry) { return NULL; }
static inline bool ovl_dentry_is_opaque(struct dentry *dentry) { return false; }
static inline int ovl_want_write(struct dentry *dentry) { return 0; }
static inline int ovl_copy_up(struct dentry *dentry) { return 0; }
static inline struct cred *prepare_creds(void) { return NULL; }
static inline void cap_raise(unsigned int *cap, int capnum) {}
static inline const struct cred *override_creds(const struct cred *new) { return NULL; }
static inline struct dentry *ovl_check_empty_and_clear(struct dentry *dentry) { return NULL; }
static inline struct dentry *lock_rename(struct dentry *d1, struct dentry *d2) { return NULL; }
static inline void dget(struct dentry *dentry) {}
static inline struct dentry *lookup_one_len(const char *name, struct dentry *parent, int len) { return NULL; }
static inline int ovl_set_opaque(struct dentry *dentry) { return 0; }
static inline int ovl_do_rename(struct inode *old_dir, struct dentry *old_dentry,
                               struct inode *new_dir, struct dentry *new_dentry,
                               unsigned int flags) { return 0; }
static inline int vfs_rename(struct inode *old_dir, struct dentry *old_dentry,
                            struct inode *new_dir, struct dentry *new_dentry,
                            struct inode **delegated_inode, unsigned int flags) { return 0; }
static inline void ovl_remove_opaque(struct dentry *dentry) {}
static inline void ovl_dentry_set_opaque(struct dentry *dentry, bool opaque) {}
static inline void ovl_cleanup(struct inode *dir, struct dentry *dentry) {}
static inline void ovl_dentry_version_inc(struct dentry *dentry) {}
static inline void dput(struct dentry *dentry) {}
static inline void unlock_rename(struct dentry *d1, struct dentry *d2) {}
static inline void revert_creds(const struct cred *old_cred) {}
static inline void put_cred(struct cred *cred) {}
static inline void ovl_drop_write(struct dentry *dentry) {}