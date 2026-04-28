#include <cstdint>

typedef uint64_t AP4_UI64;
typedef unsigned int AP4_Size;

class AP4_Atom {
public:
    enum Type {};
    AP4_Atom(Type type, AP4_UI64 size);
};

class AP4_ByteStream {
public:
    void Read(char* str, AP4_Size size);
};

#define AP4_ATOM_HEADER_SIZE 8

class AP4_NullTerminatedStringAtom : public AP4_Atom {
public:
    AP4_NullTerminatedStringAtom(AP4_Atom::Type type, AP4_UI64 size, AP4_ByteStream& stream);
private:
    char* m_Value;
};