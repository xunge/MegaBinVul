#include <stdint.h>
#include <string.h>
#include <errno.h>

#define GFP_ATOMIC 0
#define IS_ERR(x) 0
#define PTR_ERR(x) 0
#define ERR_PTR(x) ((void*)(long)(x))
#define HZ 100
#define CONFIG_MODULES 1
#define CONFIG_NF_CONNTRACK_MARK 1

#define ntohl(x) (x)
#define nla_get_be32(x) (0)

#define IPS_HELPER 0x01
#define IPS_CONFIRMED 0x02
#define IPS_EXPECTED_BIT 0x03

struct nlattr;
struct net;
struct nf_conntrack_zone;
struct nf_conn;
struct nf_conntrack_helper;
struct nf_conn_tstamp;
struct nf_conn_help;
struct nf_conntrack_tuple_hash;

struct nf_conntrack_tuple {
    int dummy;
};

struct nf_conntrack_helper {
    int (*from_nlattr)(struct nlattr *attr, struct nf_conn *ct);
};

struct nf_conn {
    unsigned long status;
    void *proto;
    struct nf_conn *master;
};

struct nf_conn_help {
    struct nf_conntrack_helper *helper;
};

struct nf_conn_tstamp {
    uint64_t start;
};

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;

enum {
    CTA_TIMEOUT,
    CTA_HELP,
    CTA_STATUS,
    CTA_SEQ_ADJ_ORIG,
    CTA_SEQ_ADJ_REPLY,
    CTA_PROTOINFO,
    CTA_SYNPROXY,
    CTA_MARK,
    CTA_TUPLE_MASTER
};

static inline void rcu_read_lock() {}
static inline void rcu_read_unlock() {}
static inline int request_module(const char *fmt, ...) { return 0; }
static inline void RCU_INIT_POINTER(void *p, void *v) {}
static inline void __set_bit(int nr, volatile void *addr) {}
static inline struct nf_conn *nf_conntrack_alloc(struct net *net, const struct nf_conntrack_zone *zone,
    struct nf_conntrack_tuple *otuple, struct nf_conntrack_tuple *rtuple, int flags) { return NULL; }
static inline void nf_conntrack_free(struct nf_conn *ct) {}
static inline void __nf_ct_set_timeout(struct nf_conn *ct, u64 timeout) {}
static inline int ctnetlink_parse_help(const struct nlattr *attr, char **name, struct nlattr **info) { return 0; }
static inline struct nf_conntrack_helper *__nf_conntrack_helper_find(const char *name, int l3num, int protonum) { return NULL; }
static inline int nf_ct_l3num(const struct nf_conn *ct) { return 0; }
static inline int nf_ct_protonum(const struct nf_conn *ct) { return 0; }
static inline struct nf_conn_help *nf_ct_helper_ext_add(struct nf_conn *ct, int flags) { return NULL; }
static inline int ctnetlink_setup_nat(struct nf_conn *ct, const struct nlattr * const cda[]) { return 0; }
static inline void nf_ct_acct_ext_add(struct nf_conn *ct, int flags) {}
static inline void nf_ct_tstamp_ext_add(struct nf_conn *ct, int flags) {}
static inline void nf_ct_ecache_ext_add(struct nf_conn *ct, int a, int b, int flags) {}
static inline void nf_ct_labels_ext_add(struct nf_conn *ct) {}
static inline void nfct_seqadj_ext_add(struct nf_conn *ct) {}
static inline void nfct_synproxy_ext_add(struct nf_conn *ct) {}
static inline int ctnetlink_change_status(struct nf_conn *ct, const struct nlattr * const cda[]) { return 0; }
static inline int ctnetlink_change_seq_adj(struct nf_conn *ct, const struct nlattr * const cda[]) { return 0; }
static inline int ctnetlink_change_protoinfo(struct nf_conn *ct, const struct nlattr * const cda[]) { return 0; }
static inline int ctnetlink_change_synproxy(struct nf_conn *ct, const struct nlattr * const cda[]) { return 0; }
static inline void ctnetlink_change_mark(struct nf_conn *ct, const struct nlattr * const cda[]) {}
static inline int ctnetlink_parse_tuple(const struct nlattr * const cda[], struct nf_conntrack_tuple *tuple, int type, u8 u3, void *unused) { return 0; }
static inline struct nf_conntrack_tuple_hash *nf_conntrack_find_get(struct net *net, const struct nf_conntrack_zone *zone, struct nf_conntrack_tuple *tuple) { return NULL; }
static inline struct nf_conn *nf_ct_tuplehash_to_ctrack(struct nf_conntrack_tuple_hash *hash) { return NULL; }
static inline struct nf_conn_tstamp *nf_conn_tstamp_find(struct nf_conn *ct) { return NULL; }
static inline int nf_conntrack_hash_check_insert(struct nf_conn *ct) { return 0; }
static inline uint64_t ktime_get_real_ns() { return 0; }