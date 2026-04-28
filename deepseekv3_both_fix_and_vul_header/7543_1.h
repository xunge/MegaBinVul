#include <stdint.h>
#include <string.h>

#define RTCP_PSFB 206
#define PJ_EINVAL 22
#define PJ_ETOOSMALL 23
#define PJ_SUCCESS 0

typedef int pj_status_t;
typedef size_t pj_size_t;
typedef uint16_t pj_uint16_t;

#define PJ_DEF(type) type
#define PJ_ASSERT_RETURN(expr, ret) if (!(expr)) return (ret)

static inline pj_uint16_t pj_htons(pj_uint16_t hostshort) {
    return ((hostshort >> 8) & 0xFF) | ((hostshort << 8) & 0xFF00);
}

typedef struct pjmedia_rtcp_common {
    unsigned pt:8;
    unsigned count:5;
    unsigned length:16;
} pjmedia_rtcp_common;

typedef struct pjmedia_rtcp_fb_common {
    pjmedia_rtcp_common rtcp_common;
} pjmedia_rtcp_fb_common;

typedef struct pjmedia_rtcp_session {
    pjmedia_rtcp_fb_common rtcp_fb_com;
    struct {
        pjmedia_rtcp_common common;
    } rtcp_rr_pkt;
} pjmedia_rtcp_session;

#define pj_memcpy memcpy