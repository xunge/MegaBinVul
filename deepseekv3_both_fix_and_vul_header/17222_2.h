#include <stdint.h>
#include <stddef.h>

#define HPET_TIMER_NUM 32
#define HPET_CFG_LEGACY 0x0001
#define HPET_TINY_TIME_SPAN 1000
#define PTSRC_isa 0
#define PTSRC_ioapic 1

#define ASSERT(cond) ((void)0)
#define TRACE_2_LONG_4D(a, b, c, d, e) ((void)0)
#define TRC_HVM_EMUL_HPET_START_TIMER 0
#define TRC_PAR_LONG(x) (x)

typedef struct {
    unsigned int config;
    uint64_t period[HPET_TIMER_NUM];
} HPETRegisters;

typedef struct {
    int source;
} PeriodicTime;

typedef struct {
    HPETRegisters hpet;
    PeriodicTime pt[HPET_TIMER_NUM];
    void *lock;
} HPETState;

typedef struct {
    void *vpit;
} DomainArch;

typedef struct {
    DomainArch arch;
} Domain;

typedef struct {
    int vcpu;
} VCPU;

static Domain* vhpet_domain(HPETState *h) { return NULL; }
static VCPU* vhpet_vcpu(HPETState *h) { return NULL; }
static int rw_is_write_locked(void *lock) { return 1; }
static void pit_stop_channel0_irq(void *vpit) {}
static int timer_enabled(HPETState *h, unsigned int tn) { return 1; }
static uint64_t hpet_get_comparator(HPETState *h, unsigned int tn, uint64_t guest_time) { return 0; }
static uint64_t hpet_read_maincounter(HPETState *h, uint64_t guest_time) { return 0; }
static int timer_is_32bit(HPETState *h, unsigned int tn) { return 0; }
static unsigned int timer_int_route(HPETState *h, unsigned int tn) { return 0; }
static int timer_is_periodic(HPETState *h, unsigned int tn) { return 0; }
static uint64_t hpet_tick_to_ns(HPETState *h, uint64_t ticks) { return 0; }
static void destroy_periodic_time(PeriodicTime *pt) {}
static void create_periodic_time(VCPU *vcpu, PeriodicTime *pt, uint64_t diff, uint64_t period, unsigned int irq, void *a, void *b) {}