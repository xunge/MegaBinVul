#include <stddef.h>
#include <stdint.h>

typedef int pj_status_t;
typedef size_t pj_size_t;

#define PJ_EINVAL 1
#define PJ_ETOOSMALL 2
#define PJ_ENOTFOUND 3
#define PJ_SUCCESS 0
#define RTCP_PSFB 206

#define PJ_ASSERT_RETURN(expr, ret) \
    do { \
        if (!(expr)) \
            return (ret); \
    } while (0)

#define PJ_DEF(type) type

typedef struct pjmedia_rtcp_common {
    unsigned count:5;
    unsigned pt:8;
    unsigned padding:1;
    unsigned version:2;
    uint16_t length;
} pjmedia_rtcp_common;