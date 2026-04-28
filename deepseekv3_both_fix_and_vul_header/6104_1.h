#include <cstddef>
#include <new>
#include <stdexcept>
#include <cstdint>
#include <cstdlib>

struct HeapPrefix {
    HeapPrefix(uint32_t, size_t) {}
};

struct HeapStorage {
    HeapPrefix prefix;
    char buf[];
};

struct IOBuf {
    static constexpr size_t kMaxIOBufSize = 0;
    static constexpr uint32_t kIOBufInUse = 0;
    static void (*io_buf_alloc_cb)(void*, size_t);
    void* operator new(size_t size);
};

inline void* checkedMalloc(size_t size) {
    return malloc(size);
}

template<typename T>
inline void throw_exception() {
    throw T();
}