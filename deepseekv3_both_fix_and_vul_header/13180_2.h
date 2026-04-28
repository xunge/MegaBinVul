#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define FEATURE_KBD_REPORT_ID 0x5a
#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

typedef uint8_t u8;

struct work_struct {
    // dummy definition
};

struct hid_device {
    // dummy definition
};

struct asus_kbd_leds {
    struct work_struct work;
    struct hid_device *hdev;
    u8 brightness;
    bool removed;
    int lock;
};

// Dummy function declarations to satisfy compiler
static void spin_lock_irqsave(int *lock, unsigned long flags);
static void spin_unlock_irqrestore(int *lock, unsigned long flags);
static int asus_kbd_set_report(struct hid_device *hdev, u8 *buf, size_t size);
static void hid_err(struct hid_device *hdev, const char *fmt, ...);