#include <stddef.h>
#include <stdint.h>

typedef int pj_status_t;
typedef size_t pj_size_t;
typedef uint8_t pj_uint8_t;
typedef uint16_t pj_uint16_t;

#define PJ_DEF(x) x
#define PJ_EINVAL 1
#define PJ_ETOOSMALL 2
#define PJ_ENOTFOUND 3
#define PJ_SUCCESS 0
#define PJ_ASSERT_RETURN(cond, ret) if (!(cond)) return (ret)
#define PJ_MIN(a, b) ((a) < (b) ? (a) : (b))

#define RTCP_RTPFB 205

typedef struct pjmedia_rtcp_common {
    unsigned count:5;
    unsigned pt:8;
    unsigned length:16;
} pjmedia_rtcp_common;

typedef struct pjmedia_rtcp_fb_common {
    pjmedia_rtcp_common rtcp_common;
} pjmedia_rtcp_fb_common;

typedef struct pjmedia_rtcp_fb_nack {
    pj_uint16_t pid;
    pj_uint16_t blp;
} pjmedia_rtcp_fb_nack;

static pj_uint16_t pj_ntohs(pj_uint16_t val) {
    return ((val << 8) & 0xFF00) | ((val >> 8) & 0x00FF);
}

static void pj_memcpy(void *dst, const void *src, size_t len) {
    memcpy(dst, src, len);
}