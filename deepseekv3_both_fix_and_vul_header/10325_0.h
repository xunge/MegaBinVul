#include <math.h>

typedef struct {
    float x;
    float y;
    float z;
} DDSVector3;

static inline float MaxF(float a, float b) { return fmaxf(a, b); }
static inline float MinF(float a, float b) { return fminf(a, b); }