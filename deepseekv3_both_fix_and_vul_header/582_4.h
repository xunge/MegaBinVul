#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct usb_interface {
    struct {
        int dummy;
    } dev;
};

struct usb_device;
struct urb;
struct snd_card;
struct work_struct {
    unsigned long data;
    struct list_head entry;
    void (*func)(struct work_struct *work);
};

struct usb_line6 {
    struct usb_device *usbdev;
    struct delayed_work {
        struct work_struct work;
    } startup_work;
    struct urb *urb_listen;
    struct snd_card *card;
    void *line6pcm;
    void (*disconnect)(struct usb_line6 *);
    struct {
        const char *name;
    } *properties;
};

void *usb_get_intfdata(struct usb_interface *interface);
struct usb_device *interface_to_usbdev(struct usb_interface *interface);
int WARN_ON(int condition);
void cancel_delayed_work(struct delayed_work *work);
void line6_stop_listen(struct usb_line6 *line6);
void snd_card_disconnect(struct snd_card *card);
void line6_pcm_disconnect(void *line6pcm);
void dev_info(const void *dev, const char *fmt, ...);
void usb_set_intfdata(struct usb_interface *interface, void *data);
void snd_card_free_when_closed(struct snd_card *card);