#include <stddef.h>

struct net {
    struct {
        int count;
        int sysctl_checksum;
        int sysctl_log_invalid;
        int sysctl_acct;
        int sysctl_auto_assign_helper;
        int sysctl_events;
        int sysctl_tstamp;
    } ct;
    struct user_namespace *user_ns;
};

struct nf_conntrack_net {
    void *sysctl_header;
};

struct nf_udp_net {
    int timeouts[2];
};

struct ctl_table {
    void *data;
    int mode;
};

struct user_namespace {
    int dummy;
};

struct nf_generic_net {
    int timeout;
};

struct nf_icmp_net {
    int timeout;
};

struct nf_icmpv6_net {
    int timeout;
};

extern struct net init_net;
extern struct user_namespace init_user_ns;
extern const struct ctl_table nf_ct_sysctl_table[15];
extern int nf_conntrack_net_id;

#define BUILD_BUG_ON(cond)
#define GFP_KERNEL 0
#define ENOMEM 0
#define CONFIG_NF_CONNTRACK_EVENTS
#define CONFIG_NF_CONNTRACK_TIMESTAMP

#define NF_SYSCTL_CT_LAST_SYSCTL 15
#define NF_SYSCTL_CT_COUNT 0
#define NF_SYSCTL_CT_CHECKSUM 1
#define NF_SYSCTL_CT_LOG_INVALID 2
#define NF_SYSCTL_CT_ACCT 3
#define NF_SYSCTL_CT_HELPER 4
#define NF_SYSCTL_CT_EVENTS 5
#define NF_SYSCTL_CT_TIMESTAMP 6
#define NF_SYSCTL_CT_PROTO_TIMEOUT_GENERIC 7
#define NF_SYSCTL_CT_PROTO_TIMEOUT_ICMP 8
#define NF_SYSCTL_CT_PROTO_TIMEOUT_ICMPV6 9
#define NF_SYSCTL_CT_PROTO_TIMEOUT_UDP 10
#define NF_SYSCTL_CT_PROTO_TIMEOUT_UDP_STREAM 11
#define NF_SYSCTL_CT_MAX 12
#define NF_SYSCTL_CT_EXPECT_MAX 13
#define NF_SYSCTL_CT_BUCKETS 14

#define UDP_CT_UNREPLIED 0
#define UDP_CT_REPLIED 1

static inline struct nf_conntrack_net *net_generic(struct net *net, int id) { return NULL; }
static inline struct nf_udp_net *nf_udp_pernet(struct net *net) { return NULL; }
static inline void *kmemdup(const void *src, size_t len, int gfp) { return NULL; }
static inline void kfree(void *ptr) {}
static inline void *register_net_sysctl(struct net *net, const char *path, struct ctl_table *table) { return NULL; }
static inline int net_eq(struct net *net1, struct net *net2) { return 0; }
static inline struct nf_generic_net *nf_generic_pernet(struct net *net) { return NULL; }
static inline struct nf_icmp_net *nf_icmp_pernet(struct net *net) { return NULL; }
static inline struct nf_icmpv6_net *nf_icmpv6_pernet(struct net *net) { return NULL; }
static inline void nf_conntrack_standalone_init_tcp_sysctl(struct net *net, struct ctl_table *table) {}
static inline void nf_conntrack_standalone_init_sctp_sysctl(struct net *net, struct ctl_table *table) {}
static inline void nf_conntrack_standalone_init_dccp_sysctl(struct net *net, struct ctl_table *table) {}
static inline void nf_conntrack_standalone_init_gre_sysctl(struct net *net, struct ctl_table *table) {}