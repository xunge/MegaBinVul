#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/types.h>

struct mutex {
    int dummy;
};

struct timer_list {
    void (*function)(struct timer_list *);
};

struct dvb_ringbuffer {
    void *data;
    size_t size;
};

struct vb2_ctx {
    const char *name;
    int nonblock;
};

struct dmxdev_filter {
    int state;
    struct mutex mutex;
    struct dvb_ringbuffer buffer;
    struct vb2_ctx vb2_ctx;
    int type;
    struct timer_list timer;
};

struct dmxdev {
    struct dmxdev_filter *filter;
    struct mutex mutex;
    int exit;
    int filternum;
    int may_do_mmap;
};

struct dvb_device {
    void *priv;
    int users;
};

struct file {
    void *private_data;
    int f_flags;
};

struct inode {
    int dummy;
};

enum {
    DMXDEV_STATE_FREE,
    DMXDEV_STATE_ALLOCATED
};

enum {
    DMXDEV_TYPE_NONE
};

#define EINVAL 22
#define ERESTARTSYS 512
#define ENODEV 19
#define EMFILE 24

#define CONFIG_DVB_MMAP 0
#define O_NONBLOCK 04000

int mutex_lock_interruptible(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
void mutex_init(struct mutex *lock);
void timer_setup(struct timer_list *timer, void (*function)(struct timer_list *), unsigned int flags);
void dvb_ringbuffer_init(struct dvb_ringbuffer *rbuf, void *data, size_t len);
void dvb_vb2_init(struct vb2_ctx *ctx, const char *name, int nonblock);
void dvb_dmxdev_filter_state_set(struct dmxdev_filter *dmxdevfilter, int state);
void dvb_dmxdev_filter_timeout(struct timer_list *t);