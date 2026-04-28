#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include <sys/uio.h>

#define ETH_MAX_L2_HDR_LEN 18
#define ETH_MAX_IP4_HDR_LEN 60
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
    uint8_t ip_v:4;
    uint8_t ip_hl:4;
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

#define IP_HDR_GET_LEN(hdr) (((struct ip_header *)(hdr))->ip_hl * 4)
#define PKT_GET_ETH_HDR(hdr) ((struct eth_header *)(hdr))

struct VmxnetTxPkt {
    struct iovec *vec;
    struct iovec *raw;
    int raw_frags;
    uint8_t l4proto;
    uint32_t packet_type;
};

enum {
    VMXNET_TX_PKT_L2HDR_FRAG,
    VMXNET_TX_PKT_L3HDR_FRAG
};

static size_t iov_to_buf(const struct iovec *iov, const unsigned int iov_cnt,
                        size_t offset, void *buf, size_t bytes);
static uint16_t eth_get_l3_proto(const void *l2hdr, size_t l2hdr_len);
static bool eth_parse_ipv6_hdr(const struct iovec *pkt, int pkt_frags,
                              size_t ip6hdr_off, uint8_t *l4proto,
                              size_t *full_ip6hdr_len);
static void vmxnet_tx_pkt_calculate_hdr_len(struct VmxnetTxPkt *pkt);
static uint32_t get_eth_packet_type(const void *l2hdr);
static void *g_malloc(size_t size);
static uint16_t be16_to_cpu(uint16_t val);