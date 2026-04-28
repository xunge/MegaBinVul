#include <cstddef>
#include <cstring>

typedef unsigned long long AP4_UI64;

enum AP4_Result {
    AP4_SUCCESS,
    AP4_ERROR_INVALID_PARAMETERS,
    AP4_ERROR_NOT_SUPPORTED
};

enum AP4_SampleFormat {
    AP4_SAMPLE_FORMAT_MP4A,
    AP4_SAMPLE_FORMAT_AC_3,
    AP4_SAMPLE_FORMAT_EC_3
};

enum AP4_Mpeg4AudioObjectType {
    AP4_MPEG4_AUDIO_OBJECT_TYPE_AAC_LC,
    AP4_MPEG4_AUDIO_OBJECT_TYPE_AAC_MAIN,
    AP4_MPEG4_AUDIO_OBJECT_TYPE_SBR,
    AP4_MPEG4_AUDIO_OBJECT_TYPE_PS
};

class AP4_DataBuffer {
public:
    const unsigned char* GetData() const { return nullptr; }
    unsigned int GetDataSize() const { return 0; }
};

class AP4_ByteStream {
};

class AP4_Sample {
public:
    AP4_UI64 GetDts() const { return 0; }
    unsigned int GetSize() const { return 0; }
};

class AP4_SampleDescription {
public:
    virtual ~AP4_SampleDescription() {}
    virtual AP4_SampleFormat GetFormat() const = 0;
};

class AP4_MpegAudioSampleDescription : public AP4_SampleDescription {
public:
    virtual AP4_Mpeg4AudioObjectType GetMpeg4AudioObjectType() const = 0;
    virtual unsigned int GetSampleRate() const = 0;
    virtual unsigned int GetChannelCount() const = 0;
    virtual const AP4_DataBuffer& GetDecoderInfo() const = 0;
};

struct AP4_Mp4AudioDecoderConfig {
    unsigned int m_SamplingFrequency;
    unsigned int m_ChannelCount;
    AP4_Result Parse(const unsigned char* data, unsigned int size) {
        return AP4_SUCCESS;
    }
};

class AP4_Mpeg2TsAudioSampleStream {
public:
    AP4_Result WriteSample(AP4_Sample& sample,
                          AP4_DataBuffer& sample_data,
                          AP4_SampleDescription* sample_description,
                          bool with_pcr,
                          AP4_ByteStream& output);
private:
    unsigned int m_TimeScale;
    unsigned int GetSamplingFrequencyIndex(unsigned int sample_rate) { return 0; }
    void MakeAdtsHeader(unsigned char* buffer, unsigned int size, unsigned int sampling_frequency_index, unsigned int channel_configuration) {}
    void WritePES(const unsigned char* data, unsigned int size, AP4_UI64 dts, bool is_video, AP4_UI64 pcr, bool with_pcr, AP4_ByteStream& output) {}
    AP4_UI64 AP4_ConvertTime(AP4_UI64 time, unsigned int from_time_scale, unsigned int to_time_scale) {
        return time * to_time_scale / from_time_scale;
    }
};

#define AP4_DYNAMIC_CAST(type, obj) dynamic_cast<type*>(obj)
#define AP4_SUCCEEDED(result) ((result) == AP4_SUCCESS)
#define AP4_CopyMemory(dest, src, size) memcpy(dest, src, size)