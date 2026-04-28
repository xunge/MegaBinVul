#include <stdint.h>
#include <string.h>

typedef unsigned char u_char;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

#define ND_TCHECK2(p, l)
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) ((uint16_t)((p)[0] << 8 | (p)[1]))
#define EXTRACT_32BITS(p) ((uint32_t)((p)[0] << 24 | (p)[1] << 16 | (p)[2] << 8 | (p)[3]))

#define BGP_CAP_HEADER_SIZE 2

enum {
    BGP_CAPCODE_MP,
    BGP_CAPCODE_RESTART,
    BGP_CAPCODE_RR,
    BGP_CAPCODE_RR_CISCO,
    BGP_CAPCODE_AS_NEW,
    BGP_CAPCODE_ADD_PATH
};

static const char *bgp_capcode_values[] = {NULL};
static const char *af_values[] = {NULL};
static const char *bgp_safi_values[] = {NULL};
static const char *bgp_add_path_recvsend[] = {NULL};

static char astostr[64];
static const char *as_printf(netdissect_options *ndo, char *buf, size_t size, uint32_t asn) { return NULL; }
static void print_unknown_data(netdissect_options *ndo, const u_char *data, const char *str, int len) {}