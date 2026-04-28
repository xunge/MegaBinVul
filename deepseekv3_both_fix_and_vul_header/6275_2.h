#include <cstdint>

#define AP4_ATOM_TYPE_CTTS 0x63747473
#define AP4_FULL_ATOM_HEADER_SIZE 12

typedef uint32_t AP4_UI32;
typedef uint8_t AP4_UI08;
typedef int32_t AP4_SI32;

enum AP4_Result {
    AP4_SUCCESS = 0,
    AP4_FAILURE = 1
};

#define AP4_FAILED(result) ((result) != AP4_SUCCESS)

class AP4_Atom {
public:
    AP4_Atom(AP4_UI32 type, AP4_UI32 size, AP4_UI08 version, AP4_UI32 flags);
};

class AP4_ByteStream {
public:
    AP4_Result Read(void* buffer, AP4_UI32 size);
    AP4_Result ReadUI32(AP4_UI32& value);
};

struct AP4_CttsEntry {
    AP4_UI32 m_SampleCount;
    AP4_UI32 m_SampleOffset;
};

template <typename T>
class AP4_Array {
public:
    void SetItemCount(AP4_UI32 count);
    T& operator[](AP4_UI32 index);
};

typedef AP4_Array<AP4_CttsEntry> AP4_CttsEntries;

struct AP4_LookupCache {
    AP4_UI32 sample;
    AP4_UI32 entry_index;
};

class AP4_CttsAtom : public AP4_Atom {
public:
    AP4_CttsAtom(AP4_UI32 size, AP4_UI08 version, AP4_UI32 flags, AP4_ByteStream& stream);
private:
    AP4_CttsEntries m_Entries;
    AP4_LookupCache m_LookupCache;
};

inline AP4_UI32 AP4_BytesToUInt32BE(const unsigned char* data) {
    return (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
}