#include <stddef.h>
#include <string.h>

#define PJ_DEF(x) x
#define PJ_EINVAL 1
#define PJ_ETOOSMALL 2
#define PJ_SUCCESS 0
#define RTCP_PSFB 206
#define PJ_ASSERT_RETURN(expr, ret) do { if (!(expr)) return (ret); } while (0)

typedef int pj_status_t;
typedef unsigned long pj_size_t;
typedef unsigned short pj_uint16_t;
typedef unsigned char pj_uint8_t;

typedef struct pjmedia_rtcp_common {
    pj_uint8_t pt;
    pj_uint8_t count;
    pj_uint16_t length;
} pjmedia_rtcp_common;

typedef struct pjmedia_rtcp_fb_common {
    pjmedia_rtcp_common rtcp_common;
} pjmedia_rtcp_fb_common;

typedef struct {
    pj_uint8_t *ptr;
} pjmedia_rtcp_fb_rpsi_rpsi;

typedef struct pjmedia_rtcp_fb_rpsi {
    unsigned rpsi_bit_len;
    pjmedia_rtcp_fb_rpsi_rpsi rpsi;
    pj_uint8_t pt;
} pjmedia_rtcp_fb_rpsi;

typedef struct pjmedia_rtcp_session {
    pjmedia_rtcp_fb_common rtcp_fb_com;
    struct {
        struct {
            pjmedia_rtcp_common common;
        } rtcp_rr_pkt;
    };
} pjmedia_rtcp_session;

static void pj_memcpy(void *dst, const void *src, size_t len) {
    memcpy(dst, src, len);
}

static void pj_bzero(void *dst, size_t len) {
    memset(dst, 0, len);
}

static pj_uint16_t pj_htons(pj_uint16_t val) {
    return ((val << 8) & 0xFF00) | ((val >> 8) & 0x00FF);
}