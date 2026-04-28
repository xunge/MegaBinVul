#include <stdint.h>
#include <stddef.h>
#include <errno.h>

#define KEY_MAX 0x2ff
#define KEY_RESERVED 0
#define EV_KEY 0x01
#define EV_SYN 0x00
#define SYN_REPORT 0x00

struct device {
    struct device *parent;
};

struct input_dev {
    struct device dev;
    unsigned long *keybit;
    unsigned long *evbit;
    unsigned long *key;
    void *event_lock;
    int (*setkeycode)(struct input_dev *, const struct input_keymap_entry *, unsigned int *);
};

struct input_keymap_entry {
    uint32_t keycode;
};

struct input_value {
    uint16_t type;
    uint16_t code;
    int32_t value;
};

extern int is_event_supported(unsigned int code, unsigned long *bitmap, unsigned int max);
extern void input_pass_values(struct input_dev *dev, struct input_value *vals, unsigned int count);
extern void dev_warn(struct device *dev, const char *fmt, ...);
extern void __clear_bit(unsigned long nr, volatile unsigned long *addr);
extern int __test_and_clear_bit(unsigned long nr, volatile unsigned long *addr);
extern int test_bit(unsigned int nr, const volatile unsigned long *addr);
extern void spin_lock_irqsave(void *lock, unsigned long flags);
extern void spin_unlock_irqrestore(void *lock, unsigned long flags);

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

static const struct input_value input_value_sync = { EV_SYN, SYN_REPORT, 0 };