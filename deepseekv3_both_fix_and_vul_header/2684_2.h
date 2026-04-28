#include <cstddef>
#include <cstdint>
#include <vector>

using word = uint32_t;

template<typename T>
class secure_vector : public std::vector<T> {
public:
    using std::vector<T>::vector;
    T* data() { return std::vector<T>::data(); }
    const T* data() const { return std::vector<T>::data(); }
};

class BigInt {
public:
    enum Sign { Positive, Negative };
    BigInt(Sign, size_t);
    size_t sig_words() const;
    size_t size() const;
    word* mutable_data();
    const word* data() const;
    void grow_to(size_t);
    static void const_time_lookup(secure_vector<word>&, const std::vector<BigInt>&, uint32_t);
    uint32_t get_substring(size_t, size_t) const;
};

class Montgomery_Exponentiator {
public:
    BigInt execute() const;
private:
    size_t m_exp_bits;
    size_t m_window_bits;
    size_t m_mod_words;
    word m_mod_prime;
    BigInt m_R_mod;
    BigInt m_exp;
    std::vector<BigInt> m_g;
    secure_vector<word> m_modulus;
};

void bigint_monty_sqr(BigInt&, const BigInt&, const word*, size_t, word, word*);
void bigint_monty_mul(BigInt&, const BigInt&, const BigInt&, const word*, size_t, word, word*);
void bigint_monty_redc(word*, const word*, size_t, word, word*);
void bigint_mul(word*, size_t, const word*, size_t, size_t, const word*, size_t, size_t, word*);