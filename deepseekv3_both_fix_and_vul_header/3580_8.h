#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

struct vcpu {
    struct domain *domain;
    struct {
        struct {
            struct {
                uint64_t dbase;
                uint32_t ctlr;
            } vgic;
        } arch;
    };
};

struct hsr_dabt {
    int size;
    int reg;
};

struct mmio_info {
    struct hsr_dabt dabt;
    uint64_t gpa;
};
typedef struct mmio_info mmio_info_t;

struct cpu_user_regs;

struct vgic_irq_rank {
    uint32_t ienable;
    uint32_t iactive;
    uint32_t itargets[8];
    uint32_t ipriority[8];
    uint32_t icfg[2];
};

struct domain {
    struct {
        struct {
            struct {
                uint64_t dbase;
                uint32_t ctlr;
            } vgic;
        } arch;
    };
};

#define REG(offset) (offset)
#define GICD_CTLR 0x000
#define GICD_CTL_ENABLE 0x1
#define GICD_TYPER 0x004
#define GICD_IIDR 0x008
#define GICD_IGROUPR 0x080
#define GICD_IGROUPRN 0x0FC
#define GICD_ISENABLER 0x100
#define GICD_ISENABLERN 0x17C
#define GICD_ICENABLER 0x180
#define GICD_ICENABLERN 0x1FC
#define GICD_ISPENDR 0x200
#define GICD_ISPENDRN 0x27C
#define GICD_ICPENDR 0x280
#define GICD_ICPENDRN 0x2FC
#define GICD_ISACTIVER 0x300
#define GICD_ISACTIVERN 0x37C
#define GICD_ICACTIVER 0x380
#define GICD_ICACTIVERN 0x3FC
#define GICD_ITARGETSR 0x800
#define GICD_ITARGETSRN 0x8FC
#define GICD_IPRIORITYR 0x400
#define GICD_IPRIORITYRN 0x4FC
#define GICD_ICFGR 0xC00
#define GICD_ICFGRN 0xCFC
#define GICD_NSACR 0xE00
#define GICD_NSACRN 0xEFC
#define GICD_SGIR 0xF00
#define GICD_CPENDSGIR 0xF10
#define GICD_CPENDSGIRN 0xF1C
#define GICD_SPENDSGIR 0xF20
#define GICD_SPENDSGIRN 0xF2C
#define GICD_ICPIDR2 0xFE8

#define REG_RANK_INDEX(size, reg) ((reg) / (size))
#define PRIregister PRIu64

typedef uint64_t register_t;

static struct cpu_user_regs *guest_cpu_user_regs(void) { return NULL; }
static register_t *select_user_reg(struct cpu_user_regs *regs, int reg) { return NULL; }
static struct vgic_irq_rank *vgic_irq_rank(struct vcpu *v, int size, int reg) { return NULL; }
static void vgic_lock_rank(struct vcpu *v, struct vgic_irq_rank *rank) {}
static void vgic_unlock_rank(struct vcpu *v, struct vgic_irq_rank *rank) {}
static void vgic_enable_irqs(struct vcpu *v, uint32_t mask, int reg) {}
static void vgic_disable_irqs(struct vcpu *v, uint32_t mask, int reg) {}
static int vgic_to_sgi(struct vcpu *v, register_t val) { return 0; }
static void byte_write(uint32_t *addr, register_t val, int offset) {}
static void printk(const char *fmt, ...) {}
static void domain_crash_synchronous(void) {}