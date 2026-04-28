#include <stdint.h>
#include <stddef.h>

typedef uint16_t u16;
typedef uint8_t u8;

struct oz_pd {
    void *app_ctx[1];
    int app_lock[1];
};

struct oz_elt {
    int length;
};

struct oz_usb_hdr {
    u8 type;
    u8 elt_seq_num;
};

struct oz_usb_ctx {
    int stopped;
    u8 rx_seq_num;
    void *hport;
};

struct oz_get_desc_rsp {
    u16 offset;
    u16 total_size;
    u8 req_id;
    u8 rcode;
    u8 data[0];
};

struct oz_set_config_rsp {
    u8 req_id;
    u8 rcode;
};

struct oz_set_interface_rsp {
    u8 req_id;
    u8 rcode;
};

struct oz_vendor_class_rsp {
    u8 req_id;
    u8 rcode;
    u8 data[0];
};

#define OZ_APPID_USB 0
#define ON 1

enum {
    OZ_GET_DESC_RSP,
    OZ_SET_CONFIG_RSP,
    OZ_SET_INTERFACE_RSP,
    OZ_VENDOR_CLASS_RSP,
    OZ_USB_ENDPOINT_DATA
};

static inline void spin_lock_bh(int *lock) {}
static inline void spin_unlock_bh(int *lock) {}
static inline void oz_usb_get(struct oz_usb_ctx *ctx) {}
static inline void oz_usb_put(struct oz_usb_ctx *ctx) {}
static inline void oz_dbg(int level, const char *fmt, ...) {}
static inline void oz_hcd_get_desc_cnf(void *hport, int req_id, int rcode, void *data, int len, u16 offs, u16 total_size) {}
static inline void oz_hcd_control_cnf(void *hport, int req_id, int rcode, void *data, int len) {}
static inline void oz_usb_handle_ep_data(struct oz_usb_ctx *ctx, struct oz_usb_hdr *hdr, int len) {}
static inline u16 le16_to_cpu(u16 val) { return val; }
static inline u16 get_unaligned(const u16 *p) { return *p; }