#include <stdint.h>

typedef int32_t AP4_Result;

#define AP4_SUCCESS 0
#define AP4_FAILED(result) ((result) != AP4_SUCCESS)
#define AP4_ERROR_EOS 1
#define AP4_ERROR_INVALID_FORMAT 2

class AP4_Sample {
public:
    uint64_t GetDts() const;
};

class AP4_DataBuffer {
public:
    uint32_t GetDataSize() const;
};

class AP4_Track {
public:
    uint32_t GetMediaTimeScale() const;
};

class SampleReader {
public:
    AP4_Result ReadSample(AP4_Sample& sample, AP4_DataBuffer& sample_data);
};