#include <stdint.h>

typedef uint32_t AP4_UI32;
typedef uint8_t AP4_UI08;
typedef unsigned int AP4_Cardinal;
typedef int AP4_Result;

class AP4_Atom {
public:
    AP4_Atom(AP4_UI32 type, AP4_UI32 size, AP4_UI08 version, AP4_UI32 flags);
};

class AP4_ByteStream {
public:
    void ReadUI32(AP4_UI32& value);
    AP4_Result Read(unsigned char* buffer, AP4_UI32 size);
};

#define AP4_SUCCESS 0
#define AP4_FAILURE 1
#define AP4_FAILED(result) ((result) != AP4_SUCCESS)

class AP4_StszAtom : public AP4_Atom {
public:
    AP4_StszAtom(AP4_UI32 size, AP4_UI08 version, AP4_UI32 flags, AP4_ByteStream& stream);
private:
    AP4_UI32 m_SampleSize;
    AP4_UI32 m_SampleCount;
    class {
    public:
        void SetItemCount(AP4_Cardinal count);
        void Clear();
        AP4_UI32& operator[](unsigned int index);
    } m_Entries;
};

#define AP4_ATOM_TYPE_STSZ 0x7374737A

AP4_UI32 AP4_BytesToUInt32BE(const unsigned char* data);