#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>

#define LLDP_INTF_NUM_LEN 5

typedef struct netdissect_options netdissect_options;
typedef unsigned char u_char;
typedef unsigned int u_int;

struct tok {
    const char *name;
    int value;
};

extern char *lldp_network_addr_print(netdissect_options *, const u_char *, uint8_t);
extern const struct tok lldp_intf_numb_subtype_values[];
extern const char *tok2str(const struct tok *, const char *, int);
extern void safeputs(netdissect_options *, const u_char *, u_int);

/* Correct ND_PRINT macro to match the usage pattern in the code */
#define ND_PRINT(args) printf args

#define EXTRACT_32BITS(p) ((uint32_t)ntohl(*(const uint32_t *)(p)))