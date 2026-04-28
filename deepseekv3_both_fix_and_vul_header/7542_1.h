#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define PJ_DEF(x) x
#define RTCP_SR 200
#define RTCP_RR 201
#define THIS_FILE __FILE__

typedef struct {
    unsigned version;
    unsigned count;
    unsigned pt;
    uint16_t length;
    uint32_t ssrc;
} pjmedia_rtcp_common;

typedef struct {
    pjmedia_rtcp_common common;
    uint32_t ssrc_src;
} pjmedia_rtcp_fb_common;

typedef struct {
    pjmedia_rtcp_common common;
} pjmedia_rtcp_sr_pkt;

typedef struct {
    pjmedia_rtcp_common common;
} pjmedia_rtcp_rr_pkt;

typedef struct {
    struct timeval tv;
} pj_time_val;

typedef struct {
    uint32_t clock_rate;
    uint32_t samples_per_frame;
    uint32_t ssrc;
    uint32_t rtp_ts_base;
    char *name;
} pjmedia_rtcp_session_setting;

typedef struct {
    pjmedia_rtcp_sr_pkt rtcp_sr_pkt;
    pjmedia_rtcp_rr_pkt rtcp_rr_pkt;
    pjmedia_rtcp_fb_common rtcp_fb_com;
    pj_time_val tv_base;
    uint64_t ts_base;
    uint64_t ts_freq;
    uint32_t rtp_ts_base;
    unsigned rtp_last_ts;
    char *name;
    uint32_t clock_rate;
    uint32_t pkt_size;
    void *stat;
} pjmedia_rtcp_session;

static inline uint16_t pj_htons(uint16_t hostshort) {
    return ((hostshort >> 8) & 0xff) | ((hostshort & 0xff) << 8);
}

static inline uint32_t pj_htonl(uint32_t hostlong) {
    return ((hostlong >> 24) & 0xff) | ((hostlong >> 8) & 0xff00) | 
           ((hostlong & 0xff00) << 8) | ((hostlong & 0xff) << 24);
}

static inline void pj_bzero(void *s, size_t n) {
    memset(s, 0, n);
}

static inline void pj_memcpy(void *dest, const void *src, size_t n) {
    memcpy(dest, src, n);
}

static inline void pj_gettimeofday(pj_time_val *tv) {
    gettimeofday(&tv->tv, NULL);
}

static inline void pj_get_timestamp(uint64_t *ts) {
    *ts = (uint64_t)clock();
}

static inline void pj_get_timestamp_freq(uint64_t *freq) {
    *freq = CLOCKS_PER_SEC;
}

static inline void pjmedia_rtcp_init_stat(void *stat) {
    memset(stat, 0, sizeof(void *));
}