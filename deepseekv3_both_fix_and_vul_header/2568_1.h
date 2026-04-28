#include <stdint.h>
#include <string.h>
#include <sys/types.h>

#define VM_CMU { 0x63, 0x82, 0x53, 0x63 }
#define VM_RFC1048 { 0x63, 0x82, 0x53, 0x63 }

#define BOOTPREQUEST 1

typedef uint8_t u_char;
typedef unsigned int u_int;

struct in_addr {
    uint32_t s_addr;
};

struct bootp {
    uint8_t bp_op;
    uint8_t bp_htype;
    uint8_t bp_hlen;
    uint8_t bp_hops;
    uint32_t bp_xid;
    uint16_t bp_secs;
    uint16_t bp_flags;
    struct in_addr bp_ciaddr;
    struct in_addr bp_yiaddr;
    struct in_addr bp_siaddr;
    struct in_addr bp_giaddr;
    uint8_t bp_chaddr[16];
    char bp_sname[64];
    char bp_file[128];
    uint8_t bp_vend[64];
};

#define ND_TCHECK(p)
#define ND_TCHECK2(p, l)
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) (*(uint16_t*)(p))
#define EXTRACT_32BITS(p) (*(uint32_t*)(p))

extern const char *tstr;
extern const char *bootp_op_values[];
extern const char *bootp_flag_values[];

typedef struct netdissect_options {
    int ndo_vflag;
    const u_char *ndo_snapend;
} netdissect_options;