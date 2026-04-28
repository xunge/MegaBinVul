#include <iostream>
#include <cstdint>
#include <stdexcept>

typedef unsigned char byte;

enum ByteOrder { littleEndian, bigEndian };

class CiffComponent {
public:
    static void doRead(const byte* pData, uint32_t size, uint32_t start, ByteOrder byteOrder);
    uint32_t offset() const;
    uint32_t size() const;
    uint32_t tag() const;
};

class CiffDirectory : public CiffComponent {
public:
    void doRead(const byte* pData, uint32_t size, uint32_t start, ByteOrder byteOrder);
    void readDirectory(const byte* pData, uint32_t size, ByteOrder byteOrder);
};

class Error : public std::runtime_error {
public:
    explicit Error(int code) : std::runtime_error("") {}
};

const int kerOffsetOutOfRange = 0;