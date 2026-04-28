#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

struct dentry;
struct file {
    void *private_data;
};

struct inode {
    unsigned long i_ino;
    mode_t i_mode;
    loff_t i_size;
    struct timespec i_mtime;
    struct timespec i_ctime;
    void *i_mapping;
};

struct iattr {
    unsigned int ia_valid;
    mode_t ia_mode;
    uid_t ia_uid;
    gid_t ia_gid;
    loff_t ia_size;
    struct timespec ia_mtime;
    struct timespec ia_ctime;
};

struct fuse_mount {
    struct fuse_conn *fc;
};

struct fuse_conn {
    bool default_permissions;
    bool writeback_cache;
    bool atomic_o_trunc;
    bool handle_killpriv_v2;
};

struct fuse_inode {
    void *i_mmap_sem;
    void *lock;
    unsigned long state;
};

struct fuse_file {
    uint64_t fh;
};

struct fuse_setattr_in {
    unsigned int valid;
    uint64_t fh;
    uint64_t lock_owner;
};

struct fuse_attr_out {
    struct {
        mode_t mode;
        loff_t size;
    } attr;
};

struct fuse_args {
    int dummy;
};

struct task_struct {
    void *files;
};

extern struct task_struct *current;

#define ATTR_FORCE (1 << 0)
#define ATTR_SIZE (1 << 1)
#define ATTR_OPEN (1 << 2)
#define ATTR_MODE (1 << 3)
#define ATTR_UID (1 << 4)
#define ATTR_GID (1 << 5)
#define ATTR_MTIME_SET (1 << 6)
#define ATTR_TIMES_SET (1 << 7)
#define ATTR_MTIME (1 << 8)
#define ATTR_CTIME (1 << 9)

#define FATTR_FH (1 << 0)
#define FATTR_KILL_SUIDGID (1 << 1)
#define FATTR_LOCKOWNER (1 << 2)

#define FUSE_I_SIZE_UNSTABLE (1 << 0)

#define EIO 5
#define EINTR 4
#define CAP_FSETID 4

#define WARN_ON(cond) (0)

static inline struct inode *d_inode(struct dentry *dentry) { return (struct inode *)0; }
static inline struct fuse_mount *get_fuse_mount(struct inode *inode) { return (struct fuse_mount *)0; }
static inline struct fuse_inode *get_fuse_inode(struct inode *inode) { return (struct fuse_inode *)0; }
static inline int setattr_prepare(struct dentry *dentry, struct iattr *attr) { return 0; }
static inline int FUSE_IS_DAX(struct inode *inode) { return 0; }
static inline void down_write(void *sem) {}
static inline int fuse_dax_break_layouts(struct inode *inode, int a, int b) { return 0; }
static inline void up_write(void *sem) {}
static inline void i_size_write(struct inode *inode, loff_t size) {}
static inline void truncate_pagecache(struct inode *inode, loff_t size) {}
static inline int write_inode_now(struct inode *inode, int b) { return 0; }
static inline void fuse_set_nowrite(struct inode *inode) {}
static inline void fuse_release_nowrite(struct inode *inode) {}
static inline void set_bit(int bit, unsigned long *addr) {}
static inline void iattr_to_fattr(struct fuse_conn *fc, struct iattr *attr, 
                                struct fuse_setattr_in *inarg, bool b) {}
static inline uint64_t fuse_lock_owner_id(struct fuse_conn *fc, void *files) { return 0; }
static inline int capable(int cap) { return 0; }
static inline void fuse_setattr_fill(struct fuse_conn *fc, struct fuse_args *args,
                                   struct inode *inode, struct fuse_setattr_in *inarg,
                                   struct fuse_attr_out *outarg) {}
static inline int fuse_simple_request(struct fuse_mount *fm, struct fuse_args *args) { return 0; }
static inline void fuse_invalidate_attr(struct inode *inode) {}
static inline int fuse_invalid_attr(void *attr) { return 0; }
static inline void make_bad_inode(struct inode *inode) {}
static inline void spin_lock(void *lock) {}
static inline void fuse_change_attributes_common(struct inode *inode, void *attr, int timeout) {}
static inline int attr_timeout(void *outarg) { return 0; }
static inline void __fuse_release_nowrite(struct inode *inode) {}
static inline void spin_unlock(void *lock) {}
static inline void invalidate_inode_pages2(void *mapping) {}
static inline void clear_bit(int bit, unsigned long *addr) {}

#define FUSE_ARGS(args) struct fuse_args args = {0}