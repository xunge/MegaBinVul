#include <stdlib.h>
#include <string.h>

struct usb_device {
    void *dev;
};

struct usbip_device {
    int dummy;
};

struct stub_device {
    struct usbip_device ud;
    struct usb_device *udev;
};

struct urb {
    void *transfer_buffer;
    void *setup_packet;
    void *context;
    struct usb_device *dev;
    int pipe;
    void (*complete)(struct urb *);
};

struct stub_priv {
    struct urb *urb;
};

struct usbip_header_basic {
    unsigned int ep;
    unsigned int direction;
    unsigned int seqnum;
};

struct usbip_header_cmd_submit {
    int transfer_buffer_length;
    int number_of_packets;
    unsigned char setup[8];
};

struct usbip_header {
    struct usbip_header_basic base;
    union {
        struct usbip_header_cmd_submit cmd_submit;
    } u;
};

enum {
    SDEV_EVENT_ERROR_MALLOC,
    SDEV_EVENT_ERROR_SUBMIT,
    USBIP_CMD_SUBMIT
};

enum usbip_dir {
    USBIP_DIR_IN,
    USBIP_DIR_OUT
};

#define GFP_KERNEL 0

static inline int usb_pipeisoc(int pipe) { return 0; }
static inline void usbip_event_add(struct usbip_device *ud, int event) {}
static inline int usbip_recv_xbuff(struct usbip_device *ud, struct urb *urb) { return 0; }
static inline int usbip_recv_iso(struct usbip_device *ud, struct urb *urb) { return 0; }
static inline void tweak_special_requests(struct urb *urb) {}
static inline void masking_bogus_flags(struct urb *urb) {}
static inline void usbip_dump_header(struct usbip_header *pdu) {}
static inline void usbip_dump_urb(struct urb *urb) {}
static inline void usbip_pack_pdu(struct usbip_header *pdu, struct urb *urb, int cmd, int pack) {}
static inline void usbip_dbg_stub_rx(const char *fmt, ...) {}
static inline struct stub_priv *stub_priv_alloc(struct stub_device *sdev, struct usbip_header *pdu) { return malloc(sizeof(struct stub_priv)); }
static inline int get_pipe(struct stub_device *sdev, unsigned int ep, unsigned int dir) { return 0; }
static inline struct urb *usb_alloc_urb(int iso_packets, int flags) { return malloc(sizeof(struct urb)); }
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void *kmemdup(const void *src, size_t len, int flags) { void *dst = malloc(len); if (dst) memcpy(dst, src, len); return dst; }
static inline int usb_submit_urb(struct urb *urb, int flags) { return 0; }
static inline void stub_complete(struct urb *urb) {}
static inline void dev_err(void *dev, const char *fmt, ...) {}