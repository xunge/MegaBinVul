#include <cstring>
#include <cstdint>

typedef uint32_t SmpLength;

struct ModSample {
    bool HasSampleData() const;
    void FreeSample();
    bool AllocateSample();
    SmpLength nLength;
    uint8_t* pSample8;
    uint8_t* pSample;
    struct {
        void set(int, bool);
    } uFlags;
    SmpLength nLoopStart;
    SmpLength nLoopEnd;
    int cues;
};

enum {
    CHN_LOOP
};

void MemsetZero(int&);