#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define QFQ_MAX_WSHIFT 32
#define QFQ_MTU_SHIFT 16
#define QFQ_MIN_LMAX 512
#define QFQ_MAX_WSUM (2*QFQ_MAX_WSHIFT)
#define ONE_FP (1UL << 16)

#define GFP_KERNEL 0
#define EINVAL 22
#define ENOBUFS 105

typedef uint32_t u32;

struct Qdisc {
    void *dev_queue;
};

struct nlattr;
struct netlink_ext_ack;

struct gnet_stats_basic_sync {
    uint64_t bytes;
    uint32_t packets;
};

struct qdisc_rate_table {
    u32 rate;
    u32 burst;
};

struct qfq_aggregate {
    u32 lmax;
    u32 class_weight;
};

struct qfq_class {
    struct {
        u32 classid;
    } common;
    struct qfq_aggregate *agg;
    struct gnet_stats_basic_sync bstats;
    struct qdisc_rate_table rate_est;
    struct Qdisc *qdisc;
    u32 deficit;
};

struct qfq_sched {
    u32 wsum;
    void *clhash;
};

enum {
    TCA_OPTIONS,
    TCA_RATE,
    TCA_QFQ_WEIGHT,
    TCA_QFQ_LMAX,
    TCA_QFQ_MAX
};

struct nla_policy {
    unsigned int type;
    unsigned int len;
};

static const struct nla_policy qfq_policy[TCA_QFQ_MAX + 1] = {0};

#define pr_notice(fmt, ...)

struct Qdisc_ops {
    // dummy structure
};

extern struct Qdisc_ops pfifo_qdisc_ops;
extern struct Qdisc noop_qdisc;

static inline void gnet_stats_basic_sync_init(struct gnet_stats_basic_sync *bstats) {}
static inline int gen_replace_estimator(struct gnet_stats_basic_sync *bstats, void *p1,
                                      struct qdisc_rate_table *rate_est, void *p2,
                                      bool b, struct nlattr *attr) { return 0; }
static inline int gen_new_estimator(struct gnet_stats_basic_sync *bstats, void *p1,
                                   struct qdisc_rate_table *rate_est, void *p2,
                                   bool b, struct nlattr *attr) { return 0; }
static inline void gen_kill_estimator(struct qdisc_rate_table *rate_est) {}
static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline void kfree(void *ptr) {}
static inline void sch_tree_lock(struct Qdisc *sch) {}
static inline void sch_tree_unlock(struct Qdisc *sch) {}
static inline void qdisc_class_hash_insert(void *clhash, void *common) {}
static inline void qdisc_class_hash_grow(struct Qdisc *sch, void *clhash) {}
static inline void qdisc_hash_add(struct Qdisc *qdisc, bool b) {}
static inline void qdisc_put(struct Qdisc *qdisc) {}
static inline struct Qdisc *qdisc_create_dflt(void *dev_queue, struct Qdisc_ops *ops,
                                            u32 classid, void *p) { return NULL; }
static inline void *qdisc_priv(struct Qdisc *sch) { return NULL; }
static inline void *qdisc_dev(struct Qdisc *sch) { return NULL; }
static inline unsigned int psched_mtu(void *dev) { return 0; }
static inline int nla_parse_nested_deprecated(struct nlattr **tb, int max,
                                            struct nlattr *nla,
                                            const struct nla_policy *policy,
                                            void *extack) { return 0; }
static inline u32 nla_get_u32(struct nlattr *nla) { return 0; }

static inline struct qfq_aggregate *qfq_find_agg(struct qfq_sched *q, u32 lmax, u32 weight) { return NULL; }
static inline void qfq_init_agg(struct qfq_sched *q, struct qfq_aggregate *agg, u32 lmax, u32 weight) {}
static inline void qfq_deact_rm_from_agg(struct qfq_sched *q, struct qfq_class *cl) {}
static inline void qfq_add_to_agg(struct qfq_sched *q, struct qfq_aggregate *agg, struct qfq_class *cl) {}