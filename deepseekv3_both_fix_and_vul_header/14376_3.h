#include <stdint.h>
#include <string.h>
#include <sys/types.h>

typedef size_t pj_size_t;
typedef uint8_t pj_uint8_t;
typedef uint16_t pj_uint16_t;
typedef uint32_t pj_uint32_t;
typedef uint64_t pj_uint64_t;
typedef int32_t pj_int32_t;
typedef int8_t pj_int8_t;

#define RTCP_XR 207
#define BT_RR_TIME 4
#define BT_DLRR 5
#define BT_STATS 6
#define BT_VOIP_METRICS 7

typedef struct pjmedia_rtcp_xr_session {
    const char *name;
    struct {
        struct {
            struct {
                uint32_t mean;
                unsigned n;
            } rtt;
            struct {
                struct {
                    uint16_t begin_seq;
                    uint16_t end_seq;
                    uint32_t lost;
                    uint32_t dup;
                    struct {
                        uint32_t min;
                        uint32_t max;
                        uint32_t mean;
                    } jitter;
                    struct {
                        uint8_t min;
                        uint8_t max;
                        uint8_t mean;
                    } toh;
                    unsigned l:1;
                    unsigned d:1;
                    unsigned j:1;
                    unsigned t:2;
                    struct {
                        uint32_t sec;
                        uint32_t msec;
                    } update;
                } stat_sum;
                struct {
                    uint8_t loss_rate;
                    uint8_t discard_rate;
                    uint8_t burst_den;
                    uint8_t gap_den;
                    uint16_t burst_dur;
                    uint16_t gap_dur;
                    uint16_t rnd_trip_delay;
                    uint16_t end_sys_delay;
                    int8_t signal_lvl;
                    int8_t noise_lvl;
                    uint8_t rerl;
                    uint8_t gmin;
                    uint8_t r_factor;
                    uint8_t ext_r_factor;
                    uint8_t mos_lq;
                    uint8_t mos_cq;
                    uint8_t rx_config;
                    uint16_t jb_nom;
                    uint16_t jb_max;
                    uint16_t jb_abs_max;
                    struct {
                        uint32_t sec;
                        uint32_t msec;
                    } update;
                } voip_mtc;
            } tx;
        } stat;
    };
    uint32_t rx_lrr;
    struct {
        uint64_t u64;
    } rx_lrr_time;
    struct {
        uint64_t u64;
    } ts_freq;
    void *rtcp_session;
} pjmedia_rtcp_xr_session;

typedef struct {
    uint8_t pt;
    uint8_t count;
    uint16_t length;
} pjmedia_rtcp_common;

typedef struct {
    pjmedia_rtcp_common common;
    uint8_t buf[1];
} pjmedia_rtcp_xr_pkt;

typedef struct {
    uint8_t bt;
    uint8_t specific;
    uint16_t length;
} pjmedia_rtcp_xr_rb_header;

typedef struct {
    pjmedia_rtcp_xr_rb_header header;
    uint32_t ntp_sec;
    uint32_t ntp_frac;
} pjmedia_rtcp_xr_rb_rr_time;

typedef struct {
    uint32_t lrr;
    uint32_t dlrr;
} pjmedia_rtcp_xr_dlrr_item;

typedef struct {
    pjmedia_rtcp_xr_rb_header header;
    pjmedia_rtcp_xr_dlrr_item item;
} pjmedia_rtcp_xr_rb_dlrr;

typedef struct {
    pjmedia_rtcp_xr_rb_header header;
    uint16_t begin_seq;
    uint16_t end_seq;
    uint32_t lost;
    uint32_t dup;
    uint32_t jitter_min;
    uint32_t jitter_max;
    uint32_t jitter_mean;
    uint32_t jitter_dev;
    uint8_t toh_min;
    uint8_t toh_max;
    uint8_t toh_mean;
    uint32_t toh_dev;
} pjmedia_rtcp_xr_rb_stats;

typedef struct {
    pjmedia_rtcp_xr_rb_header header;
    uint8_t loss_rate;
    uint8_t discard_rate;
    uint8_t burst_den;
    uint8_t gap_den;
    uint16_t burst_dur;
    uint16_t gap_dur;
    uint16_t rnd_trip_delay;
    uint16_t end_sys_delay;
    uint8_t signal_lvl;
    uint8_t noise_lvl;
    uint8_t rerl;
    uint8_t gmin;
    uint8_t r_factor;
    uint8_t ext_r_factor;
    uint8_t mos_lq;
    uint8_t mos_cq;
    uint8_t rx_config;
    uint16_t jb_nom;
    uint16_t jb_max;
    uint16_t jb_abs_max;
} pjmedia_rtcp_xr_rb_voip_mtc;

typedef struct {
    uint32_t hi;
    uint32_t lo;
} pjmedia_rtcp_ntp_rec;

#define TRACE_(args)
#define PJ_LOG(level, args)

static uint16_t pj_ntohs(uint16_t val) { return val; }
static uint32_t pj_ntohl(uint32_t val) { return val; }
static void pj_get_timestamp(void *ts) {}
static void pjmedia_rtcp_get_ntp_time(void *sess, pjmedia_rtcp_ntp_rec *ntp) {}
static void pj_bzero(void *buf, size_t size) { memset(buf, 0, size); }
static void pj_math_stat_update(void *stat, unsigned val) {}
static void pj_math_stat_set_stddev(void *stat, uint32_t val) {}
static void pj_gettimeofday(void *tv) {}