#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <stddef.h>

typedef unsigned char u_char;

typedef struct ipv6_hdr_t {
    uint8_t ip_nh;
} ipv6_hdr_t;

struct tcpr_ipv6_ext_hdr_base {
    uint8_t ip_nh;
    uint8_t ip_len;
};

#define TCPR_IPV6_H 40
#define TCPR_IPV6_NH_IPV6 41
#define TCPR_IPV6_NH_AH 51
#define TCPR_IPV6_NH_ROUTING 43
#define TCPR_IPV6_NH_DESTOPTS 60
#define TCPR_IPV6_NH_HBH 0
#define TCPR_IPV6_NH_FRAGMENT 44
#define TCPR_IPV6_NH_ESP 50

#define IPV6_EXTLEN_TO_BYTES(len) ((len) + 1) * 8

void dbg(int level, const char *fmt, ...);
void dbgx(int level, const char *fmt, ...);

struct tcpr_ipv6_ext_hdr_base *get_ipv6_next(struct tcpr_ipv6_ext_hdr_base *next, uint32_t maxlen);