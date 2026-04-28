#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct netdissect_options netdissect_options;
typedef unsigned char u_char;

struct z_packet {
    int kind;
    const char *class;
    const char *inst;
    const char *opcode;
    const char *sender;
    const char *recipient;
    const char *version;
    int numfields;
    const char *uid;
    int port;
    int auth;
    int authlen;
    const char *authdata;
    const char *format;
    int cksum;
    int multi;
    const char *multi_uid;
};

#define Z_PACKET_SERVACK 0
const char *z_types[] = {NULL};
const char *parse_field(netdissect_options *, const char **, int *, ...);
const char *str_to_lower(const char *);
const char *z_triple(const char *, const char *, const char *);
#define ND_PRINT(args)