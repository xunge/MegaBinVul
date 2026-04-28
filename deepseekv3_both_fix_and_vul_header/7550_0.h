#include <stddef.h>
#include <stdint.h>

#define PJ_DEF(x) x
#define PJ_EINVAL (-1)
#define PJ_ETOOSMALL (-2)
#define PJ_SUCCESS 0
#define RTCP_RTPFB 205
#define PJ_ASSERT_RETURN(expr, ret) if (!(expr)) return (ret)

typedef int pj_status_t;
typedef size_t pj_size_t;
typedef uint16_t pj_uint16_t;
typedef uint8_t pj_uint8_t;

typedef struct pjmedia_rtcp_fb_nack {
    unsigned pid;
    unsigned blp;
} pjmedia_rtcp_fb_nack;

typedef struct pjmedia_rtcp_common {
    unsigned pt;
    unsigned count;
    pj_uint16_t length;
} pjmedia_rtcp_common;

typedef struct pjmedia_rtcp_fb_common {
    pjmedia_rtcp_common rtcp_common;
} pjmedia_rtcp_fb_common;

typedef struct pjmedia_rtcp_session {
    pjmedia_rtcp_fb_common rtcp_fb_com;
    struct {
        struct {
            pjmedia_rtcp_common common;
        } rtcp_rr_pkt;
    };
} pjmedia_rtcp_session;

static inline pj_uint16_t pj_htons(pj_uint16_t hostshort) {
    return ((hostshort << 8) | (hostshort >> 8));
}

static inline void pj_memcpy(void *dst, const void *src, size_t n) {
    memcpy(dst, src, n);
}