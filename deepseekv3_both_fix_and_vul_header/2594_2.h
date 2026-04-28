#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>

typedef struct netdissect_options {
    int ndo_eflag;
    int ndo_qflag;
    int ndo_vflag;
    const uint8_t *ndo_snapend;
} netdissect_options;

#define NLPID_ESIS 0x82
#define ESIS_VERSION 1
#define ESIS_PDU_TYPE_MASK 0x0F

#define ESIS_PDU_REDIRECT 0x01
#define ESIS_PDU_ESH 0x02
#define ESIS_PDU_ISH 0x03

#define ESIS_OPTION_ES_CONF_TIME 0x81
#define ESIS_OPTION_PROTOCOLS 0x82
#define ESIS_OPTION_QOS_MAINTENANCE 0x83
#define ESIS_OPTION_SECURITY 0x84
#define ESIS_OPTION_PRIORITY 0x85
#define ESIS_OPTION_ADDRESS_MASK 0x86
#define ESIS_OPTION_SNPA_MASK 0x87

struct esis_header_t {
    uint8_t length_indicator;
    uint8_t nlpid;
    uint8_t version;
    uint8_t type;
    uint8_t cksum[2];
    uint8_t holdtime[2];
};

#define ND_TCHECK(a)
#define ND_TCHECK2(a, b)
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) ((uint16_t)((p)[0] << 8) | (p)[1])

typedef unsigned int u_int;

const char *tok2str(const char *str, const char *fmt, int val);
const char *isonsap_string(netdissect_options *ndo, const uint8_t *s, u_int len);
const char *etheraddr_string(netdissect_options *ndo, const uint8_t *ep);
const char *linkaddr_string(netdissect_options *ndo, const uint8_t *ep, int type, u_int len);
void print_unknown_data(netdissect_options *ndo, const uint8_t *cp, const char *prefix, u_int len);
void osi_print_cksum(netdissect_options *ndo, const uint8_t *pptr, u_int16_t checksum, int offset, u_int length);

static const char *esis_pdu_values[] = {
    NULL
};

static const char *esis_option_values[] = {
    NULL
};

static const char *nlpid_values[] = {
    NULL
};