#include <stdint.h>
#include <stddef.h>

template<typename T, size_t N>
class iptreet {
public:
    static bool bit(const uint8_t* addr, size_t pos);
    static void setbit(uint8_t* addr, size_t len, size_t pos);
    static void setbit(uint8_t* addr, size_t pos);
};