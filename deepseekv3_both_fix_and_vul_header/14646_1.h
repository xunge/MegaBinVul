#include <stdint.h>
#include <string.h>

#define RTCP_RTPFB 205
#define PJ_EINVAL 22
#define PJ_ETOOSMALL 71
#define PJ_ENOTFOUND 44
#define PJ_SUCCESS 0

typedef int pj_status_t;
typedef size_t pj_size_t;
typedef uint8_t pj_uint8_t;
typedef uint16_t pj_uint16_t;

typedef struct pjmedia_rtcp_common {
    unsigned count:5;
    unsigned pt:8;
    unsigned length:16;
} pjmedia_rtcp_common;

typedef struct pjmedia_rtcp_fb_nack {
    pj_uint16_t pid;
    pj_uint16_t blp;
} pjmedia_rtcp_fb_nack;

#define PJ_DEF(type) type
#define PJ_ASSERT_RETURN(expr, retval) if (!(expr)) return (retval)
#define PJ_MIN(a, b) ((a) < (b) ? (a) : (b))

static uint16_t pj_ntohs(uint16_t val) {
    return ((val << 8) & 0xFF00) | ((val >> 8) & 0x00FF);
}

#define pj_memcpy memcpy