#include <stdint.h>

#define NR_IRQS_LEGACY 16
#define MP_INTSRC 0
#define mp_INT 0
#define MP_ISA_BUS 0
#define ACPI_INVALID_GSI 0xFFFFFFFF

#define __init

typedef uint8_t u8;
typedef uint32_t u32;

struct mpc_intsrc {
    int type;
    int irqtype;
    int irqflag;
    int srcbus;
    int srcbusirq;
    int dstapic;
    int dstirq;
};

extern int mp_find_ioapic(uint32_t gsi);
extern int mp_find_ioapic_pin(int ioapic, uint32_t gsi);
extern int mpc_ioapic_id(int ioapic);
extern void mp_save_irq(struct mpc_intsrc *mp_irq);
extern int nr_legacy_irqs(void);
extern uint32_t isa_irq_to_gsi[];
extern void pr_warn(const char *fmt, ...);