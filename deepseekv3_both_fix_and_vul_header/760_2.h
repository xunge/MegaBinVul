#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>

#define MAXHOSTNAMELEN 256
#define ICMP_EXTD_MINLEN 8
#define ICMP_MPLS_EXT_VERSION 1

typedef struct netdissect_options {
    int ndo_vflag;
    int ndo_snaplen;
    const u_char *ndo_snapend;
} netdissect_options;

struct icmp_ext_t {
    uint8_t icmp_ext_version_res[1];
    uint16_t icmp_ext_checksum;
    uint16_t icmp_length;
    uint8_t icmp_ext_data[1];
};

struct icmp_mpls_ext_object_header_t {
    uint8_t class_num;
    uint8_t ctype;
    uint16_t length;
};

struct mtu_discovery {
    uint16_t nexthopmtu;
};

struct ih_rdiscovery {
    uint8_t ird_addrnum;
    uint8_t ird_addrsiz;
    uint16_t ird_lifetime;
};

struct id_rdiscovery {
    struct in_addr ird_addr;
    uint32_t ird_pref;
};

struct cksum_vec {
    const uint8_t *ptr;
    int len;
};

#define ND_TCHECK(p) 
#define ND_TCHECK2(p, l) 
#define ND_TCHECK_16BITS(p) 
#define ND_PRINT(args)
#define ND_TTEST(p) 1
#define ND_TTEST2(p, l) 1

#define EXTRACT_16BITS(p) ntohs(*(const uint16_t *)(p))
#define EXTRACT_32BITS(p) ntohl(*(const uint32_t *)(p))

#define ICMP_MPLS_EXT_EXTRACT_VERSION(v) ((v) >> 4)
#define ICMP_MPLS_EXT_TYPE(type) (0)
#define ICMP_ERRTYPE(type) (0)

#define MPLS_LABEL(l) ((l) >> 12)
#define MPLS_EXP(l) (((l) >> 9) & 0x7)
#define MPLS_STACK(l) (((l) >> 8) & 0x1)
#define MPLS_TTL(l) ((l) & 0xff)

static const char *icmp2str[] = { NULL };
static const char *unreach2str[] = { NULL };
static const char *type2str[] = { NULL };
static const char *icmp_mpls_ext_obj_values[] = { NULL };

static const char *ipaddr_string(netdissect_options *ndo, const void *p) { return ""; }
static const char *tcpport_string(netdissect_options *ndo, uint16_t p) { return ""; }
static const char *udpport_string(netdissect_options *ndo, uint16_t p) { return ""; }
static const char *icmp_tstamp_print(uint32_t t) { return ""; }
static uint16_t in_cksum(const struct cksum_vec *vec, int len) { return 0; }
static uint16_t in_cksum_shouldbe(uint16_t sum, uint16_t computed) { return 0; }
static void ip_print(netdissect_options *ndo, const u_char *bp, u_int length) {}
static void print_unknown_data(netdissect_options *ndo, const uint8_t *cp, const char *s, int len) {}
static const char *tok2str(const char *str[], const char *fmt, int val) { return ""; }