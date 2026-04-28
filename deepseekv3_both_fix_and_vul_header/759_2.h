#include <sys/types.h>
#include <netinet/in.h>
#include <stdbool.h>

#define LDP_VERSION 1
#define LDP_MASK_MSG_TYPE(x) ((x) & 0x7fff)
#define LDP_MASK_U_BIT(x) ((x) & 0x8000)
#define FALSE false
#define TRUE true

struct ldp_common_header {
    u_int16_t version;
    u_int16_t pdu_length;
    u_int32_t lsr_id;
    u_int16_t label_space;
};

struct ldp_msg_header {
    u_int16_t type;
    u_int16_t length;
    u_int32_t id;
};

#define LDP_MSG_NOTIF 0x0001
#define LDP_MSG_HELLO 0x0100
#define LDP_MSG_INIT 0x0200
#define LDP_MSG_KEEPALIVE 0x0201
#define LDP_MSG_ADDRESS 0x0300
#define LDP_MSG_ADDRESS_WITHDRAW 0x0301
#define LDP_MSG_LABEL_MAPPING 0x0400
#define LDP_MSG_LABEL_REQUEST 0x0401
#define LDP_MSG_LABEL_WITHDRAW 0x0402
#define LDP_MSG_LABEL_RELEASE 0x0403
#define LDP_MSG_LABEL_ABORT_REQUEST 0x0404

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

#define ND_TCHECK(x)
#define ND_TCHECK2(x, y)
#define ND_PRINT(x)
#define EXTRACT_16BITS(p) ntohs(*(const u_int16_t *)(p))
#define EXTRACT_32BITS(p) ntohl(*(const u_int32_t *)(p))

extern const char *tok2str(const char **, const char *, int);
extern const char *ipaddr_string(netdissect_options *, const u_int32_t *);
extern int ldp_tlv_print(netdissect_options *, const u_char *, u_short);
extern void print_unknown_data(netdissect_options *, const u_char *, const char *, u_int);