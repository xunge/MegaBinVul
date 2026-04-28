#include <mutex>
#include <vector>

#define ASSERT(cond) ((void)0)

class Biquad {
public:
    void getFrequencyResponse(int nFrequencies, const float* frequency, float* magResponse, float* phaseResponse);
};

class AudioParam {
public:
    double value();
};

class BiquadProcessor {
public:
    AudioParam* parameter1();
    AudioParam* parameter2();
    AudioParam* parameter3();
    AudioParam* parameter4();
};

class MutexLocker {
public:
    MutexLocker(std::mutex& mutex);
};

class BiquadDSPKernel {
public:
    double nyquist();
    void updateCoefficients(double cutoffFrequency, double Q, double gain, double detune);
    void updateCoefficientsIfNecessary(bool smooth, bool force);
    BiquadProcessor* biquadProcessor();
    void getFrequencyResponse(int nFrequencies, const float* frequencyHz, float* magResponse, float* phaseResponse);
    std::mutex m_processLock;
    Biquad m_biquad;
};

template<typename T>
class Vector {
public:
    Vector(int size);
    T& operator[](int index);
    T* data();
};

float narrowPrecisionToFloat(double value);