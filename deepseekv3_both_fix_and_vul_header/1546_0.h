#include <stdint.h>

typedef uint64_t AP4_UI64;
typedef uint8_t AP4_UI08;
typedef unsigned int AP4_Size;

class AP4_ByteStream {
public:
    void Read(void* buffer, AP4_Size size);
};

class AP4_UuidAtom {
public:
    AP4_UuidAtom(AP4_UI64 size, const AP4_UI08* uuid);
    AP4_Size GetHeaderSize();
};

class AP4_DataBuffer {
public:
    void SetDataSize(AP4_Size size);
    AP4_Size GetDataSize();
    unsigned char* UseData();
private:
    unsigned char* m_Data;
    AP4_Size m_Size;
};

class AP4_UnknownUuidAtom : public AP4_UuidAtom {
public:
    AP4_UnknownUuidAtom(AP4_UI64 size, const AP4_UI08* uuid, AP4_ByteStream& stream);
private:
    AP4_DataBuffer m_Data;
};