#include <stdint.h>
#include <cstddef>

typedef int64_t AP4_SI64;
typedef int AP4_Result;

class AP4_Atom {
public:
    virtual AP4_Atom* FindChild(const char* path) = 0;
};

class AP4_StcoAtom : public AP4_Atom {
public:
    AP4_Result AdjustChunkOffsets(int delta);
};

class AP4_Co64Atom : public AP4_Atom {
public:
    AP4_Result AdjustChunkOffsets(AP4_SI64 delta);
};

class AP4_TrakAtom : public AP4_Atom {
public:
    AP4_Result AdjustChunkOffsets(AP4_SI64 delta);
};

#define AP4_DYNAMIC_CAST(T, ptr) dynamic_cast<T*>(ptr)
#define AP4_ERROR_INVALID_FORMAT 1
#define AP4_ERROR_INVALID_STATE 2