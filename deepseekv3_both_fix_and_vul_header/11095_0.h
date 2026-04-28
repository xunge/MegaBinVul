#include <stdint.h>
#include <string.h>
#include <netinet/in.h>

#define SIZE_OF_PACKET 1024
#define TRUE 1
#define FALSE 0
#define TH_SYN 0x02
#define TH_ACK 0x10
#define TH_PUSH 0x08
#define FLOW_PKT_TOSERVER 0x01
#define STREAMTCP_FLAG_ASYNC 0x01
#define TCP_ESTABLISHED 1

#define unlikely(x) (x)
#define FAIL_IF(cond) if (cond) return -1
#define PASS return 0
#define SCMalloc(size) malloc(size)
#define SCFree(ptr) free(ptr)

typedef struct Packet {
    struct Flow *flow;
    uint8_t *payload;
    uint16_t payload_len;
    uint8_t flowflags;
    struct TCPHdr *tcph;
} Packet;

typedef struct Flow {
    void *protoctx;
} Flow;

typedef struct ThreadVars {
    // empty struct
} ThreadVars;

typedef struct StreamTcpThread {
    void *ra_ctx;
} StreamTcpThread;

typedef struct TCPHdr {
    uint32_t th_seq;
    uint32_t th_ack;
    uint16_t th_win;
    uint8_t th_flags;
} TCPHdr;

typedef struct PacketQueue {
    // empty struct
} PacketQueue;

typedef struct TcpSession {
    uint8_t state;
    uint8_t flags;
    struct {
        uint32_t last_ack;
    } client;
    struct {
        uint32_t next_seq;
    } server;
} TcpSession;

typedef struct {
    int async_oneside;
} StreamConfig;

extern StreamConfig stream_config;

#define FLOW_INITIALIZE(f) memset((f), 0, sizeof(Flow))
#define FLOW_DESTROY(f) 

void StreamTcpUTInit(void **ra_ctx);
void StreamTcpUTDeinit(void *ra_ctx);
int StreamTcpPacket(ThreadVars *tv, Packet *p, StreamTcpThread *stt, PacketQueue *pq);
void StreamTcpCreateTestPacket(uint8_t *payload, uint8_t val, uint8_t len, uint8_t pad);
void StreamTcpSessionClear(void *protoctx);