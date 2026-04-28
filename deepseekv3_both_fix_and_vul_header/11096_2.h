#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <time.h>

typedef struct ThreadVars ThreadVars;
typedef struct PacketQueue PacketQueue;

typedef struct tcphdr {
    uint8_t th_flags;
} tcphdr;

typedef struct timeval {
    time_t tv_sec;
} timeval;

typedef struct {
    uint32_t isn;
    uint32_t next_seq;
    uint32_t last_ack;
    uint32_t window;
    uint32_t next_win;
    uint32_t last_ts;
    uint32_t last_pkt_ts;
    uint16_t wscale;
    uint8_t flags;
} TcpStream;

typedef struct TcpSession {
    TcpStream client;
    TcpStream server;
    uint8_t flags;
} TcpSession;

typedef struct Packet {
    tcphdr *tcph;
    uint32_t payload_len;
    timeval ts;
} Packet;

typedef struct StreamTcpThread {
    void *ra_ctx;
} StreamTcpThread;

typedef struct {
    bool async_oneside;
} StreamConfig;

extern StreamConfig stream_config;

#define TH_SYN 0x02
#define TH_ACK 0x10
#define TH_RST 0x04
#define TH_FIN 0x01

#define FALSE 0
#define TRUE 1

#define TCP_CLOSED 0
#define TCP_SYN_RECV 1
#define TCP_ESTABLISHED 2

#define STREAMTCP_FLAG_4WHS (1 << 0)
#define STREAMTCP_FLAG_SERVER_WSCALE (1 << 1)
#define STREAMTCP_FLAG_CLIENT_SACKOK (1 << 2)
#define STREAMTCP_FLAG_SACKOK (1 << 3)
#define STREAMTCP_FLAG_ASYNC (1 << 4)
#define STREAMTCP_FLAG_TIMESTAMP (1 << 5)

#define STREAMTCP_STREAM_FLAG_RST_RECV (1 << 0)
#define STREAMTCP_STREAM_FLAG_TIMESTAMP (1 << 1)
#define STREAMTCP_STREAM_FLAG_ZERO_TIMESTAMP (1 << 2)

#define STREAM_4WHS_SYNACK_WITH_WRONG_ACK 1
#define STREAM_4WHS_SYNACK_WITH_WRONG_SYN 2
#define STREAM_3WHS_SYNACK_IN_WRONG_DIRECTION 3
#define STREAM_3WHS_SYNACK_WITH_WRONG_ACK 4
#define STREAM_3WHS_ASYNC_WRONG_SEQ 5

#define TCP_WSCALE_MAX 14

#define PKT_IS_TOCLIENT(p) (0)
#define PKT_IS_TOSERVER(p) (1)

#define TCP_GET_SEQ(p) (0)
#define TCP_GET_ACK(p) (0)
#define TCP_GET_WINDOW(p) (0)
#define TCP_GET_TSVAL(p) (0)
#define TCP_GET_WSCALE(p) (0)
#define TCP_GET_SACKOK(p) (0)
#define TCP_HAS_TS(p) (0)
#define TCP_HAS_WSCALE(p) (0)

#define SEQ_EQ(a, b) ((a) == (b))

#define STREAMTCP_SET_RA_BASE_SEQ(stream, seq) do { } while (0)

#define SCLogDebug(fmt, ...) do { } while (0)

int StateSynSentValidateTimestamp(TcpSession *ssn, Packet *p);
int StreamTcpValidateRst(TcpSession *ssn, Packet *p);
void StreamTcpPacketSetState(Packet *p, TcpSession *ssn, int state);
void StreamTcpSetEvent(Packet *p, int event);
void StreamTcp3whsSynAckUpdate(TcpSession *ssn, Packet *p, void *arg);
void StreamTcpReassembleHandleSegment(ThreadVars *tv, void *ra_ctx, TcpSession *ssn, TcpStream *stream, Packet *p, PacketQueue *pq);