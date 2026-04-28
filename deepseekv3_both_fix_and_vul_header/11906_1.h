#include <stdint.h>

typedef uint32_t AP4_UI32;
typedef uint8_t AP4_UI08;
typedef uint16_t AP4_UI16;
typedef uint64_t AP4_UI64;
typedef int32_t AP4_SI32;
typedef int64_t AP4_SI64;

class AP4_ByteStream {
public:
    void ReadUI32(AP4_UI32&);
    void ReadUI16(AP4_UI16&);
    void ReadUI64(AP4_UI64&);
};

class AP4_Atom {
public:
    AP4_Atom(AP4_UI32, AP4_UI32, AP4_UI08, AP4_UI32);
};

class AP4_ElstEntry {
public:
    AP4_ElstEntry(AP4_UI32, AP4_SI32, AP4_UI16);
    AP4_ElstEntry(AP4_UI64, AP4_SI64, AP4_UI16);
};

template <typename T>
class AP4_Array {
public:
    void EnsureCapacity(AP4_UI32);
    void Append(const T&);
};

class AP4_ElstAtom : public AP4_Atom {
public:
    AP4_ElstAtom(AP4_UI32 size, AP4_UI08 version, AP4_UI32 flags, AP4_ByteStream& stream);
private:
    AP4_Array<AP4_ElstEntry> m_Entries;
};

const AP4_UI32 AP4_ATOM_TYPE_ELST = 0;
const AP4_UI32 AP4_FULL_ATOM_HEADER_SIZE = 0;