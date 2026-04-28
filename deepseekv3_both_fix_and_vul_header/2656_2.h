#include <stdint.h>
#include <cstddef>

typedef uint32_t AP4_UI32;
typedef uint32_t AP4_Size;
typedef uint64_t AP4_Position;

class AP4_ByteStream {
public:
    void ReadUI32(AP4_UI32&);
    void Tell(AP4_Position&);
};

class AP4_Atom {
public:
    AP4_Atom(AP4_UI32 type, AP4_UI32 size);
};

class AP4_SubStream {
public:
    AP4_SubStream(AP4_ByteStream&, AP4_Position, AP4_Size);
};

class AP4_DataAtom : public AP4_Atom {
public:
    AP4_DataAtom(AP4_UI32 size, AP4_ByteStream& stream);
private:
    AP4_SubStream* m_Source;
    enum DataType {};
    enum DataLang {};
    DataType m_DataType;
    DataLang m_DataLang;
};

#define AP4_ATOM_TYPE_DATA 0
#define AP4_ATOM_HEADER_SIZE 8