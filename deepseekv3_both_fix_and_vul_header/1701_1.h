#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

typedef int pj_status_t;
typedef int32_t pj_ssize_t;
typedef uint8_t pj_uint8_t;
typedef uint32_t pj_uint32_t;
typedef int pj_bool_t;

typedef enum srtp_err_status_t {
    srtp_err_status_ok,
    srtp_err_status_auth_fail,
    srtp_err_status_replay_old,
    srtp_err_status_replay_fail
} srtp_err_status_t;

typedef struct pjmedia_rtp_hdr {
    pj_uint32_t ssrc;
    uint8_t pt;
} pjmedia_rtp_hdr;

typedef struct pjmedia_tp_cb_param {
    void *user_data;
    void *pkt;
    pj_ssize_t size;
    int rem_switch;
} pjmedia_tp_cb_param;

typedef struct pjmedia_transport {
    struct {
        pj_status_t (*send_rtp)(struct pjmedia_transport*, void*, pj_ssize_t);
    } *op;
} pjmedia_transport;

typedef struct {
    pj_uint32_t ssrc;
    unsigned roc;
} pjmedia_srtp_crypto_setting;

typedef struct {
    pj_uint32_t ssrc;
    unsigned roc;
} pjmedia_srtp_crypto_prev_setting;

typedef struct {
    pjmedia_srtp_crypto_setting rx_roc;
    pjmedia_srtp_crypto_prev_setting prev_rx_roc;
} pjmedia_srtp_crypto;

typedef void* srtp_t;

typedef struct transport_srtp {
    pj_bool_t bypass_srtp;
    void (*rtp_cb)(void*, void*, pj_ssize_t);
    void (*rtp_cb2)(pjmedia_tp_cb_param*);
    void *user_data;
    unsigned probation_cnt;
    void *mutex;
    pj_bool_t session_inited;
    pj_bool_t use_rtcp_mux;
    pjmedia_srtp_crypto tx_policy;
    pjmedia_srtp_crypto rx_policy;
    srtp_t srtp_rx_ctx;
    pj_uint32_t rx_ssrc;
    pj_bool_t offerer_side;
    pjmedia_srtp_crypto_setting setting;
    pjmedia_srtp_crypto_prev_setting prev_rx_roc;
    void *pool;
    unsigned keying_cnt;
    pjmedia_transport **keying;
} transport_srtp;

#define PJ_EIGNORED (-1)
#define PJ_SUCCESS 0
#define PJ_LOG(level, args)
#define THIS_FILE ""
#define PJ_ASSERT_ON_FAIL(cond, action) if (!(cond)) { action; }