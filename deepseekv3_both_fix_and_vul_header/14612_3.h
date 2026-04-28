#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct hrtimer {
    void (*function)(struct hrtimer *);
};

struct kvm_io_device {
    int dummy;
};

struct kvm_io_device_ops {
    int dummy;
};

struct kvm_lapic {
    void *regs;
    struct kvm_vcpu *vcpu;
    struct {
        struct hrtimer timer;
        int timer_advance_ns;
    } lapic_timer;
    struct kvm_io_device dev;
};

struct kvm_vcpu {
    struct {
        struct kvm_lapic *apic;
        unsigned long apic_base;
    } arch;
    int vcpu_id;
};

struct static_key_false {
    struct {
        unsigned long enabled;
    } key;
};

extern struct static_key_false apic_sw_disabled;
extern bool lapic_timer_advance_dynamic;
extern const struct kvm_io_device_ops apic_mmio_ops;
extern void apic_timer_fn(struct hrtimer *timer);
extern void kvm_iodevice_init(struct kvm_io_device *dev, const struct kvm_io_device_ops *ops);
extern void *kzalloc(size_t size, int flags);
extern void *get_zeroed_page(int flags);
extern void kfree(void *ptr);
extern void hrtimer_init(struct hrtimer *timer, int clock, int mode);
extern int printf(const char *format, ...);
extern void static_branch_inc(struct static_key_false *key);

#define GFP_KERNEL_ACCOUNT 0
#define LAPIC_TIMER_ADVANCE_NS_INIT 0
#define MSR_IA32_APICBASE_ENABLE 0
#define KERN_ERR ""
#define ENOMEM (-1)
#define HRTIMER_MODE_ABS_HARD 0
#define ASSERT(x) do { if (!(x)) abort(); } while (0)
#define printk(fmt, ...) printf(fmt, ##__VA_ARGS__)