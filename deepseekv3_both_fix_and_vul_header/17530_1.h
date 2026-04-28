#include <stdbool.h>
#include <stdint.h>

typedef unsigned long gpa_t;
typedef uint8_t u8;

struct vmcs12 {
    gpa_t io_bitmap_a;
    gpa_t io_bitmap_b;
};

struct kvm_vcpu;

bool nested_cpu_has(struct vmcs12 *vmcs12, int flag);
unsigned long vmcs_readl(unsigned long field);
bool kvm_vcpu_read_guest(struct kvm_vcpu *vcpu, gpa_t gpa, void *data, int len);

#define CPU_BASED_USE_IO_BITMAPS 0x100000
#define CPU_BASED_UNCOND_IO_EXITING 0x80000
#define EXIT_QUALIFICATION 0x6402