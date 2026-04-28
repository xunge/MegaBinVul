#include <stdint.h>
#include <stdio.h>

#define DABT_WORD 2
#define XENLOG_G_ERR 
#define PRIregister "lx"

#define GICR_IGRPMODR0   0x0D00
#define GICR_IGROUPR0    0x0080
#define GICR_ISENABLER0  0x0100
#define GICR_ICENABLER0  0x0180
#define GICR_ISACTIVER0  0x0300
#define GICR_ICACTIVER0  0x0380
#define GICR_ICFGR1      0x0C04
#define GICR_IPRIORITYR0 0x0400
#define GICR_IPRIORITYR7 0x041C
#define GICR_ISPENDR0    0x0200
#define GICR_ICPENDR0    0x0280
#define GICR_NSACR       0x0E00

struct vcpu;
struct cpu_user_regs;
typedef unsigned long register_t;

struct hsr_dabt {
    int size;
    int reg;
};

typedef struct mmio_info {
    struct hsr_dabt dabt;
} mmio_info_t;

struct vgic_irq_rank {
    unsigned long pendsgi;
};

extern struct cpu_user_regs *guest_cpu_user_regs();
extern register_t *select_user_reg(struct cpu_user_regs *regs, int reg);
extern struct vgic_irq_rank *vgic_rank_offset(struct vcpu *v, int rank, int offset, int size);
extern void vgic_lock_rank(struct vcpu *v, struct vgic_irq_rank *rank, unsigned long flags);
extern void vgic_unlock_rank(struct vcpu *v, struct vgic_irq_rank *rank, unsigned long flags);
extern int __vgic_v3_distr_common_mmio_write(struct vcpu *v, mmio_info_t *info, uint32_t reg);
extern void domain_crash_synchronous();
extern int printk(const char *fmt, ...);