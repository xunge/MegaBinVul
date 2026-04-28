#include <stddef.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip6.h>
#include <arpa/inet.h>
#include <sys/types.h>

typedef struct netdissect_options {
    int ndo_vflag;
    int ndo_packettype;
} netdissect_options;

#define ND_TTEST(p) 1
#define ND_TCHECK(p) 
#define ND_TCHECK2(p, l) 
#define ND_PRINT(args) 
#define EXTRACT_16BITS(p) ntohs(*(const uint16_t *)(p))
#define EXTRACT_32BITS(p) ntohl(*(const uint32_t *)(p))
#define IP_V(ip) ((ip)->ip_v)
#define INET6_ADDRSTRLEN 46
#define PGM_MIN_OPT_LEN 4
#define PGM_OPT_MASK 0x7f
#define PGM_OPT_END 0x80

#define AFNUM_INET 1
#define AFNUM_INET6 2
#define IPPROTO_PGM 113
#define PT_PGM_ZMTP1 255

#define PGM_SPM 0
#define PGM_POLL 1
#define PGM_POLR 2
#define PGM_ODATA 3
#define PGM_RDATA 4
#define PGM_NAK 5
#define PGM_NULLNAK 6
#define PGM_NCF 7
#define PGM_ACK 8
#define PGM_SPMR 9

#define PGM_OPT_LENGTH 0
#define PGM_OPT_FRAGMENT 1
#define PGM_OPT_NAK_LIST 2
#define PGM_OPT_JOIN 3
#define PGM_OPT_NAK_BO_IVL 4
#define PGM_OPT_NAK_BO_RNG 5
#define PGM_OPT_REDIRECT 6
#define PGM_OPT_PARITY_PRM 7
#define PGM_OPT_PARITY_GRP 8
#define PGM_OPT_CURR_TGSIZE 9
#define PGM_OPT_NBR_UNREACH 10
#define PGM_OPT_PATH_NLA 11
#define PGM_OPT_SYN 12
#define PGM_OPT_FIN 13
#define PGM_OPT_RST 14
#define PGM_OPT_CR 15
#define PGM_OPT_CRQST 16
#define PGM_OPT_PGMCC_DATA 17
#define PGM_OPT_PGMCC_FEEDBACK 18

#define PGM_OPT_BIT_PRESENT 0x80

struct pgm_header {
    uint16_t pgm_sport;
    uint16_t pgm_dport;
    uint8_t pgm_type;
    uint8_t pgm_options;
    uint16_t pgm_length;
    uint8_t pgm_gsid[6];
};

struct pgm_spm {
    uint32_t pgms_seq;
    uint32_t pgms_trailseq;
    uint32_t pgms_leadseq;
    uint16_t pgms_nla_afi;
};

struct pgm_poll {
    uint32_t pgmp_seq;
    uint16_t pgmp_round;
};

struct pgm_polr {
    uint32_t pgmp_seq;
    uint16_t pgmp_round;
    uint16_t pgmp_nla_afi;
};

struct pgm_data {
    uint32_t pgmd_trailseq;
    uint32_t pgmd_seq;
};

struct pgm_nak {
    uint32_t pgmn_seq;
    uint16_t pgmn_source_afi;
};

struct pgm_ack {
    uint32_t pgma_rx_max_seq;
};

const char *ipaddr_string(netdissect_options *ndo, const void *ip);
const char *ip6addr_string(netdissect_options *ndo, const void *ip6);
const char *tcpport_string(netdissect_options *ndo, uint16_t port);
void addrtostr(const void *addr, char *buf, size_t bufsize);
void addrtostr6(const void *addr, char *buf, size_t bufsize);
void zmtp1_print_datagram(netdissect_options *ndo, const u_char *bp, u_int length);