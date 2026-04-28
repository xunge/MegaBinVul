#include <stdint.h>

typedef int pj_status_t;
typedef uint8_t pj_uint8_t;
typedef uint16_t pj_uint16_t;

typedef struct {
    char *ptr;
    unsigned slen;
} pj_str_t;

#define PJ_SUCCESS 0
#define PJLIB_UTIL_EDNSINNAMEPTR (-1)
#define PJLIB_UTIL_EDNSINSIZE (-2)

static pj_uint16_t pj_htons(pj_uint16_t hostshort);
static pj_uint16_t pj_ntohs(pj_uint16_t netshort);
static void pj_memcpy(void *dst, const void *src, unsigned n);