#include <stdint.h>

typedef struct PMTState {
    int lock;
    struct {
        uint32_t tmr_val;
    } pm;
} PMTState;

typedef struct pl_time {
    PMTState vpmt;
} pl_time;

typedef struct hvm_domain {
    pl_time pl_time;
} hvm_domain;

typedef struct arch_domain {
    hvm_domain hvm_domain;
} arch_domain;

typedef struct domain {
    arch_domain arch;
} domain;

typedef struct vcpu {
    domain *domain;
} vcpu;

#define XENLOG_WARNING 0
#define IOREQ_READ 0
#define X86EMUL_OKAY 0
#define X86EMUL_UNHANDLEABLE 1

extern vcpu *current;

static inline int spin_trylock(int *lock) { return 1; }
static inline void spin_unlock(int *lock) {}
static inline void spin_barrier(int *lock) {}

void gdprintk(int level, const char *fmt, ...);
void pmt_update_time(PMTState *s);