#include <cstdint>
#include <cstddef>

typedef uint32_t AP4_UI32;
typedef uint8_t AP4_UI08;
typedef unsigned int AP4_Ordinal;
typedef std::size_t AP4_Size;

enum AP4_Result {
    AP4_SUCCESS,
    AP4_FAILURE
};

#define AP4_FAILED(result) ((result) != AP4_SUCCESS)

class AP4_ByteStream {
public:
    AP4_Result Read(void* buffer, AP4_Size bytesToRead);
    void ReadUI32(AP4_UI32& value);
};

class AP4_Atom {
public:
    AP4_Atom(AP4_UI32 type, AP4_UI32 size, AP4_UI08 version, AP4_UI32 flags);
    static const AP4_UI32 AP4_ATOM_TYPE_STCO;
    static const AP4_UI32 AP4_FULL_ATOM_HEADER_SIZE;
};

class AP4_StcoAtom : public AP4_Atom {
public:
    AP4_StcoAtom(AP4_UI32 size, AP4_UI08 version, AP4_UI32 flags, AP4_ByteStream& stream);
private:
    AP4_UI32 m_EntryCount;
    AP4_UI32* m_Entries;
};

AP4_UI32 AP4_BytesToUInt32BE(const unsigned char* bytes);