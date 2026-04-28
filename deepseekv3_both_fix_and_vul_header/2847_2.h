#include <cstdint>
#include <cstddef>

typedef int AP4_Result;
typedef uint32_t AP4_UI32;
typedef uint64_t AP4_UI64;
typedef int64_t AP4_LargeSize;
typedef uint64_t AP4_Position;

class AP4_ByteStream {
public:
    AP4_Result Tell(AP4_Position& position);
    AP4_Result ReadUI32(AP4_UI32& value);
    AP4_Result ReadUI64(AP4_UI64& value);
    AP4_Result Seek(AP4_Position position);
    AP4_Result GetSize(AP4_LargeSize& size);
};

class AP4_Atom {
public:
    typedef AP4_UI32 Type;
    void SetSize32(AP4_UI32 size);
    void SetSize64(AP4_UI64 size);
};

class AP4_UnknownAtom : public AP4_Atom {
public:
    AP4_UnknownAtom(AP4_Atom::Type type, AP4_UI64 size, AP4_ByteStream& stream);
};

class AP4_AtomFactory {
public:
    AP4_Result CreateAtomFromStream(AP4_ByteStream& stream, AP4_LargeSize& bytes_available, AP4_Atom*& atom);
    AP4_Result CreateAtomFromStream(AP4_ByteStream& stream, AP4_Atom::Type type, AP4_UI32 size_32, AP4_UI64 size, AP4_Atom*& atom);
};

#define AP4_SUCCESS 0
#define AP4_ERROR_EOS 1
#define AP4_ERROR_INVALID_FORMAT 2
#define AP4_FAILED(result) ((result) != AP4_SUCCESS)