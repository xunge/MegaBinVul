#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

struct mutex {
    void *lock;
};
struct inode;
struct file {
    void *private_data;
    int f_flags;
};
struct dvb_device {
    void *priv;
    int users;
    void *entity;
    struct {
        void *wait_queue;
    };
};
struct media_device {
    struct mutex graph_mutex;
    void (*disable_source)(void *);
};
struct dvb_frontend {
    void *frontend_priv;
    struct {
        void *device;
        struct mutex mdev_lock;
        struct media_device *mdev;
    } *dvb;
    struct {
        void (*ts_bus_ctrl)(struct dvb_frontend *, int);
    } ops;
    int exit;
    struct mutex remove_mutex;
};
struct dvb_frontend_private {
    unsigned long release_jiffies;
    struct {
        void *wait_queue;
    };
};
struct device;

extern unsigned long jiffies;
#define mb() __asm__ __volatile__ ("" : : : "memory")
#define dev_dbg(dev, fmt, ...) 
#define DVB_FE_NO_EXIT 0
#define CONFIG_MEDIA_CONTROLLER_DVB

int dvb_generic_release(struct inode *, struct file *);
void wake_up(void *);
void mutex_lock(struct mutex *);
void mutex_unlock(struct mutex *);
void dvb_frontend_put(struct dvb_frontend *);