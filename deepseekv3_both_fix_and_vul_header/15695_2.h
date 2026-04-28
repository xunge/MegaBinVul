#include <stdint.h>

enum AP4_Result {
    AP4_SUCCESS,
    AP4_FAILURE
};

#define AP4_FAILED(result) ((result) != AP4_SUCCESS)

class AP4_ByteStream {
public:
    AP4_Result WriteUI32(uint32_t value);
};

class AP4_AtomListWriter {
public:
    AP4_AtomListWriter(AP4_ByteStream& stream);
};

class AP4_AtomList {
public:
    uint32_t ItemCount() const;
    AP4_Result Apply(const AP4_AtomListWriter& writer);
};

class AP4_DrefAtom {
public:
    AP4_Result WriteFields(AP4_ByteStream& stream);
private:
    AP4_AtomList m_Children;
};