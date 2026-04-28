#include <vector>
#include <cstddef>

typedef unsigned int word;

class BigInt {
public:
    enum Sign { Positive };
    BigInt() = default;
    BigInt(Sign, size_t);
    BigInt(int);
    size_t bits() const;
    size_t size() const;
    void shrink_to_fit();
    void grow_to(size_t);
    word* data();
    const word* data() const;
};

template<typename T>
class secure_vector : public std::vector<T> {
public:
    secure_vector(size_t size) : std::vector<T>(size) {}
};

class Power_Mod {
public:
    static size_t window_bits(size_t, size_t, size_t);
};

class Montgomery_Exponentiator {
public:
    void set_base(const BigInt& base);
private:
    size_t m_window_bits;
    BigInt m_exp;
    size_t m_hints;
    std::vector<BigInt> m_g;
    size_t m_mod_words;
    BigInt m_R2_mod;
    BigInt m_modulus;
    word m_mod_prime;
    class Reducer {
    public:
        BigInt reduce(const BigInt&);
    } m_reducer;
};

void bigint_monty_mul(BigInt&, const BigInt&, const BigInt&, const word*, size_t, word, word*);