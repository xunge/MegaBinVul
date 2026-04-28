#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define DVB_FE_DEVICE_REMOVED 0
#define DVB_FE_NORMAL_EXIT 1
#define FESTATE_IDLE 0

struct dvb_device {
    int users;
    pthread_cond_t wait_queue;
    pthread_mutex_t lock;
};

struct dvb_frontend_private {
    pthread_t thread;
    sem_t sem;
    int state;
    struct dvb_device *dvbdev;
};

struct dvb_adapter {
    void *device;
};

struct dvb_frontend {
    struct dvb_frontend_private *frontend_priv;
    struct dvb_adapter *dvb;
    int exit;
    pthread_mutex_t remove_mutex;
};