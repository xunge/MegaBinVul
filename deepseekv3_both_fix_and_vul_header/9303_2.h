#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

#define __unused __attribute__((unused))
#define ALOGV(...) printf(__VA_ARGS__)

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

template<typename KEY, typename VALUE>
class Vector {
public:
    void add(KEY key, VALUE value) {}
};

class Sample {
public:
    Sample(int sampleID, int fd, int64_t offset, int64_t length) {}
    int sampleID() const { return 0; }
    void startLoad() {}
};

class DecodeThread {
public:
    void loadSample(int sampleID) {}
};

class SoundPool {
public:
    int load(int fd, int64_t offset, int64_t length, int priority __unused);
private:
    Mutex mLock;
    int mNextSampleID;
    Vector<int, sp<Sample>> mSamples;
    DecodeThread* mDecodeThread;
    void doLoad(const sp<Sample>& sample) {}
};