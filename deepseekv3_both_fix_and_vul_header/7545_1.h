#include <stdint.h>
#include <stddef.h>

#define PJ_DEF(x) x
#define PJ_ASSERT_RETURN(expr, ret) if (!(expr)) return (ret)
#define PJ_EINVAL 1
#define PJ_ETOOSMALL 2
#define PJ_ENOTFOUND 3
#define PJ_SUCCESS 0
#define RTCP_PSFB 206
#define PJ_MIN(a, b) ((a) < (b) ? (a) : (b))

typedef int pj_status_t;
typedef size_t pj_size_t;
typedef uint16_t pj_uint16_t;
typedef uint8_t pj_uint8_t;

typedef struct pjmedia_rtcp_common {
    uint8_t count;
    uint8_t pt;
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

static pj_uint16_t pj_ntohs(pj_uint16_t val) {
    return ((val << 8) & 0xFF00) | ((val >> 8) & 0x00FF);
}