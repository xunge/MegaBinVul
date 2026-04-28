#include <stddef.h>
#include <stdint.h>

typedef enum {
    ppresIsTCP,
    ppresIsUDP
} tTcpUdp;

typedef enum {
    ppresXxpIncomplete,
    ppresXxpKnown
} tXxpStatus;

typedef struct {
    tTcpUdp TcpUdp;
    tXxpStatus xxpStatus;
    int xxpFull;
    uint32_t XxpIpHeaderSize;
} tTcpIpPacketParsingResult;

typedef struct {
    uint16_t udp_length;
} UDPHeader;

typedef void* PVOID;
typedef uint32_t ULONG;
typedef uint16_t USHORT;

#define swap_short(x) (((x) >> 8) | ((x) << 8))
#define RtlOffsetToPointer(base, offset) ((PVOID)((uint8_t*)(base) + (offset)))
#define DPrintf(level, args)
#define TRUE 1
#define FALSE 0