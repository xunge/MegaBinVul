#include <stdint.h>
#include <linux/ip.h>

#define DEFAULT_TOS 0
#define DEFAULT_TTL 64

static inline __u16 bpf_htons(__u16 x) {
    return ((__u16)(((x & 0x00ff) << 8) | ((x & 0xff00) >> 8)));
}

static inline void ipv4_csum_inline(struct iphdr *iph, __u64 *csum) {
    unsigned short *buf = (unsigned short *)iph;
    __u32 sum = 0;
    for (int i = 0; i < sizeof(struct iphdr) >> 1; i++) {
        sum += buf[i];
    }
    *csum = (sum >> 16) + (sum & 0xffff);
    *csum += (*csum >> 16);
    *csum = ~(*csum);
}