#include <stdint.h>
#include <stddef.h>
#include <string.h>

typedef int pj_status_t;
typedef uint8_t pj_uint8_t;
typedef uint16_t pj_uint16_t;

#define PJ_SUCCESS 0
#define PJLIB_UTIL_EDNSINNAMEPTR -1

static pj_uint16_t pj_htons(pj_uint16_t hostshort) { return htons(hostshort); }
static pj_uint16_t pj_ntohs(pj_uint16_t netshort) { return ntohs(netshort); }
#define pj_memcpy memcpy