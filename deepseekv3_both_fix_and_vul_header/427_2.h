#include <stdint.h>
#include <stddef.h>
#include <sys/time.h>

typedef struct ThreadVars ThreadVars;
typedef struct DecodeThreadVars DecodeThreadVars;
typedef struct PacketQueue PacketQueue;

enum DecodeTunnelProto {
    DECODE_TUNNEL_IPV6_TEREDO
};

#define DLT_RAW 12

struct Packet {
    struct Packet *root;
    uint8_t recursion_level;
    struct timeval ts;
    uint32_t datalink;
    uint32_t tenant_id;
    uint32_t flags;
};

typedef struct Packet Packet;

#define SCEnter()
#define SCReturnPtr(ptr, type) return (ptr)
#define SCLogDebug(msg)
#define unlikely(expr) (expr)
#define PacketGetFromQueueOrAlloc() NULL
#define PacketCopyData(pkt, data, len)
#define GET_PKT_DATA(pkt) NULL
#define GET_PKT_LEN(pkt) 0
#define SET_TUNNEL_PKT(pkt)
#define UNSET_TUNNEL_PKT(pkt)
#define PKT_IS_INVALID 0x01
#define TmqhOutputPacketpool(tv, pkt)
#define TUNNEL_INCR_PKT_TPR(pkt)
#define DecodeSetNoPayloadInspectionFlag(pkt)
#define TM_ECODE_OK 0

int DecodeTunnel(ThreadVars *tv, DecodeThreadVars *dtv, Packet *p, uint8_t *data, uint32_t len, PacketQueue *pq, enum DecodeTunnelProto proto);