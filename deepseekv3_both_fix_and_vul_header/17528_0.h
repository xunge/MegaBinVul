#include <stdbool.h>

struct kvm_vcpu;
struct vmcs12;

#define CPU_BASED_USE_IO_BITMAPS 0
#define CPU_BASED_UNCOND_IO_EXITING 0
#define EXIT_QUALIFICATION 0

static bool nested_cpu_has(struct vmcs12 *vmcs12, int flag);
static unsigned long vmcs_readl(int field);
static bool nested_vmx_check_io_bitmaps(struct kvm_vcpu *vcpu, unsigned int port, int size);