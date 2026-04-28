#include <stdint.h>

#define AP4_ATOM_TYPE_PSSH 0x70737368
#define AP4_FULL_ATOM_HEADER_SIZE 12
#define AP4_PSSH_MAX_DATA_SIZE 0x100000

typedef uint32_t AP4_UI32;
typedef uint8_t AP4_UI08;

class AP4_Atom {
public:
    AP4_Atom(AP4_UI32 type, AP4_UI32 size, AP4_UI08 version, AP4_UI32 flags);
    AP4_UI32 GetComputedSize();
    AP4_UI08 m_Version;
};

class AP4_ByteStream {
public:
    void Read(void* buffer, AP4_UI32 size);
    void ReadUI32(AP4_UI32& value);
};

class AP4_DataBuffer {
public:
    void SetDataSize(AP4_UI32 size);
    unsigned char* UseData();
};

class AP4_PsshAtom : public AP4_Atom {
public:
    AP4_PsshAtom(AP4_UI32 size, AP4_UI08 version, AP4_UI32 flags, AP4_ByteStream& stream);
private:
    AP4_UI32 m_KidCount;
    unsigned char m_SystemId[16];
    AP4_DataBuffer m_Kids;
    AP4_DataBuffer m_Data;
    AP4_DataBuffer m_Padding;
};