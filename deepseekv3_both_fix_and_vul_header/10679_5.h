#include <stdint.h>
#include <cstddef>
#include <stdbool.h>

typedef unsigned long ULONG;
typedef void *PVOID;
typedef uint16_t USHORT;

#define FALSE false

struct virtio_net_hdr_basic {
    uint8_t flags;
    uint8_t gso_type;
    uint16_t hdr_len;
    uint16_t gso_size;
    uint16_t csum_start;
    uint16_t csum_offset;
};

struct IPv4Header {
    // IPv4 header fields would be defined here
};

struct tTcpIpPacketParsingResult {
    int xxpCheckSum;
    bool fixedXxpCS;
    int ipStatus;
    size_t XxpIpHeaderSize;
};

enum {
    ppresPCSOK,
    ppresIPV4
};

enum {
    VIRTIO_NET_HDR_F_NEEDS_CSUM,
    VIRTIO_NET_HDR_GSO_TCPV4,
    VIRTIO_NET_HDR_GSO_TCPV6
};

enum {
    pcrIpChecksum,
    pcrFixIPChecksum,
    pcrTcpChecksum,
    pcrFixPHChecksum
};

#define ETH_PRIORITY_HEADER_SIZE 4
#define TCP_CHECKSUM_OFFSET 16

struct Context {
    struct {
        size_t ipHeaderOffset;
    } Offload;
};

struct ParentNBL {
    USHORT TCI();
    USHORT MSS();
    USHORT TCPHeaderOffset();
};

class CNB {
    Context* m_Context;
    ParentNBL* m_ParentNBL;
public:
    void SetupLSO(virtio_net_hdr_basic *VirtioHeader, PVOID IpHeader, ULONG EthPayloadLength) const;
};

void PopulateIPLength(IPv4Header*, USHORT);
tTcpIpPacketParsingResult ParaNdis_CheckSumVerifyFlat(IPv4Header*, ULONG, int, const char*);
tTcpIpPacketParsingResult ParaNdis_CheckSumVerifyFlat(IPv4Header*, ULONG, int, bool, const char*);