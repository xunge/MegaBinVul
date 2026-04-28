#include <stdint.h>
#include <stdbool.h>

#define MaxWinMask 0xFFFF
#define MAX_INC_LZ_MATCH 260
#define MAX_LZ_MATCH 260

typedef uint32_t uint;
typedef uint8_t byte;

struct InpStruct {
    uint32_t InAddr;
    uint32_t InBit;
    uint32_t getbits32();
    void addbits(uint32_t);
};

struct BlockHeader {
    uint32_t HeaderSize;
    uint32_t BlockSize;
    uint32_t BlockStart;
    uint32_t BlockBitSize;
};

struct BlockTables {
    void *LD;
    void *DD;
    void *LDD;
    void *RD;
};

struct UnpackThreadData {
    bool TableRead;
    bool DamagedData;
    bool NoDataLeft;
    bool Incomplete;
    struct InpStruct Inp;
    struct BlockHeader BlockHeader;
    struct BlockTables BlockTables;
    uint32_t DataSize;
};

struct UnpackFilter {
};

struct Unpack {
    bool UnpackLargeBlock(UnpackThreadData &D);
};

extern uint32_t UnpPtr;
extern uint32_t WriteBorder;
extern uint32_t WrittenFileSize;
extern uint32_t DestUnpSize;
extern uint8_t Window[];
extern uint32_t OldDist[];
extern uint32_t LastLength;

bool ReadTables(struct InpStruct, struct BlockHeader, struct BlockTables);
bool ReadFilter(struct InpStruct, struct UnpackFilter&);
bool AddFilter(struct UnpackFilter&);
uint32_t DecodeNumber(struct InpStruct, void*);
uint32_t SlotToLength(struct InpStruct, uint32_t);
void InsertOldDist(uint32_t);
void CopyString(uint32_t, uint32_t);
void UnpWriteBuf();
uint32_t Min(uint32_t, uint32_t);