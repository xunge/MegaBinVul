#include <stdint.h>
#include <string.h>

#define ON 1
#define ENOMEM 12

typedef uint8_t u8;
typedef uint16_t u16;

struct urb {
    void *transfer_buffer;
    int transfer_buffer_length;
    int actual_length;
    void *setup_packet;
};

struct usb_ctrlrequest {
    u8 bRequestType;
    u8 bRequest;
    u16 wValue;
    u16 wIndex;
    u16 wLength;
};

struct oz_port {
    void *hpd;
    struct ozhcd *ozhcd;
};

struct ozhcd {
    void *hcd;
};

int oz_dbg(int level, const char *fmt, ...);
struct urb *oz_find_urb_by_id(struct oz_port *port, int ep_num, u8 req_id);
int oz_enqueue_ep_urb(struct oz_port *port, int ep_num, int in_dir, struct urb *urb, u8 req_id);
int oz_usb_get_desc_req(void *hpd, u8 req_id, u8 req_type, u8 desc_type, u8 index, u16 windex, int offset, int len);
void oz_dequeue_ep_urb(struct oz_port *port, int ep_num, int in_dir, struct urb *urb);
void oz_complete_urb(void *hcd, struct urb *urb, int status);

static inline u16 le16_to_cpu(u16 val) { return val; }