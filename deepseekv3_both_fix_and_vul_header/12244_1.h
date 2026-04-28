#include <linux/bpf.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <linux/icmp.h>
#include <linux/in.h>
#include <linux/types.h>

#define ICMP_TOOBIG_SIZE (sizeof(struct icmphdr) + sizeof(struct iphdr) + 8)
#define ICMP_TOOBIG_PAYLOAD_SIZE (sizeof(struct icmphdr) + sizeof(struct iphdr) + 8)
#define MAX_PCKT_SIZE 1500
#define DEFAULT_TTL 64
#define ICMP_DEST_UNREACH 3
#define ICMP_FRAG_NEEDED 4

#define XDP_DROP 1
#define XDP_TX 2

static inline unsigned short bpf_htons(unsigned short hostshort) {
    return ((hostshort & 0xff) << 8) | ((hostshort & 0xff00) >> 8);
}

static inline void swap_mac(void* data, struct ethhdr* orig_eth) {
    struct ethhdr* eth = data;
    __builtin_memcpy(eth->h_source, orig_eth->h_dest, ETH_ALEN);
    __builtin_memcpy(eth->h_dest, orig_eth->h_source, ETH_ALEN);
    eth->h_proto = orig_eth->h_proto;
}

static inline void ipv4_csum(void* data, int size, __u64* csum) {
    *csum = bpf_csum_diff(0, 0, data, size, 0);
    *csum = bpf_htons((unsigned short)(~(*csum & 0xffff)));
}