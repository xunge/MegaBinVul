#include <stdint.h>
#include <stddef.h>
#include <arpa/inet.h>

#define TM_ECODE_OK 0
#define TM_ECODE_FAILED -1
#define IPV6_HEADER_LEN 40
#define TEREDO_ORIG_INDICATION_LENGTH 8
#define DECODE_TUNNEL_IPV6_TEREDO 1
#define DECODE_TUNNEL_IPV6 2

typedef struct ThreadVars ThreadVars;
typedef struct DecodeThreadVars {
    uint64_t counter_teredo;
} DecodeThreadVars;
typedef struct Packet {
    int src;
} Packet;
typedef struct PacketQueue PacketQueue;
typedef struct IPV6Hdr {
    uint8_t version;
    uint8_t traffic_class;
    uint16_t flow_label;
    uint16_t payload_len;
    uint8_t next_header;
    uint8_t hop_limit;
    uint8_t src_addr[16];
    uint8_t dst_addr[16];
} IPV6Hdr;

extern int g_teredo_enabled;

#define IP_GET_RAW_VER(p) (((*(p)) >> 4) & 0x0f)
#define IPV6_GET_RAW_HLIM(hdr) ((hdr)->hop_limit)
#define IPV6_GET_RAW_NH(hdr) ((hdr)->next_header)
#define IPV6_GET_RAW_PLEN(hdr) (ntohs((hdr)->payload_len))
#define PKT_SET_SRC(pkt, src_val) ((pkt)->src = (src_val))

static const int PKT_SRC_DECODER_TEREDO = 3;

Packet *PacketTunnelPktSetup(ThreadVars *tv, DecodeThreadVars *dtv, Packet *p, uint8_t *pkt, uint16_t len, int type, PacketQueue *pq);
void PacketEnqueue(PacketQueue *pq, Packet *p);
void StatsIncr(ThreadVars *tv, uint64_t counter);