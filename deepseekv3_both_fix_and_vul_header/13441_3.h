#include <stdint.h>
#include <stdlib.h>

struct xt_table_info {
    unsigned int number;
    void *initial_entries;
};

struct xt_table {
    const char *name;
    int af;
    struct xt_table_info *private;
};

typedef uint32_t seqcount_t;
typedef uint32_t u32;

#define pr_debug(fmt, ...)
#define GFP_KERNEL 0
#define AUDIT_XT_OP_REGISTER 0
#define AUDIT_XT_OP_REPLACE 1
#define EAGAIN 11

seqcount_t xt_recseq;

#define for_each_possible_cpu(cpu) for (cpu = 0; cpu < 1; cpu++)
#define per_cpu(var, cpu) (var)

static inline void local_bh_disable(void) {}
static inline void local_bh_enable(void) {}
static inline void smp_wmb(void) {}
static inline void cpu_relax(void) {}
static inline void cond_resched(void) {}
static inline uint32_t raw_read_seqcount(seqcount_t *s) { return 0; }

static int xt_jumpstack_alloc(struct xt_table_info *newinfo) { return 0; }
void audit_log_nfcfg(const char *name, int af, unsigned int number, int op, int gfp);