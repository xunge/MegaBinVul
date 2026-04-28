#include <stdint.h>

#define CP2112_GPIO_CONFIG 0x02
#define CP2112_GPIO_CONFIG_LENGTH 3
#define HID_FEATURE_REPORT 3
#define HID_REQ_GET_REPORT 1
#define HID_REQ_SET_REPORT 9
#define EIO 5

typedef uint8_t u8;

struct gpio_chip;
struct hid_device;

struct cp2112_device {
    struct hid_device *hdev;
    u8 *in_out_buffer;
    int lock;
};

#define gpio_push_pull 0x00

static inline void spin_lock_irqsave(int *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(int *lock, unsigned long flags) {}
static inline void hid_err(struct hid_device *hdev, const char *fmt, ...) {}
static inline int hid_hw_raw_request(struct hid_device *hdev, int reportnum, u8 *buf, int len, int reporttype, int reqtype) { return 0; }
static inline struct cp2112_device *gpiochip_get_data(struct gpio_chip *chip) { return 0; }
static inline void cp2112_gpio_set(struct gpio_chip *chip, unsigned offset, int value) {}