#include <stdbool.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct usb_request {
    int status;
};

struct usb_ep {
    // Minimal definition to make it complete
    int dummy;
};

struct dwc3 {
    void *sysdev;
    void *lock;
    void *dev;
};

struct dwc3_ep {
    struct dwc3 *dwc;
    int number;
    struct usb_ep endpoint;
};

struct dwc3_request {
    bool started;
    struct list_head list;
    int remaining;
    struct usb_request request;
    void *trb;
    int direction;
};

static inline void list_del(struct list_head *entry) {
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
}

#define EINPROGRESS 115

void usb_gadget_unmap_request_by_dev(void *sysdev, struct usb_request *req, int direction);
void usb_gadget_giveback_request(struct usb_ep *ep, struct usb_request *req);
void spin_unlock(void *lock);
void spin_lock(void *lock);
void pm_runtime_put(void *dev);
void trace_dwc3_gadget_giveback(struct dwc3_request *req);