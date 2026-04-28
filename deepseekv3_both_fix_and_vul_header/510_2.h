#include <stddef.h>
#include <stdint.h>

struct usb_function;
struct kfifo {
    unsigned char *buffer;
    unsigned int size;
    unsigned int in;
    unsigned int out;
};

struct f_midi {
    unsigned int ms_id;
    struct usb_ep *in_ep;
    struct usb_ep *out_ep;
    unsigned int qlen;
    unsigned int buflen;
    struct kfifo in_req_fifo;
};

struct usb_request {
    void *buf;
    unsigned int length;
    void (*complete)(struct usb_ep *, struct usb_request *);
};

struct usb_ep {
    char *name;
};

#define ENOMEM 12
#define GFP_ATOMIC 0

#define ERROR(midi, fmt, ...) 

extern struct f_midi *func_to_midi(struct usb_function *f);
extern int f_midi_start_ep(struct f_midi *midi, struct usb_function *f, struct usb_ep *ep);
extern struct usb_request *midi_alloc_ep_req(struct usb_ep *ep, int buflen);
extern void f_midi_complete(struct usb_ep *ep, struct usb_request *req);
extern void free_ep_req(struct usb_ep *ep, struct usb_request *req);
extern int usb_ep_queue(struct usb_ep *ep, struct usb_request *req, int gfp_flags);
extern int kfifo_avail(struct kfifo *fifo);
extern int kfifo_put(struct kfifo *fifo, struct usb_request *req);