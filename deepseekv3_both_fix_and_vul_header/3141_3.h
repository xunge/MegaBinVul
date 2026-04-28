#include <algorithm>
#include <cstddef>
#include <memory>

class FFTFrame {
public:
    explicit FFTFrame(size_t fftSize) {}
    void doPaddedFFT(const float* input, size_t length) {}
};

class FFTConvolver {
public:
    explicit FFTConvolver(size_t fftSize) {}
};

class DirectConvolver {
public:
    explicit DirectConvolver(size_t renderSliceSize) {}
};

class ReverbAccumulationBuffer {};

template<typename T> class OwnPtr {
public:
    OwnPtr() : m_ptr(nullptr) {}
    explicit OwnPtr(T* ptr) : m_ptr(ptr) {}
    ~OwnPtr() { delete m_ptr; }
    T* get() const { return m_ptr; }
    void clear() { delete m_ptr; m_ptr = nullptr; }
    T* leakPtr() { T* ptr = m_ptr; m_ptr = nullptr; return ptr; }
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool operator!() const { return !m_ptr; }
    explicit operator bool() const { return m_ptr; }
private:
    T* m_ptr;
};

template<typename T> inline OwnPtr<T> adoptPtr(T* ptr) { return OwnPtr<T>(ptr); }

class AudioFloatArray {
public:
    explicit AudioFloatArray(size_t size = 0) : m_size(size), m_data(size ? new float[size]() : nullptr) {}
    ~AudioFloatArray() { delete[] m_data; }
    void allocate(size_t size) { if (m_data) delete[] m_data; m_size = size; m_data = size ? new float[size]() : nullptr; }
    void copyToRange(const float* source, size_t start, size_t length) { std::copy(source, source + length, m_data + start); }
    float* data() { return m_data; }
    size_t size() const { return m_size; }
private:
    size_t m_size;
    float* m_data;
};

class ReverbConvolverStage {
public:
    ReverbConvolverStage(const float* impulseResponse, size_t, size_t reverbTotalLatency, size_t stageOffset, size_t stageLength,
                        size_t fftSize, size_t renderPhase, size_t renderSliceSize, ReverbAccumulationBuffer* accumulationBuffer, bool directMode);
private:
    ReverbAccumulationBuffer* m_accumulationBuffer;
    size_t m_accumulationReadIndex;
    size_t m_inputReadIndex;
    bool m_directMode;
    OwnPtr<FFTFrame> m_fftKernel;
    OwnPtr<FFTConvolver> m_fftConvolver;
    OwnPtr<AudioFloatArray> m_directKernel;
    OwnPtr<DirectConvolver> m_directConvolver;
    AudioFloatArray m_temporaryBuffer;
    size_t m_preDelayLength;
    size_t m_postDelayLength;
    size_t m_preReadWriteIndex;
    size_t m_framesProcessed;
    AudioFloatArray m_preDelayBuffer;
};

#define ASSERT(cond) ((void)0)