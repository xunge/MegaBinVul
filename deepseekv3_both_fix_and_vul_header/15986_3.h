#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define FMODE_READ 1
#define FMODE_WRITE 2
#define O_NONBLOCK 04000
#define ENODEV 19
#define EBUSY 16
#define ENOMEM 12
#define EIO 5
#define ETIMEDOUT 110
#define USB_DIR_OUT 0
#define BUF_SIZE_ORDER 0
#define BUFNUM 0
#define XILLY_RESPONSE_TIMEOUT 0
#define OPCODE_SET_CHECKPOINT 0
#define OPCODE_SET_PUSH 0
#define GFP_KERNEL 0

typedef uint32_t u32;

struct kref {
    int count;
};

struct mutex {
    int lock;
};

struct inode {
    int dummy;
};

struct file {
    void *private_data;
    int f_mode;
    int f_flags;
};

struct device {
    int dummy;
};

struct xillyfifo {
    size_t size;
};

struct xillyusb_endpoint {
    struct xillyfifo fifo;
    int fill_mask;
};

struct xillyusb_channel {
    struct mutex lock;
    int readable;
    int writable;
    int in_synchronous;
    int out_synchronous;
    int open_for_read;
    int open_for_write;
    struct xillyfifo *in_fifo;
    struct xillyusb_endpoint *out_ep;
    int chan_idx;
    int out_log2_fifo_size;
    int out_log2_element_size;
    int in_log2_fifo_size;
    int in_log2_element_size;
    int out_bytes;
    int flushed;
    int read_data_ok;
    int poll_used;
    u32 in_consumed_bytes;
    u32 in_current_checkpoint;
};

struct xillyusb_dev {
    struct kref kref;
    struct xillyusb_channel *channels;
    struct device *dev;
    int error;
};

extern void bulk_out_work(void);

extern struct mutex kref_mutex;
extern int xillybus_find_inode(struct inode *, void **, int *);
extern int fifo_init(struct xillyfifo *, int);
extern void fifo_mem_release(struct xillyfifo *);
extern struct xillyusb_endpoint *endpoint_alloc(struct xillyusb_dev *, int, void *, int, int);
extern void endpoint_dealloc(struct xillyusb_endpoint *);
extern int flush_downstream(struct xillyusb_channel *, int, bool);
extern void report_io_error(struct xillyusb_dev *, int);
extern int xillyusb_send_opcode(struct xillyusb_dev *, int, int, u32);
extern void request_read_anything(struct xillyusb_channel *, int);
extern void safely_assign_in_fifo(struct xillyusb_channel *, struct xillyfifo *);
extern void cleanup_dev(struct kref *);
extern void mutex_lock(struct mutex *);
extern void mutex_unlock(struct mutex *);
extern void kref_get(struct kref *);
extern void kref_put(struct kref *, void (*)(struct kref *));
extern void *kzalloc(size_t, int);
extern void kfree(void *);
extern void dev_err(struct device *, const char *);