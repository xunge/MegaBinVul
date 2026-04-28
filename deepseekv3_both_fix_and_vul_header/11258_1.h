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

typedef struct TcpHdr {
    uint8_t th_flags;
} TcpHdr;

typedef struct TcpStream {
    uint8_t tcp_flags;
    uint32_t last_ack;
    uint8_t flags;
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
    TcpHdr *tcph;
    uint64_t pcap_cnt;
    uint8_t flags;
} Packet;

typedef struct PacketQueue {
    unsigned int len;
} PacketQueue;

typedef struct StreamTcpThread {
    PacketQueue pseudo_queue;
    void *ra_ctx;
    int counter_tcp_synack;
    int counter_tcp_syn;
    int counter_tcp_rst;
} StreamTcpThread;

#define TH_SYN 0x02
#define TH_ACK 0x10
#define TH_RST 0x04

#define STREAMTCP_FLAG_ASYNC (1 << 0)
#define STREAMTCP_FLAG_MIDSTREAM_SYNACK (1 << 1)
#define STREAMTCP_FLAG_BYPASS (1 << 2)

#define STREAMTCP_STREAM_FLAG_DEPTH_REACHED (1 << 0)
#define STREAMTCP_STREAM_FLAG_NOREASSEMBLY (1 << 1)

#define PKT_PSEUDO_STREAM_END (1 << 0)
#define PKT_STREAM_EST (1 << 1)
#define PKT_STREAM_MODIFIED (1 << 2)
#define PKT_STREAM_NOPCAPLOG (1 << 3)

#define STREAM_PKT_BROKEN_ACK 1

enum {
    TCP_NONE,
    TCP_SYN_SENT,
    TCP_SYN_RECV,
    TCP_ESTABLISHED,
    TCP_FIN_WAIT1,
    TCP_FIN_WAIT2,
    TCP_CLOSING,
    TCP_CLOSE_WAIT,
    TCP_LAST_ACK,
    TCP_TIME_WAIT,
    TCP_CLOSED
};

#define SCEnter()
#define SCReturnInt(x) return x
#define SCLogDebug(fmt, ...)
#define DEBUG_ASSERT_FLOW_LOCKED(x)
#define unlikely(x) (x)
#define PKT_IS_TOSERVER(p) 0
#define PKT_IS_TOCLIENT(p) 0
#define StatsIncr(tv, counter)
#define TCP_GET_ACK(p) 0
#define StreamTcpSetEvent(p, event)
#define StreamTcpCheckFlowDrops(p) 0
#define FlowSetNoPacketInspectionFlag(flow)
#define DecodeSetNoPacketInspectionFlag(p)
#define StreamTcpDisableAppLayer(flow)
#define PACKET_DROP(p)
#define StreamTcpSessionPktFree(p)
#define StreamTcpPacketStateNone(tv, p, stt, ssn, pq) 0
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
#define StreamTcpReassembleHandleSegment(tv, ctx, ssn, stream, p, pq)
#define PacketDequeue(pq) NULL
#define PacketEnqueue(pq, p)
#define ReCalculateChecksum(p)
#define StreamTcpBypassEnabled() 0
#define PacketBypassCallback(p)
#define StreamTcpInlineDropInvalid() 0
#define DecodeSetNoPayloadInspectionFlag(p)

extern int g_detect_disabled;