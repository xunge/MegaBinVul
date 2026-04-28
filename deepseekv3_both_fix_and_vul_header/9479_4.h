#include <stdint.h>
#include <stddef.h>
#include <errno.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef uint16_t u16;

struct list_head {
    struct list_head *prev;
    struct list_head *next;
};

struct spinlock {};

struct file {
    void *private_data;
    struct dentry *f_dentry;
};

struct dir_context {
    u64 pos;
};

struct inode {
    u64 i_ino;
    u16 i_mode;
    void *i_sb;
};

struct dentry {
    struct inode *d_inode;
    struct list_head d_subdirs;
    struct list_head d_child;
    struct {
        struct list_head d_child;
    } d_u;
    struct spinlock d_lock;
    struct {
        unsigned int len;
        const char *name;
    } d_name;
    void *d_sb;
};

struct ceph_file_info {
    struct dentry *dentry;
    unsigned int flags;
    unsigned int next_offset;
};

struct ceph_dentry_info {
    u32 lease_shared_gen;
    u64 offset;
};

#define d_unhashed(d) (0)
#define dget_dlock(d) 
#define dput(d) 
#define spin_lock(l) 
#define spin_unlock(l) 
#define spin_lock_nested(l, n) 
#define list_empty(l) (0)
#define list_entry(ptr, type, member) ((type *)(ptr))
#define CEPH_F_ATEND (1 << 0)
#define CEPH_SNAPDIR (1)
#define CEPH_INO_CEPH (1)
#define DENTRY_D_LOCK_NESTED (1)
#define EAGAIN (-11)

static inline int fpos_cmp(u64 a, u64 b) { return (a > b) - (a < b); }
static inline struct ceph_dentry_info *ceph_dentry(struct dentry *d) { return NULL; }
static inline int ceph_dir_is_complete(struct inode *i) { return 1; }
static inline u64 ceph_translate_ino(void *sb, u64 ino) { return ino; }
static inline u64 fpos_off(u64 offset) { return offset; }
static inline int dir_emit(struct dir_context *ctx, const char *name, int len, u64 ino, unsigned type) { return 0; }
static inline int ceph_snap(struct inode *i) { return 0; }
static inline u64 ceph_ino(struct inode *i) { return 0; }
static inline void dout(const char *fmt, ...) {}