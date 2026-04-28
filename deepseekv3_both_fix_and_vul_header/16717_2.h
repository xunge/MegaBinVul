#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef uint32_t u32;
typedef struct { int counter; } seqcount_t;

struct xt_table_info {
    unsigned int number;
    void *initial_entries;
};

struct xt_table {
    const char *name;
    unsigned int af;
    struct xt_table_info *private;
};

#define GFP_KERNEL 0
#define AUDIT_XT_OP_REGISTER 0
#define AUDIT_XT_OP_REPLACE 1
#define EAGAIN 11

extern int xt_jumpstack_alloc(struct xt_table_info *);
extern void local_bh_disable(void);
extern void local_bh_enable(void);
extern void smp_wmb(void);
extern void cpu_relax(void);
extern void cond_resched(void);
extern void audit_log_nfcfg(const char *, unsigned int, unsigned int, int, int);
extern seqcount_t *xt_recseq;
extern unsigned int raw_read_seqcount(seqcount_t *s);
#define for_each_possible_cpu(cpu) for (cpu = 0; cpu < 1; cpu++)
#define per_cpu(var, cpu) (var)
#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)