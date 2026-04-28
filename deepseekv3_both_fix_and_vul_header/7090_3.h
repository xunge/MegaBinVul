#include <stdint.h>
#include <stdbool.h>

#define FF_RUMBLE 0x50

struct ff_effect {
    uint16_t type;
    union {
        struct {
            uint16_t weak_magnitude;
            uint16_t strong_magnitude;
        } rumble;
    } u;
};

struct input_dev;
struct hid_device;

struct bigben_device {
    bool right_motor_on;
    uint8_t left_motor_force;
    bool work_ff;
    int lock;
    void *worker;
};

typedef uint8_t u8;

static inline void spin_lock_irqsave(int *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(int *lock, unsigned long flags) {}
static inline void schedule_work(void *work) {}
static inline void *input_get_drvdata(struct input_dev *dev) { return 0; }
static inline void *hid_get_drvdata(struct hid_device *hid) { return 0; }
static inline void hid_err(struct hid_device *hid, const char *msg) {}