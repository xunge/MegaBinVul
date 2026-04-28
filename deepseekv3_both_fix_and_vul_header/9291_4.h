#include <cstdint>
#include <cstring>
#include <vector>
#include <cassert>

using uint8 = uint8_t;
using uint32 = uint32_t;
using uint64 = uint64_t;
using int16 = int16_t;
using int32 = int32_t;

enum ScopeMode {
    SCOPE_ALL_DATA,
    SCOPE_PARTIAL_DATA
};

enum LacingType {
    LACING_NONE,
    LACING_XIPH,
    LACING_EBML,
    LACING_FIXED
};

typedef uint64_t filepos_t;
typedef unsigned char binary;

class KaxInternalBlock;

class SafeReadIOCallback {
public:
    class EndOfStreamX {
    public:
        EndOfStreamX(uint64_t) {}
    };
    SafeReadIOCallback(KaxInternalBlock&) {}
    uint8 GetUInt8() { return 0; }
    uint16_t GetUInt16BE() { return 0; }
    size_t GetPosition() { return 0; }
    void Skip(size_t) {}
};

class IOCallback {
public:
    virtual filepos_t getFilePointer() = 0;
    virtual uint32_t read(binary* buffer, size_t size) = 0;
};

class EbmlBinary {
public:
    virtual binary* GetBuffer() = 0;
    virtual filepos_t GetSize() = 0;
    virtual filepos_t ReadData(IOCallback&, ScopeMode) = 0;
    virtual void SetValueIsSet(bool) = 0;
    virtual void SetValueIsSet() {}
};

class DataBuffer {
public:
    DataBuffer(binary*, size_t) {}
    binary* Buffer() { return nullptr; }
    size_t Size() { return 0; }
};

class big_int16 {
public:
    void Eval(binary*) {}
    operator int16() { return 0; }
};

class KaxInternalBlock : public EbmlBinary {
public:
    filepos_t ReadData(IOCallback& input, ScopeMode ReadFully);
};

class EbmlId {
public:
    EbmlId(const KaxInternalBlock&) {}
    bool operator==(uint32_t) const { return false; }
};

#define EBML_ID(x) 0

extern std::vector<DataBuffer*> myBuffers;
extern std::vector<uint32_t> SizeList;
extern filepos_t FirstFrameLocation;
extern uint64_t TrackNumber;
extern int16_t LocalTimecode;
extern bool bLocalTimecodeUsed;
extern bool bIsKeyframe;
extern bool bIsDiscardable;
extern bool mInvisible;
extern LacingType mLacing;
extern int64_t Timecode;

int32_t ReadCodedSizeValue(binary*, uint32_t&, uint64_t&) { return 0; }
int32_t ReadCodedSizeSignedValue(binary*, uint32_t&, uint64_t&) { return 0; }