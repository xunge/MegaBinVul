#include <cstddef>

typedef unsigned int word;

class BigInt {
public:
    word* mutable_data();
};

void bigint_mul(BigInt& z, const BigInt& x, const BigInt& y, word* ws);
void bigint_monty_redc(word z[], const word p[], size_t p_size, word p_dash, word ws[]);