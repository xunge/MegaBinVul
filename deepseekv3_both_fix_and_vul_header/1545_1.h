#include <stdint.h>
#include <cstddef>

typedef uint64_t AP4_UI64;
typedef uint32_t AP4_Size;

class AP4_ByteStream {
public:
    std::size_t Read(void* buffer, std::size_t bytes);
};

class AP4_DataBuffer {
public:
    void SetDataSize(AP4_Size size);
    unsigned char* UseData();
    AP4_Size GetDataSize();
private:
    unsigned char* m_Data;
    AP4_Size m_Size;
};

class AP4_UuidAtom {
public:
    AP4_UuidAtom(AP4_UI64 size, bool isFull, AP4_ByteStream& stream);
    AP4_Size GetHeaderSize();
};

class AP4_UnknownUuidAtom : public AP4_UuidAtom {
public:
    AP4_UnknownUuidAtom(AP4_UI64 size, AP4_ByteStream& stream);
private:
    AP4_DataBuffer m_Data;
};