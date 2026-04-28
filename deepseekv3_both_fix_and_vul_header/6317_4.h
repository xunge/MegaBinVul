#include <vector>
#include <cstdint>
#include <stdexcept>
#include <memory>

template<typename T>
using secure_vector = std::vector<T>;

class RandomNumberGenerator {
public:
    virtual ~RandomNumberGenerator() = default;
};

class BigInt {
public:
    BigInt(const uint8_t* msg, size_t msg_len);
    BigInt(RandomNumberGenerator& rng, size_t bits);
    BigInt(RandomNumberGenerator& rng, size_t bits, bool);
    bool operator>=(const BigInt& other) const;
    static secure_vector<uint8_t> encode_fixed_length_int_pair(const BigInt& a, const BigInt& b, size_t bytes);
};

class DL_Group {
public:
    size_t p_bits() const;
    size_t exponent_bits() const;
    size_t p_bytes() const;
    BigInt get_p() const;
    BigInt power_g_p(const BigInt& k, size_t k_bits) const;
    BigInt multiply_mod_p(const BigInt& a, const BigInt& b) const;
};

class ElGamal_Encryption_Operation {
    DL_Group m_group;
    std::unique_ptr<BigInt> m_monty_y_p;
    BigInt monty_execute(BigInt& monty, const BigInt& k, size_t k_bits);
public:
    secure_vector<uint8_t> raw_encrypt(const uint8_t msg[], size_t msg_len, RandomNumberGenerator& rng);
};

class Invalid_Argument : public std::runtime_error {
public:
    explicit Invalid_Argument(const char* msg) : std::runtime_error(msg) {}
};