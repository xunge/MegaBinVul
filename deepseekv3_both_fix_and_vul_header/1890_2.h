#include <stdint.h>
#include <stddef.h>

typedef uint64_t mfn_t;
typedef uint64_t paddr_t;

#define _mfn(x) ((mfn_t)(x))
#define INVALID_MFN _mfn(0)

struct hvm {
    struct {
        mfn_t apic_access_mfn;
    } vmx;
};

struct domain {
    struct {
        struct hvm hvm;
    } arch;
};

struct vcpu {
    struct domain *domain;
};

struct vlapic {
    void *regs_page;
};

static struct vlapic *vcpu_vlapic(struct vcpu *v) { return NULL; }
static paddr_t page_to_maddr(void *page) { return 0; }
static paddr_t mfn_to_maddr(mfn_t mfn) { return 0; }
static void vmx_vmcs_enter(struct vcpu *v) {}
static void vmx_vmcs_exit(struct vcpu *v) {}
static void __vmwrite(uint64_t field, uint64_t value) {}

static int cpu_has_vmx_virtualize_apic_accesses;
static mfn_t apic_access_mfn;

#define VIRTUAL_APIC_PAGE_ADDR 0
#define APIC_ACCESS_ADDR 0
#define ASSERT(x) (void)(x)
#define mfn_eq(a, b) ((a) == (b))