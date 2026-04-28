#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip6.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <stddef.h>

typedef struct netdissect_options {
    int ndo_vflag;
    int ndo_packettype;
} netdissect_options;

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

#define ND_TTEST(p) 1
#define ND_TTEST2(p, l) 1
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) ntohs(*(const uint16_t *)(p))
#define EXTRACT_32BITS(p) ntohl(*(const uint32_t *)(p))
#define INET6_ADDRSTRLEN 46
#define PGM_MIN_OPT_LEN 4
#define PGM_OPT_MASK 0x7F
#define PGM_OPT_END 0x80
#define PGM_OPT_LENGTH 1
#define PGM_OPT_FRAGMENT 2
#define PGM_OPT_NAK_LIST 3
#define PGM_OPT_JOIN 4
#define PGM_OPT_NAK_BO_IVL 5
#define PGM_OPT_NAK_BO_RNG 6
#define PGM_OPT_REDIRECT 7
#define PGM_OPT_PARITY_PRM 8
#define PGM_OPT_PARITY_GRP 9
#define PGM_OPT_CURR_TGSIZE 10
#define PGM_OPT_NBR_UNREACH 11
#define PGM_OPT_PATH_NLA 12
#define PGM_OPT_SYN 13
#define PGM_OPT_FIN 14
#define PGM_OPT_RST 15
#define PGM_OPT_CR 16
#define PGM_OPT_CRQST 17
#define PGM_OPT_PGMCC_DATA 18
#define PGM_OPT_PGMCC_FEEDBACK 19

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

#define PGM_OPT_BIT_PRESENT 0x80

#define AFNUM_INET 1
#define AFNUM_INET6 2

#define IPPROTO_PGM 113
#define PT_PGM_ZMTP1 0

#define IP_V(ip) (((const struct ip *)ip)->ip_v)

static const char *ipaddr_string(struct netdissect_options *ndo, const void *addr) { return ""; }
static const char *ip6addr_string(struct netdissect_options *ndo, const void *addr) { return ""; }
static const char *tcpport_string(struct netdissect_options *ndo, uint16_t port) { return ""; }
static void addrtostr(const void *addr, char *buf, size_t size) {}
static void addrtostr6(const void *addr, char *buf, size_t size) {}
static void zmtp1_print_datagram(struct netdissect_options *ndo, const u_char *bp, u_int length) {}