#include <stdint.h>
#include <stdio.h>

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct icmp6_hdr {
    uint8_t icmp6_code;
};

typedef unsigned char u_char;
typedef unsigned int u_int;

#define ND_PRINT(args) printf args

#define ND_RPL_DAG_IS 0
#define ND_RPL_DAG_IO 1
#define ND_RPL_DAO 2
#define ND_RPL_DAO_ACK 3

void rpl_dio_print(netdissect_options *, const u_char *, u_int);
void rpl_dao_print(netdissect_options *, const u_char *, u_int);
void rpl_daoack_print(netdissect_options *, const u_char *, u_int);