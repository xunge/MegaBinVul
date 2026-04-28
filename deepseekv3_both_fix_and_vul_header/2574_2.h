#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

typedef struct netdissect_options netdissect_options;

typedef uint8_t u_char;
typedef uint32_t u_int;
typedef uint16_t u_short;

#define ND_TCHECK2(a, b)
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) ((uint16_t)ntohs(*(const uint16_t *)(p)))

static const char tstr[] = "[|truncated]";

#define TUNNEL_PASS 1
#define TUNNEL_CLIENT_END 2
#define TUNNEL_SERVER_END 3
#define TUNNEL_PRIV_GROUP 4
#define TUNNEL_ASSIGN_ID 5
#define TUNNEL_CLIENT_AUTH 6
#define TUNNEL_SERVER_AUTH 7
#define EGRESS_VLAN_NAME 8

static const char *rfc4675_tagged[] = { NULL };
static const char *tok2str(const char *const *table, const char *fmt, int val) { return NULL; }