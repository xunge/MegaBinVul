#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define unlikely(x) (x)
#define pr_debug(fmt, ...) 

typedef uint64_t u64;

struct list_head {
    struct list_head *next, *prev;
};

struct sk_buff {
    // minimal definition
};

struct Qdisc {
    struct {
        unsigned int qlen;
    } q;
    void *priv;
};

struct qfq_class {
    // minimal definition
};

struct qfq_aggregate {
    struct list_head active;
    unsigned int budget;
    unsigned int initial_budget;
    unsigned int budgetmax;
    u64 F;
};

struct qfq_sched {
    struct qfq_aggregate *in_serv_agg;
    u64 V;
    u64 iwsum;
};

static inline struct qfq_sched *qdisc_priv(struct Qdisc *sch) {
    return (struct qfq_sched *)sch->priv;
}

static inline bool list_empty(const struct list_head *head) {
    return head->next == head;
}

enum {
    requeue = 0
};

static struct sk_buff *qfq_peek_skb(struct qfq_aggregate *agg, struct qfq_class **cl, unsigned int *len);
static void charge_actual_service(struct qfq_aggregate *agg);
static void qfq_update_agg_ts(struct qfq_sched *q, struct qfq_aggregate *agg, int requeue);
static void qfq_schedule_agg(struct qfq_sched *q, struct qfq_aggregate *agg);
static struct qfq_aggregate *qfq_choose_next_agg(struct qfq_sched *q);
static struct sk_buff *agg_dequeue(struct qfq_aggregate *agg, struct qfq_class *cl, unsigned int len);
static void qdisc_qstats_backlog_dec(struct Qdisc *sch, struct sk_buff *skb);
static void qdisc_bstats_update(struct Qdisc *sch, struct sk_buff *skb);