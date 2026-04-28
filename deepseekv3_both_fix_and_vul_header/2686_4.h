#include <vector>
#include <cstddef>
#include <cassert>

namespace CT {
    template<typename T>
    T select(bool condition, T a, T b);

    template<typename T>
    bool is_equal(T a, T b);

    void poison(const void* addr, size_t len);
    void unpoison(const void* addr, size_t len);
    void unpoison(size_t idx);
}

template<typename T>
class secure_vector {
public:
    size_t size() const;
    T* data();
    const T* data() const;
    T& operator[](size_t idx);
    const T& operator[](size_t idx) const;
};

class BigInt {
public:
    size_t size() const;
    unsigned long word_at(size_t w) const;
    void const_time_lookup(secure_vector<unsigned long>& output,
                         const std::vector<BigInt>& vec,
                         size_t idx);
};

#define BOTAN_ASSERT(expr, msg) assert((expr) && (msg))

using word = unsigned long;

void clear_mem(void* ptr, size_t len);