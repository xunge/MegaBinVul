#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/types.h>

#define TH_SYN 0x02
#define TH_ACK 0x10
#define MP_JOIN_B 0x80

typedef unsigned char u_char;
typedef unsigned int u_int;

struct mp_join {
    uint8_t sub_b;
    uint8_t addr_id;
    union {
        struct {
            uint32_t token;
            uint32_t nonce;
        } syn;
        struct {
            uint64_t mac;
            uint32_t nonce;
        } synack;
        struct {
            uint8_t mac[20];
        } ack;
    } u;
};

typedef struct netdissect_options netdissect_options;
#define ND_PRINT(args)
#define EXTRACT_32BITS(p) (*(const uint32_t *)(p))
#define EXTRACT_64BITS(p) (*(const uint64_t *)(p))