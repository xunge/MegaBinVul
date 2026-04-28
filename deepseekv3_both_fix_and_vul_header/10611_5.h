#include <cstddef>
#include <climits>
#include <algorithm>
#include <stdexcept>

typedef unsigned char byte;
typedef unsigned short word16;

enum BlockType { STORED, FIXED, DYNAMIC };
enum DecodeState { LITERAL, LENGTH_BITS, DISTANCE, DISTANCE_BITS };
enum InflatorState { POST_STREAM, WAIT_HEADER };

class HuffmanDecoder {
public:
    bool Decode(class BitReader&, unsigned int&) const;
};

class BitReader {
public:
    unsigned int BitsBuffered() const;
    void SkipBits(unsigned int);
    bool FillBuffer(unsigned int);
    unsigned int GetBits(unsigned int);
};

template<typename T, size_t N>
class SecBlockWithHint {
public:
    SecBlockWithHint(size_t size);
    T& operator[](size_t index);
    const T* data() const;
    size_t size() const;
    operator const T*() const { return data(); }
};

class Queue {
public:
    bool IsEmpty() const;
    const byte* Spy(size_t&) const;
    void Skip(size_t);
    void Unget(const byte*, size_t);
};

class Inflator {
public:
    bool DecodeBody();
private:
    BlockType m_blockType;
    DecodeState m_nextDecode;
    InflatorState m_state;
    bool m_eof;
    word16 m_storedLen;
    unsigned int m_literal;
    unsigned int m_distance;
    BitReader m_reader;
    Queue m_inQueue;

    const HuffmanDecoder& GetLiteralDecoder() const;
    const HuffmanDecoder& GetDistanceDecoder() const;
    void OutputString(const byte*, size_t);
    void OutputByte(byte);
    void OutputPast(unsigned int, unsigned int);
    void FlushOutput();
};

template<typename T, typename U>
auto UnsignedMin(const T& a, const U& b) -> decltype(a < b ? a : b) {
    return a < b ? a : b;
}

#define CRYPTOPP_ASSERT(cond) ((void)0)
#define COUNTOF(arr) (sizeof(arr)/sizeof(arr[0]))

class BadBlockErr : public std::runtime_error {
public: BadBlockErr() : std::runtime_error("") {}
};

class BadDistanceErr : public std::runtime_error {
public: BadDistanceErr() : std::runtime_error("") {}
};