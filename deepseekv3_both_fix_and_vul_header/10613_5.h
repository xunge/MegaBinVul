#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>

typedef unsigned int word32;
typedef unsigned char byte;

class Redirector;

class TheBitBucket {
public:
    TheBitBucket() {}
    operator TheBitBucket*() { return this; }
};

class Redirector {
public:
    Redirector(TheBitBucket* bucket) {}
    Redirector(class MeterFilter* filter) {}
};

class MeterFilter {
public:
    MeterFilter(Redirector* redirector) {}
    size_t GetTotalBytes() const { return 0; }
    operator MeterFilter*() { return this; }
};

class Deflator {
public:
    Deflator(Redirector* redirector) {}
};

class AES {};

template <typename T>
class AutoSeededX917RNG {
public:
    AutoSeededX917RNG() {}
    void DiscardBytes(size_t n) {}
    bool CanIncorporateEntropy() { return false; }
    void IncorporateEntropy(const byte* input, size_t length) {}
    std::string AlgorithmName() { return ""; }
    word32 GenerateWord32() { return 0; }
    word32 GenerateWord32(word32 min, word32 max) { return 0; }
    void GenerateBlock(byte* output, size_t size) {}
};

class RandomNumberSource {
public:
    RandomNumberSource(AutoSeededX917RNG<AES>& rng, size_t size, bool pumpAll, Deflator* deflator) {}
};

class SecByteBlock {
public:
    SecByteBlock(size_t size) {}
    size_t SizeInBytes() const { return 0; }
    byte* BytePtr() { return nullptr; }
    operator byte*() { return BytePtr(); }
};

class GlobalRNG {
public:
    void GenerateBlock(byte* output, size_t size) {}
    static GlobalRNG& Instance() { static GlobalRNG instance; return instance; }
};

GlobalRNG& GlobalRNG() { return GlobalRNG::Instance(); }

class Exception : public std::runtime_error {
public:
    Exception() : std::runtime_error("") {}
};