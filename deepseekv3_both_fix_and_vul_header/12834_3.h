#include <cstdint>
#include <cstring>
#include <algorithm>

typedef unsigned char byte;
typedef unsigned int uint;

class BitInput {
public:
    static const uint MAX_SIZE = 0x4000;
    byte InBuf[MAX_SIZE];
    void InitBitInput();
    uint fgetbits();
    void faddbits(uint n);
    bool Overflow(uint n);
    uint InAddr;
};

class RarVM {
public:
    static uint ReadData(BitInput &input);
    void Init();
    void Prepare(byte *code, uint codeSize, void *prg);
};

template<typename T>
class Array {
public:
    Array(uint size) {}
    void Add(uint count) {}
    T &operator[](uint index) { static T t; return t; }
    uint Size() { return 0; }
    void Push(const T& value) {}
};

class UnpackFilter30 {
public:
    uint ParentFilter;
    uint BlockStart;
    uint BlockLength;
    bool NextWindow;
    struct {
        uint InitR[7];
        int Type;
    } Prg;
};

class Unpack {
private:
    BitInput VMCodeInp;
    RarVM VM;
    Array<UnpackFilter30*> Filters30;
    Array<uint> OldFilterLengths;
    Array<UnpackFilter30*> PrgStack;
    uint LastFilter;
    uint UnpPtr;
    uint WrPtr;
    uint MaxWinMask;
    static const uint MAX3_UNPACK_FILTERS = 1024;
    void InitFilters30(bool reset);
public:
    bool AddVMCode(uint FirstByte, byte *Code, uint CodeSize);
    bool AddVMCode(uint FirstByte, byte *Code, int CodeSize);
};

template<typename T1, typename T2>
auto Min(T1 a, T2 b) -> decltype(a < b ? a : b) { 
    return a < b ? a : b; 
}