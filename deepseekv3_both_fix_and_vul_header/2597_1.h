#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    /* dummy structure since actual definition is not provided */
} netdissect_options;

#define FALSE 0
#define TRUE 1

#define AFNUM_INET 1
#define AFNUM_INET6 2

static const char *af_values[] = {
    NULL
};

const char *tok2str(const char **, const char *, unsigned int);
const char *ipaddr_string(netdissect_options *, const u_char *);
const char *ip6addr_string(netdissect_options *, const u_char *);

#define ND_PRINT(args) printf args