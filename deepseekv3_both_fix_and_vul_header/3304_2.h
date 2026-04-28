#include <stdint.h>
#include <time.h>

#define ASSERT(expr) ((void)0)

typedef int64_t ktime_t;
typedef uint32_t u32;
typedef int64_t s64;

struct hrtimer {
    // Minimal hrtimer structure definition
    ktime_t _softexpires;
    ktime_t _expires;
};

struct kvm_lapic {
    struct {
        struct hrtimer timer;
        uint64_t period;
    } lapic_timer;
    u32 divide_count;
};

u32 kvm_apic_get_reg(struct kvm_lapic *apic, int reg);
ktime_t hrtimer_get_remaining(const struct hrtimer *timer);
int64_t ktime_to_ns(ktime_t t);
ktime_t ktime_set(int64_t secs, int64_t nsecs);
int64_t mod_64(int64_t dividend, int64_t divisor);
uint64_t div64_u64(uint64_t dividend, uint64_t divisor);

#define APIC_TMICT 0x380
#define APIC_BUS_CYCLE_NS 1