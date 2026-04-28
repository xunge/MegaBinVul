#include <stdint.h>

typedef uint32_t AP4_UI32;
typedef uint8_t AP4_UI08;
typedef uint16_t AP4_UI16;
typedef int AP4_Result;
typedef unsigned int AP4_Cardinal;

class AP4_ByteStream {
public:
    AP4_Result Read(void* buffer, AP4_UI32 size);
    AP4_Result ReadUI08(AP4_UI08& value);
    AP4_Result ReadUI32(AP4_UI32& value);
};

class AP4_Atom {
public:
    AP4_Atom(AP4_UI32 type, AP4_UI32 size, AP4_UI08 version, AP4_UI32 flags);
};

class AP4_Stz2Atom : public AP4_Atom {
public:
    AP4_Stz2Atom(AP4_UI32 size, AP4_UI08 version, AP4_UI32 flags, AP4_ByteStream& stream);
private:
    AP4_UI08 m_FieldSize;
    AP4_UI32 m_SampleCount;
    class Entries {
    public:
        void SetItemCount(AP4_Cardinal count);
        AP4_UI32& operator[](AP4_Cardinal index);
    } m_Entries;
};

#define AP4_ATOM_TYPE_STZ2 0x73747A32
#define AP4_FULL_ATOM_HEADER_SIZE 12
#define AP4_FAILED(result) ((result) < 0)

static inline AP4_UI16 AP4_BytesToUInt16BE(const unsigned char* data) {
    return (AP4_UI16)((data[0] << 8) | data[1]);
}