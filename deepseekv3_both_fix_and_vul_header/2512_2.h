#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

#define ND_PRINT(args)
#define ND_TCHECK(expr)
#define ND_TCHECK2(expr, size)
#define ND_DEFAULTPRINT(ptr, len)
#define min(a, b) ((a) < (b) ? (a) : (b))

extern const char *tstr;

#define RMF_PAD    0x80
#define RMF_PADMASK 0x3F
#define RMF_FVER   0x40
#define RMF_CTLMSG 0x20
#define RMF_MASK   0x03
#define RMF_LONG   0x02
#define RMF_SHORT  0x01
#define RMF_RQR    0x10
#define RMF_RTS    0x08
#define RMF_IE     0x04
#define VIS_MASK   0x3F

struct shorthdr {
    uint8_t sh_flags;
    uint8_t sh_dst[2];
    uint8_t sh_src[2];
    uint8_t sh_visits;
};

struct longhdr {
    uint8_t lg_flags;
    struct {
        struct {
            uint8_t dne_nodeaddr[2];
        } dne_remote;
    } lg_dst;
    struct {
        struct {
            uint8_t dne_nodeaddr[2];
        } dne_remote;
    } lg_src;
    uint8_t lg_visits;
};

union routehdr {
    struct shorthdr rh_short;
    struct longhdr rh_long;
};

static inline uint8_t EXTRACT_LE_8BITS(const void *p) {
    return *(const uint8_t *)p;
}

static inline uint16_t EXTRACT_LE_16BITS(const void *p) {
    const uint8_t *u = p;
    return (u[1] << 8) | u[0];
}

const char *dnaddr_string(netdissect_options *, uint16_t);
int print_decnet_ctlmsg(netdissect_options *, const union routehdr *, u_int, u_int);
int print_nsp(netdissect_options *, const u_char *, u_int);