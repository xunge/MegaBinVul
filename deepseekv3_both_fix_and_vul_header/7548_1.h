#include <stdint.h>
#include <arpa/inet.h>

#define PJ_DEF(x) x
#define PJ_ASSERT_RETURN(expr, ret) if (!(expr)) return (ret)
#define PJ_EINVAL 1
#define PJ_ETOOSMALL 2
#define PJ_ENOTFOUND 3
#define PJ_ETOOBIG 4
#define PJ_SUCCESS 0
#define PJ_PERROR(level, args)
#define THIS_FILE ""
#define RTCP_PSFB 206

typedef int pj_status_t;
typedef uint32_t pj_size_t;
typedef uint8_t pj_uint8_t;
typedef uint16_t pj_uint16_t;

typedef struct pj_str_t {
    char *ptr;
    pj_size_t slen;
} pj_str_t;

typedef struct pjmedia_rtcp_common {
    pj_uint8_t count;
    pj_uint8_t pt;
    pj_uint16_t length;
} pjmedia_rtcp_common;

typedef struct pjmedia_rtcp_fb_common {
    pjmedia_rtcp_common rtcp_common;
} pjmedia_rtcp_fb_common;

typedef struct pjmedia_rtcp_fb_rpsi {
    pj_uint8_t pt;
    unsigned rpsi_bit_len;
    pj_str_t rpsi;
} pjmedia_rtcp_fb_rpsi;

static void pj_strset(pj_str_t *str, char *ptr, pj_size_t len) {
    str->ptr = ptr;
    str->slen = len;
}

static pj_uint16_t pj_ntohs(pj_uint16_t val) {
    return ntohs(val);
}