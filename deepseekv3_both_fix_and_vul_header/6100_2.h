#include <cstdint>
#include <cstdlib>
#include <new>
#include <stdexcept>

struct SharedInfo {};

constexpr size_t kMaxIOBufSize = SIZE_MAX;

size_t goodMallocSize(size_t size);

inline void throw_exception() {
    throw std::bad_alloc();
}

template <typename E>
void throw_exception() {
    throw E();
}

struct IOBuf {
    static size_t goodExtBufferSize(std::size_t minCapacity);
};