#include <stddef.h>
#include <stdint.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options netdissect_options;
typedef struct isakmp_gen isakmp_gen;

struct ikev1_pl_t {
    uint32_t t_id;
    uint32_t t_no;
};

struct attrmap {
    uint32_t attr;
    const char *name;
};

#define _U_
#define ND_PRINT(x)
#define ND_TCHECK(x)
#define UNALIGNED_MEMCPY(dst, src, len)
#define NPSTR(x) ""
#define STR_OR_ID(id, map) ""
#define ISAKMP_NPTYPE_T 0

static const struct attrmap oakley_t_map[] = {{0, NULL}};
static const struct attrmap ipsec_t_map[] = {{0, NULL}};
static const struct attrmap ikev1_p_map[] = {{0, NULL}};
static const struct attrmap ah_p_map[] = {{0, NULL}};
static const struct attrmap esp_p_map[] = {{0, NULL}};
static const struct attrmap ipcomp_p_map[] = {{0, NULL}};

static const u_char *ikev1_attrmap_print(netdissect_options *ndo, const u_char *cp, 
                                       const u_char *ep, const struct attrmap *map, 
                                       size_t nmap) { return cp; }
static const u_char *ikev1_attr_print(netdissect_options *ndo, const u_char *cp, 
                                    const u_char *ep) { return cp; }