#include <cstddef>
#include <cstdint>
#include <new>

template<typename T>
class sp {
public:
    sp(T *ptr = nullptr);
    T* operator->() const;
    operator bool() const;
    T* get() const;
};

class MemorySource {
public:
    MemorySource(const uint8_t *data, size_t size);
};

struct ID3 {
    enum {
        ID3_UNKNOWN
    };

    bool mIsValid;
    const uint8_t *mData;
    size_t mSize;
    size_t mFirstFrameOffset;
    int mVersion;
    size_t mRawSize;

    ID3(const uint8_t *data, size_t size, bool ignoreV1);
    bool parseV2(const sp<MemorySource> &source, int offset);
    bool parseV1(const sp<MemorySource> &source);
};