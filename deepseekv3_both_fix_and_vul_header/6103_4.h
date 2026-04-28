#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <new>
#include <stdexcept>
#include <cassert>

#define DCHECK(cond) assert(cond)
#define DCHECK_LT(a, b) assert((a) < (b))
#define UNLIKELY(x) (x)

enum IOBufFlags {
    kFlagFreeSharedInfo = 1
};

struct SharedInfo {
    void* userData;
    void (*freeFn)(void*);
    bool useHeapFullStorage;
    static void releaseStorage(SharedInfo*);
};

struct IOBuf {
    size_t length_;
    uint8_t* data_;
    uint8_t* buf_;
    size_t capacity_;
    
    size_t headroom() const;
    size_t tailroom() const;
    uint8_t* writableBuffer();
    bool isSharedOne() const;
    SharedInfo* sharedInfo();
    size_t capacity() const;
    void setFlagsAndSharedInfo(int, SharedInfo*);
    int flags() const;
    void reserveSlow(std::size_t minHeadroom, std::size_t minTailroom);
};

extern bool checked_add(size_t*, size_t, size_t);
extern size_t kMaxIOBufSize;
extern size_t jemallocMinInPlaceExpandable;
extern bool usingJEMalloc();
extern size_t goodExtBufferSize(size_t);
extern void* checkedMalloc(size_t);
extern void freeExtBuffer();
extern void initExtBuffer(uint8_t*, size_t, SharedInfo**, size_t*);
extern void (*io_buf_free_cb)(void*, size_t);
extern void (*io_buf_alloc_cb)(void*, size_t);
extern size_t xallocx(void*, size_t, size_t, int);

template <typename T>
inline void throw_exception() { throw T(); }