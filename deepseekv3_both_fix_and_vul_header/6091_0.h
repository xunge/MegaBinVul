#include <cstdint>
#include <limits>
#include <algorithm>

#define MAX_FRACTION_VALUE 1000000
#define MAX_FRACTION_DENOMINATOR 1000000

struct Fraction {
    int32_t numerator;
    int32_t denominator;
    
    Fraction(int32_t num, int32_t den);
    
    static int32_t gcd(int32_t a, int32_t b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};