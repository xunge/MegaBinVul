#include <stdio.h>
#include <pthread.h>

struct inode;
struct file {
    void *private_data;
};

struct dvb_device {
    void *priv;
    int users;
    pthread_cond_t wait_queue;
};

struct dvb_ca_private {
    pthread_mutex_t remove_mutex;
    int open;
    int exit;
    struct {
        void *owner;
    } *pub;
};

extern int dvb_generic_release(struct inode *inode, struct file *file);
extern void dvb_ca_en50221_thread_update_delay(struct dvb_ca_private *ca);
extern void dvb_ca_private_put(struct dvb_ca_private *ca);
extern void dprintk(const char *fmt, ...);
extern void module_put(void *owner);