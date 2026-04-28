#include <stdint.h>
#include <stddef.h>

typedef uint8_t UCHAR;
typedef uint16_t USHORT;
typedef uint32_t ULONG;
typedef int BOOLEAN;

#define FALSE 0
#define TRUE 1
typedef UCHAR* PUCHAR;

#define PROTOCOL_TCP 6
#define PROTOCOL_UDP 17

#define ppresNotIP 0
#define ppresIPV4 1
#define ppresIPV6 2
#define ppresIPTooShort 3
#define ppresCSOK 0
#define ppresXxpKnown 1
#define ppresXxpOther 2
#define ppresIsTCP 1
#define ppresIsUDP 2

#define MAX_SUPPORTED_IPV6_HEADERS 256

typedef union {
    struct {
        UCHAR ip_verlen;
        UCHAR ip_tos;
        USHORT ip_length;
        USHORT ip_id;
        USHORT ip_offset;
        UCHAR ip_ttl;
        UCHAR ip_protocol;
        USHORT ip_checksum;
        uint32_t ip_src;
        uint32_t ip_dst;
    } v4;
    struct {
        uint32_t ip6_flow;
        USHORT ip6_payload_len;
        UCHAR ip6_next_header;
        UCHAR ip6_hop_limit;
        uint32_t ip6_src[4];
        uint32_t ip6_dst[4];
    } v6;
} IPHeader;

typedef struct {
    UCHAR ip6ext_next_header;
    UCHAR ip6ext_hdr_len;
} IPv6ExtHeader;

typedef struct {
    uint32_t value;
    UCHAR ipStatus;
    UCHAR ipCheckSum;
    UCHAR xxpStatus;
    UCHAR TcpUdp;
    UCHAR xxpFull;
    UCHAR IsFragment;
    USHORT ipHeaderSize;
} tTcpIpPacketParsingResult;

typedef struct {
    UCHAR ip_verlen;
    UCHAR ip_tos;
    USHORT ip_length;
    USHORT ip_id;
    USHORT ip_offset;
    UCHAR ip_ttl;
    UCHAR ip_protocol;
    USHORT ip_checksum;
    uint32_t ip_src;
    uint32_t ip_dst;
} IPv4Header;

typedef struct {
    uint32_t ip6_flow;
    USHORT ip6_payload_len;
    UCHAR ip6_next_header;
    UCHAR ip6_hop_limit;
    uint32_t ip6_src[4];
    uint32_t ip6_dst[4];
} IPv6Header;

static USHORT swap_short(USHORT val) {
    return (val >> 8) | (val << 8);
}

#define DPrintf(level, args) (void)0

static tTcpIpPacketParsingResult ProcessTCPHeader(tTcpIpPacketParsingResult res, IPHeader *pIpHeader, ULONG len, USHORT ipHeaderSize) {
    return res;
}

static tTcpIpPacketParsingResult ProcessUDPHeader(tTcpIpPacketParsingResult res, IPHeader *pIpHeader, ULONG len, USHORT ipHeaderSize) {
    return res;
}