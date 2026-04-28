#include <stddef.h>
#include <stdint.h>

#define TRUE 1
#define FALSE 0

typedef enum {
    ppresXxpIncomplete,
    ppresXxpKnown
} tXxpStatus;

typedef enum {
    ppresIsTCP,
    ppresIsUDP
} tTcpUdp;

typedef struct {
    tXxpStatus xxpStatus;
    int xxpFull;
    tTcpUdp TcpUdp;
    uint32_t XxpIpHeaderSize;
} tTcpIpPacketParsingResult;

typedef struct {
    uint16_t th_offx2;
} TCPHeader;

#define TCP_HEADER_LENGTH(pTcpHeader) (((pTcpHeader)->th_offx2 & 0xf0) >> 2)

#define DPrintf(level, fmt)

#define PVOID void*
#define ULONG uint32_t
#define USHORT uint16_t
#define RtlOffsetToPointer(base, offset) ((void*)((char*)(base) + (offset)))