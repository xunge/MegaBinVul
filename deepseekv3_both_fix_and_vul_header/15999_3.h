#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdatomic.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

#define GFP_KERNEL 0
#define EINVAL 22
#define ENOMEM 12
#define EINTR 4
#define DVB_DEVICE_CA 1
#define DVB_CA_SLOTSTATE_NONE 0
#define DVB_CA_EN50221_CAMCHANGE_REMOVED 0

#define dprintk(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define kzalloc(size, flags) calloc(1, size)
#define kcalloc(n, size, flags) calloc(n, size)
#define kfree free
#define kref_init(ref) (*(ref) = 1)
#define atomic_set(ptr, val) (*(ptr) = (val))
#define mutex_init(mtx) pthread_mutex_init(mtx, NULL)
#define init_waitqueue_head(wq) ((void)0)
#define mb() asm volatile("" ::: "memory")
#define IS_ERR(ptr) (0)
#define PTR_ERR(ptr) (0)
#define pr_err(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define signal_pending(p) (0)
#define current (pthread_self())

struct dvb_adapter {
    int num;
};

struct dvb_device {
    struct dvb_adapter *adapter;
    int id;
};

struct dvb_ca_en50221 {
    void *private;
};

struct dvb_ca_slot {
    int slot_state;
    atomic_int camchange_count;
    int camchange_type;
    pthread_mutex_t slot_lock;
};

struct dvb_ca_private {
    int refcount;
    struct dvb_ca_en50221 *pub;
    int flags;
    int slot_count;
    struct dvb_ca_slot *slot_info;
    int open;
    int wakeup;
    int next_read_slot;
    struct dvb_device *dvbdev;
    pthread_t thread;
    pthread_mutex_t ioctl_mutex;
    pthread_mutex_t remove_mutex;
    int wait_queue;
};

static struct dvb_device dvbdev_ca = {0};
static int dvb_register_device(struct dvb_adapter *adap, struct dvb_device **pdvbdev,
                              const struct dvb_device *template, void *priv,
                              int type, int demux_sink_pads) { return 0; }
static void dvb_unregister_device(struct dvb_device *dvbdev) {}
static int dvb_ca_en50221_thread(void *data) { return 0; }
static int kthread_run(int (*threadfn)(void *data), void *data, const char *namefmt, ...) { return 0; }