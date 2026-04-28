#include <stdint.h>
#include <stddef.h>

typedef uint32_t ULONG;
typedef uint8_t BOOLEAN;
typedef const char* LPCSTR;

typedef enum {
    ppresNotIP,
    ppresIPV4,
    ppresIPV6,
    ppresIPTooShort,
    ppresXxpKnown,
    ppresIsTCP,
    ppresIsUDP
} tPacketParsingResult;

typedef struct {
    void *Virtual;
    void *Physical;
} tCompletePhysicalAddress;

typedef struct {
    tPacketParsingResult ipStatus;
    tPacketParsingResult ipCheckSum;
    tPacketParsingResult xxpStatus;
    tPacketParsingResult TcpUdp;
} tTcpIpPacketParsingResult;

typedef struct {
    uint8_t v4[20];
} IPHeader;

#define pcrIpChecksum 0x01
#define pcrFixIPChecksum 0x02
#define pcrTcpV4Checksum 0x04
#define pcrFixTcpV4Checksum 0x08
#define pcrUdpV4Checksum 0x10
#define pcrFixUdpV4Checksum 0x20
#define pcrTcpV6Checksum 0x40
#define pcrFixTcpV6Checksum 0x80
#define pcrUdpV6Checksum 0x100
#define pcrFixUdpV6Checksum 0x200
#define pcrFixPHChecksum 0x400

tTcpIpPacketParsingResult QualifyIpPacket(IPHeader *pIpHeader, ULONG ulDataLength, ...);
tTcpIpPacketParsingResult VerifyIpChecksum(void *pIpHeader, tTcpIpPacketParsingResult res, BOOLEAN fix);
tTcpIpPacketParsingResult VerifyTcpChecksum(tCompletePhysicalAddress *pDataPages, ULONG ulDataLength, ULONG ulStartOffset, tTcpIpPacketParsingResult res, ULONG flags);
tTcpIpPacketParsingResult VerifyUdpChecksum(tCompletePhysicalAddress *pDataPages, ULONG ulDataLength, ULONG ulStartOffset, tTcpIpPacketParsingResult res, ULONG flags);
void PrintOutParsingResult(tTcpIpPacketParsingResult res, int level, LPCSTR caller);
void *RtlOffsetToPointer(void *base, ULONG offset);