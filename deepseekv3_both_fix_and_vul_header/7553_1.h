#include <stdint.h>
#include <stddef.h>
#include <string.h>

typedef int32_t pj_status_t;
typedef uint8_t pj_uint8_t;
typedef uint16_t pj_uint16_t;

#define PJ_SUCCESS 0
#define PJLIB_UTIL_EDNSINNAMEPTR -1
#define PJLIB_UTIL_EDNSINSIZE -2

static inline pj_uint16_t pj_htons(pj_uint16_t hostshort) {
    return htons(hostshort);
}

static inline pj_uint16_t pj_ntohs(pj_uint16_t netshort) {
    return ntohs(netshort);
}

#define pj_memcpy memcpy