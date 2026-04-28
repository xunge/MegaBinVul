#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#define MAX_WRITES_IN_FLIGHT 4
#define ENODEV 19
#define EINVAL 22
#define ENOMEM 12
#define EFAULT 14
#define EAGAIN 11
#define ERESTART 85
#define O_NONBLOCK 04000
#define GFP_KERNEL 0
#define URB_NO_TRANSFER_DMA_MAP (1 << 0)

struct usb_device {
    int dummy;
};

struct usb_interface {
    struct usb_device dev;
};

struct usb_endpoint_descriptor {
    unsigned char bEndpointAddress;
    unsigned char bInterval;
};

struct urb {
    unsigned int transfer_flags;
    void *transfer_dma;
};

struct iowarrior {
    struct usb_device *udev;
    struct usb_interface *interface;
    pthread_mutex_t mutex;
    bool present;
    unsigned int minor;
    size_t report_size;
    int product_id;
    struct usb_endpoint_descriptor *int_out_endpoint;
    atomic_int write_busy;
    pthread_cond_t write_wait;
    bool opened;
};

struct file {
    void *private_data;
    int f_flags;
};

#define USB_DEVICE_ID_CODEMERCS_IOW24 0x1500
#define USB_DEVICE_ID_CODEMERCS_IOWPV1 0x1510
#define USB_DEVICE_ID_CODEMERCS_IOWPV2 0x1511
#define USB_DEVICE_ID_CODEMERCS_IOW40 0x1501
#define USB_DEVICE_ID_CODEMERCS_IOW56 0x1503

#define __user

static inline void mutex_lock(pthread_mutex_t *mutex) { pthread_mutex_lock(mutex); }
static inline void mutex_unlock(pthread_mutex_t *mutex) { pthread_mutex_unlock(mutex); }
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline int copy_from_user(void *to, const void *from, size_t n) { memcpy(to, from, n); return 0; }
static inline int usb_set_report(void *intf, int type, int id, void *buf, size_t size) { return 0; }
static inline struct urb *usb_alloc_urb(int iso_packets, int mem_flags) { return calloc(1, sizeof(struct urb)); }
static inline void *usb_alloc_coherent(void *dev, size_t size, int mem_flags, void *dma) { return malloc(size); }
static inline void usb_fill_int_urb(struct urb *urb, void *dev, void *pipe, void *buf, int len, void *complete_fn, void *context, int interval) {}
static inline int usb_submit_urb(struct urb *urb, int mem_flags) { return 0; }
static inline void usb_free_urb(struct urb *urb) { free(urb); }
static inline void usb_free_coherent(void *dev, size_t size, void *addr, void *dma) { free(addr); }
static inline int wait_event_interruptible(pthread_cond_t cond, int condition) { return 0; }
static inline void wake_up_interruptible(pthread_cond_t *cond) { pthread_cond_signal(cond); }
static inline void dbg(const char *fmt, ...) {}
static inline void dev_err(void *dev, const char *fmt, ...) {}
static inline void iowarrior_write_callback(struct urb *urb) {}
static inline void *usb_sndintpipe(void *dev, unsigned char endpoint) { return NULL; }