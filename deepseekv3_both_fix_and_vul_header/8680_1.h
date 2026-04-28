#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include <stddef.h>

#define ETH_MAX_L2_HDR_LEN 18
#define ETH_MAX_IP4_HDR_LEN 60
#define VMXNET_TX_PKT_L2HDR_FRAG 0
#define VMXNET_TX_PKT_L3HDR_FRAG 1
#define ETH_P_VLAN 0x8100
#define ETH_P_DVLAN 0x88A8
#define ETH_P_IP 0x0800
#define ETH_P_IPV6 0x86DD

struct eth_header {
    uint8_t h_dest[6];
    uint8_t h_source[6];
    uint16_t h_proto;
};

struct vlan_header {
    uint16_t h_tci;
    uint16_t h_proto;
};

struct ip_header {
    uint8_t ip_ver_len;
    uint8_t ip_tos;
    uint16_t ip_len;
    uint16_t ip_id;
    uint16_t ip_off;
    uint8_t ip_ttl;
    uint8_t ip_p;
    uint16_t ip_sum;
    uint32_t ip_src;
    uint32_t ip_dst;
};

struct VmxnetTxPkt {
    struct iovec *vec;
    void *raw;
    int raw_frags;
    uint8_t l4proto;
    uint32_t packet_type;
};

struct iovec {
    void *iov_base;
    size_t iov_len;
};

#define PKT_GET_ETH_HDR(p) ((struct eth_header *)(p))
#define IP_HDR_GET_LEN(p) (((struct ip_header *)(p))->ip_ver_len & 0x0F) * 4

uint16_t be16_to_cpu(uint16_t x);
uint16_t eth_get_l3_proto(const void *l2hdr, size_t l2hdr_len);
bool eth_parse_ipv6_hdr(const void *pkt, int pkt_frags, size_t ip6hdr_off,
                       uint8_t *l4proto, size_t *full_hdr_len);
void vmxnet_tx_pkt_calculate_hdr_len(struct VmxnetTxPkt *pkt);
uint32_t get_eth_packet_type(const void *l2hdr);
size_t iov_to_buf(const void *pkt, int pkt_frags, size_t offset,
                 void *buf, size_t bytes);
void *g_malloc(size_t size);