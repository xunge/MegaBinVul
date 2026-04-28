#include <stdbool.h>
#include <stdint.h>

#define NUM_LEDS 4
#define LED_OFF_VALUE 0
#define BIT(n) (1UL << (n))

enum led_brightness {
    LED_OFF = LED_OFF_VALUE,
    LED_HALF,
    LED_FULL
};

struct device {
    struct device *parent;
};

struct hid_device;

struct work_struct {
    // minimal definition
};

struct led_classdev {
    struct device *dev;
};

struct bigben_device {
    struct led_classdev *leds[NUM_LEDS];
    unsigned long led_state;
    int lock;
    bool work_led;
    struct work_struct worker;
};

static inline struct hid_device *to_hid_device(struct device *dev) { return (struct hid_device *)0; }
static inline void *hid_get_drvdata(struct hid_device *hid) { return (void *)0; }
static inline void hid_err(struct hid_device *hid, const char *msg) {}
static inline void spin_lock_irqsave(int *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(int *lock, unsigned long flags) {}
static inline void schedule_work(struct work_struct *work) {}