#include <stdint.h>
#include <stddef.h>

class BigInt {
public:
    BigInt(const uint8_t*, size_t);
    BigInt(const uint8_t*, size_t, size_t);
    bool operator<=(int) const;
    bool operator>=(int) const;
    bool operator<(const BigInt&) const;
    bool operator>(const BigInt&) const;
    bool operator==(const BigInt&) const;
    bool operator>=(const BigInt&) const;
    bool operator<=(const BigInt&) const;
};

class PointGFp {
public:
    bool is_zero() const;
    BigInt get_affine_x() const;
};

class ECDSA_Verification_Operation {
private:
    class Group {
    public:
        size_t get_order_bytes() const;
        size_t get_order_bits() const;
        BigInt get_order() const;
        BigInt inverse_mod_order(const BigInt&) const;
        BigInt multiply_mod_order(const BigInt&, const BigInt&) const;
        BigInt mod_order(const BigInt&) const;
    };

    class Gy_mul {
    public:
        PointGFp multi_exp(const BigInt&, const BigInt&) const;
    };

    Group m_group;
    Gy_mul m_gy_mul;

public:
    bool verify(const uint8_t msg[], size_t msg_len, const uint8_t sig[], size_t sig_len);
};