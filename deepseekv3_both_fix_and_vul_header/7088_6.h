#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#define NUM_LEDS 4
#define LED_ON 1
#define LED_OFF 0
#define GFP_KERNEL 0
#define ENOMEM 12
#define ENODEV 19
#define BIT(n) (1UL << (n))
#define HID_CONNECT_DEFAULT 0
#define HID_CONNECT_FF 0
#define HID_OUTPUT_REPORT 0
#define FF_RUMBLE 0

struct list_head {
    struct list_head *next, *prev;
};

struct device {
    const char *name;
};

struct hid_device_id {
    unsigned int dummy;
};

struct hid_report_enum {
    struct list_head report_list;
};

struct hid_device {
    struct device dev;
    struct hid_report_enum report_enum[1];
    struct list_head inputs;
};

struct input_dev {
    unsigned long ffbit;
};

struct hid_input {
    struct list_head list;
    struct input_dev *input;
};

struct hid_report {
    struct list_head list;
};

struct work_struct {
    unsigned long data;
};

struct spinlock {
    unsigned long lock;
};

struct led_classdev {
    const char *name;
    int brightness;
    int max_brightness;
    int (*brightness_get)(struct led_classdev *led_cdev);
    int (*brightness_set)(struct led_classdev *led_cdev, int brightness);
};

struct bigben_device {
    struct hid_device *hid;
    struct hid_report *report;
    struct led_classdev *leds[NUM_LEDS];
    unsigned long led_state;
    unsigned char right_motor_on;
    unsigned char left_motor_force;
    bool work_led;
    bool work_ff;
    bool removed;
    struct spinlock lock;
    struct work_struct worker;
};

int bigben_get_led(struct led_classdev *led_cdev);
int bigben_set_led(struct led_classdev *led_cdev, int brightness);
void bigben_worker(struct work_struct *work);
int hid_bigben_play_effect(struct input_dev *dev, void *data, void *effect);

#define INIT_WORK(_work, _func) ((void)0)
#define spin_lock_init(_lock) ((void)0)
#define list_empty(_list) (1)
#define list_first_entry(_list, _type, _member) ((_type *)0)
#define list_entry(_ptr, _type, _member) ((_type *)0)
#define set_bit(nr, addr) ((void)0)

static inline void *devm_kzalloc(struct device *dev, size_t size, int flags) { return NULL; }
static inline void hid_set_drvdata(struct hid_device *hid, void *data) {}
static inline int hid_parse(struct hid_device *hid) { return 0; }
static inline int hid_hw_start(struct hid_device *hid, int connect_mask) { return 0; }
static inline void hid_hw_stop(struct hid_device *hid) {}
static inline void hid_err(struct hid_device *hid, const char *fmt, ...) {}
static inline void hid_info(struct hid_device *hid, const char *fmt, ...) {}
static inline int input_ff_create_memless(struct input_dev *dev, void *data, int (*play_effect)(struct input_dev *dev, void *data, void *effect)) { return 0; }
static inline int devm_led_classdev_register(struct device *dev, struct led_classdev *led_cdev) { return 0; }
static inline void schedule_work(struct work_struct *work) {}
static inline const char *dev_name(const struct device *dev) { return ""; }