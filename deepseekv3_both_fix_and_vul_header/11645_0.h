#include <stdint.h>
#include <string.h>

template<typename T, size_t N>
class iptreet {
public:
    static bool bit(const uint8_t *addr, size_t bitpos);
    static void setbit(uint8_t *addr, size_t bitpos);
    static void setbit(uint8_t *addr, size_t size, size_t bitpos);
};

extern void add(const uint8_t *addr, size_t addrlen, uint64_t val);