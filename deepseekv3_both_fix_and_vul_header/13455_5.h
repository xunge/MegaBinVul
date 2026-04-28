#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <arpa/inet.h>

#define IFNAMSIZ 16
#define NF_DROP 0
#define XT_CONTINUE 0
#define XT_RETURN 1
#define IPT_F_GOTO 0x01
#define IP_OFFSET 0x1FFF

struct sk_buff {
    unsigned int len;
    void* nf_trace;
};

struct nf_hook_state {
    unsigned int hook;
    struct {
        const char* name;
    } *in, *out;
    void* net;
};

struct xt_table {
    unsigned int valid_hooks;
    void* private;
    const char* name;
};

struct xt_table_info {
    void* entries;
    void** jumpstack;
    unsigned int stacksize;
    unsigned int* hook_entry;
    unsigned int* underflow;
};

struct xt_action_param {
    unsigned int fragoff;
    unsigned int thoff;
    bool hotdrop;
    const struct nf_hook_state* state;
    struct {
        int (*match)(const struct sk_buff*, struct xt_action_param*);
    } *match;
    void* matchinfo;
    struct {
        unsigned int (*target)(struct sk_buff*, const struct xt_action_param*);
    } *target;
    void* targinfo;
};

struct xt_match {
    int (*match)(const struct sk_buff*, struct xt_action_param*);
};

struct xt_target {
    unsigned int (*target)(struct sk_buff*, const struct xt_action_param*);
};

struct xt_entry_target {
    union {
        struct {
            struct xt_target *target;
        } kernel;
    } u;
    void* data;
    unsigned int target_size;
};

struct xt_entry_match {
    union {
        struct {
            struct xt_match *match;
        } kernel;
    } u;
    void* data;
    unsigned int match_size;
};

struct xt_counters {
    uint64_t pcnt;
    uint64_t bcnt;
};

struct xt_standard_target {
    int verdict;
    char data[0];
};

struct ipt_entry {
    struct {
        unsigned int flags;
    } ip;
    struct xt_counters counters;
    unsigned int next_offset;
    unsigned int comefrom;
    unsigned short target_offset;
    unsigned short next_offset_hook;
};

struct iphdr {
    uint16_t frag_off;
};

struct static_key_false {
    bool enabled;
};

static struct static_key_false xt_tee_enabled;
static unsigned int nf_skb_duplicated;

#define WARN_ON(cond) (void)(cond)
#define local_bh_disable()
#define local_bh_enable()
#define READ_ONCE(x) (x)
#define smp_processor_id() 0
#define __this_cpu_read(x) (x)
#define static_key_false(x) ((x)->enabled)
#define IS_ENABLED(x) 0
#define unlikely(x) (x)

static inline const struct iphdr* ip_hdr(const struct sk_buff* skb) {
    return (const struct iphdr*)skb;
}

static inline unsigned int ip_hdrlen(const struct sk_buff* skb) {
    return sizeof(struct iphdr);
}

static inline struct ipt_entry* get_entry(const void* base, unsigned int offset) {
    return (struct ipt_entry*)((char*)base + offset);
}

static inline struct ipt_entry* ipt_next_entry(const struct ipt_entry* entry) {
    return (struct ipt_entry*)((char*)entry + entry->next_offset);
}

static inline int ip_packet_match(const struct iphdr* ip,
                                const char* indev,
                                const char* outdev,
                                const void* ipinfo,
                                unsigned int fragoff) {
    return 1;
}

#define xt_ematch_foreach(ematch, e) \
    for ((ematch) = (const struct xt_entry_match*)((char*)(e) + sizeof(struct ipt_entry)); \
         (char*)(ematch) < (char*)(e) + (e)->next_offset; \
         (ematch) = (const struct xt_entry_match*)((char*)(ematch) + (ematch)->match_size))

static inline struct xt_counters* xt_get_this_cpu_counter(struct xt_counters* cnt) {
    return cnt;
}

#define ADD_COUNTER(c, b, p) do { (c).pcnt += (p); (c).bcnt += (b); } while (0)

static inline struct xt_entry_target* ipt_get_target_c(struct ipt_entry* e) {
    return (struct xt_entry_target*)((char*)e + e->target_offset);
}

static inline unsigned int xt_write_recseq_begin(void) {
    return 0;
}

static inline void xt_write_recseq_end(unsigned int addend) {
}