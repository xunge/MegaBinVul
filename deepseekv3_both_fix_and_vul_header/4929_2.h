#include <mutex>
#include <cstddef>
#include <cassert>

class BiquadDSPKernel {
public:
    void process(const float* source, float* destination, size_t framesToProcess);
    void updateCoefficientsIfNecessary();
    void updateCoefficientsIfNecessary(bool, bool);
    bool biquadProcessor();
    
private:
    std::mutex m_processLock;
    class Biquad {
    public:
        void process(const float*, float*, size_t);
    } m_biquad;
};

class MutexTryLocker {
public:
    MutexTryLocker(std::mutex&);
    bool locked();
};

#define ASSERT(x) assert(x)