#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

typedef struct ThreadVars_ ThreadVars;
typedef struct Packet_ Packet;
typedef struct StreamTcpThread_ StreamTcpThread;
typedef struct PacketQueue_ PacketQueue;
typedef struct TcpSession_ TcpSession;
typedef struct Flow_ Flow;

struct PacketQueue_ {
    unsigned len;
};

struct tcphdr {
    uint8_t th_flags;
};

struct StreamTcpThread_ {
    uint64_t counter_tcp_synack;
    uint64_t counter_tcp_syn;
    uint64_t counter_tcp_rst;
    struct PacketQueue_ pseudo_queue;
    void *ra_ctx;
};

struct TcpSession_ {
    uint8_t tcp_packet_flags;
    uint8_t flags;
    uint8_t state;
    struct {
        uint8_t tcp_flags;
        uint32_t last_ack;
        uint8_t flags;
    } client, server;
    void *protoctx;
};

struct Packet_ {
    struct Flow_ *flow;
    uint64_t pcap_cnt;
    struct tcphdr *tcph;
    uint8_t flags;
};

struct Flow_ {
    void *protoctx;
    uint16_t alproto;
    uint8_t flags;
};

#define SCEnter()
#define SCReturnInt(x) return x
#define SCLogDebug(fmt, ...)
#define DEBUG_ASSERT_FLOW_LOCKED(flow)
#define PKT_IS_TOSERVER(p) 0
#define PKT_IS_TOCLIENT(p) 0
#define TCP_GET_ACK(p) 0
#define PACKET_DROP(p)
#define STREAMTCP_FLAG_ASYNC 0
#define STREAMTCP_FLAG_BYPASS 0
#define TH_SYN 0
#define TH_ACK 0
#define TH_RST 0
#define TCP_NONE 0
#define TCP_ESTABLISHED 0
#define STREAM_PKT_BROKEN_ACK 0
#define PKT_PSEUDO_STREAM_END 0
#define PKT_STREAM_NO_EVENTS 0
#define PKT_STREAM_EST 0
#define PKT_STREAM_MODIFIED 0
#define PKT_STREAM_NOPCAPLOG 0
#define FLOW_WRONG_THREAD 0
#define STREAMTCP_STREAM_FLAG_GAP 0
#define STREAMTCP_STREAM_FLAG_DEPTH_REACHED 0
#define STREAMTCP_STREAM_FLAG_NOREASSEMBLY 0

void HandleThreadId(ThreadVars *tv, Packet *p, StreamTcpThread *stt);
void StatsIncr(ThreadVars *tv, uint64_t counter);
void StreamTcpSetEvent(Packet *p, int event);
int StreamTcpCheckFlowDrops(Packet *p);
void FlowSetNoPacketInspectionFlag(Flow *flow);
void DecodeSetNoPacketInspectionFlag(Packet *p);
void StreamTcpDisableAppLayer(Flow *flow);
void StreamTcpSessionPktFree(Packet *p);
int StreamTcpPacketStateNone(ThreadVars *tv, Packet *p, StreamTcpThread *stt, TcpSession *ssn, PacketQueue *pq);
void StreamTcpReassembleHandleSegment(ThreadVars *tv, void *ra_ctx, TcpSession *ssn, void *stream, Packet *p, PacketQueue *pq);
int StreamTcpPacketIsKeepAlive(TcpSession *ssn, Packet *p);
int StreamTcpPacketIsKeepAliveACK(TcpSession *ssn, Packet *p);
void StreamTcpClearKeepAliveFlag(TcpSession *ssn, Packet *p);
int StreamTcpPacketIsFinShutdownAck(TcpSession *ssn, Packet *p);
int StreamTcpPacketIsWindowUpdate(TcpSession *ssn, Packet *p);
int StreamTcpPacketIsBadWindowUpdate(TcpSession *ssn, Packet *p);
int StreamTcpStateDispatch(ThreadVars *tv, Packet *p, StreamTcpThread *stt, TcpSession *ssn, PacketQueue *pq, uint8_t state);
void StreamTcpPacketCheckPostRst(TcpSession *ssn, Packet *p);
void ReCalculateChecksum(Packet *p);
int StreamTcpBypassEnabled(void);
void PacketBypassCallback(Packet *p);
int StreamTcpInlineDropInvalid(void);
void DecodeSetNoPayloadInspectionFlag(Packet *p);
Packet *PacketDequeue(PacketQueue *pq);
void PacketEnqueue(PacketQueue *pq, Packet *p);

extern int g_detect_disabled;