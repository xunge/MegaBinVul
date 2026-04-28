#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <stddef.h>

struct file {
    void *private_data;
    int f_flags;
};

struct usb_request {
    void *buf;
    int status;
    int zero;
    unsigned length;
    void (*complete)(struct usb_request *);
    void *context;
};

struct usb_function {
    struct {
        struct {
            void *cdev;
        } *config;
    } func;
};

struct usb_ep;

struct f_hidg {
    int write_spinlock;
    int write_pending;
    int write_queue;
    struct usb_request *req;
    unsigned report_length;
    struct usb_function func;
    struct usb_ep *in_ep;
};

#define __user
#define GFP_ATOMIC 0
#define O_NONBLOCK 00004000
#define ERESTARTSYS 512

static void f_hidg_req_complete(struct usb_request *req) {}

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

static inline int access_ok(const void *addr, size_t size) { return 1; }
static inline void spin_lock_irqsave(int *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(int *lock, unsigned long flags) {}
static inline int wait_event_interruptible_exclusive(int queue, int condition) { return 0; }
static inline void wake_up(int *queue) {}
static inline void free_ep_req(struct usb_ep *ep, struct usb_request *req) {}
static inline int usb_ep_queue(struct usb_ep *ep, struct usb_request *req, int gfp) { return 0; }
static inline size_t copy_from_user(void *to, const void *from, size_t n) { return 0; }

#define ERROR(dev, fmt, ...)