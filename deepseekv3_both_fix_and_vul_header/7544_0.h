#include <stddef.h>

typedef int pj_status_t;
typedef size_t pj_size_t;

#define PJ_DEF(x) x
#define PJ_EINVAL 1
#define PJ_ETOOSMALL 2
#define PJ_ENOTFOUND 3
#define PJ_SUCCESS 0
#define PJ_ASSERT_RETURN(expr, ret) if (!(expr)) return (ret)

#define RTCP_PSFB 206

typedef struct pjmedia_rtcp_common {
    unsigned int pt:8;
    unsigned int count:5;
} pjmedia_rtcp_common;

typedef struct pjmedia_rtcp_fb_common {
    pjmedia_rtcp_common rtcp_common;
} pjmedia_rtcp_fb_common;