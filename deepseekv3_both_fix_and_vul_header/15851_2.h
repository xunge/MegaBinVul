#include <stdint.h>
#include <stdbool.h>

typedef uint32_t u32;

#define SFB_LEVELS 2
#define SFB_BUCKETS 16
#define SFB_BUCKET_MASK 0xF
#define SFB_BUCKET_SHIFT 4
#define SFB_MAX_PROB 0xFFFF
#define NET_XMIT_SUCCESS 0
#define __NET_XMIT_BYPASS 0x10000000
#define NET_XMIT_CN 0x20000000

struct sk_buff;
struct Qdisc {
    struct {
        unsigned int qlen;
    } q;
};
struct tcf_proto;

struct sfb_bucket {
    u32 qlen;
    u32 p_mark;
};

struct sfb_bins {
    struct sfb_bucket bins[SFB_LEVELS][SFB_BUCKETS];
    u32 perturbation;
};

struct sfb_sched_data {
    u32 slot;
    u32 limit;
    u32 max;
    u32 bin_size;
    u32 rehash_interval;
    unsigned long rehash_time;
    bool double_buffering;
    u32 warmup_time;
    struct sfb_bins bins[2];
    struct Qdisc *qdisc;
    struct tcf_proto *filter_list;
    struct {
        u32 queuedrop;
        u32 bucketdrop;
        u32 penaltydrop;
        u32 earlydrop;
        u32 marked;
        u32 childdrop;
    } stats;
};

struct sfb_skb_cb {
    u32 hashes[2];
};

static inline struct sfb_sched_data *qdisc_priv(struct Qdisc *sch) {
    return (struct sfb_sched_data *)0;
}

static inline bool unlikely(bool x) { return x; }
static inline bool likely(bool x) { return x; }
static inline u32 jhash_1word(u32 a, u32 b) { return a + b; }
static inline u32 skb_get_hash_perturb(struct sk_buff *skb, u32 p) { return 0; }
static inline u32 prandom_u32(void) { return 0; }
static inline void qdisc_qstats_overlimit(struct Qdisc *sch) {}
static inline void sfb_swap_slot(struct sfb_sched_data *q) {}
static inline struct tcf_proto *rcu_dereference_bh(struct tcf_proto *p) { return p; }
static inline bool sfb_classify(struct sk_buff *skb, struct tcf_proto *fl, int *ret, u32 *salt) { return false; }
static inline struct sfb_skb_cb *sfb_skb_cb(struct sk_buff *skb) { return (struct sfb_skb_cb *)0; }
static inline void decrement_prob(struct sfb_bucket *b, struct sfb_sched_data *q) {}
static inline void increment_prob(struct sfb_bucket *b, struct sfb_sched_data *q) {}
static inline bool sfb_rate_limit(struct sk_buff *skb, struct sfb_sched_data *q) { return false; }
static inline bool INET_ECN_set_ce(struct sk_buff *skb) { return false; }
static inline int qdisc_enqueue(struct sk_buff *skb, struct Qdisc *sch, struct sk_buff **to_free) { return 0; }
static inline void qdisc_qstats_backlog_inc(struct Qdisc *sch, struct sk_buff *skb) {}
static inline void increment_qlen(struct sk_buff *skb, struct sfb_sched_data *q) {}
static inline bool net_xmit_drop_count(int ret) { return false; }
static inline void qdisc_qstats_drop(struct Qdisc *sch) {}
static inline void qdisc_drop(struct sk_buff *skb, struct Qdisc *sch, struct sk_buff **to_free) {}
static inline void kfree_skb(struct sk_buff *skb) {}

extern unsigned long jiffies;