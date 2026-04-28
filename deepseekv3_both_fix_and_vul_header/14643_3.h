#include <stdint.h>
#include <sys/time.h>
#include <stddef.h>
#include <stdarg.h>

typedef uint32_t pj_uint32_t;
typedef uint64_t pj_uint64_t;
typedef size_t pj_size_t;

typedef struct pjmedia_rtcp_session {
    const char *name;
    pj_uint32_t rx_lsr;
    struct {
        pj_uint64_t u64;
    } rx_lsr_time;
    struct {
        pj_uint64_t u64;
    } ts_freq;
    struct {
        struct {
            pj_uint32_t loss;
            struct {
                pj_uint32_t mean;
                unsigned n;
            } rtt;
            struct {
                pj_uint32_t loss;
                pj_uint32_t jitter;
                unsigned update_cnt;
                struct timeval update;
                struct {
                    pj_uint32_t loss_period;
                };
            } tx;
        } stat;
    };
    pj_uint32_t clock_rate;
    pj_uint32_t pkt_size;
    int xr_enabled;
    void *xr_session;
} pjmedia_rtcp_session;

typedef struct pjmedia_rtcp_common {
    uint8_t pt;
    uint8_t count;
} pjmedia_rtcp_common;

typedef struct pjmedia_rtcp_sr {
    pj_uint32_t ntp_sec;
    pj_uint32_t ntp_frac;
} pjmedia_rtcp_sr;

typedef struct pjmedia_rtcp_rr {
    pj_uint32_t total_lost_2;
    pj_uint32_t total_lost_1;
    pj_uint32_t total_lost_0;
    pj_uint32_t jitter;
    pj_uint32_t lsr;
    pj_uint32_t dlsr;
} pjmedia_rtcp_rr;

typedef struct pjmedia_rtcp_sr_pkt {
    pjmedia_rtcp_common common;
    pjmedia_rtcp_sr sr;
} pjmedia_rtcp_sr_pkt;

typedef struct pjmedia_rtcp_ntp_rec {
    pj_uint32_t hi;
    pj_uint32_t lo;
} pjmedia_rtcp_ntp_rec;

#define RTCP_SR 200
#define RTCP_RR 201
#define RTCP_XR 207

#define PJMEDIA_HAS_RTCP_XR 1

static pj_uint32_t pj_ntohl(pj_uint32_t val) { return val; }
static void pj_get_timestamp(void *ts) {}
static void pjmedia_rtcp_xr_rx_rtcp_xr(void *xr_session, const void *pkt, pj_size_t size) {}
static void pjmedia_rtcp_get_ntp_time(pjmedia_rtcp_session *sess, pjmedia_rtcp_ntp_rec *ntp) {}
static void pj_gettimeofday(struct timeval *tv) {}
static void pj_math_stat_update(void *stat, pj_uint32_t val) {}

#define TRACE_(args...) do { \
    const char *_name = args; \
    (void)_name; \
} while(0)

#define PJ_LOG(level, args...) do { \
    const char *_name = args; \
    (void)_name; \
    (void)level; \
} while(0)