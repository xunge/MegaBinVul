#include <stdint.h>

#define IOAPIC_NUM_PINS 24
#define IOAPIC_VERSION_ID 0x11
#define IOAPIC_REG_VERSION 0x01
#define IOAPIC_REG_APIC_ID 0x02
#define IOAPIC_REG_ARB_ID 0x03

struct kvm_ioapic {
    unsigned long ioregsel;
    unsigned long id;
    struct {
        uint64_t bits;
    } redirtbl[IOAPIC_NUM_PINS];
};

#define ASSERT(cond) ((void)0)

typedef uint32_t u32;
typedef uint64_t u64;