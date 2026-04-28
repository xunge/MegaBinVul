#include <stdint.h>
#include <stddef.h>

typedef uint32_t ULONG;
typedef uint8_t BOOLEAN;
#define FALSE 0
#define TRUE 1

#define VIRTIO_NET_HDR_F_NEEDS_CSUM 1
#define VIRTIO_NET_HDR_F_DATA_VALID 2
#define ETH_HEADER_SIZE 14

typedef struct {
    unsigned fRxIPChecksum : 1;
    unsigned fRxTCPChecksum : 1;
    unsigned fRxUDPChecksum : 1;
    unsigned fRxTCPv6Checksum : 1;
    unsigned fRxUDPv6Checksum : 1;
} tOffloadSettingsFlags;

typedef struct {
    tOffloadSettingsFlags flags;
} OffloadSettings;

typedef struct {
    ULONG framesRxCSHwOK;
} ExtraStatistics;

typedef struct _PARANDIS_ADAPTER {
    OffloadSettings Offload;
    ExtraStatistics extraStatistics;
} PARANDIS_ADAPTER;

typedef struct {
    ULONG value;
    struct {
        BOOLEAN IpOK;
        BOOLEAN IpFailed;
        BOOLEAN TcpOK;
        BOOLEAN TcpFailed;
        BOOLEAN UdpOK;
        BOOLEAN UdpFailed;
    } flags;
} tChecksumCheckResult;

typedef struct {
    ULONG ipCheckSum;
    ULONG xxpStatus;
    ULONG ipStatus;
    BOOLEAN IsFragment;
    ULONG TcpUdp;
    ULONG xxpCheckSum;
    BOOLEAN fixedXxpCS;
} tTcpIpPacketParsingResult;

typedef struct {
    void *pAddr;
    size_t size;
} tCompletePhysicalAddress;

enum {
    pcrIpChecksum,
    pcrFixXxpChecksum,
    pcrTcpChecksum,
    pcrUdpChecksum,
    pcrTcpV4Checksum,
    pcrUdpV4Checksum,
    pcrTcpV6Checksum,
    pcrUdpV6Checksum
};

enum {
    ppresIPTooShort,
    ppresXxpIncomplete,
    ppresIPV4,
    ppresIPV6,
    ppresXxpKnown,
    ppresIsTCP,
    ppresCSOK,
    ppresCSBad
};

tTcpIpPacketParsingResult ParaNdis_CheckSumVerify(
    tCompletePhysicalAddress *pPacketPages,
    ULONG ulPacketLength,
    ULONG ulDataOffset,
    ULONG flagsToCalculate,
    BOOLEAN verifyLength,
    const char *functionName
);

tTcpIpPacketParsingResult ParaNdis_CheckSumVerify(
    tCompletePhysicalAddress *pPacketPages,
    ULONG ulPacketLength,
    ULONG ulDataOffset,
    ULONG flagsToCalculate,
    const char *functionName
);