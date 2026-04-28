#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

struct mutex {
    int dummy;
};

struct rw_semaphore {
    int dummy;
};

struct kref {
    int refcount;
};

struct wait_queue_head {
    int dummy;
};

struct device {
    int dummy;
};

struct file_operations {
    void *owner;
};

struct dvb_adapter {
    int num;
    void *module;
    struct device *device;
    struct list_head device_list;
};

struct dvb_device {
    int type;
    int id;
    int minor;
    struct dvb_adapter *adapter;
    void *priv;
    struct file_operations *fops;
    struct kref ref;
    struct wait_queue_head wait_queue;
    struct list_head list_head;
};

enum dvb_device_type {
    DVB_DEVICE_UNKNOWN
};

struct dvbdevfops_node {
    struct file_operations *fops;
    enum dvb_device_type type;
    const struct dvb_device *template;
    struct list_head list_head;
};

extern struct mutex dvbdev_register_lock;
extern struct rw_semaphore minor_rwsem;
extern struct list_head dvbdevfops_list;
extern struct device *dvb_class;
extern struct dvb_device *dvb_minors[];
extern const char *dnames[];

#define MAX_DVB_MINORS 256
#define DVB_MAJOR 212
#define ENFILE 23
#define ENOMEM 12
#define EINVAL 22

#define GFP_KERNEL 0
#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)
#define MKDEV(a,b) (0)
#define pr_err(fmt, ...) 
#define dprintk(fmt, ...)

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline void down_write(struct rw_semaphore *sem) {}
static inline void up_write(struct rw_semaphore *sem) {}
static inline void kref_init(struct kref *kref) {}
static inline void init_waitqueue_head(struct wait_queue_head *wq) {}
static inline void list_add_tail(struct list_head *new, struct list_head *head) {}
static inline void list_del(struct list_head *entry) {}
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void *kmemdup(const void *src, size_t len, int gfp) { 
    void *p = malloc(len);
    if (p) memcpy(p, src, len);
    return p;
}
static inline void kfree(void *ptr) { free(ptr); }
static inline struct dvb_device *dvb_device_get(struct dvb_device *dvbdev) { return dvbdev; }
static inline int dvbdev_get_free_id(struct dvb_adapter *adap, enum dvb_device_type type) { return 0; }
static inline int dvb_register_media_device(struct dvb_device *dvbdev, enum dvb_device_type type, int minor, int demux_sink_pads) { return 0; }
static inline void dvb_media_device_free(struct dvb_device *dvbdev) {}
static inline struct device *device_create(struct device *class, struct device *parent, int devt, void *drvdata, const char *fmt, ...) { return NULL; }
static inline int nums2minor(int num, enum dvb_device_type type, int id) { return 0; }