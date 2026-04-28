#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define SFB_LEVELS 2
#define SFB_BUCKET_MASK 0xFF
#define SFB_BUCKET_SHIFT 8
#define SFB_MAX_PROB 0xFFFF
#define NET_XMIT_SUCCESS 0
#define __NET_XMIT_BYPASS 1
#define NET_XMIT_CN 2

typedef uint32_t u32;
typedef unsigned long jiffies_t;

struct sk_buff {
    // Minimal definition
    void *data;
};

struct Qdisc {
    struct {
        u32 qlen;
    } q;
    // Other minimal fields
};

struct tcf_proto {
    // Minimal definition
};

struct sfb_bucket {
    u32 qlen;
    u32 p_mark;
};

struct sfb_bins {
    struct sfb_bucket bins[SFB_LEVELS][SFB_BUCKET_MASK + 1];
    uint64_t perturbation[2];
};

struct sfb_sched_data {
    struct Qdisc *qdisc;
    u32 slot;
    u32 limit;
    u32 max;
    u32 bin_size;
    u32 rehash_interval;
    jiffies_t rehash_time;
    u32 warmup_time;
    bool double_buffering;
    struct sfb_bins bins[2];
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

// Function prototypes
#define likely(x) (x)
#define unlikely(x) (x)
static inline struct sfb_sched_data *qdisc_priv(struct Qdisc *sch) { return NULL; }
static inline void qdisc_qstats_overlimit(struct Qdisc *sch) {}
static inline jiffies_t time_after(jiffies_t a, jiffies_t b) { return 0; }
static inline void sfb_swap_slot(struct sfb_sched_data *q) {}
static inline struct tcf_proto *rcu_dereference_bh(struct tcf_proto *p) { return p; }
static inline int sfb_classify(struct sk_buff *skb, struct tcf_proto *fl, int *ret, u32 *salt) { return 0; }
static inline u32 siphash_1u32(u32 a, uint64_t *p) { return 0; }
static inline u32 skb_get_hash_perturb(struct sk_buff *skb, uint64_t *p) { return 0; }
static inline struct sfb_skb_cb *sfb_skb_cb(struct sk_buff *skb) { return NULL; }
static inline void decrement_prob(struct sfb_bucket *b, struct sfb_sched_data *q) {}
static inline void increment_prob(struct sfb_bucket *b, struct sfb_sched_data *q) {}
static inline int sfb_rate_limit(struct sk_buff *skb, struct sfb_sched_data *q) { return 0; }
static inline u32 prandom_u32(void) { return rand(); }
static inline int INET_ECN_set_ce(struct sk_buff *skb) { return 0; }
static inline int qdisc_enqueue(struct sk_buff *skb, struct Qdisc *sch, struct sk_buff **to_free) { return 0; }
static inline void qdisc_qstats_backlog_inc(struct Qdisc *sch, struct sk_buff *skb) {}
static inline void increment_qlen(struct sk_buff *skb, struct sfb_sched_data *q) {}
static inline int net_xmit_drop_count(int ret) { return 0; }
static inline void qdisc_qstats_drop(struct Qdisc *sch) {}
static inline void qdisc_drop(struct sk_buff *skb, struct Qdisc *sch, struct sk_buff **to_free) {}
static inline void kfree_skb(struct sk_buff *skb) {}

// Global variable
jiffies_t jiffies;