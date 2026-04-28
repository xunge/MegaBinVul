#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define NNI_NANO_MAX_HEADER_SIZE 5
#define NNG_TRAN_MAX_LMQ_SIZE 16

#define SERVER_UNAVAILABLE 1
#define PACKET_TOO_LARGE 2
#define UNSPECIFIED_ERROR 3
#define PROTOCOL_ERROR 4

#define CMD_PUBLISH 0x30
#define CMD_PUBACK 0x40
#define CMD_PUBREC 0x50
#define CMD_PUBREL 0x60
#define CMD_PUBCOMP 0x70

#define MQTT_PROTOCOL_VERSION_v5 5

typedef struct nni_aio nni_aio;
typedef struct nni_iov {
    void *iov_buf;
    size_t iov_len;
} nni_iov;
typedef struct nni_msg nni_msg;
typedef struct nni_mtx {
    // opaque structure
} nni_mtx;
typedef struct nni_lmq {
    // opaque structure
} nni_lmq;
typedef struct nng_stream nng_stream;
typedef struct property property;
typedef struct nni_list {
    // opaque structure
} nni_list;

typedef struct mqtts_tcptran_pipe {
    nni_aio *rxaio;
    nni_aio *qsaio;
    nni_mtx mtx;
    nng_stream *conn;
    nni_lmq rslmq;
    uint32_t gotrxhead;
    uint32_t wantrxhead;
    uint8_t rxlen[NNI_NANO_MAX_HEADER_SIZE];
    nni_msg *rxmsg;
    size_t rcvmax;
    uint8_t proto;
    bool busy;
    uint32_t pingcnt;
    void *npipe;
    void *cparam;
    nni_list recvq;
    uint32_t sndmax;
} mqtts_tcptran_pipe;

int mqtt_get_remaining_length(uint8_t *, uint32_t, uint32_t *, uint8_t *);
void nni_aio_set_iov(nni_aio *, int, nni_iov *);
void nni_aio_set_msg(nni_aio *, nni_msg *);
void nni_aio_finish_sync(nni_aio *, int, size_t);
void nni_aio_finish_error(nni_aio *, int);
int nni_aio_result(nni_aio *);
size_t nni_aio_count(nni_aio *);
void nni_aio_iov_advance(nni_aio *, size_t);
int nni_aio_iov_count(nni_aio *);
void nni_aio_list_remove(nni_aio *);
int nni_msg_alloc(nni_msg **, size_t);
void nni_msg_set_remaining_len(nni_msg *, uint32_t);
void *nni_msg_body(nni_msg *);
size_t nni_msg_len(nni_msg *);
void nni_msg_header_append(nni_msg *, uint8_t *, size_t);
void nni_msg_free(nni_msg *);
uint8_t nni_msg_get_pub_qos(nni_msg *);
uint16_t nni_msg_get_pub_pid(nni_msg *);
int nni_mqtt_pubres_decode(nni_msg *, uint16_t *, uint8_t *, property **, uint8_t);
void nni_mqtt_msgack_encode(nni_msg *, uint16_t, uint8_t, property *, uint8_t);
void nni_mqtt_pubres_header_encode(nni_msg *, uint8_t);
void property_free(property *);
void nni_msg_insert(nni_msg *, void *, size_t);
size_t nni_msg_header_len(nni_msg *);
void *nni_msg_header(nni_msg *);
int nni_lmq_full(nni_lmq *);
int nni_lmq_cap(nni_lmq *);
int nni_lmq_resize(nni_lmq *, size_t);
int nni_lmq_put(nni_lmq *, nni_msg *);
int nni_lmq_get(nni_lmq *, nni_msg **);
void nni_pipe_bump_rx(void *, size_t);
void nni_pipe_bump_error(void *, int);
void nni_mtx_lock(nni_mtx *);
void nni_mtx_unlock(nni_mtx *);
nni_aio *nni_list_first(nni_list *);
bool nni_list_empty(nni_list *);
void mqtts_tcptran_pipe_recv_start(mqtts_tcptran_pipe *);
void nng_stream_recv(nng_stream *, nni_aio *);
void nng_stream_send(nng_stream *, nni_aio *);