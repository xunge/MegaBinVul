#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

typedef uint32_t FlowThreadId;

typedef struct ThreadVars {
    int id;
} ThreadVars;

typedef struct Flow {
    FlowThreadId thread_id;
    void *protoctx;
    uint16_t alproto;
} Flow;

typedef struct tcphdr {
    uint16_t th_flags;
} tcphdr;

typedef struct TcpStream {
    uint32_t tcp_flags;
    uint32_t last_ack;
    uint32_t flags;
} TcpStream;

typedef struct TcpSession {
    uint8_t tcp_packet_flags;
    uint8_t flags;
    uint8_t state;
    TcpStream client;
    TcpStream server;
} TcpSession;

typedef struct Packet {
    Flow *flow;
    tcphdr *tcph;
    uint64_t pcap_cnt;
    uint32_t flags;
} Packet;

typedef struct PacketQueue {
    unsigned len;
} PacketQueue;

typedef struct StreamTcpThread {
    PacketQueue pseudo_queue;
    void *ra_ctx;
    int counter_tcp_synack;
    int counter_tcp_syn;
    int counter_tcp_rst;
} StreamTcpThread;

#define SCEnter()
#define SCReturnInt(x) return x
#define DEBUG_ASSERT_FLOW_LOCKED(x)
#define SCLogDebug(fmt, ...)
#define unlikely(x) (x)
#define DEBUG
#define PKT_IS_TOSERVER(p) 0
#define PKT_IS_TOCLIENT(p) 0
#define TCP_GET_ACK(p) 0
#define STREAM_PKT_BROKEN_ACK 0
#define PKT_PSEUDO_STREAM_END 0
#define PKT_STREAM_EST 0
#define PKT_STREAM_MODIFIED 0
#define PKT_STREAM_NOPCAPLOG 0
#define STREAMTCP_FLAG_ASYNC 0
#define STREAMTCP_FLAG_MIDSTREAM_SYNACK 0
#define STREAMTCP_FLAG_BYPASS 0
#define STREAMTCP_STREAM_FLAG_DEPTH_REACHED 0
#define STREAMTCP_STREAM_FLAG_NOREASSEMBLY 0

#define TCP_NONE 0
#define TCP_SYN_SENT 1
#define TCP_SYN_RECV 2
#define TCP_ESTABLISHED 3
#define TCP_FIN_WAIT1 4
#define TCP_FIN_WAIT2 5
#define TCP_CLOSING 6
#define TCP_CLOSE_WAIT 7
#define TCP_LAST_ACK 8
#define TCP_TIME_WAIT 9
#define TCP_CLOSED 10

#define TH_SYN 0x02
#define TH_ACK 0x10
#define TH_RST 0x04

#define StatsIncr(tv, counter)
#define StreamTcpSetEvent(p, event)
#define StreamTcpCheckFlowDrops(p) 0
#define FlowSetNoPacketInspectionFlag(flow)
#define DecodeSetNoPacketInspectionFlag(p)
#define StreamTcpDisableAppLayer(flow)
#define PACKET_DROP(p)
#define StreamTcpSessionPktFree(p)
#define StreamTcpPacketStateNone(tv, p, stt, ssn, pq) 0
#define StreamTcpReassembleHandleSegment(tv, ctx, ssn, side, p, pq)
#define StreamTcpPacketSwitchDir(ssn, p)
#define StreamTcpPacketIsKeepAlive(ssn, p) 0
#define StreamTcpPacketIsKeepAliveACK(ssn, p) 0
#define StreamTcpClearKeepAliveFlag(ssn, p)
#define StreamTcpPacketIsFinShutdownAck(ssn, p) 0
#define StreamTcpPacketIsWindowUpdate(ssn, p) 0
#define StreamTcpPacketIsBadWindowUpdate(ssn, p) 0
#define StreamTcpPacketStateSynSent(tv, p, stt, ssn, pq) 0
#define StreamTcpPacketStateSynRecv(tv, p, stt, ssn, pq) 0
#define StreamTcpPacketStateEstablished(tv, p, stt, ssn, pq) 0
#define StreamTcpPacketStateFinWait1(tv, p, stt, ssn, pq) 0
#define StreamTcpPacketStateFinWait2(tv, p, stt, ssn, pq) 0
#define StreamTcpPacketStateClosing(tv, p, stt, ssn, pq) 0
#define StreamTcpPacketStateCloseWait(tv, p, stt, ssn, pq) 0
#define StreamTcpPacketStateLastAck(tv, p, stt, ssn, pq) 0
#define StreamTcpPacketStateTimeWait(tv, p, stt, ssn, pq) 0
#define PacketDequeue(queue) NULL
#define PacketEnqueue(queue, p)
#define ReCalculateChecksum(p)
#define StreamTcpBypassEnabled() 0
#define PacketBypassCallback(p)
#define StreamTcpInlineDropInvalid() 0

extern int g_detect_disabled;