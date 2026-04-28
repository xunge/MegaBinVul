#include <stddef.h>
#include <stdint.h>

typedef uint16_t USHORT;
typedef uint32_t ULONG;
typedef void* PVOID;

#define FALSE 0
#define ppresNotIP 0
#define __FUNCTION__ __func__

struct tIPPackeReview {
    int ipStatus;
    USHORT ipHeaderSize;
};

struct CNB {
    ULONG GetDataLength() const;
    USHORT QueryL4HeaderOffset(PVOID PacketData, ULONG IpHeaderOffset) const;
};

void* RtlOffsetToPointer(void* base, ULONG offset);
tIPPackeReview ParaNdis_ReviewIPPacket(PVOID, ULONG, const char*);
tIPPackeReview ParaNdis_ReviewIPPacket(PVOID, ULONG, int, const char*);
void DPrintf(int, const char*, ...);