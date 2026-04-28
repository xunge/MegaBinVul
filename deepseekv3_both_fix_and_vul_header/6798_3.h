#include <cstddef>
#include <cstring>
#include <cstdint>
#include <vector>
#include <iterator>

#define MAX_SAMPLE_LENGTH 0xFFFFFFFF
#define CHN_LOOP 1

typedef uint32_t SmpLength;

namespace mpt {
    template <typename T>
    size_t size(T* arr) {
        return std::extent<T>::value;
    }
}

struct ModSample {
    bool HasSampleData() const;
    bool AllocateSample();
    void FreeSample();
    SmpLength nLength;
    uint8_t* pSample;
    uint8_t* pSample8;
    SmpLength* cues;
    SmpLength nLoopStart;
    SmpLength nLoopEnd;
    struct {
        void set(int flag);
    } uFlags;
};

struct STPLoopInfo {
    SmpLength loopStart;
    SmpLength loopLength;
};

struct STPLoopList {
    size_t size() const;
    STPLoopInfo& operator[](size_t index);
    std::vector<STPLoopInfo> data;
};