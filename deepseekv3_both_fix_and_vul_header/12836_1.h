#include <stdint.h>
#include <stdbool.h>

typedef uint8_t byte;
typedef uint32_t uint;

#define MAX_INC_LZ_MATCH 260
#define MAX_LZ_MATCH 260
#define MaxWinMask 0xFFFF

struct BitInput {
    uint InAddr;
    uint InBit;
    uint getbits32();
    void addbits(uint bits);
};

struct BlockHeader {
    uint BlockStart;
    uint BlockSize;
    uint BlockBitSize;
    bool LastBlockInFile;
    bool TablePresent;
};

struct BlockTables {
    struct {
        uint LD;
    } LD;
    struct {
        uint DD;
    } DD;
    struct {
        uint LDD;
    } LDD;
    struct {
        uint RD;
    } RD;
};

struct UnpackFilter {
    // Filter structure members
};

class FragWindow {
public:
    void CopyString(uint length, uint distance, uint unpPtr, uint maxWinMask);
    byte& operator[](uint index);
};

class Unpack {
public:
    void Unpack5(bool Solid);
    void UnpInitData(bool Solid);
    bool UnpReadBuf();
    bool ReadBlockHeader(BitInput& Inp, BlockHeader& header);
    bool ReadTables(BitInput& Inp, BlockHeader& header, BlockTables& tables);
    uint DecodeNumber(BitInput& Inp, void* table);
    uint SlotToLength(BitInput& Inp, uint slot);
    bool ReadFilter(BitInput& Inp, UnpackFilter& filter);
    bool AddFilter(UnpackFilter& filter);
    void InsertOldDist(uint distance);
    void CopyString(uint length, uint distance);
    void UnpWriteBuf();
};

byte Window[0x10000];
FragWindow FragWindow;
BitInput Inp;
BlockHeader BlockHeader;
BlockTables BlockTables;
uint UnpPtr;
uint WriteBorder;
uint ReadBorder;
uint WrittenFileSize;
uint DestUnpSize;
bool FileExtracted;
bool Suspended;
bool TablesRead5;
bool Fragmented;
uint OldDist[4];
uint LastLength;