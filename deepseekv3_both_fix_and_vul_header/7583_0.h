#include <stdint.h>
#include <sys/types.h>

typedef struct ipv6_hdr_t {
    uint8_t ip_nh;
} ipv6_hdr_t;

struct tcpr_ipv6_ext_hdr_base {
    uint8_t ip_nh;
    uint8_t ip_len;
};

#define TCPR_IPV6_NH_HBH 0
#define TCPR_IPV6_NH_ROUTING 43
#define TCPR_IPV6_NH_FRAGMENT 44