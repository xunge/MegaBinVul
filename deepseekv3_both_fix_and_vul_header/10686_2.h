#include <stddef.h>

typedef void* PVOID;
typedef unsigned long ULONG;
typedef unsigned char BOOLEAN;
typedef const char* LPCSTR;

typedef struct _tCompletePhysicalAddress {
    PVOID Virtual;
    ULONG size;
} tCompletePhysicalAddress;

typedef enum _tTcpIpPacketParsingResult {
    // Add appropriate enum values here
} tTcpIpPacketParsingResult;

tTcpIpPacketParsingResult ParaNdis_CheckSumVerify(
    tCompletePhysicalAddress* SGBuffer,
    ULONG ulDataLength,
    int zero,
    ULONG flags,
    BOOLEAN verifyLength,
    LPCSTR caller
);

tTcpIpPacketParsingResult ParaNdis_CheckSumVerify(
    tCompletePhysicalAddress* SGBuffer,
    ULONG ulDataLength,
    int zero,
    ULONG flags,
    LPCSTR caller
);