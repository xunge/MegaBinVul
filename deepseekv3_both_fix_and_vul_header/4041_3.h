#include <stdint.h>
#include <stdlib.h>

typedef uint32_t u32;

struct Qdisc;
struct qfq_class;
struct qfq_sched;

struct qfq_aggregate {
    /* placeholder for aggregate structure */
    int dummy;
};

#define QFQ_MIN_LMAX 512
#define QFQ_MAX_LMAX (1 << 16)
#define GFP_ATOMIC 0
#define EINVAL 22
#define ENOBUFS 105

void *kzalloc(size_t size, int flags);
void qfq_init_agg(struct qfq_sched *q, struct qfq_aggregate *agg, u32 lmax, u32 weight);
struct qfq_aggregate *qfq_find_agg(struct qfq_sched *q, u32 lmax, u32 weight);
void qfq_deact_rm_from_agg(struct qfq_sched *q, struct qfq_class *cl);
void qfq_add_to_agg(struct qfq_sched *q, struct qfq_aggregate *agg, struct qfq_class *cl);
struct qfq_sched *qdisc_priv(struct Qdisc *sch);