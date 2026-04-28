#include <stddef.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <string.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    /* dummy structure */
} netdissect_options;

typedef struct isakmp_gen {
    /* dummy structure */
} isakmp_gen;

typedef struct ikev2_t {
    struct {
        int critical;
    } h;
    uint16_t t_id;
    uint16_t t_type;
} ikev2_t;

typedef struct attrmap {
    uint16_t attr;
    const char *name;
} attrmap;

#define ND_TCHECK(x)
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define ND_PRINT(args)
#define NPSTR(x) ""
#define STR_OR_ID(id, map) ""

enum {
    ISAKMP_NPTYPE_T,
    IV2_T_ENCR,
    IV2_T_PRF,
    IV2_T_INTEG,
    IV2_T_DH,
    IV2_T_ESN
};

static const attrmap encr_t_map[] = {{0}};
static const attrmap prf_p_map[] = {{0}};
static const attrmap integ_p_map[] = {{0}};
static const attrmap dh_p_map[] = {{0}};
static const attrmap esn_p_map[] = {{0}};
static const attrmap ikev2_t_type_map[] = {{0}};

static const u_char *ikev2_pay_print(netdissect_options *ndo, const char *str, int critical) { return NULL; }
static const u_char *ikev1_attrmap_print(netdissect_options *ndo, const u_char *cp, const u_char *ep, const attrmap *map, size_t nmap) { return NULL; }
static const u_char *ikev1_attr_print(netdissect_options *ndo, const u_char *cp, const u_char *ep) { return NULL; }