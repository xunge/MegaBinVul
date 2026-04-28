#include <stddef.h>

struct usb_interface;

struct frame_buffer {
    int status;
    unsigned long length;
};

struct camera_data {
    void *v4l2_dev;
    void *v4l2_lock;
    void *wq_stream;
    struct frame_buffer *buffers;
    struct frame_buffer *curbuff;
};

#define FRAME_READY 1
#define DBG(fmt, ...) 
#define LOG(fmt, ...) 

static inline void *usb_get_intfdata(struct usb_interface *intf) { return NULL; }
static inline void usb_set_intfdata(struct usb_interface *intf, void *data) {}
static inline void mutex_lock(void *lock) {}
static inline void mutex_unlock(void *lock) {}
static inline void v4l2_device_disconnect(void *dev) {}
static inline void v4l2_device_put(void *dev) {}
static inline void wake_up_interruptible(void *wq) {}

extern int cpia2_usb_stream_stop(struct camera_data *cam);
extern int cpia2_unregister_camera(struct camera_data *cam);