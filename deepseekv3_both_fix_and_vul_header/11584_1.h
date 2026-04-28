#include <cstdlib>
#include <cstddef>

struct SkImageInfo;
class SkAutoPixmapStorage {
public:
    void freeStorage();
    void reset(const SkImageInfo&, void*, size_t);
    bool tryAlloc(const SkImageInfo&);
    void* fStorage;
};

size_t AllocSize(const SkImageInfo&, size_t*);
void* sk_malloc_canfail(size_t);
void* sk_malloc_flags(size_t, int);