#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

#define ND_TCHECK2(a, b)
#define EXTRACT_16BITS(p) ((uint16_t)ntohs(*(const uint16_t *)(p)))
#define EXTRACT_32BITS(p) ((uint32_t)ntohl(*(const uint32_t *)(p)))
#define ND_PRINT(args)
#define MESSAGE_PAD1 0
#define MESSAGE_PADN 1
#define MESSAGE_ACK_REQ 2
#define MESSAGE_ACK 3
#define MESSAGE_HELLO 4
#define MESSAGE_IHU 5
#define MESSAGE_ROUTER_ID 6
#define MESSAGE_NH 7
#define MESSAGE_UPDATE 8
#define MESSAGE_REQUEST 9
#define MESSAGE_MH_REQUEST 10
#define MESSAGE_TSPC 11
#define MESSAGE_HMAC 12
#define MESSAGE_UPDATE_SRC_SPECIFIC 13
#define MESSAGE_REQUEST_SRC_SPECIFIC 14
#define MESSAGE_MH_REQUEST_SRC_SPECIFIC 15
#define ICHECK(a, b)

static const char *tstr = "[|]";
static const char *istr = "[invalid]";

static const char *format_interval(uint16_t interval);
static const char *format_interval_update(uint16_t interval);
static const char *format_address(netdissect_options *ndo, const u_char *address);
static const char *format_id(const u_char *id);
static const char *format_prefix(netdissect_options *ndo, const u_char *prefix, u_char plen);
static int network_address(u_char ae, const u_char *addr, u_int len, u_char *out);
static int network_prefix(u_char ae, u_char plen, u_char omitted, const u_char *p, const u_char *pfx, u_int len, u_char *out);
static void subtlvs_print(netdissect_options *ndo, const u_char *cp, const u_char *ep, u_int type);