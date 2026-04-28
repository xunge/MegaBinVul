#include <stdint.h>
#include <stddef.h>
#include <errno.h>

#define CP2112_GPIO_CONFIG 0x02
#define CP2112_GPIO_CONFIG_LENGTH 3
#define HID_FEATURE_REPORT 1
#define HID_REQ_GET_REPORT 1
#define HID_REQ_SET_REPORT 2

typedef uint8_t u8;

struct gpio_chip;
struct hid_device;

struct cp2112_device {
    struct hid_device *hdev;
    u8 *in_out_buffer;
    int lock;
};

extern int gpio_push_pull;
extern void spin_lock_irqsave(int *lock, unsigned long flags);
extern void spin_unlock_irqrestore(int *lock, unsigned long flags);
extern struct cp2112_device* gpiochip_get_data(struct gpio_chip *chip);
extern int hid_hw_raw_request(struct hid_device *hdev, unsigned char reportnum, u8 *buf, size_t len, unsigned char rtype, int reqtype);
extern void hid_err(struct hid_device *hdev, const char *fmt, ...);