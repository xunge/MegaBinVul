#include <stdint.h>
#include <string.h>

struct kref {
    int refcount;
};

struct mutex {
    int lock;
};

struct semaphore {
    int count;
};

struct wait_queue_head {
    int dummy;
};

struct dvb_adapter {
    int num;
    void* device;
};

struct dvb_frontend {
    int id;
    void* frontend_priv;
    struct {
        struct {
            const char* name;
        } info;
        int delsys[1];
    } ops;
    struct {
        int delivery_system;
    } dtv_property_cache;
    struct kref refcount;
    struct mutex remove_mutex;
    struct dvb_adapter* dvb;
};

struct dvb_frontend_private {
    struct semaphore sem;
    struct wait_queue_head wait_queue;
    struct {
        struct wait_queue_head wait_queue;
        struct mutex mtx;
    } events;
    int inversion;
    void* dvbdev;
};

struct dvb_device {
    uint32_t users;
    uint32_t writers;
    uint32_t readers;
    void* fops;
    const char* name;
};

struct dvb_frontend_fops {
    int dummy;
};

extern struct mutex frontend_mutex;
extern const struct dvb_frontend_fops dvb_frontend_fops;

#define GFP_KERNEL 0
#define ERESTARTSYS 512
#define ENOMEM 12
#define CONFIG_MEDIA_CONTROLLER_DVB
#define DVB_DEVICE_FRONTEND 0

enum fe_inversion {
    INVERSION_OFF
};

static inline void mutex_init(struct mutex* lock) { lock->lock = 0; }
static inline int mutex_lock_interruptible(struct mutex* lock) { return 0; }
static inline void mutex_unlock(struct mutex* lock) { lock->lock = 0; }
static inline void sema_init(struct semaphore* sem, int val) { sem->count = val; }
static inline void init_waitqueue_head(struct wait_queue_head* wq_head) {}
static inline void kref_init(struct kref* kref) { kref->refcount = 1; }
static inline void* kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void dvb_frontend_get(struct dvb_frontend* fe) { kref_init(&fe->refcount); }
static inline void dvb_frontend_put(struct dvb_frontend* fe) {}
static inline int dvb_register_device(void* dvb, void** dvbdev, const struct dvb_device* template, void* priv, int type, int flags) { return 0; }
static inline void dvb_frontend_clear_cache(struct dvb_frontend* fe) {}
static inline void dev_dbg(void* dev, const char* fmt, ...) {}
static inline void dev_info(void* dev, const char* fmt, ...) {}