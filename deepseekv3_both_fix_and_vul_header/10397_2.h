#include <stdint.h>
#include <stddef.h>

#define CP2112_GPIO_SET 0x01
#define CP2112_GPIO_SET_LENGTH 3
#define HID_FEATURE_REPORT 3
#define HID_REQ_SET_REPORT 9

typedef uint8_t u8;

struct gpio_chip;
struct hid_device;

struct cp2112_device {
    struct hid_device *hdev;
    u8 *in_out_buffer;
    int lock;
};

int hid_hw_raw_request(struct hid_device *hdev, unsigned char reportnum, u8 *buf, size_t len, unsigned char rtype, int reqtype);
void hid_err(struct hid_device *hdev, const char *fmt, ...);
void *gpiochip_get_data(struct gpio_chip *chip);

#define spin_lock_irqsave(lock, flags) (void)flags
#define spin_unlock_irqrestore(lock, flags) (void)flags