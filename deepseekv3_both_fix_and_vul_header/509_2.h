#include <stdlib.h>

struct usb_ep;
struct usb_request {
    void *buf;
};

void usb_ep_free_request(struct usb_ep *ep, struct usb_request *req);