#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct netdissect_options netdissect_options;
#define IPV4_MAPPED_HEADING_LEN 12

static int is_ipv4_mapped_address(const u_char *addr);
static int decode_prefix6(netdissect_options *ndo, const u_char *prefix, u_int max_length, char *buf, size_t bufsize);
static const char *ipaddr_string(netdissect_options *ndo, const struct in_addr *addr);
#define ND_PRINT(args) printf args