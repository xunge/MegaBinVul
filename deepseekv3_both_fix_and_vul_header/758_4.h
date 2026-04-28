#include <stdint.h>
#include <netinet/in.h>
#include <stddef.h>

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

#define ND_TCHECK(p) 
#define ND_TCHECK2(p, l)
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) ntohs(*(const uint16_t *)(p))
#define EXTRACT_32BITS(p) ntohl(*(const uint32_t *)(p))
#define LDP_MASK_TLV_TYPE(x) ((x) & 0x7fff)
#define LDP_MASK_U_BIT(x) ((x) & 0x8000)
#define LDP_MASK_F_BIT(x) ((x) & 0x4000)
#define TLV_TCHECK(n)

enum {
    LDP_TLV_COMMON_HELLO,
    LDP_TLV_IPV4_TRANSPORT_ADDR,
    LDP_TLV_IPV6_TRANSPORT_ADDR,
    LDP_TLV_CONFIG_SEQ_NUMBER,
    LDP_TLV_ADDRESS_LIST,
    LDP_TLV_COMMON_SESSION,
    LDP_TLV_FEC,
    LDP_TLV_GENERIC_LABEL,
    LDP_TLV_STATUS,
    LDP_TLV_FT_SESSION,
    LDP_TLV_MTU,
    LDP_TLV_HOP_COUNT,
    LDP_TLV_PATH_VECTOR,
    LDP_TLV_ATM_LABEL,
    LDP_TLV_FR_LABEL,
    LDP_TLV_EXTD_STATUS,
    LDP_TLV_RETURNED_PDU,
    LDP_TLV_RETURNED_MSG,
    LDP_TLV_ATM_SESSION_PARM,
    LDP_TLV_FR_SESSION_PARM,
    LDP_TLV_LABEL_REQUEST_MSG_ID
};

enum {
    LDP_FEC_WILDCARD,
    LDP_FEC_PREFIX,
    LDP_FEC_HOSTADDRESS,
    LDP_FEC_MARTINI_VC
};

enum {
    LDP_FEC_MARTINI_IFPARM_MTU,
    LDP_FEC_MARTINI_IFPARM_DESC,
    LDP_FEC_MARTINI_IFPARM_VCCV
};

enum {
    AFNUM_INET,
    AFNUM_INET6
};

#define LDP_TLV_ADDRESS_LIST_AFNUM_LEN 2

static const char *tok2str(const char *str, const char *fmt, int val) { return NULL; }
static const char *bittok2str(const char *str, const char *fmt, int val) { return NULL; }
static int decode_prefix4(netdissect_options *ndo, const u_char *p, u_int len, char *buf, u_int bufsize) { return 0; }
static int decode_prefix6(netdissect_options *ndo, const u_char *p, u_int len, char *buf, u_int bufsize) { return 0; }
static const char *ipaddr_string(netdissect_options *ndo, const u_char *p) { return NULL; }
static const char *ip6addr_string(netdissect_options *ndo, const u_char *p) { return NULL; }
static void safeputchar(netdissect_options *ndo, u_char c) {}
static void print_unknown_data(netdissect_options *ndo, const u_char *p, const char *s, u_int len) {}

static const char *ldp_tlv_values[] = { NULL };
static const char *af_values[] = { NULL };
static const char *ldp_fec_values[] = { NULL };
static const char *mpls_pw_types_values[] = { NULL };
static const char *ldp_fec_martini_ifparm_values[] = { NULL };
static const char *ldp_fec_martini_ifparm_vccv_cc_values[] = { NULL };
static const char *ldp_fec_martini_ifparm_vccv_cv_values[] = { NULL };