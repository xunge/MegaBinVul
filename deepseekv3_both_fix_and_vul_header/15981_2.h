#include <pthread.h>

struct inode {
    // dummy definition
};

struct file {
    void *private_data;
};

struct dvb_device {
    void *priv;
    int users;
    pthread_cond_t wait_queue;
};

struct dvb_net {
    pthread_mutex_t remove_mutex;
    int exit;
};

int dvb_generic_release(struct inode *inode, struct file *file);
void wake_up(pthread_cond_t *cond);
void mutex_lock(pthread_mutex_t *mutex);
void mutex_unlock(pthread_mutex_t *mutex);