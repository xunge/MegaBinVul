#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

struct address_space {
    struct inode *host;
};

struct mutex {
    pthread_mutex_t lock;
};

struct inode {
    struct mutex i_mutex;
    unsigned long i_mode;
};

struct file {
    struct address_space *f_mapping;
    unsigned int f_flags;
};

struct pipe_inode_info {
    struct inode *inode;
};

struct splice_desc {
    size_t total_len;
    unsigned int flags;
    loff_t pos;
    union {
        struct file *file;
    } u;
};

#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)

#define PAGE_CACHE_SIZE 4096
#define PAGE_CACHE_SHIFT 12
#define IS_SYNC(inode) (0)
#define OSYNC_METADATA (1 << 0)
#define OSYNC_DATA (1 << 1)
#define I_MUTEX_PARENT 0
#define I_MUTEX_CHILD 1

typedef ssize_t (*splice_actor)(struct pipe_inode_info *, struct splice_desc *);
extern ssize_t pipe_to_file(struct pipe_inode_info *, struct splice_desc *);

extern void inode_double_lock(struct inode *inode1, struct inode *inode2);
extern void inode_double_unlock(struct inode *inode1, struct inode *inode2);
extern ssize_t file_remove_suid(struct file *file);
extern ssize_t __splice_from_pipe(struct pipe_inode_info *pipe, struct splice_desc *sd, splice_actor actor);
extern int generic_osync_inode(struct inode *inode, struct address_space *mapping, int what);
extern void balance_dirty_pages_ratelimited_nr(struct address_space *mapping, unsigned long nr_pages);
extern void mutex_lock(struct mutex *lock);
extern void mutex_unlock(struct mutex *lock);
extern void mutex_lock_nested(struct mutex *lock, int subclass);
extern void WARN_ON(int condition);