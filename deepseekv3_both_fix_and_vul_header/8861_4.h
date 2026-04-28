#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <new>
#include <cassert>

#define ALOGV(...)
#define ALOGE(...)
#define ALOGW(...)
#define ALOGI(...)
#define CHECK_EQ(a, b) assert((a) == (b))
#define NULL nullptr

template<typename T> class sp {
public:
    sp(T* ptr = nullptr) : mPtr(ptr) {}
    T* operator->() const { return mPtr; }
    bool operator==(const sp<T>& other) const { return mPtr == other.mPtr; }
    bool operator==(const T* ptr) const { return mPtr == ptr; }
    bool operator==(std::nullptr_t) const { return mPtr == nullptr; }
    T* mPtr;
};

class DataSource {
public:
    virtual ssize_t readAt(off64_t offset, void *data, size_t size) const = 0;
};

class VBRISeeker {
public:
    off64_t mBasePos;
    int64_t mDurationUs;
    struct {
        void push(uint32_t);
    } mSegments;
    static sp<VBRISeeker> CreateFromSource(const sp<DataSource> &source, off64_t post_id3_pos);
};

uint32_t U32_AT(const uint8_t *ptr);
uint16_t U16_AT(const uint8_t *ptr);
uint32_t U24_AT(const uint8_t *ptr);
bool GetMPEGAudioFrameSize(uint32_t header, size_t *frame_size, int *sample_rate);