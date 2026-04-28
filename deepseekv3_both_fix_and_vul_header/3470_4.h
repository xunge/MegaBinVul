#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define CT_DCCP_ROLE_CLIENT 0
#define CT_DCCP_ROLE_SERVER 1
#define CT_DCCP_ROLE_MAX 2
#define CT_DCCP_NONE 0
#define CT_DCCP_MAX 1
#define CT_DCCP_REQUEST 0
#define CT_DCCP_INVALID 1
#define DCCP_PKT_REQUEST 0
#define DCCP_PKT_SYNCACK 1
#define IP_CT_DIR_ORIGINAL 0
#define IP_CT_DIR_REPLY 1
#define IPPROTO_DCCP 33

typedef uint8_t u_int8_t;

struct dccp_hdr {
    uint8_t dccph_type;
};

struct dccp_net {
    int dccp_loose;
};

struct net;
struct sk_buff;

struct nf_conn {
    struct {
        struct {
            uint8_t role[2];
            uint8_t state;
            uint8_t last_pkt;
            uint8_t last_dir;
            uint32_t handshake_seq;
        } dccp;
    } proto;
};

#define BUG_ON(condition) ((void)0)

extern struct net *nf_ct_net(struct nf_conn *ct);
extern struct dccp_net *dccp_pernet(struct net *net);
extern void *skb_header_pointer(const struct sk_buff *skb, unsigned int offset, unsigned int len, void *buffer);
extern int nf_ct_l3num(const struct nf_conn *ct);
extern void nf_log_packet(struct net *net, int pf, unsigned int hooknum, const struct sk_buff *skb, const void *in, const void *out, const char *prefix, const char *fmt, ...);
extern bool LOG_INVALID(struct net *net, int proto);

uint8_t dccp_state_table[CT_DCCP_ROLE_MAX][DCCP_PKT_SYNCACK + 1][CT_DCCP_MAX + 1];