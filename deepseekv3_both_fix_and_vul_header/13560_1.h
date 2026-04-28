#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <pthread.h>

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
#define CMD_PINGRESP 0xD0
#define CMD_DISCONNECT 0xE0

enum {
    MQTT_PROTOCOL_VERSION_v5 = 5
};

typedef struct nni_aio nni_aio;
typedef struct nni_iov {
    void *iov_buf;
    size_t iov_len;
} nni_iov;
typedef struct nni_msg nni_msg;
typedef struct nng_stream nng_stream;
typedef struct property property;

typedef struct nni_mtx {
    pthread_mutex_t lock;
} nni_mtx;

typedef struct nni_list {
    void *l_first;
} nni_list;

typedef struct nni_lmq {
    size_t lmq_len;
    size_t lmq_cap;
    void **lmq_msgs;
} nni_lmq;

typedef struct mqtt_tcptran_pipe {
    nni_aio *rxaio;
    nni_aio *qsaio;
    nni_mtx mtx;
    nni_list recvq;
    uint8_t rxlen[NNI_NANO_MAX_HEADER_SIZE];
    size_t gotrxhead;
    size_t wantrxhead;
    nni_msg *rxmsg;
    size_t rcvmax;
    uint8_t proto;
    bool busy;
    nni_lmq rslmq;
    nng_stream *conn;
    void *npipe;
    int pingcnt;
    size_t sndmax;
#ifdef NNG_HAVE_MQTT_BROKER
    void *cparam;
#endif
} mqtt_tcptran_pipe;