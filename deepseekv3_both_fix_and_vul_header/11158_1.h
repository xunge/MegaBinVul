#include <stddef.h>

typedef int AP4_Result;
typedef unsigned int AP4_Ordinal;
typedef size_t AP4_Size;

#define AP4_SUCCESS 0
#define AP4_ERROR_OUT_OF_RANGE (-1)
#define AP4_ERROR_INVALID_PARAMETERS (-2)

class AP4_Array {
public:
    unsigned int ItemCount() const;
    AP4_Size& operator[](unsigned int index);
};

class AP4_StszAtom {
public:
    AP4_Result SetSampleSize(AP4_Ordinal sample, AP4_Size sample_size);
private:
    AP4_Size m_SampleSize;
    AP4_Ordinal m_SampleCount;
    AP4_Array m_Entries;
};