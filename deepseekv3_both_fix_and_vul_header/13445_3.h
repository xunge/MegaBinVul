#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define IFNAMSIZ 16
#define NF_DROP 0
#define XT_RETURN (-1)
#define XT_CONTINUE 0xFFFFFFFF

struct sk_buff {
    void *dev;
};
struct nf_hook_state {
    unsigned int hook;
    struct net_device *in;
    struct net_device *out;
};
struct xt_table {
    void *private;
};
struct xt_table_info {
    void *entries;
    void *jumpstack[1];
    unsigned int hook_entry[1];
    unsigned int underflow[1];
    unsigned int stacksize;
};
struct xt_counters {
    uint64_t pcnt;
    uint64_t bcnt;
};
struct arpt_entry {
    unsigned int next_offset;
    unsigned int target_offset;
    void *arp;
    struct xt_counters counters;
};
struct arphdr {};
struct xt_action_param {
    const struct nf_hook_state *state;
    bool hotdrop;
    struct xt_target *target;
    void *targinfo;
};
struct xt_entry_target {
    union {
        struct {
            struct xt_target *target;
        } kernel;
    } u;
    void *data;
};
struct xt_target {
    unsigned int (*target)(struct sk_buff *, const struct xt_action_param *);
};
struct net_device {
    char name[IFNAMSIZ];
};
struct xt_standard_target {
    int verdict;
};

static inline unsigned int arp_hdr_len(const struct net_device *dev) {
    return sizeof(struct arphdr);
}
static inline bool pskb_may_pull(struct sk_buff *skb, unsigned int len) {
    return true;
}
static inline void local_bh_disable(void) {}
static inline void local_bh_enable(void) {}
static inline unsigned int xt_write_recseq_begin(void) { return 0; }
static inline void xt_write_recseq_end(unsigned int addend) {}
static inline struct arpt_entry *get_entry(const void *base, unsigned int offset) {
    return (struct arpt_entry *)((char *)base + offset);
}
static inline struct arpt_entry *arpt_next_entry(const struct arpt_entry *entry) {
    return (struct arpt_entry *)((char *)entry + entry->next_offset);
}
static inline const struct xt_entry_target *arpt_get_target_c(const struct arpt_entry *e) {
    return (const struct xt_entry_target *)((char *)e + e->target_offset);
}
static inline bool arp_packet_match(const struct arphdr *arp, const void *dev, 
                                  const char *indev, const char *outdev, const void *arpinfo) {
    return true;
}
static inline struct xt_counters *xt_get_this_cpu_counter(struct xt_counters *cnt) {
    return cnt;
}
static inline struct arphdr *arp_hdr(const struct sk_buff *skb) {
    return (struct arphdr *)skb;
}
#define ADD_COUNTER(c, b, p) do { (c).pcnt += (p); (c).bcnt += (b); } while (0)
#define READ_ONCE(x) (x)
#define rcu_access_pointer(p) (p)
#define smp_processor_id() 0
#define unlikely(x) (x)