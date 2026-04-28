#include <stdint.h>
#include <netinet/in.h>
#include <netinet/ip6.h>
#include <netinet/icmp6.h>
#include <netinet/udp.h>

typedef struct netdissect_options {
    const u_char *ndo_snapend;
    int ndo_vflag;
} netdissect_options;

#define ND_TCHECK(p)
#define ND_TTEST2(p, l) 1
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) ntohs(*(const uint16_t *)(p))
#define EXTRACT_32BITS(p) ntohl(*(const uint32_t *)(p))
#define MLD_MINLEN 24
#define MLDV2_MINLEN 28

/* ICMP6 message types not defined in standard headers */
#define ICMP6_HADISCOV_REQUEST        144
#define ICMP6_HADISCOV_REPLY          145
#define ICMP6_MOBILEPREFIX_SOLICIT    146
#define ICMP6_MOBILEPREFIX_ADVERT     147
#define ICMP6_MEMBERSHIP_QUERY        130
#define ICMP6_MEMBERSHIP_REPORT       131
#define ICMP6_MEMBERSHIP_REDUCTION    132
#define ICMP6_V2_MEMBERSHIP_REPORT    143
#define ICMP6_NI_QUERY                139
#define ICMP6_NI_REPLY                140
#define IND_SOLICIT                   141
#define IND_ADVERT                    142
#define ND_RPL_MESSAGE                155

/* Function prototypes */
uint16_t icmp6_cksum(struct netdissect_options *, const struct ip6_hdr *, 
                    const struct icmp6_hdr *, u_int);
const struct udphdr *get_upperlayer(struct netdissect_options *, 
                                  const u_char *, int *);
void print_unknown_data(struct netdissect_options *, const u_char *, 
                      const char *, u_int);
void mld6_print(struct netdissect_options *, const u_char *);
void mldv2_query_print(struct netdissect_options *, const u_char *, u_int);
void mldv2_report_print(struct netdissect_options *, const u_char *, u_int);
void icmp6_opt_print(struct netdissect_options *, const u_char *, u_int);
void icmp6_rrenum_print(struct netdissect_options *, const u_char *, 
                      const u_char *);
void icmp6_nodeinfo_print(struct netdissect_options *, u_int, 
                        const u_char *, const u_char *);
void rpl_print(struct netdissect_options *, const struct icmp6_hdr *, 
              const uint8_t *, u_int);