#include <gmp.h>

typedef struct {
    mpz_t x;
    mpz_t y;
} PointZZ_p;

typedef struct {
    mpz_t p;
    mpz_t a;
    mpz_t b;
} CurveZZ_p;