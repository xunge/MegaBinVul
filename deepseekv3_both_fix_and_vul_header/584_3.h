#include <stddef.h>

struct work_struct {
    void *data;
    void (*func)(struct work_struct *work);
};

struct usb_line6 {
    void (*disconnect)(struct usb_line6 *);
    void (*startup)(struct usb_line6 *);
    struct snd_card *card;
    void *line6pcm;
};

struct usb_line6_toneport {
    int type;
    int serial_number;
    int firmware_version;
    struct work_struct pcm_work;
};

struct usb_device_id {
    int driver_info;
};

struct snd_card;
struct snd_kcontrol;
struct snd_kcontrol_new;

extern int line6_init_pcm(struct usb_line6 *line6, void *properties);
extern int snd_ctl_add(struct snd_card *card, struct snd_kcontrol *kctl);
extern struct snd_kcontrol *snd_ctl_new1(const struct snd_kcontrol_new *ncontrol, void *private_data);
extern int snd_card_register(struct snd_card *card);
extern void line6_read_serial_number(struct usb_line6 *line6, int *serial_number);
extern void line6_read_data(struct usb_line6 *line6, int address, int *data, int size);

extern const struct snd_kcontrol_new toneport_control_monitor;
extern const struct snd_kcontrol_new toneport_control_source;
extern const void *toneport_pcm_properties;

extern int toneport_has_source_select(struct usb_line6_toneport *toneport);
extern int toneport_has_led(struct usb_line6_toneport *toneport);
extern int toneport_init_leds(struct usb_line6_toneport *toneport);
extern int toneport_setup(struct usb_line6_toneport *toneport);
extern void line6_toneport_disconnect(struct usb_line6 *line6);
extern void toneport_startup(struct usb_line6 *line6);
extern void toneport_start_pcm(struct work_struct *work);
extern void INIT_DELAYED_WORK(struct work_struct *work, void (*func)(struct work_struct *));