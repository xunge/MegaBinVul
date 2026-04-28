#include <netinet/in.h>
#include <netinet/icmp6.h>
#include <arpa/inet.h>
#include <netdb.h>

#define NI_MAXHOST 1025

#define ICMP6_ROUTER_RENUMBERING_COMMAND    0
#define ICMP6_ROUTER_RENUMBERING_RESULT     1
#define ICMP6_ROUTER_RENUMBERING_SEQNUM_RESET 255

#define ICMP6_RR_FLAGS_TEST         0x80
#define ICMP6_RR_FLAGS_REQRESULT    0x40
#define ICMP6_RR_FLAGS_FORCEAPPLY   0x20
#define ICMP6_RR_FLAGS_SPECSITE     0x10
#define ICMP6_RR_FLAGS_PREVDONE     0x08

#define RPM_PCO_ADD         1
#define RPM_PCO_CHANGE      2
#define RPM_PCO_SETGLOBAL   3

#define ICMP6_RR_PCOUSE_FLAGS_DECRVLTIME   0x80
#define ICMP6_RR_PCOUSE_FLAGS_DECRPLTIME   0x40

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

#define ND_TCHECK(p)
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) ntohs(*(const uint16_t *)(p))
#define EXTRACT_32BITS(p) ntohl(*(const uint32_t *)(p))

static int addrtostr6(const struct in6_addr *addr, char *buf, size_t buf_size) {
    return 0;
}