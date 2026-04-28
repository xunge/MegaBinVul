#include <stdint.h>
#include <stdio.h>

#define PRIregister "lx"
#define XENLOG_G_ERR

struct vcpu;

struct hsr_dabt {
    int reg;
    int size;
};

typedef struct mmio_info_t {
    struct hsr_dabt dabt;
} mmio_info_t;

struct cpu_user_regs {
    int dummy;
};

typedef uint64_t register_t;

#define GICR_CTLR      0x0000
#define GICR_IIDR      0x0004
#define GICR_TYPER     0x0008
#define GICR_STATUSR   0x0010
#define GICR_WAKER     0x0014
#define GICR_SETLPIR   0x0040
#define GICR_CLRLPIR   0x0048
#define GICR_PROPBASER 0x0070
#define GICR_PENDBASER 0x0078
#define GICR_INVLPIR   0x00A0
#define GICR_INVALLR   0x00B0
#define GICR_SYNCR     0x00C0
#define GICR_MOVLPIR   0x00D0
#define GICR_MOVALLR   0x00E0
#define GICR_PIDR0     0xFFE0
#define GICR_PIDR1     0xFFE4
#define GICR_PIDR2     0xFFE8
#define GICR_PIDR3     0xFFEC
#define GICR_PIDR4     0xFFD0
#define GICR_PIDR5     0xFFD4
#define GICR_PIDR6     0xFFD8
#define GICR_PIDR7     0xFFDC

#define DABT_WORD 0
#define DABT_DOUBLE_WORD 1

struct cpu_user_regs *guest_cpu_user_regs(void);
register_t *select_user_reg(struct cpu_user_regs *regs, int reg);
void printk(const char *fmt, ...);
void domain_crash_synchronous(void);