#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

#define FALSE 0
#define TRUE 1

#define ND_PRINT(args) printf args
#define EXTRACT_16BITS(p) ((uint16_t)ntohs(*(const uint16_t *)(p)))
#define EXTRACT_32BITS(p) ((uint32_t)ntohl(*(const uint32_t *)(p)))

typedef struct netdissect_options netdissect_options;

enum {
    LLDP_PRIVATE_8023_SUBTYPE_MACPHY,
    LLDP_PRIVATE_8023_SUBTYPE_MDIPOWER,
    LLDP_PRIVATE_8023_SUBTYPE_LINKAGGR,
    LLDP_PRIVATE_8023_SUBTYPE_MTU
};

struct tok {
    const char *s;
    uint32_t v;
};

extern const struct tok lldp_8023_subtype_values[];
extern const struct tok lldp_8023_autonegotiation_values[];
extern const struct tok lldp_pmd_capability_values[];
extern const struct tok lldp_mau_types_values[];
extern const struct tok lldp_mdi_values[];
extern const struct tok lldp_mdi_power_pairs_values[];
extern const struct tok lldp_mdi_power_class_values[];
extern const struct tok lldp_aggregation_values[];