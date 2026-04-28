#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>

#define unlikely(x) __builtin_expect(!!(x), 0)
#define IS_SYNC(inode) (0)
#define OSYNC_METADATA (1)
#define OSYNC_DATA (2)

struct mutex;

struct address_space {
    struct inode *host;
};

struct inode {
    struct mutex *i_mutex;
};

struct file {
    struct address_space *f_mapping;
    struct dentry *f_dentry;
    unsigned int f_flags;
};

struct dentry;
struct pipe_inode_info;
struct pipe_buffer;
struct splice_desc;

extern int should_remove_suid(struct dentry *);
extern int __remove_suid(struct dentry *, int);
extern ssize_t splice_from_pipe(struct pipe_inode_info *, struct file *, loff_t *, size_t, unsigned int, int (*)(struct pipe_inode_info *, struct pipe_buffer *, struct splice_desc *));
extern int generic_osync_inode(struct inode *, struct address_space *, int);
extern int pipe_to_file(struct pipe_inode_info *, struct pipe_buffer *, struct splice_desc *);

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}