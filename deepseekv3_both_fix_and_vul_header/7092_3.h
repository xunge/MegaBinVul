#include <stdbool.h>
#include <stdint.h>

#define NUM_LEDS 4

enum led_brightness {
    LED_OFF_VALUE = 0,
    LED_HALF,
    LED_FULL
};

#define LED_OFF LED_OFF_VALUE

struct device {
    struct device *parent;
};

struct hid_device;

struct led_classdev {
    struct device *dev;
};

struct bigben_device {
    struct led_classdev *leds[NUM_LEDS];
    uint32_t led_state;
    int lock;
    bool work_led;
    int worker;
};

#define BIT(n) (1 << (n))

void hid_err(struct hid_device *hid, const char *msg);
struct hid_device *to_hid_device(struct device *dev);
void *hid_get_drvdata(struct hid_device *hid);
void spin_lock_irqsave(int *lock, unsigned long flags);
void spin_unlock_irqrestore(int *lock, unsigned long flags);
void schedule_work(int *work);