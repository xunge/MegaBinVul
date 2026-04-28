#include <stdint.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <string.h>

#define DLT_EN10MB 1
#define DLT_JUNIPER_ETHER 14
#define TCPR_IPV6_H 40
#define ETHERTYPE_IP 0x0800
#define ETHERTYPE_IP6 0x86DD
#define ETHERTYPE_VLAN 0x8100
#define COUNTER_SPEC "%u"
#define ETHER_ADDR_LEN 6

typedef uint32_t bpf_u_int32;
typedef uint32_t COUNTER;

struct pcap_pkthdr {
    bpf_u_int32 caplen;
    bpf_u_int32 len;
};

typedef struct eth_hdr_t {
    uint8_t ether_dhost[ETHER_ADDR_LEN];
    uint8_t ether_shost[ETHER_ADDR_LEN];
    uint16_t ether_type;
} eth_hdr_t;

typedef struct vlan_hdr_t {
    uint16_t vlan_tpid;
    uint16_t vlan_tci;
} vlan_hdr_t;

typedef struct ipv4_hdr_t {
    struct in_addr ip_src;
    struct in_addr ip_dst;
} ipv4_hdr_t;

typedef struct ipv6_hdr_t {
    union {
        struct {
            uint32_t __u6_addr32[4];
        } __u6_addr;
    } ip_src;
    union {
        struct {
            uint32_t __u6_addr32[4];
        } __u6_addr;
    } ip_dst;
} ipv6_hdr_t;

extern void fast_edit_packet_dl(struct pcap_pkthdr *pkthdr, u_char **pktdata,
        COUNTER iteration, bool cached, int datalink);
extern void dbgx(int level, const char *fmt, ...);
extern void warnx(const char *fmt, ...);
extern const char *pcap_datalink_val_to_description(int dlt);