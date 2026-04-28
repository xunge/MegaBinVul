#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>

struct qstr {
    const char *name;
};

struct dentry {
    struct qstr d_name;
};

struct path {
    struct dentry *dentry;
};

struct kstat {
    unsigned int mode;
    uid_t uid;
    gid_t gid;
    off_t size;
};

struct ovl_copy_up_ctx {
    struct dentry *parent;
    struct dentry *dentry;
    struct dentry *workdir;
    struct path lowerpath;
    struct kstat stat;
    bool metacopy;
    struct dentry *destdir;
    struct qstr destname;
    struct kstat pstat;
    const char *link;
};

struct delayed_call {
    void (*fn)(void *);
    void *arg;
};

#define DEFINE_DELAYED_CALL(name) struct delayed_call name = {NULL, NULL}
#define WARN_ON(cond) (cond)
#define IS_ERR(ptr) (0)
#define PTR_ERR(ptr) (0)
#define unlikely(cond) (cond)
#define STATX_BASIC_STATS 0
#define STATX_ATIME 0
#define STATX_MTIME 0
#define AT_STATX_SYNC_AS_STAT 0

static inline void do_delayed_call(struct delayed_call *call)
{
    if (call->fn)
        call->fn(call->arg);
}

static inline int vfs_getattr(const struct path *path, struct kstat *stat,
                unsigned int request_mask, unsigned int query_flags)
{
    return 0;
}

static inline const char *vfs_get_link(struct dentry *dentry, struct delayed_call *done)
{
    return NULL;
}

struct user_namespace;
static inline struct user_namespace *current_user_ns(void) { return NULL; }
static inline bool kuid_has_mapping(struct user_namespace *ns, uid_t uid) { return true; }
static inline bool kgid_has_mapping(struct user_namespace *ns, gid_t gid) { return true; }

extern struct dentry *ovl_workdir(struct dentry *dentry);
extern void ovl_path_lower(struct dentry *dentry, struct path *path);
extern bool ovl_need_meta_copy_up(struct dentry *dentry, unsigned int mode, int flags);
extern void ovl_path_upper(struct dentry *dentry, struct path *path);
extern int ovl_copy_up_start(struct dentry *dentry, int flags);
extern int ovl_do_copy_up(struct ovl_copy_up_ctx *ctx);
extern bool ovl_dentry_upper(struct dentry *dentry);
extern bool ovl_dentry_has_upper_alias(struct dentry *dentry);
extern int ovl_link_up(struct ovl_copy_up_ctx *ctx);
extern bool ovl_dentry_needs_data_copy_up_locked(struct dentry *dentry, int flags);
extern int ovl_copy_up_meta_inode_data(struct ovl_copy_up_ctx *ctx);
extern void ovl_copy_up_end(struct dentry *dentry);