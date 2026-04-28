#include <stdint.h>
#include <cstddef>

#define AP4_ATOM_HEADER_SIZE 8
#define AP4_FAILED(result) ((result) != 0)

typedef uint8_t AP4_UI08;
typedef unsigned int AP4_Size;
typedef int AP4_Result;

class AP4_ByteStream {
public:
    virtual AP4_Result Read(void* buffer, AP4_Size bytes_to_read) = 0;
};

class AP4_DataBuffer {
public:
    AP4_DataBuffer(AP4_Size size);
    AP4_UI08* UseData();
    const AP4_UI08* GetData() const;
};

class AP4_AvccAtom {
public:
    AP4_AvccAtom(AP4_Size size, const AP4_UI08* payload);
    static AP4_AvccAtom* Create(AP4_Size size, AP4_ByteStream& stream);
};

static inline unsigned short AP4_BytesToInt16BE(const unsigned char* bytes) {
    return (bytes[0]<<8) | bytes[1];
}