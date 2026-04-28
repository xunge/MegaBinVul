#include <cstdlib>
#include <cstdint>
#include <new>
#include <stdexcept>

struct SharedInfo {
    void* userData;
};

class IOBuf {
public:
    void allocExtBuffer(std::size_t minCapacity, uint8_t** bufReturn,
                       SharedInfo** infoReturn, std::size_t* capacityReturn);
};

const std::size_t kMaxIOBufSize = 0;
std::size_t goodExtBufferSize(std::size_t minCapacity);
void* checkedMalloc(std::size_t size);
void initExtBuffer(uint8_t* buf, std::size_t mallocSize, SharedInfo** infoReturn, std::size_t* capacityReturn);
void (*io_buf_alloc_cb)(void*, std::size_t);

template <typename E>
void throw_exception() { throw E(); }