#include <stdint.h>
#include <cstddef>

typedef int32_t AP4_Result;
typedef uint32_t AP4_Ordinal;
typedef uint32_t AP4_UI32;
typedef uint64_t AP4_UI64;
typedef uint32_t AP4_Size;

#define AP4_ERROR_INVALID_FORMAT (-1)
#define AP4_ERROR_INTERNAL (-2)
#define AP4_SUCCESS (0)
#define AP4_FAILED(result) ((result) < 0)

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
    void SetDataStream(class AP4_ByteStream* stream);
};

class AP4_AtomSampleTable {
public:
    AP4_Result GetSample(AP4_Ordinal index, AP4_Sample& sample);
private:
    class AP4_StcoAtom* m_StcoAtom;
    class AP4_Co64Atom* m_Co64Atom;
    class AP4_StscAtom* m_StscAtom;
    class AP4_StszAtom* m_StszAtom;
    class AP4_Stz2Atom* m_Stz2Atom;
    class AP4_SttsAtom* m_SttsAtom;
    class AP4_CttsAtom* m_CttsAtom;
    class AP4_StssAtom* m_StssAtom;
    class AP4_ByteStream* m_SampleStream;
};

class AP4_StcoAtom {
public:
    AP4_Result GetChunkOffset(AP4_Ordinal chunk, AP4_UI32& offset);
};

class AP4_Co64Atom {
public:
    AP4_Result GetChunkOffset(AP4_Ordinal chunk, AP4_UI64& offset);
};

class AP4_StscAtom {
public:
    AP4_Result GetChunkForSample(AP4_Ordinal sample, AP4_Ordinal& chunk, AP4_Ordinal& skip, AP4_Ordinal& desc);
};

class AP4_StszAtom {
public:
    AP4_Result GetSampleSize(AP4_Ordinal sample, AP4_Size& size);
};

class AP4_Stz2Atom {
public:
    AP4_Result GetSampleSize(AP4_Ordinal sample, AP4_Size& size);
};

class AP4_SttsAtom {
public:
    AP4_Result GetDts(AP4_Ordinal sample, AP4_UI64& dts, AP4_UI32* duration);
};

class AP4_CttsAtom {
public:
    AP4_Result GetCtsOffset(AP4_Ordinal sample, AP4_UI32& offset);
};

class AP4_StssAtom {
public:
    bool IsSampleSync(AP4_Ordinal sample);
};

class AP4_ByteStream {
};