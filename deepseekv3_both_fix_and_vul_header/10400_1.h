#include <stdint.h>

struct gpio_chip;
struct hid_device;

struct cp2112_device {
    struct hid_device *hdev;
    uint8_t *in_out_buffer;
    int lock;
};

#define CP2112_GPIO_GET 0x00
#define CP2112_GPIO_GET_LENGTH 2
#define HID_FEATURE_REPORT 0
#define HID_REQ_GET_REPORT 0
#define EIO 5

typedef uint8_t u8;

static inline void spin_lock_irqsave(int *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(int *lock, unsigned long flags) {}
static inline int hid_hw_raw_request(struct hid_device *hdev, int req, uint8_t *buf, int len, int type, int rtype) { return 0; }
static inline void hid_err(struct hid_device *hdev, const char *fmt, ...) {}
static inline struct cp2112_device *gpiochip_get_data(struct gpio_chip *chip) { return 0; }