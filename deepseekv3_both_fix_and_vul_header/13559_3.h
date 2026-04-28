#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

typedef struct nni_aio nni_aio;
typedef struct nni_msg nni_msg;
typedef struct nng_stream nng_stream;
typedef struct property property;

typedef struct {
    void *iov_buf;
    size_t iov_len;
} nni_iov;

typedef struct {
    struct {
        char *body;
    } clientid;
    struct {
        char *body;
    } username;
    uint8_t pro_ver;
} conn_param;

typedef struct nni_mtx {
    void *unused;
} nni_mtx;

typedef struct nni_list {
    void *unused;
} nni_list;

typedef struct nni_lmq {
    void *unused;
} nni_lmq;

typedef struct {
    size_t max_packet_size;
} tlstran_conf;

#define NNI_NANO_MAX_HEADER_SIZE 5
#define NANO_MAX_QOS_PACKET 16
#define NMQ_SERVER_BUSY 1
#define NMQ_SERVER_UNAVAILABLE 2
#define NMQ_PACKET_TOO_LARGE 3
#define NMQ_RECEIVE_MAXIMUM_EXCEEDED 4
#define PROTOCOL_ERROR 5
#define NNG_EMSGSIZE 6

#define CMD_PINGREQ 0xC0
#define CMD_PINGRESP 0xD0
#define CMD_PUBLISH 0x30
#define CMD_PUBACK 0x40
#define CMD_PUBREC 0x50
#define CMD_PUBREL 0x60
#define CMD_PUBCOMP 0x70

typedef struct {
    nni_mtx    mtx;
    nni_aio   *rxaio;
    nni_aio   *qsaio;
    nni_aio   *rpaio;
    uint8_t    rxlen[NNI_NANO_MAX_HEADER_SIZE];
    uint8_t    txlen[2];
    size_t     gotrxhead;
    size_t     wantrxhead;
    nni_msg   *rxmsg;
    conn_param *tcp_cparam;
    nni_list   recvq;
    bool       busy;
    nni_lmq    rslmq;
    uint32_t   qrecv_quota;
    uint32_t   qsend_quota;
    nng_stream *conn;
    void      *npipe;
    tlstran_conf *conf;
} tlstran_pipe;

void log_trace(const char *fmt, ...);
void log_warn(const char *fmt, ...);
void log_error(const char *fmt, ...);
const char *nng_strerror(int err);
uint64_t get_var_integer(uint8_t *buf, uint32_t *pos);
void fixed_header_adaptor(uint8_t *rxlen, nni_msg *msg);
int nni_mqtt_pubres_decode(nni_msg *msg, uint16_t *packet_id, uint8_t *reason_code, property **prop, uint8_t pro_ver);
void nni_mqtt_msgack_encode(nni_msg *msg, uint16_t packet_id, uint8_t reason_code, property *prop, uint8_t pro_ver);
void nni_mqtt_pubres_header_encode(nni_msg *msg, uint8_t cmd);
void property_free(property *prop);
uint64_t nng_clock(void);
void *nni_msg_body(nni_msg *msg);
int nni_msg_alloc(nni_msg **msg, size_t size);