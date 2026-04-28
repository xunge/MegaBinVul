#include <stdint.h>
#include <pthread.h>

#define CP2112_GPIO_CONFIG 0x05
#define CP2112_GPIO_CONFIG_LENGTH 3
#define HID_FEATURE_REPORT 1
#define HID_REQ_GET_REPORT 1
#define HID_REQ_SET_REPORT 2
#define EIO 5

typedef uint8_t u8;

struct gpio_chip;
struct hid_device;

struct cp2112_device {
    struct hid_device *hdev;
    u8 *in_out_buffer;
    pthread_mutex_t lock;
};

extern u8 gpio_push_pull;

void hid_err(struct hid_device *hdev, const char *format, ...);
int hid_hw_raw_request(struct hid_device *hdev, unsigned char reportnum, u8 *buf, size_t len, unsigned char rtype, int reqtype);
void *gpiochip_get_data(struct gpio_chip *chip);

static inline void mutex_lock(pthread_mutex_t *mutex) {
    pthread_mutex_lock(mutex);
}

static inline void mutex_unlock(pthread_mutex_t *mutex) {
    pthread_mutex_unlock(mutex);
}