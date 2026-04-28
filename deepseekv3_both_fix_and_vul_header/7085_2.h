#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint32_t u32;

struct work_struct {
    // Minimal definition for compilation
};

struct hid_field {
    u8* value;
    // Other minimal fields
};

struct hid_report {
    struct hid_field** field;
    u8 id;
    u8 type;
    // Other minimal fields
};

struct hid_device {
    // Minimal definition
};

struct bigben_device {
    struct work_struct worker;
    struct hid_device *hid;
    struct hid_report *report;
    int lock;
    bool removed;
    bool work_led;
    bool work_ff;
    u8 led_state;
    bool right_motor_on;
    u8 left_motor_force;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define GFP_KERNEL 0
#define HID_REQ_SET_REPORT 0

static void spin_lock_irqsave(int *lock, unsigned long flags) {}
static void spin_unlock_irqrestore(int *lock, unsigned long flags) {}
static u8* hid_alloc_report_buf(struct hid_report *report, int flags) { return NULL; }
static u32 hid_report_len(struct hid_report *report) { return 0; }
static void hid_output_report(struct hid_report *report, u8 *buf) {}
static void hid_hw_raw_request(struct hid_device *hid, u8 id, u8 *buf, u32 len, u8 type, int req) {}
static void kfree(void *buf) {}