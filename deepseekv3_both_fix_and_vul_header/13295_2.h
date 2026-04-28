#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#define MAX_EVENT 8
#define O_NONBLOCK 04000
#define TASK_INTERRUPTIBLE 1
#define EOVERFLOW 75
#define EWOULDBLOCK EAGAIN
#define ERESTARTSYS 512

struct dvb_frontend_event {
    int dummy;
};

struct dvb_dummy_device {
    void *device;
};

struct dvb_frontend {
    struct dvb_frontend_private *frontend_priv;
    struct {
        struct dvb_dummy_device *device;
    } *dvb;
};

struct wait_queue_entry {
    unsigned int flags;
    void *private;
    struct wait_queue_entry *next;
};

struct wait_queue_head {
    struct wait_queue_entry *first;
};

struct dvb_fe_events {
    pthread_mutex_t mtx;
    struct wait_queue_head wait_queue;
    struct dvb_frontend_event events[MAX_EVENT];
    int eventr;
    int eventw;
    int overflow;
};

struct dvb_frontend_private {
    struct dvb_fe_events events;
    void *frontend_priv;
};

extern int current;

static inline void dev_dbg(void *device, const char *fmt, ...) {}

static inline void init_waitqueue_entry(struct wait_queue_entry *wq, int current) {
    memset(wq, 0, sizeof(*wq));
}

static inline void add_wait_queue(struct wait_queue_head *wq, struct wait_queue_entry *entry) {}

static inline void remove_wait_queue(struct wait_queue_head *wq, struct wait_queue_entry *entry) {}

static inline void wait_woken(struct wait_queue_entry *wq, int state, int timeout) {}

static inline int wait_event_interruptible(struct wait_queue_head wq, int condition) {
    return 0;
}

static inline int signal_pending(int current) {
    return 0;
}

static inline int dvb_frontend_test_event(struct dvb_frontend_private *fepriv, struct dvb_fe_events *events) {
    return 0;
}

static inline void mutex_lock(pthread_mutex_t *mtx) {
    pthread_mutex_lock(mtx);
}

static inline void mutex_unlock(pthread_mutex_t *mtx) {
    pthread_mutex_unlock(mtx);
}