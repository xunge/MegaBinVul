#include <pthread.h>
#include <unistd.h>

struct dvb_ca_en50221 {
    struct dvb_ca_private *private;
};

struct dvb_ca_private {
    pthread_mutex_t remove_mutex;
    int exit;
    struct dvb_device *dvbdev;
    pthread_t thread;
    int slot_count;
};

struct dvb_device {
    int users;
    pthread_cond_t wait_queue;
};

#define mutex_lock pthread_mutex_lock
#define mutex_unlock pthread_mutex_unlock
#define kthread_stop pthread_cancel
#define dprintk(fmt, ...)