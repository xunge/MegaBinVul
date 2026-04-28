#include <stdint.h>
#include <cstddef>

#define AP4_ATOM_TYPE_STSD 0x73747364
#define AP4_FULL_ATOM_HEADER_SIZE 12
#define AP4_SUCCEEDED(x) ((x) == 0)

typedef uint32_t AP4_UI32;
typedef uint8_t AP4_UI08;
typedef uint64_t AP4_LargeSize;
typedef unsigned int AP4_Ordinal;

class AP4_ByteStream {
public:
    void ReadUI32(AP4_UI32& value);
};

class AP4_StsdAtom;

class AP4_Atom {
public:
    void SetParent(AP4_StsdAtom* parent);
};

class AP4_AtomFactory {
public:
    void PushContext(AP4_UI32 type);
    void PopContext();
    int CreateAtomFromStream(AP4_ByteStream& stream, AP4_LargeSize bytes_available, AP4_Atom*& atom);
};

class AP4_ContainerAtom {
public:
    AP4_ContainerAtom(AP4_UI32 type, AP4_UI32 size, bool is_full, AP4_UI08 version, AP4_UI32 flags);
    AP4_UI32 m_Type;
};

class AP4_Children {
public:
    void Add(AP4_Atom* atom);
    AP4_UI32 ItemCount() const;
};

class AP4_StsdAtom : public AP4_ContainerAtom {
public:
    AP4_StsdAtom(AP4_UI32 size, AP4_UI08 version, AP4_UI32 flags, AP4_ByteStream& stream, AP4_AtomFactory& atom_factory);
private:
    AP4_Children m_Children;
    class SampleDescriptions {
    public:
        void EnsureCapacity(AP4_UI32 capacity);
        void Append(void* item);
    };
    SampleDescriptions m_SampleDescriptions;
};