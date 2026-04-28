#include <stdint.h>
#include <list>
#include <memory>
#include <cstdio>
#include <cstdlib>

template<typename T> 
class sp {
public:
    T* operator->() const { return m_ptr; }
    T* get() const { return m_ptr; }
private:
    T* m_ptr;
};

class IMemory {
public:
    void* pointer() const;
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&);
    };
};

class MediaBuffer {
public:
    void* data() const;
    void setObserver(void*);
    void release();
};

class Condition {
public:
    void signal();
};

template<typename T>
struct List : public std::list<T> {};

class CameraSource {
public:
    void signalBufferReturned(MediaBuffer *buffer);
private:
    Mutex mLock;
    List<sp<IMemory>> mFramesBeingEncoded;
    Condition mFrameCompleteCondition;
    int32_t mNumFramesEncoded;

    void adjustOutgoingANWBuffer(IMemory* memory);
    void releaseOneRecordingFrame(const sp<IMemory>& frame);
};

#define ALOGV(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define CHECK(expr) if (!(expr)) abort()