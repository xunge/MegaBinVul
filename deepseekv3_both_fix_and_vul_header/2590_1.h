#include <stdint.h>
#include <netinet/in.h>
#include <stddef.h>
#include <stdio.h>

#define EXTRACT_16BITS(p) ((uint16_t)ntohs(*(const uint16_t *)(p)))

typedef struct netdissect_options netdissect_options;

extern const char *tok2str(const char **, const char *, int);
extern const char *ip6addr_string(netdissect_options *, const u_char *);
extern const u_char *ns_nprint(netdissect_options *, const u_char *, const u_char *);

#define ND_PRINT(args) printf args

#define DH6OPT_DNS_SERVERS 23
#define DH6OPT_SNTP_SERVERS 31
#define DH6OPT_DOMAIN_LIST 24

static const char *dh6opt_str[] = {
    NULL
};

static const char *istr = "invalid";