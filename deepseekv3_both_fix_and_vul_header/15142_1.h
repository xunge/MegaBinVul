#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pthread.h>

struct pipe_inode_info {
    struct inode *inode;
};

struct file {
    struct address_space *f_mapping;
};

struct address_space {
    struct inode *host;
};

struct inode {
    unsigned short i_mode;
    pthread_mutex_t i_mutex;
};

struct splice_desc {
    size_t total_len;
    unsigned int flags;
    loff_t pos;
    union {
        struct file *file;
    } u;
};

typedef ssize_t (*splice_actor)(struct pipe_inode_info *, struct splice_desc *);

#define I_MUTEX_PARENT 0
#define I_MUTEX_CHILD 1

extern void mutex_lock_nested(pthread_mutex_t *mutex, int subclass);
extern void mutex_unlock(pthread_mutex_t *mutex);
extern void WARN_ON(int condition);
extern void inode_double_lock(struct inode *inode1, struct inode *inode2);
extern void inode_double_unlock(struct inode *inode1, struct inode *inode2);
extern ssize_t __splice_from_pipe(struct pipe_inode_info *pipe, struct splice_desc *sd, splice_actor actor);