#include <stdbool.h>
#include <stdint.h>

typedef struct E1000ECore {
    uint32_t *mac;
} E1000ECore;

typedef struct E1000E_RingInfo {
    uint32_t dh;
    uint32_t dt;
    uint32_t dlen;
} E1000E_RingInfo;

#define E1000_RING_DESC_LEN 16