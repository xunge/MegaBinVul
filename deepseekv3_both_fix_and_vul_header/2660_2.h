#include <stdint.h>

typedef uint32_t AP4_UI32;
typedef uint16_t AP4_UI16;
typedef uint8_t AP4_UI08;
typedef uint64_t AP4_UI64;

#define AP4_ATOM_HEADER_SIZE 8
#define AP4_ATOM_TYPE_HVCC 0x68766363

class AP4_Atom {
public:
    AP4_Atom(AP4_UI32 type, AP4_UI32 size);
};

class AP4_DataBuffer {
public:
    void SetData(const AP4_UI08* data, unsigned int size);
};

template <typename T>
class AP4_Array {
public:
    void SetItemCount(unsigned int count);
    T& operator[](unsigned int index);
};

struct Sequence {
    unsigned int m_ArrayCompleteness;
    unsigned int m_Reserved;
    unsigned int m_NaluType;
    AP4_Array<AP4_DataBuffer> m_Nalus;
};

class AP4_HvccAtom : public AP4_Atom {
public:
    AP4_DataBuffer m_RawBytes;
    AP4_UI08 m_ConfigurationVersion;
    unsigned int m_GeneralProfileSpace;
    unsigned int m_GeneralTierFlag;
    unsigned int m_GeneralProfile;
    AP4_UI32 m_GeneralProfileCompatibilityFlags;
    AP4_UI64 m_GeneralConstraintIndicatorFlags;
    AP4_UI08 m_GeneralLevel;
    unsigned int m_Reserved1;
    AP4_UI16 m_MinSpatialSegmentation;
    unsigned int m_Reserved2;
    AP4_UI08 m_ParallelismType;
    unsigned int m_Reserved3;
    AP4_UI08 m_ChromaFormat;
    unsigned int m_Reserved4;
    unsigned int m_LumaBitDepth;
    unsigned int m_Reserved5;
    unsigned int m_ChromaBitDepth;
    AP4_UI16 m_AverageFrameRate;
    unsigned int m_ConstantFrameRate;
    unsigned int m_NumTemporalLayers;
    unsigned int m_TemporalIdNested;
    unsigned int m_NaluLengthSize;
    AP4_Array<Sequence> m_Sequences;

    AP4_HvccAtom(AP4_UI32 size, const AP4_UI08* payload);
};

static inline AP4_UI32 AP4_BytesToUInt32BE(const AP4_UI08* bytes) {
    return (bytes[0]<<24) | (bytes[1]<<16) | (bytes[2]<<8) | bytes[3];
}

static inline AP4_UI16 AP4_BytesToUInt16BE(const AP4_UI08* bytes) {
    return (bytes[0]<<8) | bytes[1];
}