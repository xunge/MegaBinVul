#include <cstddef>
#include <cstdint>
#include <memory>
#include <new>
#include <stdexcept>

class IOBuf {
public:
    struct InternalConstructor {};
    IOBuf(InternalConstructor, uint64_t flagsAndInfo, uint8_t* buf, std::size_t capacity, uint8_t* data, std::size_t length);
    static uint64_t packFlagsAndSharedInfo(uint64_t flags, struct SharedInfo* info);
    static std::unique_ptr<IOBuf> createCombined(std::size_t capacity);
};

struct HeapPrefix {
    uint64_t magic;
    size_t size;
    HeapPrefix(uint64_t m, size_t s) : magic(m), size(s) {}
};

struct SharedInfo {
    void (*freeFn)(void*, void*);
    void* arg;
    SharedInfo(void (*fn)(void*, void*), void* a) : freeFn(fn), arg(a) {}
};

struct HeapFullStorage {
    struct {
        HeapPrefix prefix;
        IOBuf buf;
    } hs;
    SharedInfo shared;
    uint8_t align;
};

void freeInternalBuf(void* ptr, void* arg);
extern const std::size_t kMaxIOBufSize;
extern const uint64_t kIOBufInUse;
extern const uint64_t kDataInUse;
extern void (*io_buf_alloc_cb)(void* ptr, std::size_t size);

inline size_t goodMallocSize(size_t size) { return size; }
void* checkedMalloc(size_t size);
template <typename E> void throw_exception() { throw E(); }

using std::unique_ptr;