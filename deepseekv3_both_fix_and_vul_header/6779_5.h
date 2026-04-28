#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct stub_device;
struct stub_priv;
struct usbip_header;
struct usbip_iso_packet_descriptor;
struct usb_device;
struct device;
struct socket;

struct list_head {
    struct list_head *next, *prev;
};

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = container_of((head)->next, struct stub_priv, member), \
        n = container_of(pos->member.next, struct stub_priv, member); \
        &pos->member != (head); \
        pos = n, n = container_of(n->member.next, struct stub_priv, member))

enum {
    PIPE_ISOCHRONOUS,
    PIPE_INTERRUPT,
    PIPE_CONTROL,
    PIPE_BULK
};

enum {
    SDEV_EVENT_ERROR_MALLOC,
    SDEV_EVENT_ERROR_TCP
};

struct usbip_header {
    struct {
        unsigned int seqnum;
    } base;
};

struct usb_iso_packet_descriptor {
    unsigned int offset;
    unsigned int length;
    unsigned int actual_length;
    int status;
};

struct urb {
    void *transfer_buffer;
    int actual_length;
    int pipe;
    int number_of_packets;
    struct usb_iso_packet_descriptor *iso_frame_desc;
};

struct kvec {
    void *iov_base;
    size_t iov_len;
};

struct msghdr {
    void *msg_name;
    int msg_namelen;
    struct iovec *msg_iov;
    size_t msg_iovlen;
    void *msg_control;
    size_t msg_controllen;
    unsigned int msg_flags;
};

struct usb_device {
    struct device *dev;
};

struct stub_device {
    unsigned long priv_lock;
    struct list_head priv_free;
    struct {
        struct socket *tcp_socket;
    } ud;
    struct usb_device *udev;
};

struct stub_priv {
    struct list_head list;
    struct urb *urb;
};

#define GFP_KERNEL 0
#define kcalloc(n, size, flags) calloc(n, size)
#define kfree free

static inline int usb_pipetype(int pipe) { return PIPE_ISOCHRONOUS; }
static inline int usb_pipein(int pipe) { return 1; }
static inline void usbip_event_add(void *ud, int event) {}
static inline void setup_ret_submit_pdu(void *hdr, void *urb) {}
static inline void usbip_dbg_stub_tx(const char *fmt, ...) {}
static inline void usbip_header_correct_endian(void *hdr, int dir) {}
static inline void *usbip_alloc_iso_desc_pdu(void *urb, ssize_t *len) { return NULL; }
static inline int kernel_sendmsg(void *sock, void *msg, void *iov, int iovnum, size_t size) { return 0; }
static inline void dev_err(void *dev, const char *fmt, ...) {}
static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) {}
static inline void stub_free_priv_and_urb(struct stub_priv *priv) {}
static inline struct stub_priv *dequeue_from_priv_tx(struct stub_device *sdev) { return NULL; }