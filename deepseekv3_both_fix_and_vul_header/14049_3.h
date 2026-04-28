#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <netinet/in.h>

typedef uint16_t __be16;
typedef uint32_t __be32;
typedef uint8_t u8;
typedef uint16_t u16;

struct sk_buff {
    void *data;
    __be16 protocol;
};

struct flow_dissector;
struct flow_dissector_key_control {
    u16 addr_type;
    u16 thoff;
};
struct flow_dissector_key_basic {
    __be16 n_proto;
    u8 ip_proto;
};
struct flow_dissector_key_addrs {
    union {
        struct {
            __be32 src;
            __be32 dst;
        } v4addrs;
        struct {
            __be32 srcnode;
        } tipcaddrs;
    };
};
struct flow_dissector_key_ports {
    __be16 ports;
};
struct flow_dissector_key_tags {
    __be32 flow_label;
    __be16 vlan_id;
};
struct flow_dissector_key_keyid {
    __be32 keyid;
};
struct flow_dissector_key_eth_addrs {
    u8 h_dest[6];
};
struct flow_dissector_key_ipv6_addrs {
    u8 saddr[16];
};
struct ethhdr {
    u8 h_dest[6];
    __be16 h_proto;
};
struct vlan_hdr {
    __be16 h_vlan_encapsulated_proto;
};
struct pppoe_hdr {
    u8 ver;
};
struct mpls_label {
    __be32 entry;
};
struct iphdr {
    u8 ihl;
    u8 protocol;
    __be32 saddr;
};
struct ipv6hdr {
    u8 nexthdr;
    u8 saddr[16];
};

#define ETH_P_IP 0x0800
#define ETH_P_IPV6 0x86DD
#define ETH_P_8021Q 0x8100
#define ETH_P_8021AD 0x88A8
#define ETH_P_PPP_SES 0x8864
#define ETH_P_TIPC 0x88CA
#define ETH_P_MPLS_UC 0x8847
#define ETH_P_MPLS_MC 0x8848
#define ETH_P_TEB 0x6558
#define ETH_P_FCOE 0x8906

#define PPP_IP 0x0021
#define PPP_IPV6 0x0057

#define NEXTHDR_HOP 0
#define NEXTHDR_ROUTING 43
#define NEXTHDR_DEST 60

#define FLOW_DISSECTOR_KEY_CONTROL 0
#define FLOW_DISSECTOR_KEY_BASIC 1
#define FLOW_DISSECTOR_KEY_ETH_ADDRS 2
#define FLOW_DISSECTOR_KEY_IPV4_ADDRS 3
#define FLOW_DISSECTOR_KEY_IPV6_ADDRS 4
#define FLOW_DISSECTOR_KEY_FLOW_LABEL 5
#define FLOW_DISSECTOR_KEY_VLANID 6
#define FLOW_DISSECTOR_KEY_TIPC_ADDRS 7
#define FLOW_DISSECTOR_KEY_MPLS_ENTROPY 8
#define FLOW_DISSECTOR_KEY_GRE_KEYID 9
#define FLOW_DISSECTOR_KEY_PORTS 10

#define MPLS_LS_LABEL_MASK 0xFFFFF000
#define MPLS_LS_LABEL_SHIFT 12
#define MPLS_LABEL_ENTROPY 7
#define FCOE_HEADER_LEN 14
#define PPPOE_SES_HLEN 8

#define GRE_VERSION 0x8000
#define GRE_ROUTING 0x4000
#define GRE_CSUM 0x2000
#define GRE_KEY 0x2000
#define GRE_SEQ 0x1000

#define IPPROTO_GRE 47
#define IPPROTO_IPIP 4
#define IPPROTO_IPV6 41
#define IPPROTO_MPLS 137

static inline int skb_network_offset(const struct sk_buff *skb) { return 0; }
static inline int skb_headlen(const struct sk_buff *skb) { return 0; }
static inline uint16_t skb_vlan_tag_get_id(const struct sk_buff *skb) { return 0; }
static inline __be32 ip6_flowlabel(const struct ipv6hdr *hdr) { return 0; }
static inline bool ip_is_fragment(const struct iphdr *iph) { return false; }
static inline struct ethhdr *eth_hdr(const struct sk_buff *skb) { return NULL; }

static inline void *skb_flow_dissector_target(const struct flow_dissector *flow_dissector,
                                            int key_id, void *target_container) { return NULL; }
static inline bool skb_flow_dissector_uses_key(const struct flow_dissector *flow_dissector,
                                             int key_id) { return false; }
static inline __be16 __skb_flow_get_ports(const struct sk_buff *skb, int nhoff,
                                        u8 ip_proto, void *data, int hlen) { return 0; }
static inline void *__skb_header_pointer(const struct sk_buff *skb, int offset,
                                       int len, void *data, int hlen, void *buffer) { return NULL; }

#define htons(x) ((__be16)__builtin_bswap16((uint16_t)(x)))
#define ntohl(x) ((uint32_t)__builtin_bswap32((__be32)(x)))
#define htonl(x) ((__be32)__builtin_bswap32((uint32_t)(x)))