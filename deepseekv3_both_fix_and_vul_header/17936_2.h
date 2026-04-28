#include <stddef.h>

struct pt_regs {
    // dummy definition
};

struct cpu_hw_events {
    int n_limited;
    int n_events;
    struct perf_event **event;
    unsigned long *mmcr;
};

struct perf_event {
    struct {
        int idx;
    } hw;
};

struct pmu {
    int n_counter;
};

extern struct pmu *ppmu;
extern struct cpu_hw_events cpu_hw_events;

#define __get_cpu_var(var) (var)
#define SPRN_PMC5 0
#define SPRN_PMC6 0

static void freeze_limited_counters(struct cpu_hw_events *cpuhw, int pmc5, int pmc6) {}
static void perf_read_regs(struct pt_regs *regs) {}
static int perf_intr_is_nmi(struct pt_regs *regs) { return 0; }
static void nmi_enter(void) {}
static void irq_enter(void) {}
static int is_limited_pmc(int idx) { return 0; }
static unsigned long read_pmc(int idx) { return 0; }
static void record_and_restart(struct perf_event *event, unsigned long val, struct pt_regs *regs, int nmi) {}
static void write_pmc(int idx, unsigned long val) {}
static void write_mmcr0(struct cpu_hw_events *cpuhw, unsigned long val) {}
static void nmi_exit(void) {}
static void irq_exit(void) {}
static unsigned long mfspr(int spr) { return 0; }