#include <stdint.h>
#include <stddef.h>
#include <stdexcept>
#include <vector>

class RandomNumberGenerator {};

class BigInt {
public:
    BigInt(const uint8_t*, size_t, size_t);
    bool is_zero() const;
    BigInt operator+(const BigInt&) const;
    static std::vector<uint8_t> encode_fixed_length_int_pair(const BigInt&, const BigInt&, size_t);
};

template<typename T>
class secure_vector : public std::vector<T> {
public:
    using std::vector<T>::vector;
    secure_vector(const std::vector<T>& v) : std::vector<T>(v) {}
};

class ECDSA_Signature_Operation {
private:
    BigInt m_x;
    BigInt m_b;
    BigInt m_b_inv;
    BigInt m_rfc6979_hash;
    BigInt m_ws;
    struct {
        size_t get_order_bits() const;
        BigInt get_order() const;
        size_t get_order_bytes() const;
        BigInt random_scalar(RandomNumberGenerator& rng);
        BigInt mod_order(const BigInt&);
        BigInt blinded_base_point_multiply_x(const BigInt&, RandomNumberGenerator&, const BigInt&);
        BigInt inverse_mod_order(const BigInt&);
        BigInt square_mod_order(const BigInt&);
        BigInt multiply_mod_order(const BigInt&, const BigInt&);
        BigInt multiply_mod_order(const BigInt&, const BigInt&, const BigInt&);
    } m_group;
public:
    secure_vector<uint8_t> raw_sign(const uint8_t msg[], size_t msg_len, RandomNumberGenerator& rng);
};

#define BOTAN_HAS_RFC6979_GENERATOR
BigInt generate_rfc6979_nonce(const BigInt&, const BigInt&, const BigInt&, const BigInt&);

class Internal_Error : public std::runtime_error {
public:
    explicit Internal_Error(const char* what) : std::runtime_error(what) {}
};