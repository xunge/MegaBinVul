#include <stdint.h>
#include <stddef.h>

enum pt_source {
    PTSRC_lapic,
    PTSRC_isa,
    PTSRC_ioapic
};

struct domain {
    int domain_id;
    struct {
        struct {
            struct {
                uint8_t imr;
            } vpic[16];
        } hvm_domain;
    } arch;
};

struct vlapic {
    int dummy;
};

struct vcpu {
    struct domain *domain;
};

struct periodic_time {
    enum pt_source source;
    unsigned int irq;
    struct vcpu *vcpu;
};

#define APIC_LVTT 0
#define APIC_LVT_MASKED (1 << 16)

#define XENLOG_WARNING 0

static void dprintk(int level, const char *fmt, ...) {}
static void domain_crash(struct domain *d) {}

static struct vlapic *vcpu_vlapic(struct vcpu *v) { return NULL; }
static int vlapic_enabled(struct vlapic *vlapic) { return 0; }
static uint32_t vlapic_get_reg(struct vlapic *vlapic, int reg) { return 0; }
static int vlapic_accept_pic_intr(struct vcpu *v) { return 0; }
static unsigned int hvm_isa_irq_to_gsi(unsigned int irq) { return 0; }
static int vioapic_get_mask(struct domain *d, unsigned int gsi) { return 0; }
#define ASSERT_UNREACHABLE() ((void)0)