#include <stdint.h>
#include <netinet/in.h>

typedef struct netdissect_options {
    const uint8_t *ndo_snapend;
    int ndo_vflag;
} netdissect_options;

typedef unsigned char u_char;

struct ip6_mobility {
    uint8_t ip6m_len;
    uint8_t ip6m_type;
    uint16_t ip6m_data16[1];
    uint8_t ip6m_data8[2];
};

#define IP6M_MAX 7
#define IP6M_MINLEN 4
#define IP6M_BINDING_REQUEST 0
#define IP6M_HOME_TEST_INIT 1
#define IP6M_CAREOF_TEST_INIT 2
#define IP6M_HOME_TEST 3
#define IP6M_CAREOF_TEST 4
#define IP6M_BINDING_UPDATE 5
#define IP6M_BINDING_ACK 6
#define IP6M_BINDING_ERROR 7

#define _U_ __attribute__((unused))

extern const char *tstr;
extern const char *ip6m_str[];
extern const unsigned ip6m_hdrlen[IP6M_MAX+1];

#define ND_TTEST(p) 1
#define ND_TCHECK(p)
#define ND_TCHECK2(p, l)
#define ND_PRINT(args)

#define EXTRACT_16BITS(p) ntohs(*(const uint16_t *)(p))
#define EXTRACT_32BITS(p) ntohl(*(const uint32_t *)(p))

extern const char *tok2str(const char *[], const char *, int);
extern const char *ip6addr_string(netdissect_options *, const u_char *);
extern int mobility_opt_print(netdissect_options *, const u_char *, unsigned);