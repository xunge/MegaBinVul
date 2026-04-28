#include <stddef.h>
#include <stdint.h>

typedef unsigned short pj_uint16_t;
typedef unsigned char pj_uint8_t;
typedef size_t pj_size_t;

typedef struct pjmedia_rtcp_session {
    const char *name;
} pjmedia_rtcp_session;

typedef struct pjmedia_rtcp_common {
    pj_uint16_t length;
    pj_uint8_t pt;
} pjmedia_rtcp_common;

#define RTCP_SR   200
#define RTCP_RR   201
#define RTCP_XR   207
#define RTCP_SDES 202
#define RTCP_BYE  203
#define RTCP_RTPFB 205
#define RTCP_PSFB  206

#define PJ_DEF(x) x

static pj_uint16_t pj_ntohs(pj_uint16_t val) {
    return ((val << 8) & 0xFF00) | ((val >> 8) & 0x00FF);
}

static void parse_rtcp_report(pjmedia_rtcp_session *sess, const void *pkt, pj_size_t size) {}
static void parse_rtcp_sdes(pjmedia_rtcp_session *sess, const void *pkt, pj_size_t size) {}
static void parse_rtcp_bye(pjmedia_rtcp_session *sess, const void *pkt, pj_size_t size) {}
static void parse_rtcp_fb(pjmedia_rtcp_session *sess, const void *pkt, pj_size_t size) {}

#define TRACE_(args)