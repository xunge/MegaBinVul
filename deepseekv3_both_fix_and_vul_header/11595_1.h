#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

struct SkRegion {
    typedef int32_t RunType;
};

class SkRgnBuilder {
public:
    bool init(int maxHeight, int maxTransitions, bool pathIsInverse);
    SkRegion::RunType* fStorage;
    SkRegion::RunType* fCurrScanline;
    SkRegion::RunType* fPrevScanline;
    int fStorageCount;
};

static inline int64_t sk_64_mul(int64_t a, int64_t b) {
    return a * b;
}

static inline bool sk_64_isS32(int64_t n) {
    return n >= INT32_MIN && n <= INT32_MAX;
}

static inline int32_t sk_64_asS32(int64_t n) {
    return (int32_t)n;
}

static inline void* sk_malloc_canfail(size_t count, size_t elemSize) {
    return malloc(count * elemSize);
}

static inline void* sk_malloc_flags(size_t size, unsigned flags) {
    return malloc(size);
}