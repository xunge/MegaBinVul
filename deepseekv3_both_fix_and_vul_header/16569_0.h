#include <string>
#include <cstdint>

class BigInt {
public:
    bool is_nonzero() const;
    void swap(BigInt& other);
};

void ct_divide_u8(const BigInt& v, uint8_t radix, BigInt& q, uint8_t& r);

char lookup_base58_char(uint8_t r);

class BASE58_ALPHA {
public:
    uint8_t radix() const;
    char operator[](uint8_t idx) const;
};