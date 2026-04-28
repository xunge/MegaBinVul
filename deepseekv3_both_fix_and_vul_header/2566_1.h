#include <stdint.h>
#include <stddef.h>
#include <arpa/inet.h>

struct tok {
    int v;
    const char *s;
};

#define ND_TCHECK2(a, b)
#define EXTRACT_16BITS(p) ((uint16_t)ntohs(*(const uint16_t *)(p)))
#define EXTRACT_24BITS(p) ((uint32_t)((p)[0] << 16) | (p)[1] << 8 | (p)[2])
#define EXTRACT_32BITS(p) ((uint32_t)ntohl(*(const uint32_t *)(p)))

struct netdissect_options;
typedef struct netdissect_options netdissect_options;

#define ISIS_SUBTLV_SPB_INSTANCE 1
#define ISIS_SUBTLV_SPB_INSTANCE_MIN_LEN 18
#define ISIS_SUBTLV_SPB_INSTANCE_VLAN_TUPLE_LEN 8
#define ISIS_SUBTLV_SPBM_SI 2

static const char *tstr = "[|truncated]";

static const struct tok isis_mt_capability_subtlv_values[] = {
    { ISIS_SUBTLV_SPB_INSTANCE, "SPB Instance" },
    { ISIS_SUBTLV_SPBM_SI, "SPBM Service Identifier" },
    { 0, NULL }
};

#define ND_PRINT(args)
#define tok2str(a,b,c) ""