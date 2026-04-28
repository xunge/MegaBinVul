#include <stdint.h>
#include <stddef.h>

#define __cpuinit
#define WRITE_SYSREG64(val, reg)
#define WRITE_SYSREG32(val, reg)
#define CNTVOFF_EL2 0
#define CNTKCTL_EL1 0
#define USE_HYP_TIMER 0
#define CNTHCTL_PA 0
#define CNTHCTL_EL2 0
#define CNTP_CTL_EL0 0
#define CNTHP_CTL_EL2 0
#define isb()
#define TIMER_HYP_PPI 0
#define TIMER_VIRT_PPI 1
#define TIMER_PHYS_NONSECURE_PPI 2

struct irq_desc {
    int dummy;
};
struct irq_desc timer_irq[3];

void request_dt_irq(struct irq_desc *desc, void (*handler)(void), const char *name, void *dev);
void timer_interrupt(void);
void vtimer_interrupt(void);