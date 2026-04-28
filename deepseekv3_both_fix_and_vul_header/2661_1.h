#include <stdint.h>

#define AP4_ATOM_HEADER_SIZE 8
#define AP4_ATOM_TYPE_AVCC 0x61766343

typedef uint32_t AP4_UI32;
typedef uint8_t AP4_UI08;
typedef uint16_t AP4_UI16;

class AP4_Atom {
public:
    AP4_Atom(AP4_UI32 type, AP4_UI32 size);
};

class AP4_DataBuffer {
public:
    void SetData(const void* data, AP4_UI32 size);
};

template <typename T>
class AP4_Array {
public:
    void EnsureCapacity(AP4_UI32 capacity);
    void Append(const T& item);
    T& operator[](AP4_UI32 index);
};

typedef AP4_Array<AP4_DataBuffer> AP4_DataBufferArray;

class AP4_AvccAtom : public AP4_Atom {
public:
    AP4_AvccAtom(AP4_UI32 size, const AP4_UI08* payload);
private:
    AP4_DataBuffer m_RawBytes;
    AP4_UI08 m_ConfigurationVersion;
    AP4_UI08 m_Profile;
    AP4_UI08 m_ProfileCompatibility;
    AP4_UI08 m_Level;
    AP4_UI08 m_NaluLengthSize;
    AP4_DataBufferArray m_SequenceParameters;
    AP4_DataBufferArray m_PictureParameters;
};

static AP4_UI16 AP4_BytesToInt16BE(const AP4_UI08* bytes);