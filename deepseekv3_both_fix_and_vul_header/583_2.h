#include <stdbool.h>

struct usb_line6;
struct usb_line6_toneport {
    int pcm_work;
};

bool toneport_has_led(struct usb_line6_toneport *toneport);
void toneport_remove_leds(struct usb_line6_toneport *toneport);
void cancel_delayed_work_sync(int *work);