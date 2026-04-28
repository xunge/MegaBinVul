#include <stdlib.h>
#include <stdint.h>
#include <time.h>

typedef uint32_t u32;

struct usb_device;
struct usb_line6 {
    struct usb_device *usbdev;
    void *startup_work;
};

struct usb_line6_toneport {
    struct usb_line6 line6;
    int source;
    void *pcm_work;
};

#define GFP_KERNEL 0
#define ENOMEM 12
#define TONEPORT_PCM_DELAY 1

extern void *kmalloc(size_t size, int flags);
extern void kfree(void *ptr);
extern time_t ktime_get_real_seconds(void);
extern unsigned long msecs_to_jiffies(unsigned int msecs);
extern void schedule_delayed_work(void *work, unsigned long delay);

extern int toneport_send_cmd(struct usb_device *dev, uint16_t cmd1, uint16_t cmd2);
extern int toneport_has_source_select(struct usb_line6_toneport *toneport);
extern int toneport_has_led(struct usb_line6_toneport *toneport);
extern void toneport_update_led(struct usb_line6_toneport *toneport);
extern int line6_write_data(struct usb_line6 *line6, uint16_t address, void *data, size_t datalen);

struct toneport_source_info {
    uint16_t code;
};

extern struct toneport_source_info toneport_source_info[];