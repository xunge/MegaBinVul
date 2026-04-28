#include <stdint.h>
#include <cstddef>

typedef int AP4_Result;
typedef unsigned int AP4_Ordinal;
typedef uint32_t AP4_UI32;
typedef uint64_t AP4_UI64;
typedef unsigned int AP4_Size;

#define AP4_SUCCESS 0
#define AP4_ERROR_INVALID_FORMAT 1
#define AP4_ERROR_INTERNAL 2
#define AP4_FAILED(result) ((result) != AP4_SUCCESS)

class AP4_Sample {
public:
    void SetDescriptionIndex(AP4_Ordinal index);
    void SetDuration(AP4_UI32 duration);
    void SetDts(AP4_UI64 dts);
    void SetCts(AP4_UI64 cts);
    void SetCtsDelta(AP4_UI32 offset);
    void SetSize(AP4_Size size);
    void SetSync(bool sync);
    void SetOffset(AP4_UI64 offset);
    void SetDataStream(void* stream);
};

class StscAtom {
public:
    AP4_Result GetChunkForSample(AP4_Ordinal index, AP4_Ordinal& chunk, AP4_Ordinal& skip, AP4_Ordinal& desc);
};

class StcoAtom {
public:
    AP4_Result GetChunkOffset(AP4_Ordinal chunk, AP4_UI32& offset);
};

class Co64Atom {
public:
    AP4_Result GetChunkOffset(AP4_Ordinal chunk, AP4_UI64& offset);
};

class StszAtom {
public:
    AP4_Result GetSampleSize(AP4_Ordinal index, AP4_Size& size);
};

class Stz2Atom {
public:
    AP4_Result GetSampleSize(AP4_Ordinal index, AP4_Size& size);
};

class SttsAtom {
public:
    AP4_Result GetDts(AP4_Ordinal index, AP4_UI64& dts, AP4_UI32* duration);
};

class CttsAtom {
public:
    AP4_Result GetCtsOffset(AP4_Ordinal index, AP4_UI32& offset);
};

class StssAtom {
public:
    bool IsSampleSync(AP4_Ordinal index);
};

class AP4_AtomSampleTable {
public:
    AP4_Result GetSample(AP4_Ordinal index, AP4_Sample& sample);
private:
    StscAtom* m_StscAtom;
    StcoAtom* m_StcoAtom;
    Co64Atom* m_Co64Atom;
    StszAtom* m_StszAtom;
    Stz2Atom* m_Stz2Atom;
    SttsAtom* m_SttsAtom;
    CttsAtom* m_CttsAtom;
    StssAtom* m_StssAtom;
    void* m_SampleStream;
};