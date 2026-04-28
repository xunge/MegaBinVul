#include <stdint.h>
#include <inttypes.h>
#include <sys/types.h>

#define TH_SYN 0x02
#define TH_ACK 0x10

typedef unsigned char u_char;
typedef unsigned int u_int;

struct mp_capable {
    uint8_t sub_ver;
    uint8_t flags;
    uint8_t sender_key[8];
    uint8_t receiver_key[8];
};

#define MP_CAPABLE_OPT_VERSION(sub_ver) ((sub_ver) >> 4)
#define MP_CAPABLE_C 0x01
#define EXTRACT_64BITS(p) ((uint64_t)ntohll(*(const uint64_t *)(p)))

typedef struct netdissect_options netdissect_options;
#define ND_PRINT(args)

static inline uint64_t ntohll(uint64_t x) {
    return ((uint64_t)ntohl((uint32_t)(x >> 32))) | ((uint64_t)ntohl((uint32_t)x) << 32);
}