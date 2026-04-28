#include <pthread.h>

struct mutex {
    pthread_mutex_t lock;
};

#define mutex_lock(m) pthread_mutex_lock(&(m)->lock)
#define mutex_unlock(m) pthread_mutex_unlock(&(m)->lock)

struct inode {
    struct mutex i_mutex;
    struct pipe_inode_info *i_pipe;
};

struct pipe_inode_info {
    unsigned int readers;
};

struct file {
    // file structure members
};

#define ENOENT 2