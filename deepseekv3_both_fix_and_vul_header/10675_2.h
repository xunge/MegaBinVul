#include <stdint.h>
#include <stddef.h>

typedef uint8_t UCHAR;
typedef uint16_t USHORT;
typedef uint32_t ULONG;
typedef int BOOLEAN;
typedef UCHAR* PUCHAR;

#define TRUE 1
#define FALSE 0

typedef struct {
    UCHAR ip_verlen;
    UCHAR ip_tos;
    USHORT ip_length;
    USHORT ip_id;
    USHORT ip_offset;
    UCHAR ip_ttl;
    UCHAR ip_protocol;
    USHORT ip_xsum;
    ULONG ip_src;
    ULONG ip_dst;
} IPv4Header;

typedef union _IPHeader {
    IPv4Header v4;
    struct {
        ULONG ip6_flow;
        USHORT ip6_payload_len;
        UCHAR ip6_next_header;
        UCHAR ip6_hop_limit;
        ULONG ip6_src[4];
        ULONG ip6_dst[4];
    } v6;
} IPHeader;

typedef struct _IPv6ExtHeader {
    UCHAR ip6ext_next_header;
    UCHAR ip6ext_hdr_len;
    USHORT ip6ext_data[3];
} IPv6ExtHeader;

typedef struct _tTcpIpPacketParsingResult {
    ULONG value;
    UCHAR ipStatus;
    UCHAR ipCheckSum;
    UCHAR xxpStatus;
    UCHAR TcpUdp;
    UCHAR xxpFull;
    UCHAR IsFragment;
    USHORT ipHeaderSize;
} tTcpIpPacketParsingResult;

#define ppresNotIP 0
#define ppresIPV4 1
#define ppresIPV6 2
#define ppresIPTooShort 3
#define ppresCSOK 4
#define ppresXxpKnown 5
#define ppresXxpOther 6
#define ppresIsTCP 7
#define ppresIsUDP 8

#define PROTOCOL_TCP 6
#define PROTOCOL_UDP 17
#define MAX_SUPPORTED_IPV6_HEADERS 256

#define DPrintf(level, args)

static USHORT swap_short(USHORT val) {
    return (val << 8) | (val >> 8);
}

static tTcpIpPacketParsingResult ProcessTCPHeader(tTcpIpPacketParsingResult res, IPHeader *pIpHeader, ULONG len, USHORT ipHeaderSize) {
    return res;
}

static tTcpIpPacketParsingResult ProcessUDPHeader(tTcpIpPacketParsingResult res, IPHeader *pIpHeader, ULONG len, USHORT ipHeaderSize) {
    return res;
}