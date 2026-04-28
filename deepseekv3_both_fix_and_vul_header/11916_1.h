#include <stddef.h>

typedef int AP4_Result;
typedef size_t AP4_Size;
typedef unsigned long long AP4_LargeSize;

#define AP4_FAILURE (-1)
#define AP4_SUCCESS (0)
#define AP4_ERROR_OUT_OF_RANGE (-2)
#define AP4_FAILED(result) ((result) < 0)
#define AP4_SUCCEEDED(result) ((result) >= 0)

class AP4_DataBuffer {
public:
    AP4_Result SetDataSize(AP4_Size size);
    unsigned char* UseData();
};

class AP4_DataStream {
public:
    virtual AP4_Result GetSize(AP4_LargeSize& size);
    virtual AP4_Result Seek(AP4_Size offset);
    virtual AP4_Result Read(unsigned char* buffer, AP4_Size size);
};

class AP4_Sample {
private:
    AP4_DataStream* m_DataStream;
    AP4_Size m_Offset;
    AP4_Size m_Size;
public:
    AP4_Result ReadData(AP4_DataBuffer& data, AP4_Size size, AP4_Size offset);
};