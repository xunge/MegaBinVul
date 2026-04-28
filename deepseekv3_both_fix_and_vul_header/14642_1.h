#include <stdint.h>
#include <stddef.h>

#define PJ_DEF(x) x
#define PJ_UNUSED_ARG(x) (void)(x)
#define PJ_SUCCESS 0
#define PJMEDIA_RTP_EINVER (-1)
#define PJMEDIA_RTP_EINLEN (-2)

#define RTP_VERSION 2

typedef int pj_status_t;
typedef uint32_t pj_uint32_t;
typedef uint8_t pj_uint8_t;
typedef uint16_t pj_uint16_t;

typedef struct pjmedia_rtp_hdr {
    unsigned v:2;
    unsigned p:1;
    unsigned x:1;
    unsigned cc:4;
    unsigned m:1;
    unsigned pt:7;
    pj_uint16_t seq;
    pj_uint32_t ts;
    pj_uint32_t ssrc;
} pjmedia_rtp_hdr;

typedef struct pjmedia_rtp_ext_hdr {
    pj_uint16_t length;
} pjmedia_rtp_ext_hdr;

typedef struct pjmedia_rtp_dec_hdr {
    pjmedia_rtp_ext_hdr *ext_hdr;
    pj_uint32_t *ext;
    unsigned ext_len;
} pjmedia_rtp_dec_hdr;

typedef struct pjmedia_rtp_session pjmedia_rtp_session;

static pj_uint16_t pj_ntohs(pj_uint16_t val) {
    return ((val << 8) & 0xFF00) | ((val >> 8) & 0x00FF);
}