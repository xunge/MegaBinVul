#include <stddef.h>

enum led_brightness {
    LED_OFF,
    LED_HALF,
    LED_FULL
};

struct led_classdev {
    // 最小化定义以满足编译
    char dummy;
};

struct work_struct {
    // 最小化定义以满足编译
    char dummy;
};

struct asus_kbd_leds {
    struct led_classdev cdev;
    int lock;  // 简化自旋锁为普通int
    enum led_brightness brightness;
    struct work_struct work;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

// 空实现这些函数以避免链接错误
static void spin_lock_irqsave(int *lock, unsigned long flags) {}
static void spin_unlock_irqrestore(int *lock, unsigned long flags) {}
static void schedule_work(struct work_struct *work) {}