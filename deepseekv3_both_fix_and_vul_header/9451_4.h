#include <stdint.h>
#include <stddef.h>
#include <errno.h>

typedef uint32_t u32;
typedef uint64_t u64;

struct list_head {
    struct list_head *prev;
    struct list_head *next;
};

struct file {
    void *private_data;
    struct dentry *f_dentry;
};

struct dir_context {
    u64 pos;
};

struct inode {
    u64 i_ino;
    unsigned short i_mode;
};

struct super_block {
    // empty placeholder
};

struct dentry {
    struct inode *d_inode;
    struct list_head d_subdirs;
    struct list_head d_child;
    struct {
        struct list_head d_child;
    } d_u;
    void *d_lock;
    struct super_block *d_sb;
    struct {
        unsigned int len;
        const char *name;
    } d_name;
};

struct ceph_file_info {
    struct dentry *dentry;
    int flags;
    int next_offset;
};

struct ceph_dentry_info {
    u32 lease_shared_gen;
    u64 offset;
};

#define CEPH_F_ATEND 1
#define CEPH_SNAPDIR 2
#define CEPH_INO_CEPH 1
#define DENTRY_D_LOCK_NESTED 1
#define EAGAIN (-11)

#define dout(fmt, ...) do {} while (0)

static inline struct ceph_dentry_info *ceph_dentry(struct dentry *dentry)
{
    return NULL;
}

static inline int ceph_dir_is_complete(struct inode *inode)
{
    return 0;
}

static inline u64 ceph_translate_ino(struct super_block *sb, u64 ino)
{
    return ino;
}

static inline int fpos_cmp(u64 a, u64 b)
{
    return (a > b) - (a < b);
}

static inline u64 fpos_off(u64 pos)
{
    return pos;
}

static inline int list_empty(const struct list_head *head)
{
    return head->next == head;
}

static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}
static inline void spin_lock_nested(void *lock, int nested) {}
static inline void dget_dlock(struct dentry *dentry) {}
static inline void dput(struct dentry *dentry) {}
static inline int dir_emit(struct dir_context *ctx, const char *name, int len, u64 ino, unsigned type) { return 0; }
static inline int d_unhashed(struct dentry *dentry) { return 0; }
static inline u64 ceph_snap(struct inode *inode) { return 0; }
static inline u64 ceph_ino(struct inode *inode) { return 0; }

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))