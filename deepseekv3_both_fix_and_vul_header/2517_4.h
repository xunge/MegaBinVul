#include <stdint.h>
#include <netinet/in.h>

typedef unsigned char u_char;

typedef struct netdissect_options {
    const u_char *ndo_snapend;
    int ndo_vflag;
} netdissect_options;

struct ip6_mobility {
    uint8_t ip6m_len;
    uint8_t ip6m_type;
    uint8_t ip6m_data8[2];
    uint16_t ip6m_data16[1];
};

#define _U_
#define ND_TTEST(p) 1
#define ND_TCHECK(p)
#define ND_TCHECK2(p, l)
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) ntohs(*(const uint16_t *)(p))
#define EXTRACT_32BITS(p) ntohl(*(const uint32_t *)(p))

enum {
    IP6M_BINDING_REQUEST = 0,
    IP6M_HOME_TEST_INIT = 1,
    IP6M_CAREOF_TEST_INIT = 2,
    IP6M_HOME_TEST = 3,
    IP6M_CAREOF_TEST = 4,
    IP6M_BINDING_UPDATE = 5,
    IP6M_BINDING_ACK = 6,
    IP6M_BINDING_ERROR = 7,
    IP6M_MAX = 7
};

#define IP6M_MINLEN 4

static const char *tstr = "[|trunc]";
static const char *ip6m_str[] = {
    "Binding Request",
    "Home Test Init",
    "Care-of Test Init",
    "Home Test",
    "Care-of Test",
    "Binding Update",
    "Binding Ack",
    "Binding Error"
};
static const uint8_t ip6m_hdrlen[] = {
    IP6M_MINLEN,
    IP6M_MINLEN,
    IP6M_MINLEN,
    IP6M_MINLEN,
    IP6M_MINLEN,
    IP6M_MINLEN,
    IP6M_MINLEN,
    IP6M_MINLEN
};

const char *tok2str(const char *str[], const char *fmt, uint8_t type);
const char *ip6addr_string(netdissect_options *ndo, const u_char *bp);
int mobility_opt_print(netdissect_options *ndo, const u_char *bp, int len);