#include <stddef.h>
#include <stdint.h>

typedef unsigned long ULONG;
typedef const char* LPCSTR;
typedef void* PVOID;

typedef struct _tCompletePhysicalAddress {
    PVOID Virtual;
} tCompletePhysicalAddress;

typedef struct _IPHeader {
    union {
        struct {
            // IPv4 header fields
        } v4;
        struct {
            // IPv6 header fields
        } v6;
    };
} IPHeader;

typedef enum {
    ppresNotIP,
    ppresIPV4,
    ppresIPV6,
    ppresIPTooShort
} tIpPacketStatus;

typedef enum {
    ppresXxpUnknown,
    ppresXxpKnown
} tXxpStatus;

typedef enum {
    ppresIsTCP,
    ppresIsUDP
} tTcpUdpStatus;

typedef enum {
    ppresCSOK,
    ppresCSBad,
    ppresCSNone
} tChecksumCheckResult;

typedef struct _tTcpIpPacketParsingResult {
    tIpPacketStatus ipStatus;
    tChecksumCheckResult ipCheckSum;
    tXxpStatus xxpStatus;
    tTcpUdpStatus TcpUdp;
    tChecksumCheckResult xxpCheckSum;
    tChecksumCheckResult tcpudpCheckSum;
    tChecksumCheckResult phCheckSum;
} tTcpIpPacketParsingResult;

#define pcrIpChecksum       0x0001
#define pcrTcpV4Checksum    0x0002
#define pcrUdpV4Checksum    0x0004
#define pcrTcpV6Checksum    0x0008
#define pcrUdpV6Checksum    0x0010
#define pcrFixIPChecksum    0x0020
#define pcrFixPHChecksum    0x0040
#define pcrFixTcpV4Checksum 0x0080
#define pcrFixUdpV4Checksum 0x0100
#define pcrFixTcpV6Checksum 0x0200
#define pcrFixUdpV6Checksum 0x0400

#define RtlOffsetToPointer(base, offset) ((void*)((uintptr_t)(base) + (offset)))

tTcpIpPacketParsingResult QualifyIpPacket(IPHeader *pIpHeader, ULONG ulDataLength);
tTcpIpPacketParsingResult VerifyIpChecksum(void *pHeader, tTcpIpPacketParsingResult res, int fix);
tTcpIpPacketParsingResult VerifyTcpChecksum(tCompletePhysicalAddress *pDataPages, ULONG ulDataLength, ULONG ulStartOffset, tTcpIpPacketParsingResult res, ULONG flags);
tTcpIpPacketParsingResult VerifyUdpChecksum(tCompletePhysicalAddress *pDataPages, ULONG ulDataLength, ULONG ulStartOffset, tTcpIpPacketParsingResult res, ULONG flags);
void PrintOutParsingResult(tTcpIpPacketParsingResult res, int level, LPCSTR caller);