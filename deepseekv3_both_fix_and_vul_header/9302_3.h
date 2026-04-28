#include <mutex>
#include <vector>
#include <memory>
#include <cstdio>

#define ALOGV(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#define __unused

class Sample {
public:
    Sample(int sampleID, const char* path) {}
    int sampleID() const { return 0; }
    void startLoad() {}
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex* mutex) {}
    };
};

template<typename T>
class sp {
public:
    sp(T* ptr) {}
    T* operator->() { return nullptr; }
};

template<typename K, typename V>
class KeyedVector {
public:
    void add(K key, V value) {}
};

class DecodeThread {
public:
    void loadSample(int sampleID) {}
};

class SoundPool {
private:
    Mutex mLock;
    int mNextSampleID = 0;
    KeyedVector<int, sp<Sample>> mSamples;
    DecodeThread* mDecodeThread = nullptr;
    
    void doLoad(const sp<Sample>& sample) {}
public:
    int load(const char* path, int priority);
};