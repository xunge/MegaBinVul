#include <math.h>
#include <assert.h>

#define SK_ScalarPI 3.14159265358979323846f
#define SkASSERT assert

static float sk_float_atan2(float y, float x) {
    return atan2f(y, x);
}