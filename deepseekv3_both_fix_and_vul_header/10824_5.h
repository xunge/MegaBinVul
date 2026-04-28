#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <arpa/inet.h>

#define IFNAMSIZ 16
#define NF_DROP 0
#define XT_CONTINUE 0xFFFFFFFF
#define XT_RETURN (-2)
#define IP_OFFSET 0x1FFF
#define NF_MAX_VERDICT 5
#define IPT_F_GOTO (1 << 0)

typedef uint16_t __be16;

struct sk_buff {
    unsigned int len;
    void *nf_trace;
};

struct net_device {
    char name[IFNAMSIZ];
};

struct nf_hook_state {
    unsigned int hook;
    struct net_device *in;
    struct net_device *out;
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

struct xt_match {
    int (*match)(const struct sk_buff *, void *);
};

struct xt_target {
    unsigned int (*target)(struct sk_buff *, const void *);
};

struct xt_action_param {
    unsigned int fragoff;
    unsigned int thoff;
    bool hotdrop;
    const struct nf_hook_state *state;
    struct xt_match *match;
    void *matchinfo;
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
    unsigned short target_offset;
};

struct xt_entry_match {
    union {
        struct {
            struct xt_match *match;
        } kernel;
    } u;
    void *data;
    unsigned short match_size;
};

struct xt_counters {
    uint64_t pcnt;
    uint64_t bcnt;
};

struct xt_standard_target {
    int verdict;
};

struct ipt_ip {
    unsigned int flags;
};

struct ipt_entry {
    struct ipt_ip ip;
    struct xt_counters counters;
    unsigned int next_offset;
};

struct iphdr {
    __be16 frag_off;
};

static bool xt_tee_enabled;
static unsigned int nf_skb_duplicated;

static inline const struct iphdr *ip_hdr(const struct sk_buff *skb) { return NULL; }
static inline unsigned int ip_hdrlen(const struct sk_buff *skb) { return 0; }
static inline void local_bh_disable(void) {}
static inline void local_bh_enable(void) {}
static inline unsigned int xt_write_recseq_begin(void) { return 0; }
static inline void xt_write_recseq_end(unsigned int addend) {}
static inline struct ipt_entry *ipt_next_entry(const struct ipt_entry *entry) { return NULL; }
static inline struct xt_counters *xt_get_this_cpu_counter(struct xt_counters *cnt) { return cnt; }
static inline int ip_packet_match(const struct iphdr *ip, const char *indev, const char *outdev, const struct ipt_ip *e, unsigned int fragoff) { return 0; }
static inline struct xt_entry_target *ipt_get_target(struct ipt_entry *e) { return NULL; }
static inline struct ipt_entry *get_entry(const void *base, unsigned int offset) { return NULL; }
static inline void WARN_ON(bool condition) {}
static inline unsigned int smp_processor_id(void) { return 0; }
static inline void *READ_ONCE(const void *ptr) { return (void *)ptr; }
static inline bool static_key_false(const bool *key) { return *key; }
static inline unsigned int __this_cpu_read(unsigned int var) { return var; }

#define xt_ematch_foreach(ematch, e) \
    for ((ematch) = (const struct xt_entry_match *)((char *)(e) + sizeof(struct ipt_entry)); \
         (char *)(ematch) < (char *)(e) + (e)->next_offset; \
         (ematch) = (const struct xt_entry_match *)((char *)(ematch) + (ematch)->match_size))

#define ADD_COUNTER(counter, len, num) \
    do { (counter).pcnt += (num); (counter).bcnt += (len); } while (0)

#define IS_ENABLED(x) 0