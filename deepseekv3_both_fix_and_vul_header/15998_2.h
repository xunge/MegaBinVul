#include <stddef.h>

struct inode;
struct file {
    void *private_data;
};

struct dvb_device {
    void *priv;
};

struct dvb_ca_private;
struct dvb_ca_slot;

#define dprintk(fmt, ...) do {} while (0)
#define ENODEV (-19)
#define EIO (-5)

enum {
    DVB_CA_SLOTSTATE_RUNNING
};

struct dvb_ringbuffer {
    void *data;
};

struct mutex {
    int dummy;
};

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}

struct module;

static inline int try_module_get(struct module *mod) { return 1; }
static inline void module_put(struct module *mod) {}

struct dvb_ca_slot {
    int slot_state;
    struct dvb_ringbuffer rx_buffer;
};

struct dvb_ca_private {
    struct mutex remove_mutex;
    int exit;
    struct {
        struct module *owner;
    } *pub;
    int slot_count;
    struct dvb_ca_slot *slot_info;
    int open;
};

static void dvb_ringbuffer_flush(struct dvb_ringbuffer *rb) {}
static void dvb_ca_en50221_thread_update_delay(struct dvb_ca_private *ca) {}
static void dvb_ca_en50221_thread_wakeup(struct dvb_ca_private *ca) {}
static void dvb_ca_private_get(struct dvb_ca_private *ca) {}
static int dvb_generic_open(struct inode *inode, struct file *file) { return 0; }