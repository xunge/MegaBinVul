#include <stdint.h>
#include <stddef.h>

#define GICR_CTLR        0x0000
#define GICR_IIDR        0x0004
#define GICR_TYPER       0x0008
#define GICR_STATUSR     0x0010
#define GICR_WAKER       0x0014
#define GICR_SETLPIR     0x0040
#define GICR_CLRLPIR     0x0048
#define GICR_PROPBASER   0x0070
#define GICR_PENDBASER   0x0078
#define GICR_INVLPIR     0x00A0
#define GICR_INVALLR     0x00B0
#define GICR_SYNCR       0x00C0
#define GICR_MOVLPIR     0x0100
#define GICR_MOVALLR     0x0110
#define GICR_PIDR0       0xFFE0
#define GICR_PIDR1       0xFFE4
#define GICR_PIDR2       0xFFE8
#define GICR_PIDR3       0xFFEC
#define GICR_PIDR4       0xFFF0
#define GICR_PIDR5       0xFFF4
#define GICR_PIDR6       0xFFF8
#define GICR_PIDR7       0xFFFC

#define GICV3_GICR_IIDR_VAL  0x0200143B
#define GICV3_GICR_PIDR0     0x92
#define GICV3_GICR_PIDR1     0xB4
#define GICV3_GICR_PIDR2     0x3B
#define GICV3_GICR_PIDR4     0x04
#define GICR_SYNCR_NOT_BUSY  0x0

#define DABT_WORD         2
#define DABT_DOUBLE_WORD  3

#define XENLOG_G_ERR ""

typedef struct hsr_dabt {
    int reg;
    int size;
} hsr_dabt_t;

typedef struct mmio_info {
    hsr_dabt_t dabt;
} mmio_info_t;

typedef struct vcpu {
    struct {
        uint64_t vmpidr;
    } arch;
} vcpu_t;

typedef struct cpu_user_regs {
    uint64_t regs[32];
} cpu_user_regs_t;

typedef uint64_t register_t;

static cpu_user_regs_t* guest_cpu_user_regs(void) { return NULL; }
static register_t* select_user_reg(cpu_user_regs_t *regs, int reg) { return &regs->regs[reg]; }
static void printk(const char *fmt, ...) {}
static void domain_crash_synchronous(void) {}

#define MPIDR_AFFINITY_LEVEL(mpidr, level) \
    (((mpidr) >> ((level) * 8)) & 0xFF)