#include <stddef.h>
#include <stdbool.h>

#define ERR_PTR(err) ((void *)(long)(err))
#define ENOENT 2
#define ENOMEM 12
#define GFP_KERNEL 0
#define PRINTER_NOT_ERROR 0
#define minors 1

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {
    int dummy;
};

struct kref {
    int refcount;
};

struct usb_function;
struct usb_function_instance;
struct usb_configuration;
struct usb_ctrlrequest;

struct usb_function {
    const char *name;
    int (*bind)(struct usb_configuration *c, struct usb_function *f);
    void (*unbind)(struct usb_configuration *c, struct usb_function *f);
    int (*set_alt)(struct usb_function *f, unsigned intf, unsigned alt);
    void (*disable)(struct usb_function *f);
    int (*setup)(struct usb_function *f, const struct usb_ctrlrequest *ctrl);
    bool (*req_match)(struct usb_function *f, const struct usb_ctrlrequest *ctrl);
    void (*free_func)(struct usb_function *f);
};

struct usb_function_instance {
    struct list_head list;
    void *fd;
};

struct printer_dev {
    struct kref kref;
    int minor;
    const char *pnp_string;
    unsigned q_len;
    struct usb_function function;
    struct list_head tx_reqs;
    struct list_head rx_reqs;
    struct list_head rx_buffers;
    struct list_head tx_reqs_active;
    struct list_head rx_reqs_active;
    int lock;
    struct mutex lock_printer_io;
    int rx_wait;
    int tx_wait;
    int tx_flush_wait;
    int interface;
    int printer_cdev_open;
    int printer_status;
    void *current_rx_req;
    unsigned current_rx_bytes;
    void *current_rx_buf;
};

struct f_printer_opts {
    struct usb_function_instance func_inst;
    struct mutex lock;
    int minor;
    int refcnt;
    const char *pnp_string;
    unsigned q_len;
};

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline void kref_init(struct kref *kref) {}
static inline void INIT_LIST_HEAD(struct list_head *list) {}
static inline void spin_lock_init(int *lock) {}
static inline void mutex_init(struct mutex *lock) {}
static inline void init_waitqueue_head(int *wq_head) {}

int printer_func_bind(struct usb_configuration *c, struct usb_function *f);
int printer_func_setup(struct usb_function *f, const struct usb_ctrlrequest *ctrl);
void printer_func_unbind(struct usb_configuration *c, struct usb_function *f);
int printer_func_set_alt(struct usb_function *f, unsigned intf, unsigned alt);
void printer_func_disable(struct usb_function *f);
bool gprinter_req_match(struct usb_function *f, const struct usb_ctrlrequest *ctrl);
void gprinter_free(struct usb_function *f);