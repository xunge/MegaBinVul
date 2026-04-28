#include <stddef.h>
#include <stdbool.h>

struct sk_buff_atm {
    unsigned int atm_options;
};

struct sk_buff {
    unsigned int priority;
    struct sk_buff_atm *atm;
};

struct Qdisc {
    unsigned int handle;
    struct {
        unsigned int qlen;
        void *qdisc;
    } q;
};

struct atm_vcc {
    unsigned int atm_options;
};

struct atm_flow_data {
    struct atm_vcc *vcc;
    struct atm_flow_data *excess;
    struct tcf_proto *filter_list;
    struct {
        unsigned int drops;
    } qstats;
    void *q;
    struct atm_flow_data *next;
    struct atm_flow_data *list;
};

struct atm_qdisc_data {
    struct atm_flow_data link;
    struct {
        struct atm_flow_data *next;
    } flows;
    void *task;
};

struct tcf_proto;
struct tcf_result {
    unsigned long class;
    unsigned int classid;
};

#define TC_H_MAJ(pri) (((pri) >> 16) & 0xFFFF)
#define NET_XMIT_SUCCESS 0
#define __NET_XMIT_BYPASS 1
#define __NET_XMIT_STOLEN 2
#define NET_XMIT_DROP 1
#define TC_ACT_OK 0
#define TC_ACT_QUEUED 1
#define TC_ACT_STOLEN 2
#define TC_ACT_TRAP 3
#define TC_ACT_SHOT 4
#define TC_ACT_RECLASSIFY 5
#define ATM_ATMOPT_CLP (1 << 0)

#define pr_debug(fmt, ...)
#define rcu_dereference_bh(p) (p)
#define net_xmit_drop_count(ret) ((ret) == NET_XMIT_DROP)
#define __maybe_unused

#define list_for_each_entry(pos, head, member) \
    for (pos = (head)->next; pos; pos = pos->next)

static inline struct atm_qdisc_data *qdisc_priv(struct Qdisc *sch) { return NULL; }
static inline void *atm_tc_find(struct Qdisc *sch, unsigned int priority) { return NULL; }
static inline int tcf_classify(struct sk_buff *skb, void *null, struct tcf_proto *fl, struct tcf_result *res, bool b) { return 0; }
static inline void *lookup_flow(struct Qdisc *sch, unsigned int classid) { return NULL; }
static inline void __qdisc_drop(struct sk_buff *skb, struct sk_buff **to_free) {}
static inline int qdisc_enqueue(struct sk_buff *skb, void *q, struct sk_buff **to_free) { return 0; }
static inline void qdisc_qstats_drop(struct Qdisc *sch) {}
static inline void tasklet_schedule(void *task) {}
static inline struct sk_buff_atm *ATM_SKB(struct sk_buff *skb) { return skb->atm; }