#include <vector>
#include <cstdint>
#include <stdexcept>

class BigInt {
public:
    size_t bytes() const;
    void binary_encode(uint8_t* data) const;
    BigInt& operator*=(size_t);
    BigInt& operator+=(size_t);
};

class BASE58_ALPHA {
public:
    BASE58_ALPHA();
    size_t code_for(char c) const;
    size_t radix() const;
    char operator[](size_t) const;
};

size_t count_leading_zeros(const char input[], size_t input_length, char c);

class Decoding_Error : public std::runtime_error {
public:
    explicit Decoding_Error(const char* msg) : std::runtime_error(msg) {}
};

uint8_t base58_value_of(char c);