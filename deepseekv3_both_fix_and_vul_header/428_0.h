#include <stdint.h>
#include <inttypes.h>

enum DecodeTunnelProto {
    DECODE_TUNNEL_PPP,
    DECODE_TUNNEL_IPV4,
    DECODE_TUNNEL_IPV6,
    DECODE_TUNNEL_IPV6_TEREDO,
    DECODE_TUNNEL_VLAN,
    DECODE_TUNNEL_ETHERNET,
    DECODE_TUNNEL_ERSPAN
};

typedef struct ThreadVars ThreadVars;
typedef struct DecodeThreadVars DecodeThreadVars;
typedef struct Packet Packet;
typedef struct PacketQueue PacketQueue;

#define TM_ECODE_OK 0
#define SCLogDebug(...)