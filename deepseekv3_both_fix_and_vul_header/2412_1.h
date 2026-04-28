#include <stdlib.h>

struct urb {
    void *transfer_buffer;
};

struct usb_mixer_interface {
    struct urb *urb;
    struct urb *rc_urb;
    void *id_elems;
    void *rc_setup_packet;
};