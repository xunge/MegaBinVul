#include <pthread.h>
#include <stdint.h>

#define ENOENT 2
#define FMODE_READ 1
#define FMODE_WRITE 2

typedef uint32_t fmode_t;

struct mutex {
    pthread_mutex_t lock;
};

struct pipe_inode_info {
    unsigned int readers;
    unsigned int writers;
};

struct inode {
    struct mutex i_mutex;
    struct pipe_inode_info *i_pipe;
};

struct file {
    fmode_t f_mode;
};

static inline void mutex_lock(struct mutex *lock) {
    pthread_mutex_lock(&lock->lock);
}

static inline void mutex_unlock(struct mutex *lock) {
    pthread_mutex_unlock(&lock->lock);
}