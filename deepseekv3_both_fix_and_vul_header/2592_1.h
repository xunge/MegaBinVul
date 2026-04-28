#include <stdint.h>
#include <netinet/in.h>
#include <stddef.h>

typedef struct netdissect_options netdissect_options;

#define ND_PRINT(args)
#define tok2str(a, b, c) ""
#define dh4opt_str NULL
#define DH4OPT_DNS_SERVERS 6
#define DH4OPT_NTP_SERVERS 42
#define DH4OPT_DOMAIN_SEARCH 119

const char *ipaddr_string(netdissect_options *, const u_char *);
const u_char *ns_nprint(netdissect_options *, const u_char *, const u_char *);