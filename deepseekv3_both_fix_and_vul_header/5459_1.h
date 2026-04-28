#include <stdint.h>
#include <stdio.h>

#define GICD_IGROUPR      0x0080
#define GICD_IGROUPRN     0x00ff
#define GICD_ISENABLER    0x0100
#define GICD_ISENABLERN   0x011f
#define GICD_ICENABLER    0x0180
#define GICD_ICENABLERN   0x019f
#define GICD_ISPENDR      0x0200
#define GICD_ISPENDRN     0x021f
#define GICD_ICPENDR      0x0280
#define GICD_ICPENDRN     0x029f
#define GICD_ISACTIVER    0x0300
#define GICD_ISACTIVERN   0x031f
#define GICD_ICACTIVER    0x0380
#define GICD_ICACTIVERN   0x039f
#define GICD_IPRIORITYR   0x0400
#define GICD_IPRIORITYRN  0x07ff
#define GICD_ICFGR        0x0c00
#define GICD_ICFGRN       0x0cff

#define DABT_BYTE 0
#define DABT_WORD 2
#define XENLOG_ERR 1
#define XENLOG_G_ERR ""

typedef uint64_t register_t;
#define PRIregister "lx"

struct vcpu {
    const char *name;
};

struct hsr_dabt {
    int size;
    int reg;
};

typedef struct mmio_info_t {
    struct hsr_dabt dabt;
} mmio_info_t;

struct cpu_user_regs {
    register_t r[32];
};

struct vgic_irq_rank {
    uint32_t ienable;
    uint32_t ipend;
    uint32_t iactive;
    uint32_t ipriority[32];
    uint32_t icfg[32];
};

#define REG_RANK_INDEX(elements, offset, size) ((offset) / (size) % (elements))

static inline struct cpu_user_regs *guest_cpu_user_regs(void) { return NULL; }
static inline register_t *select_user_reg(struct cpu_user_regs *regs, int reg) { return NULL; }
static inline struct vgic_irq_rank *vgic_rank_offset(struct vcpu *v, int a, int b, int c) { return NULL; }
static inline void vgic_lock_rank(struct vcpu *v, struct vgic_irq_rank *rank, unsigned long flags) {}
static inline void vgic_unlock_rank(struct vcpu *v, struct vgic_irq_rank *rank, unsigned long flags) {}
static inline void vgic_enable_irqs(struct vcpu *v, uint32_t a, uint32_t b) {}
static inline void vgic_disable_irqs(struct vcpu *v, uint32_t a, uint32_t b) {}
static inline void vgic_byte_write(uint32_t *a, register_t b, uint32_t c) {}
static inline void printk(const char *fmt, ...) {}
static inline void dprintk(int level, const char *fmt, ...) {}
static inline void domain_crash_synchronous(void) {}