#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>

#define DABT_BYTE 0
#define DABT_WORD 2
#define GICD_CTLR 0x000
#define GICD_CTL_ENABLE 0x1
#define GICD_TYPER 0x004
#define GICD_IIDR 0x008
#define GICD_IGROUPR 0x080
#define GICD_IGROUPRN 0x0fc
#define GICD_ISENABLER 0x100
#define GICD_ISENABLERN 0x17c
#define GICD_ICENABLER 0x180
#define GICD_ICENABLERN 0x1fc
#define GICD_ISPENDR 0x200
#define GICD_ISPENDRN 0x27c
#define GICD_ICPENDR 0x280
#define GICD_ICPENDRN 0x2fc
#define GICD_ISACTIVER 0x300
#define GICD_ISACTIVERN 0x37c
#define GICD_ICACTIVER 0x380
#define GICD_ICACTIVERN 0x3fc
#define GICD_ITARGETSR 0x800
#define GICD_ITARGETSRN 0x8fc
#define GICD_IPRIORITYR 0x400
#define GICD_IPRIORITYRN 0x7fb
#define GICD_ICFGR 0xc00
#define GICD_ICFGRN 0xcfc
#define GICD_NSACR 0xe00
#define GICD_NSACRN 0xefc
#define GICD_SGIR 0xf00
#define GICD_CPENDSGIR 0xf10
#define GICD_CPENDSGIRN 0xf1c
#define GICD_SPENDSGIR 0xf20
#define GICD_SPENDSGIRN 0xf2c
#define GICD_ICPIDR2 0xfe8

#define REG_RANK_INDEX(per_irq, offset, size) ((offset) / ((per_irq) * (size)))
#define XENLOG_G_ERR ""

typedef uint64_t register_t;
#define PRIregister PRIx64

struct hsr_dabt {
    int reg;
    int size;
};

struct mmio_info {
    struct hsr_dabt dabt;
    uint64_t gpa;
};
typedef struct mmio_info mmio_info_t;

struct vgic_irq_rank {
    uint32_t ienable;
    uint32_t iactive;
    uint32_t ipriority[8];
    uint32_t icfg[2];
    struct {
        uint32_t itargets[8];
    } v2;
};

struct domain_arch {
    struct {
        uint64_t dbase;
        uint32_t ctlr;
    } vgic;
};

struct domain {
    struct domain_arch arch;
    unsigned int max_vcpus;
    struct vcpu **vcpu;
};

struct vcpu {
    struct domain *domain;
};

struct cpu_user_regs;

extern struct cpu_user_regs *guest_cpu_user_regs(void);
extern register_t *select_user_reg(struct cpu_user_regs *regs, int reg);
extern struct vgic_irq_rank *vgic_rank_offset(struct vcpu *v, int per_irq, int offset, int size);
extern void vgic_lock_rank(struct vcpu *v, struct vgic_irq_rank *rank, unsigned long flags);
extern void vgic_unlock_rank(struct vcpu *v, struct vgic_irq_rank *rank, unsigned long flags);
extern void vgic_enable_irqs(struct vcpu *v, uint32_t mask, int irq);
extern void vgic_disable_irqs(struct vcpu *v, uint32_t mask, int irq);
extern uint32_t vgic_byte_read(uint32_t *reg, int offset, int byte);
extern void vgic_byte_write(uint32_t *reg, uint32_t value, int offset);
extern void vgic_migrate_irq(struct vcpu *old, struct vcpu *new, int irq);
extern int vgic_v2_to_sgi(struct vcpu *v, register_t value);
extern void perfc_incr(int counter);
extern void printk(const char *fmt, ...);
extern void BUG_ON(int condition);
extern int find_next_bit(const unsigned long *addr, int size, int offset);
extern int find_first_bit(const unsigned long *addr, int size);
extern void domain_crash_synchronous(void);

static int vgicd_writes = 0;