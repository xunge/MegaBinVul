#include <stddef.h>
#include <stdint.h>

struct hsr_dabt {
    int size;
    int reg;
    int sign;
};

typedef struct mmio_info {
    struct hsr_dabt dabt;
    uint64_t gpa;
} mmio_info_t;

struct vcpu {
    struct domain *domain;
};

struct domain {
    struct {
        struct {
            uint64_t dbase;
            uint32_t ctlr;
            uint32_t nr_spis;
        } vgic;
    } arch;
    uint32_t max_vcpus;
};

struct cpu_user_regs;
struct vgic_irq_rank {
    uint32_t ienable;
    uint32_t ipend;
    uint32_t iactive;
    uint32_t ipriority[8];
    uint32_t icfg[2];
    struct {
        uint32_t itargets[8];
    } v2;
    uint32_t pendsgi;
};

#define DABT_BYTE 0
#define DABT_WORD 1
#define GICD_CTLR 0x000
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

#define GICD_TYPE_CPUS 0x00000000
#define GICD_TYPE_LINES 0x00000000

typedef uintptr_t register_t;

#define REG_RANK_INDEX(size, offset, type) ((offset) / (size))

#define XENLOG_G_ERR 0
#define perfc_incr(x) do {} while (0)
#define printk(...) do {} while (0)
#define domain_crash_synchronous() do {} while (0)

static inline struct cpu_user_regs *guest_cpu_user_regs(void) { return NULL; }
static inline register_t *select_user_reg(struct cpu_user_regs *regs, int reg) { return NULL; }
static inline void vgic_lock(struct vcpu *v) {}
static inline void vgic_unlock(struct vcpu *v) {}
static inline struct vgic_irq_rank *vgic_rank_offset(struct vcpu *v, int size, int offset, int type) { return NULL; }
static inline void vgic_lock_rank(struct vcpu *v, struct vgic_irq_rank *rank, unsigned long flags) {}
static inline void vgic_unlock_rank(struct vcpu *v, struct vgic_irq_rank *rank, unsigned long flags) {}
static inline register_t vgic_byte_read(register_t val, int sign, int reg) { return 0; }