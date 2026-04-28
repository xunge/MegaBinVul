#include <assert.h>
#include <stddef.h>
#include <netinet/in.h>

typedef struct tcpedit_s tcpedit_t;
typedef struct ipv6_hdr_s ipv6_hdr_t;
typedef struct ipv4_hdr_s ipv4_hdr_t;

#define TCPEDIT_OK 0
#define TCPEDIT_WARN 1
#define TCPEDIT_ERROR -1

#define COUNTER_SPEC "%u"

struct pcap_pkthdr {
    unsigned int caplen;
    unsigned int len;
};

struct tcpedit_s {
    struct {
        unsigned int packetnum;
    } runtime;
};

struct ipv6_hdr_s {
    unsigned int ip_v;
    unsigned int ip_len;
    unsigned int ip_nh;
};

struct ipv4_hdr_s {
    unsigned int ip_v;
};

int tcpedit_setwarn(tcpedit_t *tcpedit, const char *format, ...);
int tcpedit_seterr(tcpedit_t *tcpedit, const char *format, ...);
int ipv6_header_length(ipv6_hdr_t *ip6_hdr, unsigned int len, size_t l2len);
int do_checksum(tcpedit_t *tcpedit, u_char *ip6_hdr, unsigned int ip_nh, unsigned short ip_len);