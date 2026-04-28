#include <stddef.h>

struct ath10k;
struct ath10k_usb {
    struct ath10k_usb_pipe *pipes;
    void *udev;
};
struct ath10k_usb_pipe {
    unsigned int usb_pipe_handle;
    unsigned int max_packet_size;
    void *urb_submitted;
};
struct ath10k_urb_context {
    struct ath10k_usb_pipe *pipe;
    struct sk_buff *skb;
};
struct ath10k_hif_sg_item {
    void *transfer_context;
};
struct sk_buff {
    void *data;
    unsigned int len;
};
struct urb {
    unsigned int transfer_flags;
};

#define ENOMEM 1
#define EINVAL 2
#define GFP_ATOMIC 0
#define URB_ZERO_PACKET 0
#define ATH10K_DBG_USB_BULK 0

typedef unsigned char u8;

static inline void ath10k_dbg(struct ath10k *ar, int level, const char *fmt, ...) {}
static inline struct ath10k_usb *ath10k_usb_priv(struct ath10k *ar) { return NULL; }
static inline struct ath10k_urb_context *ath10k_usb_alloc_urb_from_pipe(struct ath10k_usb_pipe *pipe) { return NULL; }
static inline void ath10k_usb_free_urb_to_pipe(struct ath10k_usb_pipe *pipe, struct ath10k_urb_context *urb_context) {}
static inline void ath10k_usb_transmit_complete(struct urb *urb) {}
static inline struct urb *usb_alloc_urb(int iso_packets, int mem_flags) { return NULL; }
static inline void usb_fill_bulk_urb(struct urb *urb, void *dev, unsigned int pipe, void *transfer_buffer, int buffer_length, void *complete_fn, void *context) {}
static inline void usb_anchor_urb(struct urb *urb, void *anchor) {}
static inline int usb_submit_urb(struct urb *urb, int mem_flags) { return 0; }
static inline void usb_unanchor_urb(struct urb *urb) {}
static inline void usb_free_urb(struct urb *urb) {}