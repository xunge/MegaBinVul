#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define IFNAMSIZ 16
#define NF_DROP 0
#define XT_CONTINUE 0xFFFFFFFF
#define XT_RETURN (-2)
#define IP6T_F_GOTO (1 << 0)
#define IS_ENABLED(x) 0

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

struct xt_counters {
    unsigned long pcnt;
    unsigned long bcnt;
};

struct ip6t_entry {
    struct {
        unsigned int flags;
    } ipv6;
    struct xt_counters counters;
};

struct xt_match {
    int (*match)(struct sk_buff *, void *);
};

struct xt_target {
    unsigned int (*target)(struct sk_buff *, void *);
};

struct xt_entry_match {
    union {
        struct {
            struct xt_match *match;
        } kernel;
    } u;
    void *data;
};

struct xt_entry_target {
    union {
        struct {
            struct xt_target *target;
        } kernel;
    } u;
    void *data;
};

struct xt_standard_target {
    int verdict;
};

struct xt_action_param {
    bool hotdrop;
    const struct nf_hook_state *state;
    unsigned int thoff;
    unsigned int fragoff;
    struct xt_match *match;
    void *matchinfo;
    struct xt_target *target;
    void *targinfo;
};

static struct {
    bool enabled;
} xt_tee_enabled;

static int nf_skb_duplicated;

#define WARN_ON(cond) (void)(cond)
#define local_bh_disable()
#define local_bh_enable()
#define smp_processor_id() 0
#define READ_ONCE(x) (x)
#define __this_cpu_read(x) (x)
#define static_key_false(x) ((x)->enabled)
#define xt_write_recseq_begin() 0
#define xt_write_recseq_end(x) (void)(x)
#define xt_ematch_foreach(ematch, e) for (ematch = NULL; ematch != (void*)(e)+1; ematch = (void*)(ematch)+1)
#define xt_get_this_cpu_counter(x) (x)
#define ADD_COUNTER(counter, a, b) do { (counter).pcnt += (b); (counter).bcnt += (a); } while (0)
#define ip6t_get_target_c(e) ((struct xt_entry_target*)((char*)(e) + sizeof(struct ip6t_entry)))
#define ip6t_next_entry(e) ((struct ip6t_entry*)((char*)(e) + sizeof(struct ip6t_entry)))
#define get_entry(base, offset) ((struct ip6t_entry*)((char*)(base) + (offset)))

static bool ip6_packet_match(const struct sk_buff *skb, const char *indev,
                           const char *outdev, const void *ipv6,
                           unsigned int *thoff, unsigned int *fragoff,
                           bool *hotdrop) {
    return false;
}