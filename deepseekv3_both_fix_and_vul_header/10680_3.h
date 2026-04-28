#include <stddef.h>
#include <stdbool.h>

#define pcrIpChecksum 0x01
#define pcrFixIPChecksum 0x02
#define FALSE false

typedef void* PVOID;
typedef unsigned long ULONG;
typedef bool BOOLEAN;

class CNB {
public:
    void DoIPHdrCSO(PVOID IpHeader, ULONG EthPayloadLength) const;
};

void ParaNdis_CheckSumVerifyFlat(PVOID, ULONG, ULONG, BOOLEAN, const char*);
void ParaNdis_CheckSumVerifyFlat(PVOID, ULONG, ULONG, const char*);