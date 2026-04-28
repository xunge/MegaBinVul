#include <stdint.h>
#include <vector>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <cassert>

#define ALOGV(...)
#define ALOGW(...)
#define CHECK(cond) assert(cond)
#define __unused

template<typename T> class sp {
public:
    sp(T* ptr = nullptr) : m_ptr(ptr) {}
    T* get() const { return m_ptr; }
    T* operator->() const { return m_ptr; }
    bool operator!=(std::nullptr_t) const { return m_ptr != nullptr; }
    size_t size() const { return m_ptr ? 1 : 0; }
private:
    T* m_ptr;
};

class IMemory {
public:
    size_t size() const { return 0; }
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

class Condition {
public:
    void signal() {}
};

class CameraSource {
private:
    Mutex mLock;
    bool mStarted = false;
    int64_t mStartTimeUs = 0;
    int64_t mLastFrameTimestampUs = 0;
    int64_t mFirstFrameTimeUs = 0;
    int32_t mNumFramesReceived = 0;
    int32_t mNumGlitches = 0;
    int64_t mGlitchDurationThresholdUs = 0;
    std::vector<sp<IMemory>> mFramesReceived;
    std::vector<int64_t> mFrameTimes;
    Condition mFrameAvailableCondition;

    void releaseOneRecordingFrame(const sp<IMemory>& data) {}
    bool skipCurrentFrame(int64_t timestampUs) { return false; }
    void adjustIncomingANWBuffer(IMemory* data) {}
public:
    void dataCallbackTimestamp(int64_t timestampUs, int32_t msgType, const sp<IMemory>& data);
};