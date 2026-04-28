#include <stddef.h>
#include <assert.h>
#include <netinet/in.h>
#include <stdarg.h>

typedef struct tcpedit_s tcpedit_t;

struct pcap_pkthdr {
    unsigned int caplen;
    unsigned int len;
};

typedef struct ipv4_hdr_s {
    unsigned char ip_v;
} ipv4_hdr_t;

typedef struct ipv6_hdr_s {
    unsigned char ip_v;
    unsigned char ip_nh;
    unsigned short ip_len;
} ipv6_hdr_t;

#define TCPEDIT_OK 0
#define TCPEDIT_WARN 1
#define TCPEDIT_ERROR -1

int tcpedit_setwarn(tcpedit_t *tcpedit, const char *msg, ...);
int tcpedit_seterr(tcpedit_t *tcpedit, const char *msg, ...);
int ipv6_header_length_full(ipv6_hdr_t *ip6_hdr, unsigned int len, size_t l2len);
int ipv6_header_length_short(ipv6_hdr_t *ip6_hdr, unsigned int len);
int do_checksum(tcpedit_t *tcpedit, u_char *data, u_char proto, unsigned short len);

static inline int ipv6_header_length(ipv6_hdr_t *ip6_hdr, unsigned int len, ...) {
    va_list ap;
    va_start(ap, len);
    size_t l2len = va_arg(ap, size_t);
    va_end(ap);
    
    if (l2len == 0 && len != 0) {
        return ipv6_header_length_short(ip6_hdr, len);
    } else {
        return ipv6_header_length_full(ip6_hdr, len, l2len);
    }
}