#include <stddef.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>

#define RIP6_VERSION 1
#define RIP6_REQUEST 1
#define RIP6_RESPONSE 2
#define HOPCNT_INFINITY6 16

struct netinfo6 {
    struct in6_addr rip6_dest;
    u_int16_t rip6_tag;
    u_int16_t rip6_metric;
};

struct rip6 {
    u_int8_t rip6_cmd;
    u_int8_t rip6_vers;
    u_int16_t rip6_res1;
    struct netinfo6 rip6_nets[1];
};

typedef struct netdissect_options {
    const u_char *ndo_snapend;
    int ndo_vflag;
} netdissect_options;

#define ND_PRINT(x) printf x
#define min(a, b) ((a) < (b) ? (a) : (b))