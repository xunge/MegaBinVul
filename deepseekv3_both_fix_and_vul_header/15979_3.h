#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

struct mutex {
    pthread_mutex_t lock;
};
#define mutex_lock(m) pthread_mutex_lock(&(m)->lock)
#define mutex_unlock(m) pthread_mutex_unlock(&(m)->lock)

struct file {
    void *private_data;
    int f_flags;
};

struct dvb_device {
    void *priv;
    int users;
    int writers;
    void *entity;
};

struct dvb_frontend {
    void *frontend_priv;
    void *dvb;
    int exit;
    struct mutex remove_mutex;
    struct {
        int (*ts_bus_ctrl)(struct dvb_frontend *, int);
    } ops;
};

struct dvb_frontend_private {
    int reinitialise;
    int tune_mode_flags;
    int tone;
    int voltage;
    struct {
        int eventr;
        int eventw;
    } events;
    void *pipe;
    int thread;
};

struct dvb_adapter {
    int mfe_shared;
    struct mutex mfe_lock;
    struct dvb_device *mfe_dvbdev;
    void *device;
    void *mdev;
    struct mutex mdev_lock;
    struct mutex graph_mutex;
};

struct inode;

#define FE_TUNE_MODE_ONESHOT 0x01

extern int dvb_mfe_wait_time;
extern int dvb_generic_open(struct inode *inode, struct file *file);
extern int dvb_generic_release(struct inode *inode, struct file *file);
extern int dvb_frontend_start(struct dvb_frontend *fe);
extern void dvb_frontend_get(struct dvb_frontend *fe);

#define DVB_FE_DEVICE_REMOVED 1
#define ENODEV 19
#define EBUSY 16
#define EINTR 4

#define dev_dbg(dev, fmt, ...) printf(fmt, ##__VA_ARGS__)
#define dev_err(dev, fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define msleep_interruptible(x) usleep((x)*1000)
#define signal_pending(x) 0
#define current NULL