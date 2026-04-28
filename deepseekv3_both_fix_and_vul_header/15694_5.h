#include <stdint.h>

typedef uint32_t AP4_UI32;
typedef uint8_t AP4_UI08;
typedef uint64_t AP4_LargeSize;

enum AP4_Result {
    AP4_SUCCESS,
    AP4_FAILURE
};

#define AP4_SUCCEEDED(x) ((x) == AP4_SUCCESS)
#define AP4_FAILED(x) ((x) == AP4_FAILURE)

class AP4_Atom;

class AP4_ByteStream {
public:
    AP4_Result ReadUI32(AP4_UI32& value);
};

class AP4_AtomFactory {
public:
    AP4_Result CreateAtomFromStream(AP4_ByteStream& stream, AP4_LargeSize bytes_available, AP4_Atom*& atom);
};

class AP4_ContainerAtom {
public:
    AP4_ContainerAtom(uint32_t type, AP4_UI32 size, bool is_full, AP4_UI08 version, AP4_UI32 flags);
    void Add(AP4_Atom* atom);
    AP4_ContainerAtom() = default;
};

class AP4_DrefAtom : public AP4_ContainerAtom {
public:
    AP4_DrefAtom(AP4_UI32 size, AP4_UI08 version, AP4_UI32 flags, AP4_ByteStream& stream, AP4_AtomFactory& atom_factory);
    AP4_ContainerAtom m_Children;
};

enum {
    AP4_ATOM_TYPE_DREF,
    AP4_FULL_ATOM_HEADER_SIZE
};