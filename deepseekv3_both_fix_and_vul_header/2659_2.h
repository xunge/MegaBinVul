#include <cstdint>
#include <cstddef>

#define AP4_ATOM_TYPE_HDLR 0x68646C72
#define AP4_FULL_ATOM_HEADER_SIZE 12

typedef uint32_t AP4_UI32;
typedef uint8_t AP4_UI08;

class AP4_ByteStream {
public:
    void ReadUI32(AP4_UI32& value);
    void Read(void* buffer, AP4_UI32 size);
};

class AP4_Atom {
public:
    AP4_Atom(AP4_UI32 type, AP4_UI32 size, AP4_UI08 version, AP4_UI32 flags);
};

class AP4_HdlrAtom : public AP4_Atom {
public:
    AP4_HdlrAtom(AP4_UI32 size, AP4_UI08 version, AP4_UI32 flags, AP4_ByteStream& stream);
private:
    AP4_UI32 m_HandlerType;
    AP4_UI32 m_Reserved[3];
    const char* m_HandlerName;
};