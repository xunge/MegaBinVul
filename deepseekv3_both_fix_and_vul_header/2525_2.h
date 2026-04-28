#include <stdint.h>
#include <arpa/inet.h>
#include <string.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct isakmp_gen {
    uint8_t critical;
};

struct ikev2_n {
    struct isakmp_gen h;
    uint16_t type;
    uint8_t prot_id;
    uint8_t spi_size;
};

#define _U_
#define ND_TCHECK(x)
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define ND_PRINT(args)
#define NPSTR(x) ""
#define PROTOIDSTR(x) ""
#define ISAKMP_NPTYPE_N 0

#define IV2_NOTIFY_UNSUPPORTED_CRITICAL_PAYLOAD 1
#define IV2_NOTIFY_INVALID_IKE_SPI 4
#define IV2_NOTIFY_INVALID_MAJOR_VERSION 5
#define IV2_NOTIFY_INVALID_SYNTAX 7
#define IV2_NOTIFY_INVALID_MESSAGE_ID 9
#define IV2_NOTIFY_INVALID_SPI 11
#define IV2_NOTIFY_NO_PROPOSAL_CHOSEN 14
#define IV2_NOTIFY_INVALID_KE_PAYLOAD 17
#define IV2_NOTIFY_AUTHENTICATION_FAILED 24
#define IV2_NOTIFY_SINGLE_PAIR_REQUIRED 25
#define IV2_NOTIFY_NO_ADDITIONAL_SAS 26
#define IV2_NOTIFY_INTERNAL_ADDRESS_FAILURE 27
#define IV2_NOTIFY_FAILED_CP_REQUIRED 28
#define IV2_NOTIFY_INVALID_SELECTORS 29
#define IV2_NOTIFY_INITIAL_CONTACT 16384
#define IV2_NOTIFY_SET_WINDOW_SIZE 16385
#define IV2_NOTIFY_ADDITIONAL_TS_POSSIBLE 16386
#define IV2_NOTIFY_IPCOMP_SUPPORTED 16387
#define IV2_NOTIFY_NAT_DETECTION_SOURCE_IP 16388
#define IV2_NOTIFY_NAT_DETECTION_DESTINATION_IP 16389
#define IV2_NOTIFY_COOKIE 16390
#define IV2_NOTIFY_USE_TRANSPORT_MODE 16391
#define IV2_NOTIFY_HTTP_CERT_LOOKUP_SUPPORTED 16392
#define IV2_NOTIFY_REKEY_SA 16393
#define IV2_NOTIFY_ESP_TFC_PADDING_NOT_SUPPORTED 16394
#define IV2_NOTIFY_NON_FIRST_FRAGMENTS_ALSO 16395

int rawprint(netdissect_options *ndo, const uint8_t *data, size_t len);
int ike_show_somedata(netdissect_options *ndo, const u_char *cp, const u_char *ep);
void ikev2_pay_print(netdissect_options *ndo, const char *name, int critical);