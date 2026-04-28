#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t u32;

struct sk_buff {
    u32 priority;
};

struct Qdisc {
    u32 handle;
};

struct cbq_class {
    struct cbq_class **defaults;
    struct tcf_proto *filter_list;
    int level;
};

struct cbq_sched_data {
    struct cbq_class link;
};

struct tcf_proto;
struct tcf_result {
    void *class;
    u32 classid;
};

#define TC_H_MAJ(handle) ((handle) >> 16)
#define TC_PRIO_MAX 15
#define TC_PRIO_BESTEFFORT 0

#define NET_XMIT_SUCCESS 0
#define __NET_XMIT_BYPASS 1
#define __NET_XMIT_STOLEN 2

#define TC_ACT_UNSPEC (-1)
#define TC_ACT_OK 0
#define TC_ACT_RECLASSIFY 1
#define TC_ACT_SHOT 2
#define TC_ACT_STOLEN 3
#define TC_ACT_QUEUED 4
#define TC_ACT_TRAP 5

static inline struct cbq_sched_data *qdisc_priv(struct Qdisc *sch) {
    return (struct cbq_sched_data *)sch;
}

static struct cbq_class *cbq_class_lookup(struct cbq_sched_data *q, u32 prio);
static struct cbq_class *cbq_reclassify(struct sk_buff *skb, struct cbq_class *cl);
static int tcf_classify(struct sk_buff *skb, const struct tcf_proto *tp,
                       const struct tcf_proto *fl, struct tcf_result *res,
                       bool compat_mode);

#define rcu_dereference_bh(p) (p)