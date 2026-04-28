#include <stdbool.h>

struct urb;
struct usb_mixer_interface {
    bool disconnected;
    struct urb *urb;
    struct urb *rc_urb;
};