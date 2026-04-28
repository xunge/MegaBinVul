#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#define NNI_NANO_MAX_HEADER_SIZE 5
#define CMD_CONNECT 0x10
#define CMD_PUBLISH 0x30
#define CMD_PUBACK 0x40
#define CMD_PUBREC 0x50
#define CMD_PUBREL 0x60
#define CMD_PUBCOMP 0x70
#define CMD_PINGREQ 0xC0
#define CMD_PINGRESP 0xD0

#define NNG_EMSGSIZE 1
#define NNG_ECONNRESET 2
#define PROTOCOL_ERROR 0x01
#define NMQ_PACKET_TOO_LARGE 0x95
#define NMQ_RECEIVE_MAXIMUM_EXCEEDED 0x93
#define NMQ_SERVER_BUSY 0x94

typedef struct nni_msg {
    void *header;
    size_t header_len;
    void *body;
    size_t len;
    uint8_t cmd_type;
    void *conn_param;
} nni_msg;

typedef struct nni_aio {
    void *msg;
    int result;
    void *output;
} nni_aio;

typedef struct nni_iov {
    void *iov_buf;
    size_t iov_len;
} nni_iov;

typedef struct nni_mtx {
    pthread_mutex_t lock;
} nni_mtx;

typedef struct nng_stream {
    void *data;
} nng_stream;

typedef struct nni_pipe {
    void *data;
} nni_pipe;

typedef struct ws_pipe_conf {
    size_t max_packet_size;
    size_t client_max_packet_size;
} ws_pipe_conf;

typedef struct property {
    void *data;
} property;

typedef struct conn_param {
    uint8_t pro_ver;
    uint32_t rx_max;
    uint32_t max_packet_size;
} conn_param;

typedef struct ws_pipe {
    nni_mtx mtx;
    nni_aio *rxaio;
    nni_aio *user_rxaio;
    nni_aio *ep_aio;
    nni_aio *qsaio;
    nng_stream *ws;
    nni_pipe *npipe;
    nni_msg *tmp_msg;
    conn_param *ws_param;
    ws_pipe_conf *conf;
    uint64_t gotrxhead;
    uint64_t wantrxhead;
    uint32_t qsend_quota;
    uint32_t qrecv_quota;
} ws_pipe;

static void nni_mtx_lock(nni_mtx *mtx) { pthread_mutex_lock(&mtx->lock); }
static void nni_mtx_unlock(nni_mtx *mtx) { pthread_mutex_unlock(&mtx->lock); }
static int nni_aio_result(nni_aio *aio) { return aio->result; }
static nni_msg *nni_aio_get_msg(nni_aio *aio) { return aio->msg; }
static size_t nni_msg_header_len(nni_msg *msg) { return msg->header_len; }
static size_t nni_msg_len(nni_msg *msg) { return msg->len; }
static void *nni_msg_body(nni_msg *msg) { return msg->body; }
static int nni_msg_alloc(nni_msg **msg, size_t size) { *msg = calloc(1, sizeof(nni_msg)); return *msg ? 0 : -1; }
static void nni_msg_free(nni_msg *msg) { free(msg); }
static void nni_msg_append(nni_msg *msg, void *data, size_t len) { memcpy(msg->body, data, len); msg->len += len; }
static void nni_msg_set_cmd_type(nni_msg *msg, uint8_t type) { msg->cmd_type = type; }
static uint8_t nni_msg_cmd_type(nni_msg *msg) { return msg->cmd_type; }
static void nni_aio_set_output(nni_aio *aio, int index, void *val) { aio->output = val; }
static void nni_aio_finish(nni_aio *aio, int rv, size_t count) { aio->result = rv; }
static void nni_aio_finish_error(nni_aio *aio, int rv) { aio->result = rv; }
static void nni_aio_set_msg(nni_aio *aio, nni_msg *msg) { aio->msg = msg; }
static void nni_aio_set_iov(nni_aio *aio, int count, nni_iov *iov) {}
static void nni_pipe_bump_error(nni_pipe *pipe, int rv) {}
static void log_warn(const char *fmt, ...) {}
static void log_trace(const char *fmt, ...) {}
static void log_error(const char *fmt, ...) {}
static const char *nng_strerror(int err) { return ""; }
static void nng_stream_recv(nng_stream *stream, nni_aio *aio) {}
static void nng_stream_send(nng_stream *stream, nni_aio *aio) {}
static void nng_stream_close(nng_stream *stream) {}
static void nng_aio_wait(nni_aio *aio) {}
static uint64_t get_var_integer(uint8_t *data, uint32_t *pos) { return 0; }
static void conn_param_alloc(conn_param **param) { *param = calloc(1, sizeof(conn_param)); }
static void conn_param_free(conn_param *param) { free(param); }
static int conn_handler(uint8_t *data, conn_param *param, size_t len) { return 0; }
static void ws_msg_adaptor(uint8_t *data, nni_msg *msg) {}
static void property_free(property *prop) { free(prop); }
static uint8_t nni_msg_get_pub_qos(nni_msg *msg) { return 0; }
static uint16_t nni_msg_get_pub_pid(nni_msg *msg) { return 0; }
static int nni_mqtt_pubres_decode(nni_msg *msg, uint16_t *pid, uint8_t *code, property **prop, uint8_t ver) { return 0; }
static void nni_mqtt_msgack_encode(nni_msg *msg, uint16_t pid, uint8_t code, property *prop, uint8_t ver) {}
static void nni_mqtt_pubres_header_encode(nni_msg *msg, uint8_t cmd) {}
static void nni_msg_header_append(nni_msg *msg, void *data, size_t len) { memcpy(msg->header, data, len); msg->header_len += len; }
static void *nni_msg_header(nni_msg *msg) { return msg->header; }
static void nni_msg_set_conn_param(nni_msg *msg, conn_param *param) { msg->conn_param = param; }