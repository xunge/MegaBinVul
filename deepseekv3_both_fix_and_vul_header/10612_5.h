#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>

typedef unsigned int word32;
typedef unsigned char byte;

class MeterFilter;

class TheBitBucket {
public:
    static TheBitBucket& GetInstance() {
        static TheBitBucket instance;
        return instance;
    }
};

class Redirector {
public:
    Redirector(const TheBitBucket&) {}
    Redirector(MeterFilter&) {}
};

class MeterFilter {
public:
    MeterFilter(Redirector* r) {}
    size_t GetTotalBytes() const { return 0; }
};

class RandomPool {
public:
    void DiscardBytes(size_t) {}
    bool CanIncorporateEntropy() { return true; }
    void IncorporateEntropy(const byte* data, size_t size) {}
    std::string AlgorithmName() { return "unknown"; }
    word32 GenerateWord32() { return 0; }
    word32 GenerateWord32(word32 a, word32 b) { return 0; }
    void GenerateBlock(byte* output, size_t size) {}
};

class AutoSeededRandomPool : public RandomPool {};

class Deflator {
public:
    Deflator(Redirector* r) {}
};

class RandomNumberSource {
public:
    RandomNumberSource(RandomPool&, size_t, bool, Deflator*) {}
};

class Exception : public std::exception {};

class SecByteBlock : public std::vector<byte> {
public:
    SecByteBlock(size_t size) : std::vector<byte>(size) {}
    size_t SizeInBytes() const { return size(); }
    byte* data() { return std::vector<byte>::data(); }
    const byte* data() const { return std::vector<byte>::data(); }
    operator byte*() { return data(); }
    operator const byte*() const { return data(); }
};

class GlobalRNG {
public:
    static GlobalRNG& GetInstance() {
        static GlobalRNG instance;
        return instance;
    }
    void GenerateBlock(byte* output, size_t size) {}
};