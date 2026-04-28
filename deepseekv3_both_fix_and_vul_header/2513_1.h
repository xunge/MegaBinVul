#include <stdint.h>
#include <string.h>

typedef unsigned int u_int;
typedef unsigned char u_char;
typedef uint16_t u_int16_t;

typedef struct netdissect_options netdissect_options;

#define EXTRACT_LE_8BITS(p) (*(const u_char *)(p))
#define EXTRACT_LE_16BITS(p) \
    ((u_int16_t)((u_int16_t)*((const u_char *)(p) + 1) << 8) | \
     (u_int16_t)*((const u_char *)(p) + 0))

#define RMF_CTLMASK 0x1f
#define RMF_INIT 1
#define RMF_VER 2
#define RMF_TEST 3
#define RMF_L1ROUT 4
#define RMF_L2ROUT 5
#define RMF_RHELLO 6
#define RMF_EHELLO 7

#define ND_PRINT(args)
#define ND_TCHECK(p)
#define ND_DEFAULTPRINT(p, l)
#define min(a, b) ((a) < (b) ? (a) : (b))

struct initmsg {
    u_char in_info;
    u_char in_vers;
    u_char in_eco;
    u_char in_ueco;
    u_int16_t in_src;
    u_int16_t in_blksize;
    u_int16_t in_hello;
};

struct verifmsg {
    u_int16_t ve_src;
    u_char ve_fcnval;
};

struct testmsg {
    u_int16_t te_src;
    u_char te_data;
};

struct l1rout {
    u_int16_t r1_src;
};

struct l2rout {
    u_int16_t r2_src;
};

struct rhellomsg {
    u_char rh_vers;
    u_char rh_eco;
    u_char rh_ueco;
    u_char rh_src[6];
    u_char rh_info;
    u_int16_t rh_blksize;
    u_char rh_priority;
    u_int16_t rh_hello;
};

struct ehellomsg {
    u_char eh_vers;
    u_char eh_eco;
    u_char eh_ueco;
    u_char eh_src[6];
    u_char eh_info;
    u_int16_t eh_blksize;
    u_char eh_router[6];
    u_int16_t eh_hello;
    u_char eh_data;
};

union routehdr {
    struct {
        u_char sh_flags;
    } rh_short;
};

union controlmsg {
    struct initmsg cm_init;
    struct verifmsg cm_ver;
    struct testmsg cm_test;
    struct l1rout cm_l1rou;
    struct l2rout cm_l2rout;
    struct rhellomsg cm_rhello;
    struct ehellomsg cm_ehello;
};

typedef struct {
    struct {
        u_int16_t dne_nodeaddr;
    } dne_remote;
} etheraddr;

extern int print_t_info(netdissect_options *, int);
extern int print_i_info(netdissect_options *, int);
extern const char *dnaddr_string(netdissect_options *, int);
extern int print_l1_routes(netdissect_options *, const char *, u_int);
extern int print_l2_routes(netdissect_options *, const char *, u_int);
extern int print_elist(const char *, u_int);