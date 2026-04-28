#include <string.h>

#define WHITEHEAT_CMD_COMPLETE 0
#define WHITEHEAT_CMD_FAILURE 1
#define WHITEHEAT_EVENT 2
#define WHITEHEAT_GET_DTR_RTS 3
#define GFP_ATOMIC 0
#define ENOENT 2

struct urb {
    int status;
    void *context;
    unsigned char *transfer_buffer;
    int actual_length;
    struct {
        struct {
            struct {
                int dev;
            } *dev;
        } dev;
    } *dev;
};

struct usb_serial_port {
    struct urb *read_urb;
    int dev;
};

struct whiteheat_command_private {
    int command_finished;
    int wait_command;
    unsigned char result_buffer[256];
};

static inline void wake_up(int *wait) {}
static inline void dev_dbg(void *dev, const char *fmt, ...) {}
static inline void usb_serial_debug_data(void *dev, const char *func, int len, unsigned char *data) {}
static inline void *usb_get_serial_port_data(struct usb_serial_port *port) { return 0; }
static inline int usb_submit_urb(struct urb *urb, int flags) { return 0; }