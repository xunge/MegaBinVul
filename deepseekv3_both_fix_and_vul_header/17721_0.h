#include <gmp.h>

typedef struct {
    mpz_t x;
    mpz_t y;
} PointZZ_p;

typedef struct {
    mpz_t a;
    mpz_t p;
} CurveZZ_p;