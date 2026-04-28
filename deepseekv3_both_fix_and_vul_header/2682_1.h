#include <cstddef>

typedef unsigned int word;

class BigInt {
public:
    word* mutable_data() { return nullptr; }
    const word* data() const { return nullptr; }
    size_t size() const { return 0; }
    size_t sig_words() const { return 0; }
};

void bigint_sqr(word z[], size_t z_size, word ws[],
                const word x[], size_t x_size, size_t x_sw);

void bigint_monty_redc(word z[],
                      const word p[], size_t p_size, word p_dash,
                      word ws[]);