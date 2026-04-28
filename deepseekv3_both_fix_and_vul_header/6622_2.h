#include <stdint.h>

typedef uint32_t AP4_UI32;

enum AP4_AtomType {
    AP4_ATOM_TYPE_FTYP
};

enum AP4_Result {
    AP4_SUCCESS,
    AP4_FAILURE
};

#define AP4_FAILED(result) ((result) != AP4_SUCCESS)

class AP4_Atom {
public:
    AP4_Atom(AP4_AtomType type, AP4_UI32 size) {}
};

class AP4_ByteStream {
public:
    AP4_Result ReadUI32(AP4_UI32& value) { return AP4_SUCCESS; }
};

template<typename T>
class AP4_Array {
public:
    void Append(T item) {}
};

class AP4_FtypAtom : public AP4_Atom {
public:
    AP4_FtypAtom(AP4_UI32 size, AP4_ByteStream& stream);
private:
    AP4_UI32 m_MajorBrand;
    AP4_UI32 m_MinorVersion;
    AP4_Array<AP4_UI32> m_CompatibleBrands;
};