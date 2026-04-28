#include <stddef.h>
#include <stdint.h>

#define PJ_DEF(x) x
#define PJ_EINVAL (-1)
#define PJ_ETOOSMALL (-2)
#define PJ_SUCCESS 0
#define RTCP_PSFB 206
#define PJ_ASSERT_RETURN(expr, ret) if (!(expr)) return (ret)

typedef int pj_status_t;
typedef size_t pj_size_t;
typedef uint16_t pj_uint16_t;
typedef uint8_t pj_uint8_t;

typedef struct pjmedia_rtcp_common {
    pj_uint8_t pt;
    pj_uint8_t count;
    pj_uint16_t length;
} pjmedia_rtcp_common;

typedef struct pjmedia_rtcp_fb_common {
    pjmedia_rtcp_common rtcp_common;
} pjmedia_rtcp_fb_common;

typedef struct pjmedia_rtcp_fb_sli {
    unsigned first;
    unsigned number;
    unsigned pict_id;
} pjmedia_rtcp_fb_sli;

typedef struct pjmedia_rtcp_rr_pkt {
    pjmedia_rtcp_common common;
} pjmedia_rtcp_rr_pkt;

typedef struct pjmedia_rtcp_session {
    pjmedia_rtcp_fb_common rtcp_fb_com;
    pjmedia_rtcp_rr_pkt rtcp_rr_pkt;
} pjmedia_rtcp_session;

static void pj_memcpy(void *dst, const void *src, size_t len) {
    memcpy(dst, src, len);
}

static pj_uint16_t pj_htons(pj_uint16_t hostshort) {
    return ((hostshort >> 8) | (hostshort << 8));
}