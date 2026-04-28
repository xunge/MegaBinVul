#include <stddef.h>
#include <string.h>

#define KVM_MAX_VCPU_ID 256
#define KVM_MAX_VCPUS 256
#define BITS_PER_LONG (8 * sizeof(unsigned long))

struct kvm_ioapic {
    struct {
        int pending_eoi;
        struct {
            unsigned long map[KVM_MAX_VCPU_ID / BITS_PER_LONG];
        } dest_map;
    } rtc_status;
};

static inline void bitmap_zero(unsigned long *dst, unsigned int nbits)
{
    memset(dst, 0, (nbits + BITS_PER_LONG - 1) / BITS_PER_LONG * sizeof(unsigned long));
}