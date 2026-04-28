#include <sys/types.h>
#include <stdint.h>
#include <string.h>
#include <list>

template<typename T> class sp;

class AMessage {};
class IMemory {
public:
    size_t size() const { return 0; }
    void* pointer() const { return nullptr; }
};

template<typename T>
class Vector {
public:
    size_t size() const { return 0; }
    T& editItemAt(size_t index) { static T t; return t; }
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex &mutex) {}
    };
};

template<typename T>
class sp {
public:
    sp() : m_ptr(nullptr) {}
    sp(std::nullptr_t) : m_ptr(nullptr) {}
    void clear() { m_ptr = nullptr; }
    T* operator->() { return m_ptr; }
    bool operator==(std::nullptr_t) const { return m_ptr == nullptr; }
    sp<T>& operator=(const sp<T>& other) { m_ptr = other.m_ptr; return *this; }
private:
    T* m_ptr;
};

enum CommandType {
    EOS,
    DISCONTINUITY
};

enum Status {
    INFO_DISCONTINUITY = 1,
    ERROR_MALFORMED = -2,
    EWOULDBLOCK = -3
};

struct QueueEntry {
    bool mIsCommand;
    CommandType mCommand;
    sp<AMessage> mExtra;
    size_t mSize;
    size_t mOffset;
    size_t mIndex;
};

class BufferSource {
public:
    void onBufferAvailable(size_t index) {}
};

namespace NuPlayer {
    class NuPlayerStreamListener {
    public:
        ssize_t read(void *data, size_t size, sp<AMessage> *extra);
    private:
        std::list<QueueEntry> mQueue;
        Vector<sp<IMemory>> mBuffers;
        bool mEOS = false;
        bool mSendDataNotification = false;
        Mutex mLock;
        BufferSource* mSource = nullptr;
    };
}

#define CHECK_GT(a, b) ((void)0)
#define TRESPASS() ((void)0)