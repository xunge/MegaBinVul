#include <stdint.h>
#include <sys/types.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    const u_char *ndo_snapend;
    int ndo_vflag;
} netdissect_options;

struct pim {
    uint8_t pim_typever;
    uint8_t pim_rsv;
    uint16_t pim_cksum;
};

enum checksum_status {
    CORRECT,
    INCORRECT,
    UNVERIFIED
};

enum pimv2_addr_type {
    pimv2_unicast,
    pimv2_group,
    pimv2_source
};

#define PIM_TYPE(x) ((x) >> 4)
#define PIMV2_TYPE_HELLO 0
#define PIMV2_TYPE_REGISTER 1
#define PIMV2_TYPE_REGISTER_STOP 2
#define PIMV2_TYPE_JOIN_PRUNE 3
#define PIMV2_TYPE_BOOTSTRAP 4
#define PIMV2_TYPE_ASSERT 5
#define PIMV2_TYPE_GRAFT 6
#define PIMV2_TYPE_GRAFT_ACK 7
#define PIMV2_TYPE_CANDIDATE_RP 8
#define PIMV2_TYPE_PRUNE_REFRESH 9

#define PIMV2_REGISTER_FLAG_LEN 4
#define PIMV2_HELLO_OPTION_HOLDTIME 1
#define PIMV2_HELLO_OPTION_LANPRUNEDELAY 2
#define PIMV2_HELLO_OPTION_DR_PRIORITY_OLD 3
#define PIMV2_HELLO_OPTION_DR_PRIORITY 19
#define PIMV2_HELLO_OPTION_GENID 20
#define PIMV2_HELLO_OPTION_REFRESH_CAP 21
#define PIMV2_HELLO_OPTION_BIDIR_CAP 22
#define PIMV2_HELLO_OPTION_ADDRESS_LIST_OLD 23
#define PIMV2_HELLO_OPTION_ADDRESS_LIST 24

struct ip {
    uint8_t ip_vhl;
    uint8_t ip_src[4];
    uint8_t ip_dst[4];
};

#define IP_V(ip) (((ip)->ip_vhl) >> 4)

extern int pimv2_addr_len;
extern const char *pimv2_hello_option_values[];
extern const char *pimv2_register_flag_values[];

#define ND_TCHECK(p) 
#define ND_TCHECK2(p, l) 
#define ND_PRINT(args) 
#define EXTRACT_16BITS(p) ((uint16_t)(*(const uint16_t *)(p)))
#define EXTRACT_32BITS(p) ((uint32_t)(*(const uint32_t *)(p)))

void unsigned_relts_print(netdissect_options *, uint16_t);
int pimv2_addr_print(netdissect_options *, const u_char *, enum pimv2_addr_type, int);
enum checksum_status pimv2_check_checksum(netdissect_options *, const u_char *, const u_char *, u_int);
void ip_print(netdissect_options *, const u_char *, u_int);
void ip6_print(netdissect_options *, const u_char *, u_int);
void print_unknown_data(netdissect_options *, const u_char *, const char *, u_int);
const char *ipaddr_string(netdissect_options *, const uint8_t *);