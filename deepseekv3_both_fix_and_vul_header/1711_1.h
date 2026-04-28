#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <algorithm>

struct SmallVectorBase {
    void *BeginX;
    size_t Capacity;
    size_t size() const;
    size_t capacity() const;
    void grow_pod(void *FirstEl, size_t MinCapacity, size_t TSize);
};

void report_bad_alloc_error(const char*);
void* safe_malloc(size_t);
void* safe_realloc(void*, size_t);