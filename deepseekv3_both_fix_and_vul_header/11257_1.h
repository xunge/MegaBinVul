#include <stdint.h>
#include <sys/time.h>
#include <stddef.h>
#include <netinet/tcp.h>

typedef struct ThreadVars ThreadVars;
typedef struct PacketQueue PacketQueue;
typedef struct StreamTcpThread {
    void *ra_ctx;
} StreamTcpThread;

typedef struct {
    uint32_t isn;
    uint32_t next_seq;
    uint32_t last_ack;
    uint32_t window;
    uint32_t next_win;
    uint32_t last_ts;
    uint32_t last_pkt_ts;
    uint8_t wscale;
    uint16_t flags;
} TcpStream;

typedef struct {
    uint32_t flags;
    TcpStream client;
    TcpStream server;
    uint8_t wscale;
} TcpSession;

typedef struct {
    struct tcphdr *tcph;
    int payload_len;
    struct timeval ts;
} Packet;

typedef struct {
    int async_oneside;
} StreamConfig;

extern StreamConfig stream_config;

#define TH_SYN 0x02
#define TH_ACK 0x10
#define TH_RST 0x04
#define TH_FIN 0x01

#define STREAMTCP_FLAG_4WHS 0x01
#define STREAMTCP_FLAG_ASYNC 0x02
#define STREAMTCP_FLAG_TIMESTAMP 0x04
#define STREAMTCP_FLAG_SERVER_WSCALE 0x08
#define STREAMTCP_FLAG_CLIENT_SACKOK 0x10
#define STREAMTCP_FLAG_SACKOK 0x20

#define STREAMTCP_STREAM_FLAG_RST_RECV 0x01
#define STREAMTCP_STREAM_FLAG_TIMESTAMP 0x02
#define STREAMTCP_STREAM_FLAG_ZERO_TIMESTAMP 0x04

#define STREAM_4WHS_SYNACK_WITH_WRONG_ACK 1
#define STREAM_4WHS_SYNACK_WITH_WRONG_SYN 2
#define STREAM_3WHS_SYNACK_IN_WRONG_DIRECTION 3
#define STREAM_3WHS_SYNACK_WITH_WRONG_ACK 4
#define STREAM_3WHS_ASYNC_WRONG_SEQ 5

#define TCP_CLOSED 0
#define TCP_SYN_RECV 1
#define TCP_ESTABLISHED 2

#define TCP_WSCALE_MAX 14
#define FALSE 0

#define PKT_IS_TOCLIENT(p) 0
#define PKT_IS_TOSERVER(p) 1

#define SEQ_EQ(a, b) ((a) == (b))
#define TCP_GET_SEQ(p) (ntohl((p)->tcph->th_seq))
#define TCP_GET_ACK(p) (ntohl((p)->tcph->th_ack))
#define TCP_GET_WINDOW(p) (ntohs((p)->tcph->th_win))
#define TCP_GET_TSVAL(p) 0
#define TCP_GET_WSCALE(p) 0
#define TCP_GET_SACKOK(p) 0
#define TCP_HAS_TS(p) 0
#define TCP_HAS_WSCALE(p) 0

#define STREAMTCP_SET_RA_BASE_SEQ(stream, seq) do { } while (0)

#define SCLogDebug(fmt, ...) do { } while (0)

static int StreamTcpValidateRst(TcpSession *ssn, Packet *p) { return 1; }
static void StreamTcpPacketSetState(Packet *p, TcpSession *ssn, int state) {}
static void StreamTcpSetEvent(Packet *p, int event) {}
static void StreamTcp3whsSynAckUpdate(TcpSession *ssn, Packet *p, void *arg) {}
static void StreamTcpReassembleHandleSegment(ThreadVars *tv, void *ra_ctx, TcpSession *ssn, TcpStream *stream, Packet *p, PacketQueue *pq) {}