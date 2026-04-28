#include <pthread.h>

#define ENOENT 2

struct inode {
    pthread_mutex_t i_mutex;
    struct pipe_inode_info *i_pipe;
};

struct pipe_inode_info {
    int writers;
};

struct file {
};