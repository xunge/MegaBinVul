#include <stdint.h>
#include <inttypes.h>
#include <arpa/inet.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options netdissect_options;

struct mp_dss {
    uint8_t flags;
};

#define TH_SYN 0x02
#define MP_DSS_F 0x01
#define MP_DSS_A 0x02
#define MP_DSS_a 0x04
#define MP_DSS_M 0x08
#define MP_DSS_m 0x10

#define EXTRACT_16BITS(p) ((uint16_t)ntohs(*(const uint16_t *)(p)))
#define EXTRACT_32BITS(p) ((uint32_t)ntohl(*(const uint32_t *)(p)))
#define EXTRACT_64BITS(p) ((uint64_t)(((uint64_t)ntohl(*(const uint32_t *)(p))) << 32 | ntohl(*(const uint32_t *)((p)+4))))

static int mp_dss_len(const struct mp_dss *mdss, int has_csum);