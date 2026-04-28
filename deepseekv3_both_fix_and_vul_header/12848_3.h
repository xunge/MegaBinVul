#include <stdint.h>
#include <stdbool.h>

#define MaxWinMask 0xFFFF
#define MAX_INC_LZ_MATCH 260
#define MAX_LZ_MATCH 260
#define MaxWinSize 0x10000
#define LITTLE_ENDIAN
#define ALLOW_MISALIGNED

typedef uint32_t uint;
typedef uint8_t byte;
typedef uint32_t uint32;

enum {
    UNPDT_LITERAL,
    UNPDT_MATCH,
    UNPDT_REP,
    UNPDT_FULLREP,
    UNPDT_FILTER
};

struct UnpackDecodedItem {
    uint Type;
    uint Length;
    uint Distance;
    byte *Literal;
};

struct UnpackThreadData {
    UnpackDecodedItem *Decoded;
    uint DecodedSize;
};

struct UnpackFilter {
    byte Type;
    uint BlockStart;
    byte Channels;
    uint BlockLength;
};

class Unpack {
public:
    static uint UnpPtr;
    static uint WriteBorder;
    static uint WrittenFileSize;
    static uint DestUnpSize;
    static byte Window[MaxWinSize];
    static uint OldDist[4];
    static uint LastLength;

    static void UnpWriteBuf();
    static void InsertOldDist(uint Distance);
    static void CopyString(uint Length, uint Distance);
    static void AddFilter(UnpackFilter Filter);
    static bool ProcessDecoded(UnpackThreadData &D);
};