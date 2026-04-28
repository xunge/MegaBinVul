#include <stdbool.h>
#include <cstddef>
#include <cstring>

typedef int AP4_Result;
typedef unsigned int AP4_UI32;
typedef unsigned long long AP4_UI64;

class AP4_DataBuffer {
public:
    unsigned char* UseData();
    const unsigned char* GetData() const;
    unsigned int GetDataSize() const;
    void SetDataSize(unsigned int size);
    void AppendData(const void* data, unsigned int data_size);
};

class AP4_ByteStream {
};

class AP4_Sample {
public:
    bool IsSync() const;
    AP4_UI64 GetDts() const;
    AP4_UI64 GetCts() const;
    unsigned int GetDescriptionIndex() const;
};

class AP4_SampleDescription {
public:
    enum Type {
        TYPE_AVC,
        TYPE_HEVC
    };
    virtual Type GetType() const = 0;
};

class AP4_AvcSampleDescription : public AP4_SampleDescription {
public:
    unsigned int GetNaluLengthSize() const;
    class Array& GetSequenceParameters();
    class Array& GetPictureParameters();
};

class AP4_HevcSampleDescription : public AP4_SampleDescription {
public:
    unsigned int GetNaluLengthSize() const;
    class SequenceArray& GetSequences();
};

class Array {
public:
    unsigned int ItemCount() const;
    AP4_DataBuffer& operator[](unsigned int index);
    const AP4_DataBuffer& operator[](unsigned int index) const;
};

class SequenceArray {
public:
    unsigned int ItemCount() const;
    class Sequence& operator[](unsigned int index);
    const class Sequence& operator[](unsigned int index) const;
};

class Sequence {
public:
    unsigned int m_NaluType;
    Array m_Nalus;
};

namespace AP4_HvccAtom {
    typedef ::Sequence Sequence;
};

class AP4_Mpeg2TsVideoSampleStream {
private:
    int m_SampleDescriptionIndex;
    unsigned int m_NaluLengthSize;
    AP4_DataBuffer m_Prefix;
    unsigned int m_SamplesWritten;
    AP4_UI64 m_TimeScale;
public:
    AP4_Result WriteSample(AP4_Sample& sample,
                         AP4_DataBuffer& sample_data,
                         AP4_SampleDescription* sample_description,
                         bool with_pcr,
                         AP4_ByteStream& output);
    AP4_Result WritePES(const unsigned char* data,
                      unsigned int data_size,
                      AP4_UI64 dts,
                      bool has_pts,
                      AP4_UI64 pts,
                      bool with_pcr,
                      AP4_ByteStream& output);
};

#define AP4_DYNAMIC_CAST(type, obj) dynamic_cast<type*>(obj)

inline void AP4_CopyMemory(void* dest, const void* src, unsigned int size) {
    memcpy(dest, src, size);
}

inline unsigned short AP4_BytesToInt16BE(const unsigned char* data) {
    return (data[0] << 8) | data[1];
}

inline unsigned int AP4_BytesToInt32BE(const unsigned char* data) {
    return (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
}

inline AP4_UI64 AP4_ConvertTime(AP4_UI64 time, AP4_UI64 from_scale, AP4_UI64 to_scale) {
    return time * to_scale / from_scale;
}

enum {
    AP4_ERROR_INVALID_PARAMETERS,
    AP4_ERROR_NOT_SUPPORTED,
    AP4_HEVC_NALU_TYPE_VPS_NUT = 32,
    AP4_HEVC_NALU_TYPE_SPS_NUT = 33,
    AP4_HEVC_NALU_TYPE_PPS_NUT = 34,
    AP4_AVC_NAL_UNIT_TYPE_ACCESS_UNIT_DELIMITER = 9
};