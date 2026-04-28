#include <stdint.h>

typedef uint32_t AP4_UI32;
typedef uint8_t AP4_UI08;
typedef uint32_t AP4_Size;

enum AP4_Result {
    AP4_SUCCESS,
    AP4_FAILURE
};

#define AP4_FAILED(result) ((result) != AP4_SUCCESS)

class AP4_ByteStream {
public:
    AP4_Result ReadUI32(AP4_UI32& value);
    AP4_Result Read(void* buffer, AP4_Size bytesToRead);
};

class AP4_Atom {
public:
    AP4_Atom(AP4_UI32 type, AP4_UI32 size, AP4_UI08 version, AP4_UI32 flags);
};

enum {
    AP4_ATOM_TYPE_STSS,
    AP4_ATOM_HEADER_SIZE
};

template<typename T>
class AP4_Array {
public:
    void SetItemCount(AP4_UI32 count);
    T& operator[](AP4_UI32 index);
};

class AP4_StssAtom : public AP4_Atom {
private:
    int m_LookupCache;
    AP4_Array<AP4_UI32> m_Entries;
public:
    AP4_StssAtom(AP4_UI32 size, AP4_UI08 version, AP4_UI32 flags, AP4_ByteStream& stream);
};

AP4_UI32 AP4_BytesToUInt32BE(const unsigned char* data);