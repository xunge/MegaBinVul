#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define GFP_KERNEL 0
#define HID_REQ_SET_REPORT 9

typedef uint8_t u8;
typedef uint32_t u32;

#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

struct work_struct {
    // minimal stub definition
};

struct hid_field {
    u8 *value;
};

struct hid_report {
    struct hid_field **field;
    unsigned int id;
    unsigned int type;
};

struct hid_device {
    // minimal stub definition
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
    u8 right_motor_on;
    u8 left_motor_force;
};

static inline void spin_lock_irqsave(int *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(int *lock, unsigned long flags) {}
static inline u8 *hid_alloc_report_buf(struct hid_report *report, int gfp) { return NULL; }
static inline u32 hid_report_len(struct hid_report *report) { return 0; }
static inline void hid_output_report(struct hid_report *report, u8 *buf) {}
static inline void hid_hw_raw_request(struct hid_device *hid, unsigned int id, u8 *buf, u32 len, unsigned int type, int req) {}
static inline void kfree(void *ptr) {}