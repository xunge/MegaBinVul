#include <cstdint>
#include <cstring>

using UInt8 = uint8_t;
using UInt16 = uint16_t;
using UInt32 = uint32_t;
using UInt64 = uint64_t;

namespace ErrorCodes
{
    constexpr int CANNOT_DECOMPRESS = 1;
}

class Exception
{
public:
    Exception(int code, const char* message);
};

class CompressionCodecGorilla
{
public:
    void doDecompressData(const char* source, UInt32 source_size, char* dest, UInt32 uncompressed_size) const;
};

template <typename T>
void decompressDataForType(const char* source, UInt32 source_size, char* dest, UInt32 uncompressed_size);
template <typename T>
void decompressDataForType(const char* source, UInt32 source_size, char* dest);