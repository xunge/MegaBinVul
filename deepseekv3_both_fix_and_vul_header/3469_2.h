#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>

enum ip_conntrack_info {
    IP_CT_ESTABLISHED,
    IP_CT_RELATED,
    IP_CT_NEW,
    IP_CT_IS_REPLY,
    IP_CT_NUMBER
};

enum ip_conntrack_dir {
    IP_CT_DIR_ORIGINAL,
    IP_CT_DIR_REPLY,
    IP_CT_DIR_MAX
};

#define CTINFO2DIR(ctinfo) ((ctinfo) >= IP_CT_IS_REPLY ? IP_CT_DIR_REPLY : IP_CT_DIR_ORIGINAL)

enum ct_dccp_roles {
    CT_DCCP_ROLE_CLIENT,
    CT_DCCP_ROLE_SERVER,
    CT_DCCP_ROLE_MAX
};

enum ct_dccp_states {
    CT_DCCP_NONE,
    CT_DCCP_REQUEST,
    CT_DCCP_RESPOND,
    CT_DCCP_PARTOPEN,
    CT_DCCP_OPEN,
    CT_DCCP_CLOSEREQ,
    CT_DCCP_CLOSING,
    CT_DCCP_TIMEWAIT,
    CT_DCCP_IGNORE,
    CT_DCCP_INVALID,
    CT_DCCP_MAX
};

#define DCCP_PKT_REQUEST   0
#define DCCP_PKT_RESPONSE  1
#define DCCP_PKT_DATA      2
#define DCCP_PKT_ACK       3
#define DCCP_PKT_RESET     7

#define NF_ACCEPT 1

struct dccp_hdr {
    uint16_t dccph_sport;
    uint16_t dccph_dport;
    uint8_t  dccph_doff;
    uint8_t  dccph_ccval;
    uint16_t dccph_checksum;
    uint8_t  dccph_reserved1;
    uint8_t  dccph_type;
    uint8_t  dccph_x;
    uint16_t dccph_seq;
};

struct nf_conn {
    struct {
        struct {
            uint8_t state;
            uint8_t role[IP_CT_DIR_MAX];
            uint8_t last_dir;
            uint8_t last_pkt;
            uint64_t handshake_seq;
        } dccp;
    } proto;
    unsigned long status;
    void *lock;
};

struct sk_buff;
struct net;

static inline struct net *nf_ct_net(const struct nf_conn *ct) { return NULL; }
static inline void spin_lock_bh(void *lock) {}
static inline void spin_unlock_bh(void *lock) {}
static inline void set_bit(int nr, volatile unsigned long *addr) {}
static inline int test_bit(int nr, const volatile unsigned long *addr) { return 0; }
static inline void *skb_header_pointer(const struct sk_buff *skb, int offset, int len, void *buffer) { return NULL; }
static inline uint64_t dccp_hdr_seq(const void *hdr) { return 0; }
static inline uint64_t dccp_ack_seq(const void *hdr) { return 0; }
static inline void nf_ct_kill_acct(struct nf_conn *ct, enum ip_conntrack_info ctinfo, const struct sk_buff *skb) {}
static inline void nf_ct_refresh_acct(struct nf_conn *ct, enum ip_conntrack_info ctinfo, const struct sk_buff *skb, unsigned long extra_jiffies) {}
static inline void nf_conntrack_event_cache(unsigned long events, struct nf_conn *ct) {}
static inline void nf_log_packet(struct net *net, uint8_t pf, unsigned int hooknum, const struct sk_buff *skb, const void *in, const void *out, const void *prefix, const char *fmt) {}

#define LOG_INVALID(net, proto) 0
#define IPS_SEEN_REPLY_BIT 0
#define IPS_ASSURED_BIT 1
#define IPCT_PROTOINFO 0
#define IPPROTO_DCCP 0
#define BUG_ON(cond) do { if (cond) {} } while (0)

static const uint8_t dccp_state_table[CT_DCCP_ROLE_MAX][DCCP_PKT_RESET + 1][CT_DCCP_MAX] = {0};