#include <gmp.h>

typedef struct {
    mpz_t x;
    mpz_t y;
} PointZZ_p;

typedef struct {
    mpz_t a;
    mpz_t b;
    mpz_t p;
} CurveZZ_p;

void pointZZ_pDouble(PointZZ_p *rop, const PointZZ_p *point, const CurveZZ_p *curve);
void pointZZ_pAdd(PointZZ_p *rop, const PointZZ_p *p1, const PointZZ_p *p2, const CurveZZ_p *curve);