#include <stdint.h>
#include <string.h>

#define REPORT_KEY_STATE 0
#define REPORT_IR_DATA 0

typedef uint8_t u8;

struct hid_device {
    void *driver_data;
};

struct hid_report {
    int id;
};

struct input_dev;

struct picolcd_pending {
    u8 *raw_data;
    int raw_size;
    struct hid_report *in_report;
    int ready;
};

struct picolcd_data {
    struct input_dev *input_keys;
    int lock;
    struct picolcd_pending *pending;
};

static inline void *hid_get_drvdata(struct hid_device *hdev) {
    return hdev->driver_data;
}

static inline void spin_lock_irqsave(int *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(int *lock, unsigned long flags) {}
static inline void complete(int *ready) {}

static inline int picolcd_raw_keypad(struct picolcd_data *data, 
                                   struct hid_report *report,
                                   u8 *raw_data, int size) {
    return 0;
}

static inline int picolcd_raw_cir(struct picolcd_data *data,
                                struct hid_report *report,
                                u8 *raw_data, int size) {
    return 0;
}

static inline void picolcd_debug_raw_event(struct picolcd_data *data,
                                         struct hid_device *hdev,
                                         struct hid_report *report,
                                         u8 *raw_data, int size) {}