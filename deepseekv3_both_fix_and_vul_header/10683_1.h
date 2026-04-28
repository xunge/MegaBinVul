#include <stdint.h>

typedef void *PVOID;
typedef uint32_t ULONG;
typedef uint8_t BOOLEAN;
typedef const char *LPCSTR;

typedef struct _IPHeader {
    // IP header fields would be defined here
} IPHeader;

typedef struct _tTcpIpPacketParsingResult {
    // result fields would be defined here
} tTcpIpPacketParsingResult;

tTcpIpPacketParsingResult QualifyIpPacket(IPHeader *buffer, ULONG size, BOOLEAN verifyLength);
tTcpIpPacketParsingResult QualifyIpPacket(IPHeader *buffer, ULONG size);
void PrintOutParsingResult(tTcpIpPacketParsingResult res, int level, LPCSTR caller);