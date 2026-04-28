#include <stdint.h>
#include <stdbool.h>

#define FF_RUMBLE 0x50

typedef uint8_t u8;

struct input_dev;
struct hid_device;

struct ff_effect {
    uint16_t type;
    struct {
        struct {
            uint16_t weak_magnitude;
            uint16_t strong_magnitude;
        } rumble;
    } u;
};

struct work_struct {
    // Minimal stub definition
    void *data;
};

struct bigben_device {
    bool right_motor_on;
    u8 left_motor_force;
    bool work_ff;
    struct work_struct worker;
    unsigned long lock;
};

// Stub functions to satisfy compilation
static inline void *input_get_drvdata(struct input_dev *dev) { return 0; }
static inline void *hid_get_drvdata(struct hid_device *hid) { return 0; }
static inline void hid_err(struct hid_device *hid, const char *msg) {}
static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) {}
static inline void schedule_work(struct work_struct *work) {}