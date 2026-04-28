#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip_icmp.h>
#include <string.h>
#include <stdlib.h>

#define PF_IN    0
#define PF_OUT   1
#define PF_DROP  0
#define PF_PASS  1
#define PFRES_SHORT 1
#define PFRES_NORM 2
#define ICMP_MINLEN 8
#define IP_MF 0x2000
#define IP_OFFMASK 0x1fff
#define IPTOS_ECN_MASK 0x03
#define PF_VPROTO_FRAGMENT 255

struct mbuf {
    struct {
        int len;
        int ph_rtableid;
    } m_pkthdr;
    char *m_data;
};

struct pf_pdesc {
    int dir;
    void *kif;
    struct mbuf *m;
    int sidx;
    int didx;
    sa_family_t af;
    sa_family_t naf;
    unsigned int rdomain;
    void *src;
    void *dst;
    unsigned short tot_len;
    unsigned char tos;
    unsigned char ttl;
    unsigned char virtual_proto;
    unsigned char proto;
    void *nsaddr;
    void *ndaddr;
    unsigned int off;
    unsigned int hdrlen;
    unsigned int p_len;
    unsigned short *sport;
    unsigned short *dport;
    unsigned short osport;
    unsigned short odport;
    unsigned short nsport;
    unsigned short ndport;
    unsigned short *pcksum;
    unsigned int hash;
    unsigned int fragoff;
    unsigned int jumbolen;
    union {
        struct tcphdr tcp;
        struct udphdr udp;
        struct icmp icmp;
    } hdr;
};

struct pfi_kif {
    // dummy definition
};

#define REASON_SET(reason, val) do { if (reason) *(reason) = (val); } while (0)

static inline unsigned int rtable_l2(unsigned int id) { return 0; }
#define mtod(m, t) ((t)((m)->m_data))
static inline int pf_walk_header(struct pf_pdesc *pd, void *h, u_short *reason) { return PF_PASS; }
static inline void pf_addrcpy(void *dst, void *src, sa_family_t af) {}
static inline int pf_pull_hdr(struct mbuf *m, unsigned int off, void *hdr, size_t len, void *null, u_short *reason, sa_family_t af) { return 1; }
static inline unsigned int pf_pkt_hash(sa_family_t af, unsigned char proto, void *src, void *dst, unsigned short sport, unsigned short dport) { return 0; }
static inline void panic(const char *fmt, ...) { exit(1); }