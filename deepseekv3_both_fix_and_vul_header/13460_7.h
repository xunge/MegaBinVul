#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define IFNAMSIZ 16
#define NF_DROP 0
#define XT_RETURN (-1)
#define XT_CONTINUE 0
#define IP6T_F_GOTO (1 << 0)

struct sk_buff {
    unsigned int len;
    unsigned int nf_trace;
};

struct net_device {
    const char *name;
};

struct nf_hook_state {
    unsigned int hook;
    struct net_device *in;
    struct net_device *out;
    void *net;
};

struct xt_table {
    unsigned int valid_hooks;
    void *private;
    const char *name;
};

struct xt_table_info {
    void *entries;
    void *jumpstack[1];
    unsigned int stacksize;
    unsigned int hook_entry[1];
    unsigned int underflow[1];
};

struct ip6t_ipv6 {
    unsigned int flags;
};

struct xt_counters {
    unsigned long pcnt;
    unsigned long bcnt;
};

struct ip6t_entry {
    struct ip6t_ipv6 ipv6;
    struct xt_counters counters;
};

struct xt_match {
    bool (*match)(const struct sk_buff *, void *);
};

struct xt_target {
    unsigned int (*target)(struct sk_buff *, void *);
};

struct xt_action_param {
    bool hotdrop;
    const struct nf_hook_state *state;
    int thoff;
    int fragoff;
    const struct xt_match *match;
    void *matchinfo;
    const struct xt_target *target;
    void *targinfo;
};

struct xt_udata_kernel {
    const struct xt_match *match;
    const struct xt_target *target;
};

struct xt_udata {
    struct xt_udata_kernel kernel;
    void *data;
};

struct xt_entry_target {
    struct xt_udata u;
    void *data;
};

struct xt_entry_match {
    struct xt_udata u;
    void *data;
};

struct xt_standard_target {
    int verdict;
};

#define WARN_ON(cond) (void)(cond)
#define static_key_false(key) false
#define __this_cpu_read(var) 0
#define smp_processor_id() 0
#define local_bh_disable()
#define local_bh_enable()
#define READ_ONCE(x) (x)
#define rcu_access_pointer(p) (p)
#define ADD_COUNTER(counter, len, num) do { (counter).pcnt += (num); (counter).bcnt += (len); } while (0)
#define unlikely(x) (x)
#define xt_ematch_foreach(ematch, e) for ((ematch) = NULL; (ematch) != NULL; (ematch) = NULL)
#define IS_ENABLED(x) 0

static inline unsigned int xt_write_recseq_begin() { return 0; }
static inline void xt_write_recseq_end(unsigned int addend) {}
static inline struct xt_counters *xt_get_this_cpu_counter(void *counter) { return counter; }
static inline struct ip6t_entry *get_entry(const void *base, unsigned int offset) { return (struct ip6t_entry *)((char *)base + offset); }
static inline struct ip6t_entry *ip6t_next_entry(const struct ip6t_entry *entry) { return (struct ip6t_entry *)((char *)entry + sizeof(*entry)); }
static inline bool ip6_packet_match(struct sk_buff *skb, const char *indev, const char *outdev, void *ipv6, int *thoff, int *fragoff, bool *hotdrop) { return false; }
static inline struct xt_entry_target *ip6t_get_target_c(struct ip6t_entry *e) { return (struct xt_entry_target *)((char *)e + sizeof(*e)); }