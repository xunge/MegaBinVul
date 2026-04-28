#include <stdint.h>
#include <mutex>
#include <cstdio>

#define ALOGV(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#define ALOGW(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex* mutex) {}
    };
};

class Sample {
public:
    enum State { READY };
    State state() const { return READY; }
};

template<typename T>
class sp {
public:
    sp() : m_ptr(nullptr) {}
    sp(T* ptr) : m_ptr(ptr) {}
    operator T*() const { return m_ptr; }
    T* operator->() const { return m_ptr; }
    bool operator==(const T* other) const { return m_ptr == other; }
    bool operator!=(const T* other) const { return m_ptr != other; }
private:
    T* m_ptr;
};

class SoundChannel {
public:
    void play(sp<Sample> sample, int channelID, float leftVolume, float rightVolume, int priority, int loop, float rate) {}
    int state() { return 0; }
};

class SoundPool {
public:
    int play(int sampleID, float leftVolume, float rightVolume, int priority, int loop, float rate);
private:
    Mutex mLock;
    bool mQuit;
    int mNextChannelID;
    sp<Sample> findSample(int sampleID) { return nullptr; }
    sp<Sample> findSample_l(int sampleID) { return nullptr; }
    SoundChannel* allocateChannel_l(int priority) { return nullptr; }
    void dump() {}
};