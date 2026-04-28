#include <stdint.h>

#define MAX_FRACTION_VALUE 0x10000

struct Fraction {
    int32_t numerator;
    int32_t denominator;
    Fraction(int32_t num, int32_t den);
};