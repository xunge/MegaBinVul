#include <cstdlib>
#include <cstddef>

enum {
    SK_MALLOC_THROW,
    SK_MALLOC_TEMP
};

namespace SkAutoMalloc {
    enum OnShrink {
        kAlloc_OnShrink
    };
}

void* sk_malloc_throw(size_t size);
void* sk_malloc_flags(size_t size, int flags);
void sk_free(void* ptr);

#define SkASSERT(cond) ((void)0)

constexpr size_t kSize = 1024;
void* fPtr;
size_t fSize;
char fStorage[kSize];