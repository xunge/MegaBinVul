#include <stdint.h>
#include <stdbool.h>

#define VIRTIO_NET_HDR_F_NEEDS_CSUM 1
#define VIRTIO_NET_HDR_F_DATA_VALID 2
#define ETH_HEADER_SIZE 14
#define FALSE false
#define TRUE true

typedef uint32_t ULONG;

typedef struct {
    unsigned int fRxIPChecksum : 1;
    unsigned int fRxTCPChecksum : 1;
    unsigned int fRxUDPChecksum : 1;
    unsigned int fRxTCPv6Checksum : 1;
    unsigned int fRxUDPv6Checksum : 1;
} tOffloadSettingsFlags;

typedef struct {
    void *pPhysical;
    void *pVirtual;
} tCompletePhysicalAddress;

typedef struct {
    ULONG ipCheckSum;
    ULONG xxpStatus;
    ULONG xxpCheckSum;
    ULONG ipStatus;
    ULONG IsFragment;
    ULONG TcpUdp;
    ULONG fixedXxpCS;
} tTcpIpPacketParsingResult;

typedef struct {
    unsigned int value;
    struct {
        bool IpOK;
        bool IpFailed;
        bool TcpOK;
        bool TcpFailed;
        bool UdpOK;
        bool UdpFailed;
    } flags;
} tChecksumCheckResult;

typedef struct _PARANDIS_ADAPTER {
    struct {
        tOffloadSettingsFlags flags;
    } Offload;
    struct {
        ULONG framesRxCSHwOK;
    } extraStatistics;
} PARANDIS_ADAPTER;

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
    ppresCSOK,
    ppresCSBad,
    ppresIPV4,
    ppresIPV6,
    ppresXxpKnown,
    ppresIsTCP,
    ppresIsUDP
};

tTcpIpPacketParsingResult ParaNdis_CheckSumVerify(tCompletePhysicalAddress *pPacketPages, ULONG ulPacketLength, ULONG ulDataOffset, ULONG flagsToCalculate, const char *func);