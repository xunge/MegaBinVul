#include <stdint.h>

typedef int32_t pj_status_t;
typedef uint8_t pj_uint8_t;
typedef uint16_t pj_uint16_t;

#define PJ_SUCCESS 0
#define PJLIB_UTIL_EDNSINNAMEPTR (-1)

typedef struct pj_str_t {
    char *ptr;
    unsigned slen;
} pj_str_t;

pj_uint16_t pj_htons(pj_uint16_t hostshort);
pj_uint16_t pj_ntohs(pj_uint16_t netshort);
void pj_memcpy(void *dst, const void *src, unsigned len);