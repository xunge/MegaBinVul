#include <stdint.h>

typedef int AP4_Result;
typedef uint8_t AP4_UI08;
typedef uint16_t AP4_UI16;
typedef uint32_t AP4_UI32;

class AP4_ByteStream {
public:
    AP4_Result ReadUI16(AP4_UI16& value);
    AP4_Result ReadUI32(AP4_UI32& value);
    AP4_Result Read(void* buffer, unsigned int size);
};

class AP4_SampleEntry {
public:
    AP4_Result ReadFields(AP4_ByteStream& stream);
};

class AP4_VisualSampleEntry : public AP4_SampleEntry {
public:
    AP4_Result ReadFields(AP4_ByteStream& stream);
private:
    AP4_UI16 m_Predefined1;
    AP4_UI16 m_Reserved2;
    AP4_UI08 m_Predefined2[32];
    AP4_UI16 m_Width;
    AP4_UI16 m_Height;
    AP4_UI32 m_HorizResolution;
    AP4_UI32 m_VertResolution;
    AP4_UI32 m_Reserved3;
    AP4_UI16 m_FrameCount;
    const char* m_CompressorName;
    AP4_UI16 m_Depth;
    AP4_UI16 m_Predefined3;
};

const AP4_Result AP4_SUCCESS = 0;