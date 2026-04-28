#include <stddef.h>
#include <stdbool.h>
#include <errno.h>

struct work_struct {
    // Minimal definition to make it compile
    unsigned long data;
};

struct usb_request {
    int status;
    int actual;
};

struct mm_struct {
    // Minimal definition
};

struct iov_iter {
    // Minimal definition
};

struct kiocb {
    void (*ki_complete)(struct kiocb *, long, long);
    unsigned int ki_flags;
    void *private;
};

struct ffs_data {
    void *ffs_eventfd;
};

struct usb_ep {
    // Minimal definition
};

struct eventfd_ctx {
    // Minimal definition
};

struct ffs_io_data {
    struct work_struct work;
    struct usb_request *req;
    struct mm_struct *mm;
    bool read;
    void *buf;
    struct iov_iter data;
    struct kiocb *kiocb;
    struct ffs_data *ffs;
    struct usb_ep *ep;
    void *to_free;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define EFAULT 14
#define IOCB_EVENTFD (1 << 0)

// Dummy function declarations to satisfy compiler
void use_mm(struct mm_struct *mm);
void unuse_mm(struct mm_struct *mm);
long copy_to_iter(const void *from, size_t len, struct iov_iter *iter);
size_t iov_iter_count(struct iov_iter *iter);
void eventfd_signal(struct eventfd_ctx *ctx, int count);
void usb_ep_free_request(struct usb_ep *ep, struct usb_request *req);
void kfree(const void *obj);